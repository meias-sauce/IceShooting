#include "Play.h"
#include "../object/Player.h"
#include "../object/IceEnemy.h"
#include "../object/HotEnemy.h"
#include "DxLib.h"
#include "../controller/ControllerFacade.h"

Play::Play()
{
	this->player = new Player();
	this->object_list.push_back(player);
	this->bullet_list[0] = nullptr;
	this->bullet_list[1] = nullptr;
}

void Play::Update() {
	for (auto enemy : this->enemy_list) {
		if (enemy->iceChangeFlag) {
			this->enemy_list.push_back(new IceEnemy(enemy->GetPos(), enemy->GetVelo()));
			this->object_list.push_back(*(--this->enemy_list.end()));
		}
	}
	GameState::Update();
	if (this->frame % 60 == 0) {

		this->enemy_list.push_back(new IceEnemy());
		this->object_list.push_back(*(--this->enemy_list.end()));

		this->enemy_list.push_back(new HotEnemy());
		this->object_list.push_back(*(--this->enemy_list.end()));
	}

	for (auto itr = enemy_list.begin(); itr != enemy_list.end();) {
		if ((*itr)->endFlag) {
			itr = enemy_list.erase(itr);
		}
		else {
			(*itr)->CollidePlayer(player, 1);
			for (auto bullet : this->bullet_list) {
				if (bullet == nullptr) continue;
				(*itr)->CollideBullet(bullet);
			}
			itr++;
		}
	}

	const auto controller = ControllerFacade::GetInstance();
	if (controller->KeyDown(KEY_INPUT_SPACE)) {
		player->Shot(bullet_list);
	}

	for (auto& bullet : this->bullet_list) {
		if (bullet == nullptr) continue;
		bullet->Update();
		if (bullet->endFlag) {
			delete bullet;
			bullet = nullptr;
		}
	}
}

void Play::Draw() {
	GameState::Draw();
	for (auto bullet : this->bullet_list) {
		if (bullet == nullptr) continue;
		bullet->Draw();
	}
}
/*
void Play::AddEnemy(Enemy * obj)
{
	this->enemy_list.push_back(obj);
	this->object_list.push_back(*(--this->enemy_list.end()));
}*/

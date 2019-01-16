#include "Title.h"
#include "../object/Player.h"
#include "../object/IceEnemy.h"
#include "../object/HotEnemy.h"
#include "DxLib.h"

Title::Title()
{
	this->player = new Player();
	this->object_list.push_back(player);
}

void Title::Update() {
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
			itr++;
		}
	}

}

void Title::Draw() {
	GameState::Draw();
}

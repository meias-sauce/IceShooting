#include "HotEnemy.h"
#include "IceEnemy.h"
#include "../resource/Resource.h"
#include "../state/Play.h"

HotEnemy::HotEnemy()
{
	this->graphic = Resource::Load("resource/fire.png");
}


HotEnemy::~HotEnemy()
{
}


void HotEnemy::CollidePlayer(Player* player, int combo)
{
	Enemy::CollidePlayer(player, combo);
	if (player->GetCollider()->IsCollision(*(this->collider))) {
		player->AddThickness(-combo);
		this->endFlag = true;
	}
}

void HotEnemy::CollideBullet(Bullet * bullet)
{
	Enemy::CollideBullet(bullet);
	if (bullet->GetCollider()->IsCollision(*(this->collider))) {
		bullet->endFlag = true;
		this->iceChangeFlag = true;
		this->endFlag = true;
	}
}

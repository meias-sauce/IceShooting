#include "HotEnemy.h"
#include "../resource/Resource.h"

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
	if (player->GetCollider()->isCollision(*(this->collider))) {
		player->AddThickness(-combo);
		this->endFlag = true;
	}
}

void HotEnemy::CollideBullet(Bullet * bullet)
{
	Enemy::CollideBullet(bullet);
	if (bullet->GetCollider()->isCollision(*(this->collider))) {
		bullet->endFlag = true;
		this->endFlag = true;
	}
}
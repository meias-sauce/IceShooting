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
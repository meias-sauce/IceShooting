#include "IceEnemy.h"
#include "../resource/Resource.h"

IceEnemy::IceEnemy()
{
	this->graphic = Resource::Load("resource/ice.png");
}


IceEnemy::~IceEnemy()
{
}

void IceEnemy::CollidePlayer(Player* player, int combo)
{
	Enemy::CollidePlayer(player, combo);
	if (player->GetCollider()->isCollision(*(this->collider))) {
		player->AddThickness(combo);
		this->endFlag = true;
	}
}

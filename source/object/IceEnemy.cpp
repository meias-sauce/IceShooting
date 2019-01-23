#include "IceEnemy.h"
#include "../resource/Resource.h"

IceEnemy::IceEnemy()
{
	this->graphic = Resource::Load("resource/ice.png");
}

IceEnemy::IceEnemy(Vector2 pos, Vector2 velo)
{
	this->graphic = Resource::Load("resource/ice.png");
	this->pos = pos;
	this->velo = velo;
}


IceEnemy::~IceEnemy()
{
}

void IceEnemy::CollidePlayer(Player* player, int combo)
{
	Enemy::CollidePlayer(player, combo);
	if (player->GetCollider()->IsCollision(*(this->collider))) {
		player->AddThickness(combo);
		this->endFlag = true;
	}
}

void IceEnemy::CollideBullet(Bullet * bullet)
{
	Enemy::CollideBullet(bullet);
	if (bullet->GetCollider()->IsCollision(*(this->collider))) {
		bullet->endFlag = true;
	}
}

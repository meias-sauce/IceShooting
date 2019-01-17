#pragma once
#include "Enemy.h"
class IceEnemy :
	public Enemy
{
public:
	IceEnemy();
	~IceEnemy();
	void CollidePlayer(Player * player, int combo);
	void CollideBullet(Bullet * bullet);
};


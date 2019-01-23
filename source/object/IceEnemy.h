#pragma once
#include "Enemy.h"
class IceEnemy :
	public Enemy
{
public:
	IceEnemy();
	IceEnemy(Vector2 pos, Vector2 velo);
	~IceEnemy();
	void CollidePlayer(Player * player, int combo);
	void CollideBullet(Bullet * bullet);
};


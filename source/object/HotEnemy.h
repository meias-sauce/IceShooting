#pragma once
#include "Enemy.h"

class HotEnemy : public Enemy
{
public:
	HotEnemy();
	~HotEnemy();
	void CollidePlayer(Player * player, int combo);
};


#pragma once
#include <list>
#include "GameState.h"
#include "../object/Player.h"
#include "../object/Enemy.h"
#include "../object/Bullet.h"

class Title :
	public GameState
{
private:
	Player* player;
	std::list<Enemy*> enemy_list;
	Bullet* bullet_list[2];

public:
	Title();
	//~Title();
	void Update();
	void Draw();
};


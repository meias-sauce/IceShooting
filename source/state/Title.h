#pragma once
#include <list>
#include "GameState.h"
#include "../object/Player.h"
#include "../object/Enemy.h"

class Title :
	public GameState
{
private:
	Player* player;
	std::list<Enemy*> enemy_list;

public:
	Title();
	//~Title();
	void Update();
	void Draw();
};


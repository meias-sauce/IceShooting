#pragma once
#include <list>
#include "GameState.h"
#include "../object/Player.h"
#include "../object/Enemy.h"
#include "../object/Bullet.h"

class Play :
	public GameState
{
private:
	Player * player;
	std::list<Enemy*> enemy_list;
	Bullet* bullet_list[2];

public:
	Play();
	//~Play();
	void Update();
	void Draw();
	void AddEnemy(Enemy*);
};


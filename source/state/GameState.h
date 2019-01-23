#pragma once
#include <list>
#include "../object/GameObject.h"

class GameState
{
protected:
	//State内のオブジェクトはとりあえず全部ぶっこむ
	std::list<GameObject*> object_list;

	int frame;

public:
	GameState();
	~GameState();
	virtual void Update();
	virtual void Draw();
};

#pragma once
#include <list>
#include "../object/GameObject.h"

class GameState
{
protected:
	//State内のオブジェクトはとりあえず全部ぶっこむ
	std::list<GameObject*> object_list;

public:
	GameState();
	~GameState();
	void Update();
	void Draw();
	//void AddObject(GameObject * object);
};

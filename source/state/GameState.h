#pragma once
#include <list>
#include "../object/GameObject.h"

class GameState
{
protected:
	//State���̃I�u�W�F�N�g�͂Ƃ肠�����S���Ԃ�����
	std::list<GameObject*> object_list;

public:
	GameState();
	~GameState();
	void Update();
	void Draw();
	//void AddObject(GameObject * object);
};

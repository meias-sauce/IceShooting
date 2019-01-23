#pragma once
#include <list>
#include "../object/GameObject.h"

class GameState
{
protected:
	//State���̃I�u�W�F�N�g�͂Ƃ肠�����S���Ԃ�����
	std::list<GameObject*> object_list;

	int frame;

public:
	GameState();
	~GameState();
	virtual void Update();
	virtual void Draw();
};

#include "GameState.h"



GameState::GameState()
{
}


GameState::~GameState()
{
	for (auto object : object_list) {
		delete object;
	}
	object_list.clear();
}

void GameState::Update() {
	for (auto itr = this->object_list.begin(); itr != this->object_list.end();) {
		(*itr)->Update();
		if ((*itr)->endFlag) {
			delete (*itr);
			itr = this->object_list.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void GameState::Draw() {
	for (auto object : this->object_list) {
		object->Draw();
	}
}
/*
void GameState::AddObject(GameObject* object) {
	this->object_list.push_back(object);
}*/

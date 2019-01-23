#include "GameState.h"



GameState::GameState()
{
	this->frame = 0;
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
		if ((*itr)->endFlag) {
			delete (*itr);
			(*itr) = nullptr;
			itr = this->object_list.erase(itr);
		}
		else {
			(*itr)->Update();
			itr++;
		}
	}
	this->frame++;
}

void GameState::Draw() {
	for (auto object : this->object_list) {
		object->Draw();
	}
}

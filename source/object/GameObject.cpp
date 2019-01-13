#include "GameObject.h"

GameObject::GameObject() {
	this->angle = 0;
	this->endFlag = false;
}


GameObject::~GameObject()
{
}

void GameObject::Update() {
	this->velo.x += this->accel.x;
	this->velo.y += this->accel.y;
	this->pos.x += this->velo.x;
	this->pos.y += this->velo.y;
}

void GameObject::Draw() {
	if (this->graphic != nullptr) {
		this->graphic->Draw(pos.x, pos.y, angle);
	}
}

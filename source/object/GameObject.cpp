#include "GameObject.h"

GameObject::GameObject() {
	this->frame = 0;
	this->angle = 0;
	this->endFlag = false;
	this->collider = nullptr;
	this->graphic = nullptr;
}


GameObject::~GameObject()
{
	if (this->collider != nullptr) {
		delete this->collider;
		this->collider = nullptr;
	}
}

void GameObject::Update() {
	//I‚í‚Á‚Ä‚é‚È‚ç‰½‚à‚µ‚È‚¢‚Å‚¦‚¦‚¼
	if (this->endFlag) return;

	this->velo.x += this->accel.x;
	this->velo.y += this->accel.y;
	this->pos.x += this->velo.x;
	this->pos.y += this->velo.y;

	this->frame++;
}

void GameObject::Draw() {
	//‰½‚à‚µ‚È‚¢‚Å‚¦‚¦‚¼
	if (this->endFlag) return;

	if (this->graphic != nullptr) {
		this->graphic->Draw(pos.x, pos.y, angle);
	}
	if (this->collider != nullptr) {
		//this->collider->Draw();
	}
}

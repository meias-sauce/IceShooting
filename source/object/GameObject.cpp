#include "GameObject.h"

GameObject::GameObject() {
	angle = 0;
}


GameObject::~GameObject()
{
}

void GameObject::Update() {
	velo.x += accel.x;
	velo.y += accel.y;
	pos.x += velo.x;
	pos.y += velo.y;
}

void GameObject::Draw() {
	if (graphic != nullptr) {
		graphic->Draw(pos.x, pos.y, angle);
	}
}

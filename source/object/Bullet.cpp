#include "Bullet.h"
#include "../resource/Resource.h"
#include "../camera/Camera.h"

Bullet::Bullet(Vector2 pos, Vector2 velocity, float angle) {
	this->pos = pos;
	this->velo = velocity;
	this->angle = angle;
	this->graphic = Resource::Load("resource/bullet.png");

	this->collider = new Rect(this->pos, Vector2(40, 20), this->angle);
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	GameObject::Update();
	this->collider->SetParameter(this->pos, Vector2(40, 20), this->angle);

	const auto camera = Camera::GetInstance();

	if (camera->IsOutCamera(this->pos, Vector2(50, 50))) {
		this->endFlag = true;
	}
}

void Bullet::Draw()
{
	GameObject::Draw();
}

Rect * Bullet::GetCollider()
{
	return this->collider;
}

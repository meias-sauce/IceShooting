#include "Enemy.h"
#include "DxLib.h"
#include "../collider/Rect.h"
#include "../camera/Camera.h"

Enemy::Enemy()
{
	const auto camera = Camera::GetInstance();

	auto left = camera->GetFrameLeft();
	auto right = camera->GetFrameRight();
	auto up = camera->GetFrameUp();
	auto bottom = camera->GetFrameDown();


	this->pos.x = camera->GetFrameLeft() + GetRand(camera->GetFrameRight() - camera->GetFrameLeft());
	this->pos.y = camera->GetFrameUp() - GetRand(200);
	this->velo.y = GetRand(3) + 2;

	this->colliderAngle = 0;
	this->collider = new Rect(this->pos, Vector2(50 /sqrt(2), 50 / sqrt(2)), this->colliderAngle);
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
	GameObject::Update();

	const auto camera = Camera::GetInstance();

	if (this->pos.y > camera->GetFrameDown() + 25) {
		this->endFlag = true;
	}
	colliderAngle += (0.5);
	collider->SetParameter(this->pos, Vector2(50 / sqrt(2), 50 / sqrt(2)), this->colliderAngle);
}

void Enemy::Draw()
{
	GameObject::Draw();
}

void Enemy::CollidePlayer(Player* player , int combo) {
}

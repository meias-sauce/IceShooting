#include "Camera.h"
#include "DxLib.h"

//‰Šú‰»
Camera* Camera::instance = nullptr;

Camera::Camera()
{
	center = { this->windowSize.x / 2,  this->windowSize.y / 2 };
	extendRate = 1.0;
}


Camera* Camera::GetInstance()
{
	if (Camera::instance == nullptr) {
		Camera::instance = new Camera();
	}
	return Camera::instance;
}

Camera::~Camera()
{
}

void Camera::Draw(float x, float y, float angle, int handle)
{
	float drawX = this->center.x + ((x - this->center.x) * this->extendRate);
	float drawY = this->center.y + ((y - this->center.y) * this->extendRate);
	DrawRotaGraph((int)drawX, (int)drawY, (double)extendRate, (double)angle, handle, true);
}


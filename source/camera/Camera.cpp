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

void Camera::AddExtendRate(float value) {
	this->extendRate += value;
}

void Camera::SetExtendRate(float value) {
	this->extendRate = value;
}


float Camera::GetFrameLeft() {
	return this->center.x - (this->windowSize.x / 2 / this->extendRate);
}
float Camera::GetFrameRight() {
	return this->center.x + (this->windowSize.x / 2 / this->extendRate);
}
float Camera::GetFrameUp() {
	return this->center.y - (this->windowSize.y / 2 / this->extendRate);
}
float Camera::GetFrameDown() {
	return this->center.y + (this->windowSize.y / 2 / this->extendRate);
}

bool Camera::IsOutCamera(Vector2 pos, Vector2 size)
{
	bool result = false;
	if (
		pos.x + size.x / 2 < this->GetFrameLeft() ||
		pos.x - size.x / 2 > this->GetFrameRight() ||
		pos.y + size.y / 2 < this->GetFrameUp() ||
		pos.y - size.y / 2 > this->GetFrameDown()
		) {
		result = true;
	}

	return result;
}

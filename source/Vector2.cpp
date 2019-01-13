#include "Vector2.h"
#include <cmath>

float Vector2::Distance(Vector2 v1, Vector2 v2) {
	float result = sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
	return result;
}

float Vector2::Distance(Vector2 v) {
	float result = Vector2::Distance(*this, v);
	return result;
}

float Vector2::Length() {
	Vector2 zeroVec = { 0, 0 };
	float result = this->Distance(zeroVec);
	return result;
}

void Vector2::Normalize()
{
	auto length = this->Length();
	if (length != 0) {
		Vector2 result = { this->x / length, this->y / length };
		this->x = result.x;
		this->y = result.y;
	}
}

void Vector2::Rotate(float angle)
{
	float resultX = this->x * std::cos(angle) - this->y * std::sin(angle);
	float resultY = this->x * std::sin(angle) + this->y * std::cos(angle);
	this->x = resultX;
	this->y = resultY;
}

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(float value)
{
	this->x = this->x + value;
	this->y = this->y + value;
	return *this;
}

Vector2 Vector2::operator-(float value)
{
	this->x = this->x - value;
	this->y = this->y - value;
	return *this;
}

Vector2 Vector2::operator*(float value)
{
	this->x = this->x * value;
	this->y = this->y * value;
	return *this;
}

Vector2 Vector2::operator/(float value)
{
	this->x = this->x / value;
	this->y = this->y / value;
	return *this;
}

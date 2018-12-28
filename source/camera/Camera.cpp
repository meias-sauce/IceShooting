#include "Camera.h"

//‰Šú‰»
Camera* Camera::instance = nullptr;

Camera::Camera()
{
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

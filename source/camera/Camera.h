#pragma once
#include  "../resource/Resource.h"

class Camera
{
private:
	Camera();
	static Camera* instance;

public:
	static Camera* GetInstance();
	~Camera();
	void Draw(float x, float y, Resource* resource);
};


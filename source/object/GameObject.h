#pragma once
#include "../resource/Resource.h"
#include "../Vector2.h"

class GameObject
{
private:
	Vector2 pos = {};
	Vector2 velo = {};
	Vector2 accel = {};
	Resource* graphic = nullptr;

public:
	GameObject();
	~GameObject();
	void Update();
	void Draw();
};


#pragma once
#include "GameObject.h"
#include "../Vector2.h"

class Bullet :
	public GameObject
{
public:
	Bullet(Vector2 pos, Vector2 velocity, float angle);
	~Bullet();
	void Update();
	void Draw();
	Rect* GetCollider();
};

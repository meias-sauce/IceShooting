#pragma once
#include "GameObject.h"
#include "Player.h"

class Enemy :
	public GameObject
{
private:
	//ˆÅ‚Ì“–‚½‚è”»’è
	float colliderAngle;

public:
	Enemy();
	~Enemy();
	virtual void Update();
	virtual void Draw();
	virtual void CollidePlayer(Player * player, int combo);
	//bool IsCollidePlayer(Rect * playerCollider);
};


#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"

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
	virtual void CollideBullet(Bullet* bullet);
	Vector2 GetPos();
	Vector2 GetVelo();
	//bool IsCollidePlayer(Rect * playerCollider);
	bool iceChangeFlag;
};


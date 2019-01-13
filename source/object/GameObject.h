#pragma once
#include "../resource/Resource.h"
#include "../Vector2.h"
#include "../collider/Rect.h"

class GameObject
{
protected:
	Vector2 pos = {};
	Vector2 velo = {};
	Vector2 accel = {};
	float angle;
	Resource* graphic = nullptr;
	Rect* collider; //Œ»ó‘¼‚Ég—p‚·‚écollider‚ª‘¶İ‚µ‚È‚¢‚Ì‚ÅRect‚É‚µ‚Ä‚µ‚Ü‚Á‚Ä‚¢‚é

public:
	GameObject();
	~GameObject();
	virtual void Update();
	virtual void Draw();
	
	//‚±‚¢‚Â‚ğtrue‚É‚·‚é‚ÆState‚©‚çÁ‚µ‚Ä‚­‚ê‚é
	bool endFlag;
};


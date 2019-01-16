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
	Rect* collider; //現状他に使用するcolliderが存在しないのでRectにしてしまっている

	//生成されてからのフレーム数を記録
	int frame;

public:
	GameObject();
	~GameObject();
	virtual void Update();
	virtual void Draw();
	
	//こいつをtrueにするとStateから消してくれる
	bool endFlag;
};


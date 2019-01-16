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
	Rect* collider; //���󑼂Ɏg�p����collider�����݂��Ȃ��̂�Rect�ɂ��Ă��܂��Ă���

	//��������Ă���̃t���[�������L�^
	int frame;

public:
	GameObject();
	~GameObject();
	virtual void Update();
	virtual void Draw();
	
	//������true�ɂ����State��������Ă����
	bool endFlag;
};


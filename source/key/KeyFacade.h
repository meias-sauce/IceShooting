#pragma once
#include "DxLib.h"
#include "KeyChecker.h"
#include "../Vector2.h"

class KeyFacade
{
private:
	int beforeKey_list[256];
	KeyChecker* keyChecker;

public:
	KeyFacade();
	~KeyFacade();
	//�X�V����
	void Update();
	//�����Ă�Ԃ�����true
	bool KeyPress(int);
	//�������u��true
	bool KeyDown(int);
	//�������u��true
	bool KeyUp(int);

	//�A�i���O�p�b�h�̓��͂��x�N�g���œf��
	Vector2 analogVector();
};


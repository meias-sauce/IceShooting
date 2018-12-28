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
	//更新処理
	void Update();
	//押してる間ずっとtrue
	bool KeyPress(int);
	//押した瞬間true
	bool KeyDown(int);
	//離した瞬間true
	bool KeyUp(int);

	//アナログパッドの入力をベクトルで吐く
	Vector2 analogVector();
};


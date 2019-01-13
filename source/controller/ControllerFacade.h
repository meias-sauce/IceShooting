#pragma once
#include "DxLib.h"
#include "ControllerChecker.h"
#include "../Vector2.h"

class ControllerFacade
{
private:
	int beforeKey_list[256];
	int beforePad_list[32];
	ControllerChecker* contollerChecker;

	static ControllerFacade* instance;
	ControllerFacade();

	//コピーコンストラクタを殺す
	ControllerFacade(const ControllerFacade &) = delete;
	ControllerFacade& operator=(const ControllerFacade &) = delete;
	ControllerFacade(ControllerFacade &&) = delete;
	ControllerFacade& operator=(ControllerFacade &&) = delete;

public:
	static ControllerFacade* GetInstance();
	~ControllerFacade();
	//更新処理
	void Update();
	//押してる間ずっとtrue
	bool KeyPress(int);
	//押した瞬間true
	bool KeyDown(int);
	//離した瞬間true
	bool KeyUp(int);

	bool PadPress(int);
	bool PadDown(int);
	bool PadUp(int);

	//アナログパッドの入力をベクトルで吐く
	Vector2 analogVector();
	//入力を正規化してから吐く（方向だけ必要な時用）
	Vector2 analogNormalizeVector();

	//ゲームパッド（1個目）を指定のミリ秒振動させる
	void PadVibration(int);
};


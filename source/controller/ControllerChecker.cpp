#include "ControllerChecker.h"
#include "DxLib.h"

void ControllerChecker::Update()
{
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			this->key_list[i]++;     // 加算
		}
		else {              // 押されていなければ
			this->key_list[i] = 0;   // 0にする
		}
	}

	if (GetJoypadNum() > 0) {
		const int padState = GetJoypadInputState(DX_INPUT_PAD1);

		const int padMask_list[] = {
			PAD_INPUT_DOWN,
			PAD_INPUT_LEFT,
			PAD_INPUT_RIGHT,
			PAD_INPUT_UP,
			PAD_INPUT_1,
			PAD_INPUT_2,
			PAD_INPUT_3,
			PAD_INPUT_4,
			PAD_INPUT_5,
			PAD_INPUT_6,
			PAD_INPUT_7,
			PAD_INPUT_8,
			PAD_INPUT_9,
			PAD_INPUT_10,
			PAD_INPUT_11,
			PAD_INPUT_12,
			PAD_INPUT_13,
			PAD_INPUT_14,
			PAD_INPUT_15,
			PAD_INPUT_16
		};


		for (int i = 0; i < PAD_ALL_NUM; i++) {
			if (padState & padMask_list[i]) {
				this->joypad_list[i]++;
			}
			else {
				this->joypad_list[i] = 0;
			}
		}

		GetJoypadAnalogInput(&(this->analogX), &(this->analogY), DX_INPUT_PAD1);
	}
}

ControllerChecker::ControllerChecker()
{
	for (auto key : this->key_list) {
		key = 0;
	}
	for (auto joypad : this->joypad_list) {
		joypad = 0;
	}
	this->analogX = 0;
	this->analogY = 0;
}


ControllerChecker::~ControllerChecker()
{
}

#pragma once

class KeyChecker
{
private:
public:
	int joypad_list[32];
	int analogX;
	int analogY;
	int key_list[256];
	void Update();
	KeyChecker();
	~KeyChecker();
};

enum PadState {
	PAD_DOWN,
	PAD_LEFT,
	PAD_RIGHT,
	PAD_UP,
	PAD_1,
	PAD_2,
	PAD_3,
	PAD_4,
	PAD_5,
	PAD_6,
	PAD_7,
	PAD_8,
	PAD_9,
	PAD_10,
	PAD_11,
	PAD_12,
	PAD_13,
	PAD_14,
	PAD_15,
	PAD_16,
	PAD_ALL_NUM
};


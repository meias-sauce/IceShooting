#include "ControllerFacade.h"

ControllerFacade* ControllerFacade::instance = nullptr;

ControllerFacade::ControllerFacade() {
	this->contollerChecker = new ControllerChecker();
	for (auto key : this->beforeKey_list) {
		key = 0;
	}
	for (auto pad : this->beforePad_list) {
		pad = 0;
	}
}


ControllerFacade * ControllerFacade::GetInstance()
{
	if (ControllerFacade::instance == nullptr) {
		ControllerFacade::instance = new ControllerFacade();
	}
	return ControllerFacade::instance;
}

ControllerFacade::~ControllerFacade()
{
	delete this->contollerChecker;
}

void ControllerFacade::Update() {
	//“ü—Íó‘Ô‚ğ•Û‘¶
	for (int i = 0; i < 256; i++) {
		this->beforeKey_list[i] = this->contollerChecker->key_list[i];
	}
	for (int i = 0; i < 32; i++) {
		this->beforePad_list[i] = this->contollerChecker->joypad_list[i];
	}
	//XV
	this->contollerChecker->Update();
}

bool ControllerFacade::KeyPress(int keyNum)
{
	bool result = false;
	if (this->contollerChecker->key_list[keyNum] > 0) {
		result = true;
	}
	return result;
}

bool ControllerFacade::KeyDown(int keyNum)
{
	bool result = false;
	if (this->contollerChecker->key_list[keyNum] == 1) {
		result = true;
	}
	return result;
}

bool ControllerFacade::KeyUp(int keyNum)
{
	bool result = false;
	if (this->beforeKey_list[keyNum] > 0 && this->contollerChecker->key_list[keyNum] == 0) {
		result = true;
	}
	return result;
}

bool ControllerFacade::PadConnect()
{
	bool result = false;
	if (GetJoypadNum() > 0) {
		result = true;
	}
	return result;
}

Vector2 ControllerFacade::AnalogVector()
{
	Vector2 result = { (float)this->contollerChecker->analogX, (float)this->contollerChecker->analogY };
	return result;
}

Vector2 ControllerFacade::AnalogNormalizeVector()
{
	auto result = this->AnalogVector();
	result.Normalize();
	return result;
}

void ControllerFacade::PadVibration(int milliSecond)
{
	StartJoypadVibration(DX_INPUT_PAD1, 1000, milliSecond);
}

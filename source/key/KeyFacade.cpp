#include "KeyFacade.h"

KeyFacade::KeyFacade() {
	this->keyChecker = new KeyChecker();
	for (auto key : this->beforeKey_list) {
		key = 0;
	}
}


KeyFacade::~KeyFacade()
{
	delete this->keyChecker;
}

void KeyFacade::Update() {
	//入力状態を保存
	for (int i = 0; i < 256; i++) {
		this->beforeKey_list[i] = keyChecker->key_list[i];
	}
	//更新
	this->keyChecker->Update();
}

Vector2 KeyFacade::analogVector()
{
	Vector2 result = { (float)this->keyChecker->analogX, (float)this->keyChecker->analogY };
	return result;
}

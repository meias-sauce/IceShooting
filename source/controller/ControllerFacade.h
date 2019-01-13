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

	//�R�s�[�R���X�g���N�^���E��
	ControllerFacade(const ControllerFacade &) = delete;
	ControllerFacade& operator=(const ControllerFacade &) = delete;
	ControllerFacade(ControllerFacade &&) = delete;
	ControllerFacade& operator=(ControllerFacade &&) = delete;

public:
	static ControllerFacade* GetInstance();
	~ControllerFacade();
	//�X�V����
	void Update();
	//�����Ă�Ԃ�����true
	bool KeyPress(int);
	//�������u��true
	bool KeyDown(int);
	//�������u��true
	bool KeyUp(int);

	bool PadPress(int);
	bool PadDown(int);
	bool PadUp(int);

	//�A�i���O�p�b�h�̓��͂��x�N�g���œf��
	Vector2 analogVector();
	//���͂𐳋K�����Ă���f���i���������K�v�Ȏ��p�j
	Vector2 analogNormalizeVector();

	//�Q�[���p�b�h�i1�ځj���w��̃~���b�U��������
	void PadVibration(int);
};


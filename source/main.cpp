#include "main.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//���O�t�@�C�����o���Ȃ��ݒ�
	SetOutApplicationLogValidFlag(FALSE);

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�ݒ�
	SetGraphMode(640, 480, 32);
	SetWindowSize(640, 480);

	//�o�b�N�O���E���h�ł����삷��ݒ�
	SetAlwaysRunFlag(true);

	//�A�[�J�C�u�t�@�C���̃p�X�ݒ�A�R�[�h���J���Ă�̂Ŏ��̓K�o�K�o
	SetDXArchiveKeyString("atuikoori");
	//�A�[�J�C�u�t�@�C���̊g���q�ݒ�
	SetDXArchiveExtension("sgp");

	//�A�C�R���t�@�C���̓ǂݍ���
	//SetWindowIconID(IDI_ICON2);

	//�E�B���h�E�^�C�g���̐ݒ�
	SetMainWindowText("�ō��ɃA�c���V���[�e�B���O�𗊂�");


	//DxLib������
	if (DxLib_Init() == -1)	{
		return -1;
	}

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 /*&& gpUpdateKey() == 0*/) {
		//printfDx������
		clsDx();
		printfDx("���쐳��");
	}

	DxLib_End();

	return 0;
}
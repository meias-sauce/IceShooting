#pragma once
#include "c:\Users\meias\Desktop\game\IceShooting\source\object\GameObject.h"

//�f�t�H����
#define THICKNESS_DEFAULT 12.0
//������{�P��
#define THICKNESS_ADD 4.5
//�v���O�����ň����l�̓��[�U�Ɍ����鐔�l�̉��{�H
#define THICKNESS_PROGRAM_RATE 2.0
//�摜�T�C�Y�A�擾���Ă��ǂ������邩�����̂Ŏ蓮��`
#define PLAYER_GRAPH_WIDTH 3840
#define PLAYER_GRAPH_HEIGHT 50
//�ō��ړ����x
#define PLAYER_SPEED_MAX 10

class Player :
	public GameObject
{
private:
	//�X�̌��݁A���[�U�ɂ��̂܂܌����Ă������l
	float thickness;

	float GetProgramThickness();

public:
	Player();
	~Player();

	void Update();
	void Draw();

	//�R���{���𓊂���Ə���Ɍ����Ȃ邼�A��������ꍇ�̓R���{�����}�C�i�X�œ���悤
	void AddThickness(int);

	Rect* GetCollider();
};


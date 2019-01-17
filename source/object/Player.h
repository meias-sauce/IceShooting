#pragma once
#include "GameObject.h"
#include "Bullet.h"

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

	//Bullet* bullet_list[2];


public:
	Player();
	~Player();

	void Update();
	void Draw();

	//�R���{���𓊂���Ə���Ɍ����Ȃ邼�A��������ꍇ�̓R���{�����}�C�i�X�œ���悤
	void AddThickness(int);

	void Shot(Bullet * bullet_list[]);

	//���[����ˌ����邼
	//void Shot();


	Rect* GetCollider();
};


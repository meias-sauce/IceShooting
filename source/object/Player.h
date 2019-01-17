#pragma once
#include "GameObject.h"
#include "Bullet.h"

//デフォ厚み
#define THICKNESS_DEFAULT 12.0
//増分基本単位
#define THICKNESS_ADD 4.5
//プログラムで扱う値はユーザに見える数値の何倍？
#define THICKNESS_PROGRAM_RATE 2.0
//画像サイズ、取得しても良いがだるかったので手動定義
#define PLAYER_GRAPH_WIDTH 3840
#define PLAYER_GRAPH_HEIGHT 50
//最高移動速度
#define PLAYER_SPEED_MAX 10

class Player :
	public GameObject
{
private:
	//氷の厚み、ユーザにそのまま見せていい数値
	float thickness;

	float GetProgramThickness();

	//Bullet* bullet_list[2];


public:
	Player();
	~Player();

	void Update();
	void Draw();

	//コンボ数を投げると勝手に厚くなるぞ、薄くする場合はコンボ数をマイナスで入れよう
	void AddThickness(int);

	void Shot(Bullet * bullet_list[]);

	//両端から射撃するぞ
	//void Shot();


	Rect* GetCollider();
};


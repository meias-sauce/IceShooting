#include "Player.h"
#include "../controller/ControllerFacade.h"
#include "../resource/Resource.h"
#include "../camera/Camera.h"
#include "Bullet.h"

float Player::GetProgramThickness()
{
	return this->thickness * THICKNESS_PROGRAM_RATE;
}

Player::Player()
{
	this->pos = { 320, 240 };

	this->graphic = Resource::Load("resource/player.png");
	this->thickness = THICKNESS_DEFAULT;

	const int tmpX = PLAYER_GRAPH_WIDTH / 2 - GetProgramThickness() / 2;
	this->graphic->Trim(tmpX, 0, this->GetProgramThickness(), PLAYER_GRAPH_HEIGHT);

	this->collider = new Rect(this->pos, Vector2(this->GetProgramThickness(), PLAYER_GRAPH_HEIGHT), this->angle);
}


Player::~Player()
{
}

void Player::Update()
{
	GameObject::Update();

	const auto controller = ControllerFacade::GetInstance();
	this->velo = controller->AnalogVector() * PLAYER_SPEED_MAX / 1000;

	if (controller->KeyPress(KEY_INPUT_Q)) {
		this->angle -= 0.05;
	}
	if (controller->KeyPress(KEY_INPUT_W)) {
		this->angle += 0.05;
	}

	const int tmpX = PLAYER_GRAPH_WIDTH / 2 - GetProgramThickness() / 2;
	this->graphic->Trim(tmpX, 0, GetProgramThickness(), PLAYER_GRAPH_HEIGHT);

	this->collider->SetParameter(this->pos, Vector2(this->GetProgramThickness(), PLAYER_GRAPH_HEIGHT), this->angle);
}

void Player::Draw()
{
	GameObject::Draw();



	printfDx("%f", this->thickness);
}

void Player::AddThickness(int combo)
{
	this->thickness += combo * THICKNESS_ADD;

	const auto camera = Camera::GetInstance();
	if (this->thickness > 100) {
		camera->SetExtendRate(100 / this->thickness);
	}
	else {
		//デバッグ用
		//this->thickness = 100;
	}
}

void Player::Shot(Bullet* bullet_list[]) {
	if (bullet_list[0] == nullptr && bullet_list[1] == nullptr) {
		Vector2 pos0;
		pos0.x = std::cos(this->angle);
		pos0.y = std::sin(this->angle);
		pos0 = pos0 * this->thickness;
		pos0.x += this->pos.x;
		pos0.y += this->pos.y;

		Vector2 pos1;
		pos1.x = std::cos(this->angle);
		pos1.y = std::sin(this->angle);
		pos1 = pos1 * (-this->thickness);
		pos1.x += this->pos.x;
		pos1.y += this->pos.y;

		Vector2 velo0;
		velo0.x = std::cos(this->angle);
		velo0.y = std::sin(this->angle);
		velo0 = velo0 * 10;

		Vector2 velo1;
		velo1.x = std::cos(this->angle);
		velo1.y = std::sin(this->angle);
		velo1 = velo1 * (-10);

		bullet_list[0] = new Bullet(pos0, velo0, this->angle);
		bullet_list[1] = new Bullet(pos1, velo1, this->angle + 3.141592);
	}
}

Rect* Player::GetCollider()
{
	return this->collider;
}

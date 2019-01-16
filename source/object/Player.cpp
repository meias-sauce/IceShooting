#include "Player.h"
#include "../controller/ControllerFacade.h"
#include "../resource/Resource.h"
#include "../camera/Camera.h"

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
		this->thickness = 100;
	}
}

Rect* Player::GetCollider()
{
	return this->collider;
}

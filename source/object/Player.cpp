#include "Player.h"
#include "../controller/ControllerFacade.h"
#include "../resource/Resource.h"

float Player::GetProgramThickness()
{
	return this->thickness * THICKNESS_PROGRAM_RATE;
}

Player::Player()
{
	this->graphic = Resource::Load("resource/player.png");
	this->thickness = THICKNESS_DEFAULT;

	const int tmpX = PLAYER_GRAPH_WIDTH / 2 - GetProgramThickness() / 2;
	this->graphic->Trim(tmpX, 0, GetProgramThickness(), PLAYER_GRAPH_HEIGHT);
}


Player::~Player()
{
}

void Player::Update()
{
	GameObject::Update();

	const auto controller = ControllerFacade::GetInstance();
	this->velo = controller->AnalogVector() * 0.01;
}

void Player::Draw()
{
	GameObject::Draw();
}

void Player::AddThickness(int combo)
{
	this->thickness += combo * THICKNESS_ADD;
}

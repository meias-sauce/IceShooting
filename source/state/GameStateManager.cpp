#include "GameStateManager.h"
#include "Title.h"
#include "Play.h"

GameStateManager* GameStateManager::instance = nullptr;

GameStateManager::GameStateManager()
{
	state = new Play();
}


GameStateManager * GameStateManager::GetInstance()
{
	if (GameStateManager::instance == nullptr) {
		GameStateManager::instance = new GameStateManager();
	}
	return GameStateManager::instance;
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::Update()
{
	this->state->Update();
}

void GameStateManager::Draw()
{
	this->state->Draw();
}

void GameStateManager::ChangeState(GameStateType toState)
{
	delete this->state;

	switch (toState) {
	case TITLE:
		this->state = new Title();
		break;
	case PLAY:
		this->state = new Play();
		break;
	case RESULT:
		//this->state = new Result();
		break;
	}
}



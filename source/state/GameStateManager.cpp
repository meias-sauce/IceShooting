#include "GameStateManager.h"

GameStateManager* GameStateManager::instance = nullptr;

GameStateManager::GameStateManager()
{
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

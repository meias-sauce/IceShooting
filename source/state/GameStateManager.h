#pragma once
#include "GameState.h"

enum GameStateType {
	TITLE,
	PLAY,
	RESULT
};

class GameStateManager final
{
private:
	GameStateManager();
	static GameStateManager* instance;

	//コピーコンストラクタを殺す
	GameStateManager(const GameStateManager &) = delete;
	GameStateManager& operator=(const GameStateManager &) = delete;
	GameStateManager(GameStateManager &&) = delete;
	GameStateManager& operator=(GameStateManager &&) = delete;

	//現在のGameState
	GameState* state;

public:
	static GameStateManager* GetInstance();
	~GameStateManager();

	void Update();
	void Draw();

	void ChangeState(GameStateType toState);
};


#pragma once
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

public:
	static GameStateManager* GetInstance();
	~GameStateManager();
};


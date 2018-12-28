#pragma once
class GameStateManager final
{
private:
	GameStateManager();
	static GameStateManager* instance;

	//�R�s�[�R���X�g���N�^���E��
	GameStateManager(const GameStateManager &) = delete;
	GameStateManager& operator=(const GameStateManager &) = delete;
	GameStateManager(GameStateManager &&) = delete;
	GameStateManager& operator=(GameStateManager &&) = delete;

public:
	static GameStateManager* GetInstance();
	~GameStateManager();
};


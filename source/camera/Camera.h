#pragma once
#include "../Vector2.h"

class Resource;

class Camera
{
private:
	Camera();
	static Camera* instance;
	const Vector2 windowSize = { 640, 480 };
	Vector2 center;
	float extendRate;


	//�R�s�[�R���X�g���N�^���E��
	Camera(const Camera &) = delete;
	Camera& operator=(const Camera &) = delete;
	Camera(Camera &&) = delete;
	Camera& operator=(Camera &&) = delete;

public:
	static Camera* GetInstance();
	~Camera();
	void Draw(float x, float y, float angle, int handle);
	void AddExtendRate(float value);
	void SetExtendRate(float value);
	float GetFrameLeft();
	float GetFrameRight();
	float GetFrameUp();
	float GetFrameDown();
};


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


	//コピーコンストラクタを殺す
	Camera(const Camera &) = delete;
	Camera& operator=(const Camera &) = delete;
	Camera(Camera &&) = delete;
	Camera& operator=(Camera &&) = delete;

public:
	static Camera* GetInstance();
	~Camera();
	void Draw(float x, float y, float angle, int handle);
};


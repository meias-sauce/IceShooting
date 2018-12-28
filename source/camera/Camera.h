#pragma once

class Resource;

class Camera
{
private:
	Camera();
	static Camera* instance;

	//�R�s�[�R���X�g���N�^���E��
	Camera(const Camera &) = delete;
	Camera& operator=(const Camera &) = delete;
	Camera(Camera &&) = delete;
	Camera& operator=(Camera &&) = delete;

public:
	static Camera* GetInstance();
	~Camera();
	void Draw(float x, float y, int handle);
};


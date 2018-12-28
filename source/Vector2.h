#pragma once
struct Vector2 {
	float x;
	float y;

	static float Distance(Vector2, Vector2);
	float Distance(Vector2);
	float Length();
	void Normalize();
	void Rotate(float); //原点中心でangle回転させる
	Vector2();
	Vector2(float, float);
};


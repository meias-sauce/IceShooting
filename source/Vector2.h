#pragma once
struct Vector2 {
	float x;
	float y;

	static float Distance(Vector2, Vector2);
	float Distance(Vector2);
	float Length();
	void Normalize();
	void Rotate(float); //���_���S��angle��]������
	Vector2();
	Vector2(float, float);
};


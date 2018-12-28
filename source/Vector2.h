#pragma once
struct Vector2 {
	float x;
	float y;

	static float Distance(Vector2, Vector2);
	float Distance(Vector2);
	float Length();
	void Normalize();
	void Rotate(float); //Œ´“_’†S‚Åangle‰ñ“]‚³‚¹‚é
	Vector2();
	Vector2(float, float);
};


#pragma once
#include "Vector2.h"
#include "Line.h"

class Rect
{
private:
	Vector2 center;
	Vector2 size;
	float angle;

	Line line_list[4];

public:
	void SetParameter(Vector2, Vector2, float);
	static bool isCollision(Rect, Rect);
	bool isCollision(Rect);

	Rect(Vector2, Vector2, float);
	~Rect();

	void Draw();
};


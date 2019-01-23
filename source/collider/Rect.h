#pragma once
#include "../Vector2.h"
#include "Line.h"

struct Rect
{
	Vector2 center;
	Vector2 size;
	float angle;
	Line line_list[4];

	void SetParameter(Vector2, Vector2, float);
	static bool IsCollision(Rect, Rect);
	bool IsCollision(Rect);

	Rect(Vector2, Vector2, float);
	~Rect();

	void Draw();
};


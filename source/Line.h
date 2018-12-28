#pragma once
#include "Vector2.h"

struct Line {
	Vector2 p;
	Vector2 q;

	float Length();
	static bool isCrossed(Line, Line);
	bool isCrossed(Line);

	Line();
	Line(Vector2, Vector2);
	~Line();
};


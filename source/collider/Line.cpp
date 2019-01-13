#include "Line.h"



float Line::Length()
{
	return this->p.Distance(this->q);
}

//ü•ª‚ÌŒğ·”»’è
bool Line::isCrossed(Line line1, Line line2) {
	auto ta = (line2.p.x - line2.q.x) * (line1.p.y - line2.p.y) + (line2.p.y - line2.q.y) * (line2.p.x - line1.p.x);
	auto tb = (line2.p.x - line2.q.x) * (line1.q.y - line2.p.y) + (line2.p.y - line2.q.y) * (line2.p.x - line1.q.x);
	auto tc = (line1.p.x - line1.q.x) * (line2.p.y - line1.p.y) + (line1.p.y - line1.q.y) * (line1.p.x - line2.p.x);
	auto td = (line1.p.x - line1.q.x) * (line2.q.y - line1.p.y) + (line1.p.y - line1.q.y) * (line1.p.x - line2.q.x);

	return tc * td <= 0 && ta * tb <= 0;
}

bool Line::isCrossed(Line line) {
	return Line::isCrossed(*this, line);
}

Line::Line() {
	this->p = Vector2(0, 0);
	this->q = Vector2(0, 0);
}

Line::Line(Vector2 p, Vector2 q)
{
	this->p = p;
	this->q = q;
}


Line::~Line()
{
}

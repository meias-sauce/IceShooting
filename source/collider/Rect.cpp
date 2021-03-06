#include <cmath>
#include "Rect.h"
#include "DxLib.h"

Rect::Rect(Vector2 center, Vector2 size, float angle) {
	this->SetParameter(center, size, angle);
}


void Rect::SetParameter(Vector2 center, Vector2 size, float angle) {
	this->center = center;
	this->size = size;
	this->angle = angle;

	//中心が0、かつangleが0であるときの座標算出
	Vector2 tmpVertex[4];
	tmpVertex[0] = Vector2(this->size.x / 2, this->size.y / 2);
	tmpVertex[1] = Vector2(this->size.x / 2, -this->size.y / 2);
	tmpVertex[2] = Vector2(-this->size.x / 2, -this->size.y / 2);
	tmpVertex[3] = Vector2(-this->size.x / 2, this->size.y / 2);

	//上で求めた座標を回転させ、centerを考慮して算出
	Vector2 vertex[4];
	for (int i = 0; i < 4; i++) {
		tmpVertex[i].Rotate(this->angle);
		vertex[i] = Vector2(this->center.x + tmpVertex[i].x, this->center.y + tmpVertex[i].y);
	}

	//各頂点を結んだlineを登録
	this->line_list[0] = Line(vertex[0], vertex[1]);
	this->line_list[1] = Line(vertex[1], vertex[2]);
	this->line_list[2] = Line(vertex[2], vertex[3]);
	this->line_list[3] = Line(vertex[3], vertex[0]);
}

bool Rect::IsCollision(Rect r1, Rect r2) {
	for (auto r1Line : r1.line_list) {
		for (auto r2Line : r2.line_list) {
			bool cross = Line::isCrossed(r1Line, r2Line);
			if (cross == true) {
				return true; //1回でもtrueなら打ち切り
			}
		}
	}
	return false; //ここに来たらfalse
}

bool Rect::IsCollision(Rect r) {
	return Rect::IsCollision(*this, r);
}

Rect::~Rect()
{
}

void Rect::Draw() {
	for (auto line : line_list) {
		DrawLine(line.p.x, line.p.y, line.q.x, line.q.y, GetColor(255, 0, 0));
	}
}

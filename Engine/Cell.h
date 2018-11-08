#pragma once
#include "Vec2.h"
#include "DrawableCell.h"
class Cell
{
public:

	Vec2 pos={0,0};
	int size=10;
	DrawableCell* GetDrawableCell();
	void MoveBy(Vec2 offset);
	void MoveTo(Vec2 newPos);

	Cell(Vec2 pos,int size);
	Cell();
	~Cell();
};


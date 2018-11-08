#pragma once
#include "Vec2.h"
#include "DrawableCell.h"
class Cell
{
public:

	Vec2 pos={0,0};
	int size=10;
	Vec2 dir = { 1,0 };
	float speed = 1;
	Color c = Colors::Cyan;
	float savedTime = 0;
	int ChargeCounter = 0;
	bool charging = false;
	
	DrawableCell* GetDrawableCell();
	void MoveBy(Vec2 offset);
	void MoveTo(Vec2 newPos);
	void ChangeColor(Color c);
	void Update(float dt);
	Cell(Vec2 pos,int size);
	Cell();
	~Cell();
};


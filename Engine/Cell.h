#pragma once
#include "Vec2.h"
#include "DrawableCell.h"
#include "Mouse.h"
#include <math.h>

class Cell
{
private:
	bool charging = false;
	int size = 10;
	int ChargeCounter = 0;
	float speed = 1;
	float savedTime = 0;

	Vec2 pos = { 0,0 };
	Vei2 dir = { 1,0 };
	Color c = Colors::Cyan;
	Color storedColor = Colors::Cyan;
public:
	Cell(Vec2 pos, int size);
	Cell();
	~Cell();

	void MoveBy(Vec2 offset);
	void MoveTo(Vec2 newPos);
	void SetColor(Color c);
	void SetStoredColor(Color c);
	void Update(float dt);
	void Update1(float dt);
	void Update2(Vec2 mousePos);
	void SetSpeed(float newSpeed);

	Vec2 GetPos();
	DrawableCell* GetDrawableCell();
	
};


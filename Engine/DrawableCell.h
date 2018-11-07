#pragma once
#include "Rect.h"
#include "Vec2.h"
#include "Graphics.h"
class DrawableCell
{

public:
	Rect<float>* rect;
	Vec2 translation = {0,0};
	float scaleX = 1;
	float scaleY = 1;
	DrawableCell(Vec2 _pos , int size);
	void Scale(float scale_in);
	void ScaleIndependent(float x, float y);
	void Translate(Vec2 pos);
	void Render(Graphics& gfx) 
	{
		rect->MoveBy(translation);
		rect->Scale(scaleX, scaleY);
		gfx.FillRect(*rect);
	}
	~DrawableCell();
};


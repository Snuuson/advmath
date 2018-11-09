#pragma once
#include "Rect.h"
#include "Vec2.h"
#include "Graphics.h"
class DrawableCell
{
private:
	float scaleX = 1;
	float scaleY = 1;
	Rect<float>* rect;
	Vec2 translation = { 0,0 };
	Color c = Colors::Cyan;

public:
	DrawableCell(Vec2 _pos , int size);
	DrawableCell(Vec2 _pos, int size,Color c);
	~DrawableCell();
	void Scale(float scale_in);
	void ScaleIndependent(float x, float y);
	void Translate(Vec2 pos);
	void ChangeColor(Color c);
	void Render(Graphics& gfx);
	
};


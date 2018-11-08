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
	Color c = Colors::Cyan;

	DrawableCell(Vec2 _pos , int size);
	DrawableCell(Vec2 _pos, int size,Color c);
	void Scale(float scale_in);
	void ScaleIndependent(float x, float y);
	void Translate(Vec2 pos);
	void ChangeColor(Color c);
	void Render(Graphics& gfx) 
	{
		rect->Scale(scaleX, scaleY);
		rect->MoveBy(translation);
		
		
		if (rect->IsOverlappingWith(gfx.GetScreenRect())) {
			gfx.FillRect(rect->GetExpanded(-1),c);
		}
		
	}
	~DrawableCell();
};


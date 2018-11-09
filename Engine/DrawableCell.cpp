#include "DrawableCell.h"



DrawableCell::DrawableCell(Vec2 _pos, int size)
	:
	rect(new Rect<float>(_pos*(float)size,(float)size,(float)size))
{
}

DrawableCell::DrawableCell(Vec2 _pos, int size, Color c)
	:
	rect(new Rect<float>(_pos*(float)size, (float)size, (float)size)),
	c(c)
{
}

void DrawableCell::Scale(float scale_in)
{
	scaleX *= scale_in;
	scaleY *= scale_in; 
	translation *= scale_in;
	
	
}

void DrawableCell::ScaleIndependent(float scale_x, float scale_y)
{
	scaleX *= scale_x;
	scaleY *= scale_y;
	translation.x *= scale_x;
	translation.y *= scale_y;
	
}

void DrawableCell::Translate(Vec2 pos)
{
	translation += pos;
	
}

void DrawableCell::ChangeColor(Color c)
{
	this->c = c;
}

void DrawableCell::Render(Graphics & gfx)
{
	rect->Scale(scaleX, scaleY);
	rect->MoveBy(translation);


	if (rect->IsOverlappingWith(gfx.GetScreenRect())) {
		gfx.FillRect(rect->GetExpanded(-1), c);
	}
}

DrawableCell::~DrawableCell()
{
	delete rect;
	rect = nullptr;
}

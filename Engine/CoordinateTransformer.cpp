#include "CoordinateTransformer.h"



CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
	:
	gfx(gfx)
{

	
}


void CoordinateTransformer::Do(DrawableCell * dc)
{
	dc->ScaleIndependent(1.0f, -1.0f);
	dc->Translate(Vec2(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2));
	dc->Render(gfx);
	delete dc;
	dc = nullptr;
}

void CoordinateTransformer::Do(std::vector<DrawableCell*> Drawables)
{
	for each (DrawableCell* dc in Drawables)
	{
		dc->ScaleIndependent(1.0f, -1.0f);
		dc->Translate(Vec2(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2));
		dc->Render(gfx);
		delete dc;
		dc = nullptr;
	}
	
}

CoordinateTransformer::~CoordinateTransformer()
{
}

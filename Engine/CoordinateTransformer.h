#pragma once
#include "DrawableCell.h"
#include "Graphics.h"
#include "Vec2.h"
#include <vector>
class CoordinateTransformer
{
public:

	Graphics& gfx;
	void Do(DrawableCell* dc);
	void Do(std::vector<DrawableCell*> Drawable);
	CoordinateTransformer( Graphics& gfx);
	~CoordinateTransformer();
};


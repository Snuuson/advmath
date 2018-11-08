#pragma once
#include "DrawableCell.h"
#include "Vec2.h"
#include <vector>
#include "CoordinateTransformer.h"
class Camera
{
public:
	Vec2 pos = {0,0};
	float scale = 1;
	CoordinateTransformer& ct;
	void MoveTo(Vec2 newPos);
	void MoveBy(Vec2 offset);
	void Scale(float _scale);
	Camera(CoordinateTransformer& ct);
	void Do(std::vector<DrawableCell*> allCells);
	~Camera();
};


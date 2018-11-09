#pragma once
#include "DrawableCell.h"
#include "Vec2.h"
#include <vector>
#include "CoordinateTransformer.h"
class Camera
{
private:
	float scale = 1;
	Vec2 pos = { 0,0 };
	CoordinateTransformer& ct;
public:
	Camera(CoordinateTransformer& ct);
	~Camera();
	void MoveTo(Vec2 newPos);
	void MoveBy(Vec2 offset);
	void Scale(float _scale);
	void SetPos(Vec2 newPos);
	Vec2 GetPos();
	void Do(std::vector<DrawableCell*> allCells);
	
	
};


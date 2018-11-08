#include "Camera.h"



void Camera::MoveTo(Vec2 newPos)
{
	pos = newPos;
}

void Camera::MoveBy(Vec2 offset)
{
	pos += offset;
}

void Camera::Scale(float _scale)
{
	
	pos *= _scale;
	scale *= _scale;
}

Camera::Camera(CoordinateTransformer& ct)
	:
	ct(ct)
{
}

void Camera::Do(std::vector<DrawableCell*> allCells)
{
	for each (DrawableCell* dc in allCells)
	{
		dc->Scale(scale);
		dc->Translate(pos);
		
	}
	ct.Do(allCells);
}


Camera::~Camera()
{
}

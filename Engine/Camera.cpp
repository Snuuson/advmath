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
	scale *= _scale;
	pos *= _scale;
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
		dc->Translate(pos);
		dc->Scale(scale);
	}
	ct.Do(allCells);
}


Camera::~Camera()
{
}

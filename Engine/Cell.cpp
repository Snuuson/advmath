#include "Cell.h"

Cell::Cell(Vec2 pos, int size)
	:
	pos(pos),
	size(size),
	storedColor(c)
{
}

Cell::Cell()
{
}

Cell::~Cell()
{
}

void Cell::MoveBy(Vec2 offset)
{
	pos += offset;
}

void Cell::MoveTo(Vec2 newPos)
{
	pos = newPos;
}

void Cell::SetColor(Color c)
{
	this->c = c;
	
}

void Cell::SetStoredColor(Color c)
{
	storedColor = c;
}

void Cell::Update(float dt)
{
	int min = -1;
	int max = 1;
	dir.x = rand() % (max - min + 1) + min;
	dir.y = rand() % (max - min + 1) + min;
	savedTime += dt;
	if (ChargeCounter == 50) {
		speed = 0.0625;
		charging = true;
		SetColor(storedColor);
	}
	if (ChargeCounter == 0) {
		speed = 0.8;
		charging = false;
		SetColor(Colors::Blue);
		
	}
	while (savedTime > speed) {
		
		Vec2 futurePosition = pos + Vec2((float)dir.x, (float)dir.y);
		
			pos += Vec2((float)dir.x, (float)dir.y);
		
		savedTime -= speed;
		
		charging ? ChargeCounter-- : ChargeCounter+=10;
	}
	
	
}

void Cell::Update1(float dt)
{
	int min = -1;
	int max = 1;
	dir.x = rand() % (max - min + 1) + min;;
	dir.y = rand() % (max - min + 1) + min;
	savedTime += dt;
	
	

		Vec2 futurePosition = pos + Vec2((float)dir.x, (float)dir.y);
		/*if (futurePosition.x > 0 && futurePosition.x < 49 && futurePosition.y > 0 && futurePosition.y < 49) {
			
		}*/
		pos += Vec2((float)dir.x,(float)dir.y);
		savedTime -= speed;

		if (speed > 0.1) {
			speed *= 0.95;
		}
		
}

void Cell::Update2(Vec2 mousePos)
{
	Vec2 tmp = Vec2(mousePos.x-tmp.x,mousePos.y -tmp.y);
	
	float result = std::atan(tmp.y / tmp.x);
	int i = 0;

}

void Cell::SetSpeed(float newSpeed)
{
	speed = newSpeed;
}

Vec2 Cell::GetPos()
{
	return pos;
}

DrawableCell* Cell::GetDrawableCell()
{
	return new DrawableCell(pos, size, c);
}




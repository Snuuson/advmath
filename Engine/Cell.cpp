#include "Cell.h"



DrawableCell* Cell::GetDrawableCell()
{
	return new DrawableCell(pos,size,c);
}

void Cell::MoveBy(Vec2 offset)
{
	pos += offset;
}

void Cell::MoveTo(Vec2 newPos)
{
	pos = newPos;
}

void Cell::ChangeColor(Color c)
{
	this->c = c;
}

void Cell::Update(float dt)
{
	int min = -1;
	int max = 1;
	dir.x = rand() % (max - min + 1) + min;;
	dir.y = rand() % (max - min + 1) + min;
	savedTime += dt;
	if (ChargeCounter == 50) {
		speed = 0.0625;
		charging = true;
	}
	if (ChargeCounter == 0) {
		speed = 0.8;
		charging = false;
	}
	while (savedTime > speed) {
		
		Vec2 futurePosition = pos + dir;
		if (futurePosition.x > 0  && futurePosition.x < 49 && futurePosition.y > 0 && futurePosition.y < 49) {
			pos += dir;
		}
		savedTime -= speed;
		
		charging ? ChargeCounter-- : ChargeCounter+=10;
	}
	
	
}

Cell::Cell(Vec2 pos, int size)
	:
	pos(pos),
	size(size)
{
}

Cell::Cell()
{
}


Cell::~Cell()
{
}

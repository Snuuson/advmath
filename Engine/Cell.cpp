#include "Cell.h"



DrawableCell* Cell::GetDrawableCell()
{
	return new DrawableCell(pos,size);
}

void Cell::MoveBy(Vec2 offset)
{
	pos += offset;
}

void Cell::MoveTo(Vec2 newPos)
{
	pos = newPos;
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

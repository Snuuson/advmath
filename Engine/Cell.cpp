#include "Cell.h"



DrawableCell Cell::GetDrawableCell()
{
	return DrawableCell(pos,size);
}

Cell::Cell()
{
}


Cell::~Cell()
{
}

#include "Walls.h"

Cell::Cell(int r, int c, bool a)
{
	if (r >= 0) row = r;
	if (c >= 0) col = c;
	access = a;
}
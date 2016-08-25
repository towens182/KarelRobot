#include "Cell.h"

Cell::Cell(int r, int c, bool a)
{
	if (r >= 0) y = r;
	if (c >= 0) x = c;
	access = a;
	hasBeeper = false;
}
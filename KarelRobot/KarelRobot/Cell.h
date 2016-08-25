#pragma once
#include "Item.h"
ref class Cell :Item
{
private:

	Cell(void) {};

public:
	Cell(int r, int c, bool a);

	bool getAccess() { return access; }
	int getRow() { return y; }
	int getCol() { return x; }

	void setAccess(bool a) { access = a; }
	void setBeeper(bool b) { b = true; }
};
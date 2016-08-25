#pragma once
#include "Item.h"
ref class Cell :Item
{
private:

	Cell(void) {};
	bool access;
	bool hasBeeper;

public:
	Cell(int r, int c, bool a);

	bool getAccess() { return access; }
	bool getBeeper() { return hasBeeper; }
	int getRow() { return y; }
	int getCol() { return x; }

	void setAccess(bool a) { access = a; }
	void setBeeper(bool beeper) { hasBeeper = true; }
};
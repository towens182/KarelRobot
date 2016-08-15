#pragma once
#include "Beeper.h"

ref class Cell
{
private:

	int row;
	int col;
	bool access;

	Cell(void) {};

public:
	Cell(int r, int c, bool a);

	bool getAccess() { return access; }
	int getRow() { return row; }
	int getCol() { return col; }

	void setAccess(bool a) { access = a; }
	void setBeeper(bool status) { status = true; }
};

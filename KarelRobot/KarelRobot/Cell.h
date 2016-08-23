#pragma once
#include "Robot.h"

ref class Cell
{
private:



	Cell(void) {};

public:
	Cell(int r, int c, bool a);

	bool getAccess() { return access; }
	int getRow() { return row; }
	int getCol() { return col; }

	void setAccess(bool a) { access = a; }
	void setBeeper(bool b) { b = true; }
};

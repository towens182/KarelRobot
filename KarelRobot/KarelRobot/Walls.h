#pragma once
ref class Cell
{
private:
	//Date Memebers;
	int row;
	int col;
	bool access;

	//Default Constructor
	Cell(void) {};

public:
	//Initializing Constructor
	Cell(int r, int c, bool a);

	//Accessors 
	bool getAccess() { return access; }
	int getRow() { return row; }
	int getCol() { return col; }

	//Mutators 
	void setAccess(bool a) { access = a; }
};
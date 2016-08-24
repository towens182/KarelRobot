#pragma once
//#include "Myform.h"
#include "Item.h"
ref class Robot:public Item
{
protected:

	//Class variables
	static System::Drawing::Icon^ robotRight;
	static System::Drawing::Icon^ robotLeft;
	static System::Drawing::Icon^ robotUp;
	static System::Drawing::Icon^ robotDown;
private:
	int row;
	int col;
	bool access = true;
	int numbeepers;
	
public:
	int offset = 30;
	int direction;
	//Initializing Constructor
	Robot();
	System::Drawing::Icon^ Robot::getIcon();
	void Robot::setIcon();

	//Utility methods
	void goRight() { row = (row + offset); direction = 0; }
	void goLeft() { row = (row - offset); direction = 1; }
	void goUp() { col = (col - offset); direction = 2; }
	void goDown() { col = (col + offset); direction = 3; }

	int getX() { return row; };
	int getY() { return col; };

	void setX(int x1) { row = x1; };
	void setY(int y1) { col = y1; };
	void setBeeps(int beepers) { numbeepers = beepers; };
	void setDirection(int dir) { direction = dir; };
};


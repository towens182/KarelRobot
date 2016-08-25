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
	
	
public:
	int offset = 30;
	int direction;
	int numbeepers;
	//Initializing Constructor
	Robot();
	System::Drawing::Icon^ Robot::getIcon();
	void Robot::setIcon();

	//Utility methods
	void goRight() { row++; direction = 0; }
	void goLeft() { row--; direction = 1; }
	void goUp() { col--; direction = 2; }
	void goDown() { col++; direction = 3; }

	int getX() { return row; };
	int getY() { return col; };

	void setX(int x1) { row = x1; };
	void setY(int y1) { col = y1; };
	void setBeeps(int beepers) { numbeepers = beepers; };
	void setDirection(int dir) { direction = dir; };
};


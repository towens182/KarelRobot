#pragma once
#include "Myform.h"
ref class Robot
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
	bool access;
	int numbeepers;
	Robot(void) {};
public:

	//Initializing Constructor
	Robot(int newRow, int newcol, int beepers);
	System::Drawing::Icon^ Robot::getIcon() override;
	void Robot::setIcon() override;

	//Utility methods
	void goRight() { row++; direction = 0; }
	void goLeft() { col--; direction = 1; }
	void goUp() { row--; direction = 2; }
	void goDown() { row++; direction = 3; }
};

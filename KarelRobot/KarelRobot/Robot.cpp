#pragma once
#include "Robot.h"
Robot::Robot(int newRow, int newCol, int beepers)
{
	row = newRow;
	col = newCol;
	numbeepers = beepers;
	setIcon();
}

void Robot::setIcon()
{
	robotRight = gcnew System::Drawing::Icon("Carol_right.bmp");
	robotLeft = gcnew System::Drawing::Icon("Carol_left.bmp");
	robotUp = gcnew System::Drawing::Icon("Carol_back.bmp");
	robotDown = gcnew System::Drawing::Icon("Carol_for.bmp");
	direction = 0;
}

System::Drawing::Icon^ Robot::getIcon()
{
	if (direction == 0)
		return robotRight;
	else if (direction == 1)
		return robotLeft;
	else if (direction == 2)
		return robotUp;
	else
		return robotDown;
}

#pragma once
#include "Robot.h"
Robot::Robot()
{
	setIcon();	
}

void Robot::setIcon()
{
	robotRight = gcnew System::Drawing::Icon("Carol_right.ico");
	robotLeft = gcnew System::Drawing::Icon("Carol_left.ico");
	robotUp = gcnew System::Drawing::Icon("Carol_back.ico");
	robotDown = gcnew System::Drawing::Icon("Carol_for.ico");
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

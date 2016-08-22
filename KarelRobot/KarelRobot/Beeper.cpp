#include "Beeper.h"
Beeper::Beeper(int newX, int newY, int newNum_beepers)
{
	setX(newX);
	setY(newY);
	this->num_beepers = newNum_beepers;
}

System::Drawing::Icon^ Beeper::getIcon()
{
	return beeperIcon;
}
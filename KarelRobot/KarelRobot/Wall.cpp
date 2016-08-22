#include "Wall.h"
Wall::Wall(int X2, int Y2, int newNum_wall)
{
	setX(X2);
	setY(Y2);
	this->num_wall = newNum_wall;
}

System::Drawing::Icon^ Wall::getIcon()
{
	return wallIcon;
}
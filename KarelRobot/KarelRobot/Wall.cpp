#include "Wall.h"
Wall::Wall(int X2, int Y2)
{
	setX(X2);
	setY(Y2);
}

System::Drawing::Icon^ Wall::getIcon()
{
	return wallIcon;
}
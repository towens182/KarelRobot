#include "Wall.h"
#include "Item.h"

Wall::Wall()
{
	setIcon(gcnew System::Drawing::Icon("wall.ico"));
}
void Wall::setIcon(System::Drawing::Icon^ icon)
{
	wallIcon = icon;
}

System::Drawing::Icon^ Wall::getIcon()
{
	return wallIcon;
}
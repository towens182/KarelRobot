#include "Wall.h"
Wall::wall(bool visible)
{
	visible = 1;
	if (visible == 1)
	{
		// Karel turns away
	}
	else
	{
		visible == 0;
	}
}

System::Drawing::Icon^ Wall::getIcon()
{
	return wallIcon;
}
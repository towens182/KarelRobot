#pragma once

#include "Item.h"

ref class Wall :public Item
{ 
private:
	int direction;
	bool wall;

	static System::Drawing::Icon^ wallIcon = gcnew System::Drawing::Icon("wall.bmp");
public:
	wall(bool visible);
	System::Drawing::Icon^ Wall::getIcon();
};

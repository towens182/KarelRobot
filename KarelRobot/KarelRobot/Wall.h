#pragma once
#include "Item.h"
ref class Wall : public Item
{ 
private:
	int direction;

	static System::Drawing::Icon^ wallIcon = gcnew System::Drawing::Icon("wall.bmp");
public:
};

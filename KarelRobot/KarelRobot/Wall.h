#pragma once
#include "Item.h"

ref class Wall : public Item
{
private:
	bool access = false;
	static System::Drawing::Icon^ wallIcon;
	

public:
	Wall();
	void setIcon(System::Drawing::Icon^ icon);
	System::Drawing::Icon^ Wall::getIcon();
};
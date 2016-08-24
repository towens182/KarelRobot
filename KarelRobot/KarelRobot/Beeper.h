#pragma once
#include "Item.h"

ref class Beeper :public Item
{

private:
	
	int num_beepers;
	bool status = true;
	static System::Drawing::Icon^ beeperIcon;

public:
	//Initializing constructor
	Beeper();
	void setIcon(System::Drawing::Icon^ icon);
	void setNumBeepers(int z) { num_beepers = z; };
	void pickupBeeper();

	System::Drawing::Icon^ Beeper::getIcon();
	
};
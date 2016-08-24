#pragma once
#include "Item.h"
ref class Beeper :public Item
{

private:
	
	int num_beepers;
	bool status = true;
	
	static System::Drawing::Icon^ beeperIcon;
private:


public:
	//Initializing constructor
	Beeper();
	void setIcon(System::Drawing::Icon^ icon);
	void setNumBeepers(int z) { num_beepers = z; };
	void pickupBeeper();

	System::Drawing::Icon^ Beeper::getIcon();
	//array<Int32>^  singleDArray = gcnew array<Int32>(ARRAY_SIZE)

	//create beeper array read from text file beeper 3, 3, 1   row, col, num_beeper
};
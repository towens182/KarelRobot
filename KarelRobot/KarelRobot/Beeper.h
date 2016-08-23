#pragma once
#include "Item.h"
ref class Beeper :public Item
{

private:
	
	int num_beepers;
	bool status = true;
	
	static System::Drawing::Icon^ beeperIcon = gcnew System::Drawing::Icon("beeper.bmp");
private:	

	
public:
	//Initializing constructor
	Beeper();


	System::Drawing::Icon^ Beeper::getIcon();
	//array<Int32>^  singleDArray = gcnew array<Int32>(ARRAY_SIZE)

	//create beeper array read from text file beeper 3, 3, 1   row, col, num_beeper
};

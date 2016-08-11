#pragma once
#include "Item.h"
ref class Beeper :public Item
{

private:
	
	int num_beepers;
	bool status = true;
	
	static System::Drawing::Icon^ beeperIcon = gcnew System::Drawing::Icon("beeper.bmp");
private:	
	Beeper() {};
	
public:
	//Initializing constructor
	Beeper(int x, int y, int num_beepers);


	System::Drawing::Icon^ Beeper::getIcon();
	//array<Int32>^  singleDArray = gcnew array<Int32>(ARRAY_SIZE)

	//create beeper array read from text file beeper 3, 3, 1   row, col, num_beeper
};

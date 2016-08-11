#pragma once
ref class Beeper
{
private:
	
	int row;
	int col;
	int num_beepers;
	bool beeper_visible;

	static System::Drawing::Icon^ beeperIcon = gcnew System::Drawing::Icon("beeper.bmp");
public:
	//Initializing constructor
	Beeper(int row, int col, int num_beepers);

	//array<Int32>^  singleDArray = gcnew array<Int32>(ARRAY_SIZE)

	//create beeper array read from text file beeper 3, 3, 1   row, col, num_beeper
};

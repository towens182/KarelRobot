#pragma once
ref class Beepers
{
private:
	int num_beepers;

	static System::Drawing::Icon^ beeperIcon = gcnew System::Drawing::Icon("beeper.bmp");
public:
	//Initializing constructor
	Beepers(int row, int col, int num_beepers);

	
	//create beeper array read from text file beeper 3, 3, 1   row, col, num_beeper
};

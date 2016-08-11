#include "Beeper.h"
Beeper::Beeper(int x, int y, int num_beepers)
{
	x = 0;
	y = 0;
	
}

System::Drawing::Icon^ Beeper::getIcon()
{
	return beeperIcon;
}
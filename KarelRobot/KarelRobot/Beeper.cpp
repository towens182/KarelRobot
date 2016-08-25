#include "Beeper.h"
#include "Item.h"


Beeper::Beeper()
{
	setIcon(gcnew System::Drawing::Icon("beeper.ico"));
}
void Beeper::setIcon(System::Drawing::Icon^ icon)
{
	beeperIcon = icon;
}
void Beeper::pickupBeeper()
{
	this->status = false;
	this->num_beepers = 0;
}
System::Drawing::Icon^ Beeper::getIcon()
{
	return beeperIcon;
}
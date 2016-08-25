#pragma once


ref class Item
{
private:
	int icon;
public:
	int x;
	int y;
	bool access;

public:
	//Accessors
	int getX() { return x; };
	int getY() { return y; };
	//Mutators
	void setX(int x1) { x = x1; };
	void setY(int y1) { y = y1; };
};

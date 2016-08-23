#pragma once

ref class Item
{
private:
	int x;
	int y;
	int icon;

public:
	int getX() { return x; };
	int getY() { return y; };
	void setX(int x1);
	void setY(int y1) { y = y1; };
};

#pragma once

ref class Item
{
private:
	int x = 0;
	int y = 0;
	int icon;

public:
	int getX() { return x };
	int getY() { return y };
	void setX(int x) { this.x = x };
	void setY(int y) { this.y = y };
	void setIcon();

};

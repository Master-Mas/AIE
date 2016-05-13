#pragma once
#include <iostream>

class Position
{
public:
	Position();
	Position(float x, float y);
	~Position();

	float GetX();
	float GetY();

	bool operator == (Position & other);
	Position operator + (Position & other);
	Position operator - (Position & other);
	void operator += (Position & other);
	void operator -= (Position & other);

	friend std::ostream& operator << (std::ostream &os, Position m);
private:
	float x;
	float y;
};


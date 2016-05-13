#include "Position.h"

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

Position::Position(float x, float y)
{
	this->x = x;
	this->y = y;
}


Position::~Position()
{
}

float Position::GetX()
{
	return this->x;
}

float Position::GetY()
{
	return this->y;
}

bool Position::operator==(Position & other)
{
	return this->x == other.GetX() && this->y == other.GetY();
}

Position Position::operator+(Position & other)
{
	return Position(this->x + other.GetX(), this->y + other.GetY());
}

Position Position::operator-(Position & other)
{
	return Position(this->x - other.GetX(), this->y - other.GetY());
}

void Position::operator+=(Position & other)
{
	Position pos = *this + other;
	this->x = pos.GetX();
	this->y = pos.GetY();
}

void Position::operator-=(Position & other)
{
	Position pos = *this - other;
	this->x = pos.GetX();
	this->y = pos.GetY();
}

std::ostream& operator<<(std::ostream & os, Position m) {
	os << "X: " << m.GetX() << ", Y: " << m.GetY();
	return os;
}
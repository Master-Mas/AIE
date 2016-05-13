#include "Vector2.h"



Vector2::Vector2()
{
	SetX(0);
	SetY(0);
}

Vector2::Vector2(float x, float y)
{
	SetX(x);
	SetY(y);
}


Vector2::~Vector2()
{
}

float Vector2::GetX()
{
	return m_x;
}

float Vector2::GetY()
{
	return m_y;
}

void Vector2::SetX(float x)
{
	m_x = x;
}

void Vector2::SetY(float y)
{
	m_y = y;
}

void Vector2::AddToX(float x)
{
	m_x += x;
}

void Vector2::AddToY(float y)
{
	m_y += y;
}

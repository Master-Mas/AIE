#include "Vector2.h"

const Vector2 Vector2::ZERO = Vector2();

Vector2::Vector2()
{
}

Vector2::Vector2(const float otherX, const float otherY)
{
	x = otherX;
	y = otherY;
}

Vector2::~Vector2()
{
}

const float Vector2::getX()
{
	return x;
}

const float Vector2::getY()
{
	return y;
}

const void Vector2::setX(const float otherX)
{
	x = otherX;
}

const void Vector2::setY(const float otherY)
{
	y = otherY;
}

float Vector2::dot(const Vector2 & otherVec) const
{
	return x * otherVec.x + y * otherVec.y;
}

float Vector2::magnitude() const
{
	return sqrtf((x * x) + (y * y));
}

void Vector2::normalise()
{
	float magnitude = this->magnitude();

	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
	}
}

bool Vector2::intersects(Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2)
{
	Vector2 min1 = Vector2(pos1.x, pos2.y);
	Vector2 min2 = Vector2(pos2.x, pos2.y);

	Vector2 max1 = Vector2(pos1.x + size1.x, pos1.y + size1.y);
	Vector2 max2 = Vector2(pos2.x + size2.x, pos2.y + size2.y);

	return max1.x >= min2.x && max2.x >= min1.x && max1.y >= min2.y && max2.y >= min1.y;
}

Vector2 Vector2::operator+(Vector2 otherVec) const
{
	return Vector2(x + otherVec.x, y + otherVec.y);
}

Vector2 Vector2::operator-(Vector2 otherVec) const
{
	return Vector2(x - otherVec.x, y - otherVec.y);
}

Vector2 Vector2::operator*(float number)
{
	return Vector2(x * number, y * number);
}

Vector2 operator*(float number, const Vector2 & otherVec)
{
	return Vector2(otherVec.x * number, otherVec.y * number);
}

Vector2::operator float*()
{
	float data[2] = { x, y };
	return data;
}

bool Vector2::operator!=(const Vector2 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y)
	{
		return false;
	}
	return true;
}

bool Vector2::operator==(const Vector2 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y)
	{
		return true;
	}
	return false;
}

std::string Vector2::toString() const
{
	std::ostringstream oss;
	oss << "(" << x << ", " << y << ")";

	return oss.str();
}

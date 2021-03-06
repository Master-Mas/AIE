#include "Vector4.h"

const Vector4 Vector4::ZERO = Vector4();

Vector4::Vector4()
{
}

Vector4::Vector4(const float otherX, const float otherY, const float otherZ, const float otherA)
{
	x = otherX;
	y = otherY;
	z = otherZ;
	a = otherA;
}


Vector4::~Vector4()
{
}

const float Vector4::getX()
{
	return x;
}

const float Vector4::getY()
{
	return y;
}

const float Vector4::getZ()
{
	return z;
}
const float Vector4::getA()
{
	return z;
}

const void Vector4::setX(const float otherX)
{
	x = otherX;
}

const void Vector4::setY(const float otherY)
{
	y = otherY;
}

const void Vector4::setZ(const float otherZ)
{
	z = otherZ;
}

const void Vector4::setA(const float otherA)
{
	a = otherA;
}

Vector4 Vector4::cross(const Vector4 & otherVec) const
{
	return Vector4(
		y * otherVec.z - z * otherVec.y,
		z * otherVec.x - x * otherVec.z,
		x * otherVec.y - y * otherVec.x,
		0);
}

float Vector4::dot(const Vector4 & otherVec) const
{
	return (x * otherVec.x) + (y * otherVec.y) + (z * otherVec.z) + (a * otherVec.a);
}

float Vector4::magnitude() const
{
	return sqrtf((x * x) + (y * y) + (z * z) + (a * a));
}

void Vector4::normalise()
{
	float magnitude = this->magnitude();

	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		a /= magnitude;
	}
}

Vector4 Vector4::operator+(Vector4 otherVec) const
{
	return Vector4(x + otherVec.x, y + otherVec.y, z + otherVec.z, a + otherVec.a);
}

Vector4 Vector4::operator-(Vector4 otherVec) const
{
	return Vector4(x - otherVec.x, y - otherVec.y, z - otherVec.z, a - otherVec.a);
}

Vector4 Vector4::operator*(float number)
{
	return Vector4(x * number, y * number, z * number, a * number);
}

Vector4 operator*(float number, const Vector4 & otherVec)
{
	return Vector4(otherVec.x * number, otherVec.y * number, otherVec.z * number, otherVec.a * number);
}

Vector4::operator float*()
{
	float data[4] = { x, y, z, a };
	return data;
}

bool Vector4::operator!=(const Vector4 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y &&
		z == otherVec.z &&
		a == otherVec.a)
	{
		return false;
	}
	return true;
}

bool Vector4::operator==(const Vector4 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y &&
		z == otherVec.z &&
		a == otherVec.a)
	{
		return true;
	}
	return false;
}

std::string Vector4::toString() const
{
	std::ostringstream oss;
	oss << "(" << x << ", " << y << ", " << z << ", " << a << ")";

	return oss.str();
}

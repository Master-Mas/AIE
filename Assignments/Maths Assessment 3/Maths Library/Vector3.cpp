#include "Vector3.h"

const Vector3 Vector3::ZERO = Vector3();
const Vector3 Vector3::FORWARD = Vector3(0, 0, 1);
const Vector3 Vector3::BACK = Vector3(0, 0, -1);
const Vector3 Vector3::LEFT = Vector3(-1, 0, 0);
const Vector3 Vector3::RIGHT = Vector3(1, 0, 0);
const Vector3 Vector3::TOP = Vector3(0, 1, 0);
const Vector3 Vector3::BOTTOM = Vector3(0, -1, 0);
const Vector3 Vector3::ONE = Vector3(1, 1, 1);

Vector3::Vector3()
{
}

Vector3::Vector3(const float otherX, const float otherY, const float otherZ)
{
	x = otherX;
	y = otherY;
	z = otherZ;
}


Vector3::~Vector3()
{
}

const float Vector3::getX()
{
	return x;
}

const float Vector3::getY()
{
	return y;
}

const float Vector3::getZ()
{
	return z;
}

const void Vector3::setX(const float otherX)
{
	x = otherX;
}

const void Vector3::setY(const float otherY)
{
	y = otherY;
}

const void Vector3::setZ(const float otherZ)
{
	z = otherZ;
}

Vector3 Vector3::cross(const Vector3 & otherVec) const
{
	return Vector3(
		y * otherVec.z - z * otherVec.y,
		z * otherVec.x - x * otherVec.z,
		x * otherVec.y - y * otherVec.x);
}

float Vector3::dot(const Vector3 & otherVec) const
{
	return (x * otherVec.x) + (y * otherVec.y) + (z * otherVec.z);
}

float Vector3::magnitude() const
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector3::normalise()
{
	float magnitude = this->magnitude();

	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}
}

bool Vector3::intersects(Vector3 pos1, Vector3 size1, Vector3 pos2, Vector3 size2) const
{
	return false;
}

Vector3 Vector3::operator+(Vector3 otherVec) const
{
	return Vector3(x + otherVec.x, y + otherVec.y, z + otherVec.z);
}

Vector3 Vector3::operator-(Vector3 otherVec) const
{
	return Vector3(x - otherVec.x, y - otherVec.y, z - otherVec.z);
}

Vector3 Vector3::operator*(float number)
{
	return Vector3(x * number, y * number, z * number);
}

Vector3 operator*(float number, const Vector3 & otherVec)
{
	return Vector3(otherVec.x * number, otherVec.y * number, otherVec.z * number);
}

Vector3::operator float*()
{
	float data[3] = { x, y, z };
	return data;
}

bool Vector3::operator!=(const Vector3 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y &&
		z == otherVec.z)
	{
		return false;
	}
	return true;
}

bool Vector3::operator==(const Vector3 otherVec) const
{
	if (x == otherVec.x &&
		y == otherVec.y &&
		z == otherVec.z)
	{
		return true;
	}
	return false;
}

const std::string Vector3::toString() const
{
	std::ostringstream oss;
	oss << "(" << x << ", " << y << ", " << z << ")";

	return oss.str();
}

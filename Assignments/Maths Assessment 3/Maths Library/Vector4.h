////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-04-15
// Brief:			A Maths Vector2 Class
////////////////////////////////////////////////////////////

#pragma once
#include <math.h>
#include <string>
#include <sstream>

class Vector4
{
public:
	static const Vector4 ZERO;

	float x = 0;
	float y = 0;
	float z = 0;
	float a = 0;

	Vector4();
	Vector4(const float otherX, const float otherY, const float otherZ, const float otherA);
	~Vector4();

	const float getX();
	const float getY();
	const float getZ();
	const float getA();

	const void setX(const float otherX);
	const void setY(const float otherY);
	const void setZ(const float otherZ);
	const void setA(const float otherA);

	Vector4 cross(const Vector4 & otherVec) const;
	float dot(const Vector4 & otherVec) const;
	float magnitude() const;
	void normalise();

	Vector4 operator+ (const Vector4 otherVec) const;
	Vector4 operator- (const Vector4 otherVec) const;
	Vector4 operator* (float number);
	friend Vector4 operator* (float number, const Vector4 & otherVec);
	operator float*();
	bool operator!= (const Vector4 otherVec) const;
	bool operator== (const Vector4 otherVec) const;

	std::string toString() const;
};


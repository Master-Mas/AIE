////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-04-15
// Brief:			A Maths Vector2 Class
////////////////////////////////////////////////////////////

#include <math.h>
#include <string>
#include <sstream>
#include "Matrix4.h"

class Vector4
{
public:
	static const Vector4 ZERO;

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
	Vector4& operator* (Matrix4 & otherMatrix);
	friend Vector4& operator* (Matrix4 & otherMatrix, const Vector4 & otherVector);
	operator float*();
	bool operator!= (const Vector4 otherVec) const;
	bool operator== (const Vector4 otherVec) const;

	std::string toString() const;
private:
	float x = 0;
	float y = 0;
	float z = 0;
	float a = 0;
};


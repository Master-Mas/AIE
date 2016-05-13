////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-04-15
// Brief:			A Maths Vector2 Class
////////////////////////////////////////////////////////////

#include <math.h>
#include <string>
#include <sstream>
#include "Matrix3.h"

class Vector3
{
public:
	static const Vector3 ZERO;
	static const Vector3 FORWARD;
	static const Vector3 BACK;
	static const Vector3 LEFT;
	static const Vector3 RIGHT;
	static const Vector3 TOP;
	static const Vector3 BOTTOM;
	static const Vector3 ONE;

	Vector3();
	Vector3(const float otherX, const float otherY, const float otherZ);
	~Vector3();

	const float getX();
	const float getY();
	const float getZ();

	const void setX(const float otherX);
	const void setY(const float otherY);
	const void setZ(const float otherZ);

	Vector3 cross(const Vector3 & otherVec) const;
	float dot(const Vector3 & otherVec) const;
	float magnitude() const;
	void normalise();

	Vector3 operator+ (const Vector3 otherVec) const;
	Vector3 operator- (const Vector3 otherVec) const;
	Vector3 operator* (float number);
	friend Vector3 operator* (float number, const Vector3 & otherVec);
	Vector3& operator* (Matrix3 & otherMatrix);
	friend Vector3& operator* (Matrix3 & otherMatrix, const Vector3 & otherVector);
	operator float*();
	bool operator!= (const Vector3 otherVec) const;
	bool operator== (const Vector3 otherVec) const;

	const std::string toString() const;
private:
	float x = 0;
	float y = 0;
	float z = 0;
};

////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-06-10
// Brief:			A Maths Vector2 Class
////////////////////////////////////////////////////////////

#pragma once
#include <math.h>
#include <string>
#include <sstream>

class Vector3
{
public:
	/**
	* Vectors3's that have predenfined values for game use
	*/
	static const Vector3 ZERO;
	static const Vector3 FORWARD;
	static const Vector3 BACK;
	static const Vector3 LEFT;
	static const Vector3 RIGHT;
	static const Vector3 TOP;
	static const Vector3 BOTTOM;
	static const Vector3 ONE;

	/**
	* Variables that store the values of the Vector
	*/
	float x = 0;
	float y = 0;
	float z = 0;

	/**
	* Default Constructor
	*/
	Vector3();

	/**
	* Constructor
	* Argument Constructor to set the X and Y of the Vector2
	* @param otherX The X Coord that you would like to set
	* @param otherY The Y Coord that you would like to set
	* @param otherZ The Z Coord that you would like to set
	*/
	Vector3(const float otherX, const float otherY, const float otherZ);

	/**
	* Destructor
	*/
	~Vector3();

	/**
	* Get the X of Vector3. Returns as const so no modification can happen
	* @return const:float X coord of the Vector3
	*/
	const float getX();

	/**
	* Get the Y of Vector3. Returns as const so no modification can happen
	* @return const:float Y coord of the Vector3
	*/
	const float getY();

	/**
	* Get the Z of Vector3. Returns as const so no modification can happen
	* @return const:float Z coord of the Vector3
	*/
	const float getZ();

	/**
	* Sets the X coord of the Vector3
	* @param otherX The value to which you want to set the X coord to
	*/
	const void setX(const float otherX);

	/**
	* Sets the Y coord of the Vector3
	* @param otherY The value to which you want to set the Y coord to
	*/
	const void setY(const float otherY);

	/**
	* Sets the Y coord of the Vector3
	* @param otherY The value to which you want to set the Y coord to
	*/
	const void setZ(const float otherZ);

	Vector3 cross(const Vector3 & otherVec) const;
	float dot(const Vector3 & otherVec) const;

	/**
	* Gets the Magnitude of the Vector
	* sqrt(x^2 + y^2). This is based off pythagorean theorem a^2 + b^2 = c^2
	* |\
	* | \
	* |  \ <-- This line (hypotenuse) is the magnitude of the Vector
	* |   \
	* |____\
	*
	* @return float The magnitude of the Vector
	*/
	float magnitude() const;
	void normalise();
	bool intersects(Vector3 pos1, Vector3 size1, Vector3 pos2, Vector3 size2);
	Vector3 intersectsLocation(Vector3 pos1, Vector3 size1, Vector3 pos2, Vector3 size2);

	Vector3 operator+ (const Vector3 otherVec) const;
	Vector3 operator- (const Vector3 otherVec) const;
	Vector3 operator* (float number);
	friend Vector3 operator* (float number, const Vector3 & otherVec);
	operator float*();
	bool operator!= (const Vector3 otherVec) const;
	bool operator== (const Vector3 otherVec) const;

	const std::string toString() const;
};

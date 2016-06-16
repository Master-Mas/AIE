////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-06-16
// Brief:			A Maths Vector3 Class
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
	* Argument Constructor to set the X and Y of the Vector3
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

	/**
	* Gets the cross product of a Vector3.
	*
	* @return float
	*/
	Vector3 cross(const Vector3 & otherVec) const;

	/**
	* Gets the dot product of a Vector3.
	*
	* @return float
	*/
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

	/**
	* Normalises Vector3. This allows for the vector to retain the direction from origin,
	* but no longer is the correct length. This is from the unit circle.
	* By using Axis / magnitude of the Vector3 we can change it so the Vector is inside the unit
	* circle. This can then be used for velocity of a Vector3.
	*/
	void normalise();

	/**
	* Checks to see if 2 Rectangles are within the bounds of each other.
	* abs(x1-x2) < w1 + w2 && abs(y1-y2) < h1 + h2
	*
	*  ___________
	* |H  Width1  |
	* |E       ___|_______
	* |I      |H  Width2  |
	* |G      |E  |       |
	* |H      |I  |       |
	* |T      |G  |       |
	* |1      |H  |       |
	* |_______|T__|       |
	*         |2          |
	*         |___________|
	*
	* @param pos1 The Top Left position of the First Rectangle
	* @param size1 The Width and Height of the First Rectangle
	* @param pos2 The Top Left position of the Second Rectangle
	* @param size2 The Width and Height of the Second Rectangle
	* @return bool if the 2 rectangles are intersecting
	*/
	bool intersects(Vector3 pos1, Vector3 size1, Vector3 pos2, Vector3 size2) const;

	/**
	* Allows to plus two Vector3's together.
	* This is not a function that you call, but operator overloads the + symbol so you can
	* express a plus operation like Vector3 + Vector3. This returns a new Vector3 as it is only
	* a + and not a +=
	*
	* @return Vector3 The sum of the two Vector3's
	*/
	Vector3 operator+ (const Vector3 otherVec) const;

	/**
	* Allows to subract two Vector3's.
	* This is not a function that you call, but operator overloads the - symbol so you can
	* express a subtraction operation like Vector3 - Vector3. This returns a new Vector3 as it
	* is only a - and not a -=
	*
	* @return Vector3 The difference of the two Vector3's
	*/
	Vector3 operator- (const Vector3 otherVec) const;

	/**
	* Allows to multiply a Vector3 and a float.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like Vector3 * float. This returns a new Vector3
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* Vector3 * float
	* for this function to work
	*
	* @return Vector3 The product of the Vector3 and the float
	*/
	Vector3 operator* (float number);

	/**
	* Allows to multiply a Vector3 and a float.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like float * Vector3. This returns a new Vector3
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* float * Vector3
	* for this function to work
	*
	* @return Vector3 The product of the Vector3 and the float
	*/
	friend Vector3 operator* (float number, const Vector3 & otherVec);

	/**
	* Allows you to cast the Vector3 and get all the axis of the Vector in a float[]
	* @return float* Returns the starting element of an array of all the axis
	*/
	operator float*();

	/**
	* Test to see if two Vector3's are not equal to each other
	* @return bool Tests to see if the two Vector3's are not equal to each other
	*/
	bool operator!= (const Vector3 otherVec) const;

	/**
	* Test to see if two Vector3's are equal to each other
	* @return bool Tests to see if the two Vector3's are equal to each other
	*/
	bool operator== (const Vector3 otherVec) const;

	/**
	* Gets the String respresentation of the Vector3. This is in the form of (X, Y, Z)
	* @return string The string respresentation of the Vector3
	*/
	const std::string toString() const;
};

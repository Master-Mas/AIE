////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-06-16
// Brief:			A Maths Vector4 Class
////////////////////////////////////////////////////////////

#pragma once
#include <math.h>
#include <string>
#include <sstream>

class Vector4
{
public:
	/**
	* Vectors3's that have predenfined values for game use
	*/
	static const Vector4 ZERO;

	/**
	* Variables that store the values of the Vector
	*/
	float x = 0;
	float y = 0;
	float z = 0;
	float a = 0;

	/**
	* Default Constructor
	*/
	Vector4();

	/**
	* Constructor
	* Argument Constructor to set the X and Y of the Vector4
	* @param otherX The X Coord that you would like to set
	* @param otherY The Y Coord that you would like to set
	* @param otherZ The Z Coord that you would like to set
	* @param otherA The A Coord that you would like to set
	*/
	Vector4(const float otherX, const float otherY, const float otherZ, const float otherA);

	/**
	* Destructor
	*/
	~Vector4();

	/**
	* Get the X of Vector4. Returns as const so no modification can happen
	* @return const:float X coord of the Vector4
	*/
	const float getX();

	/**
	* Get the Z of Vector4. Returns as const so no modification can happen
	* @return const:float Z coord of the Vector4
	*/
	const float getY();

	/**
	* Get the Z of Vector4. Returns as const so no modification can happen
	* @return const:float Z coord of the Vector4
	*/
	const float getZ();

	/**
	* Get the A of Vector4. Returns as const so no modification can happen
	* @return const:float A coord of the Vector4
	*/
	const float getA();

	/**
	* Sets the X coord of the Vector4
	* @param otherX The value to which you want to set the X coord to
	*/
	const void setX(const float otherX);

	/**
	* Sets the Y coord of the Vector4
	* @param otherY The value to which you want to set the Y coord to
	*/
	const void setY(const float otherY);

	/**
	* Sets the Y coord of the Vector4
	* @param otherZ The value to which you want to set the Z coord to
	*/
	const void setZ(const float otherZ);

	/**
	* Sets the Y coord of the Vector4
	* @param otherA The value to which you want to set the A coord to
	*/
	const void setA(const float otherA);

	/**
	* Gets the cross product of a Vector4.
	*
	* @return float
	*/
	Vector4 cross(const Vector4 & otherVec) const;

	/**
	* Gets the dot product of a Vector4.
	*
	* @return float
	*/
	float dot(const Vector4 & otherVec) const;

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
	* Normalises Vector4. This allows for the vector to retain the direction from origin,
	* but no longer is the correct length. This is from the unit circle.
	* By using Axis / magnitude of the Vector4 we can change it so the Vector is inside the unit
	* circle. This can then be used for velocity of a Vector4.
	*/
	void normalise();

	/**
	* Allows to plus two Vector4's together.
	* This is not a function that you call, but operator overloads the + symbol so you can
	* express a plus operation like Vector4 + Vector4. This returns a new Vector4 as it is only
	* a + and not a +=
	*
	* @return Vector4 The sum of the two Vector4's
	*/
	Vector4 operator+ (const Vector4 otherVec) const;

	/**
	* Allows to subract two Vector4's.
	* This is not a function that you call, but operator overloads the - symbol so you can
	* express a subtraction operation like Vector4 - Vector4. This returns a new Vector4 as it
	* is only a - and not a -=
	*
	* @return Vector4 The difference of the two Vector4's
	*/
	Vector4 operator- (const Vector4 otherVec) const;

	/**
	* Allows to multiply a Vector4 and a float.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like Vector4 * float. This returns a new Vector4
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* Vector4 * float
	* for this function to work
	*
	* @return Vector4 The product of the Vector4 and the float
	*/
	Vector4 operator* (float number);

	/**
	* Allows to multiply a Vector4 and a float.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like float * Vector4. This returns a new Vector4
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* float * Vector4
	* for this function to work
	*
	* @return Vector4 The product of the Vector4 and the float
	*/
	friend Vector4 operator* (float number, const Vector4 & otherVec);

	/**
	* Allows you to cast the Vector4 and get all the axis of the Vector in a float[]
	* @return float* Returns the starting element of an array of all the axis
	*/
	operator float*();

	/**
	* Test to see if two Vector4's are not equal to each other
	* @return bool Tests to see if the two Vector4's are not equal to each other
	*/
	bool operator!= (const Vector4 otherVec) const;

	/**
	* Test to see if two Vector4's are equal to each other
	* @return bool Tests to see if the two Vector4's are equal to each other
	*/
	bool operator== (const Vector4 otherVec) const;

	/**
	* Gets the String respresentation of the Vector4. This is in the form of (X, Y, Z, A)
	* @return string The string respresentation of the Vector4
	*/
	std::string toString() const;
};


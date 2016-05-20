////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-04-15
// Brief:			A Maths Vector2 Class
////////////////////////////////////////////////////////////

#pragma once
#include <math.h>
#include <string>
#include <sstream>

class Vector2
{
public:

	/**
	* A Vector2 that is all 0. Static for quick access
	*/
	static const Vector2 ZERO;

	float x = 0;
	float y = 0;

	/**
	* Default Constructor
	*/
	Vector2();

	/**
	* Constructor
	* Argument Constructor to set the X and Y of the Vector2
	* @param otherX The X Coord that you would like to set
	* @param otherY The Y Coord that you would like to set
	*/
	Vector2(const float otherX, const float otherY);

	/**
	* Destructor
	*/
	~Vector2();

	/**
	* Get the X of Vector2. Returns as const so no modification can happen
	* @return const:float X coord of the Vector2
	*/
	const float getX();

	/**
	* Get the Y of Vector2. Returns as const so no modification can happen
	* @return const:float Y coord of the Vector2
	*/
	const float getY();

	/**
	* Sets the X coord of the Vector2
	* @param otherX The value to which you want to set the X coord to
	*/
	const void setX(const float otherX);

	/**
	* Sets the Y coord of the Vector2
	* @param otherY The value to which you want to set the Y coord to
	*/
	const void setY(const float otherY);

	/**
	* 
	*/
	float dot(const Vector2 & vector2) const;

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
	* Normalises Vector2. This allows for the vector to retain the direction from origin,
	* but no longer is the correct length. This is from the unit circle.
	* By using Axis / magnitude of the Vector2 we can change it so the Vector is inside the unit
	* circle. This can then be used for velocity of a vector2.
	*/
	void normalise();

	/**
	* Allows to plus two Vector2's together.
	* This is not a function that you call, but operator overloads the + symbol so you can
	* express a plus operation like Vector2 + Vector2. This returns a new Vector2 as it is only
	* a + and not a +=
	*
	* @return Vector2 The sum of the two Vector2's
	*/
	Vector2 operator+ (const Vector2 otherVec) const;

	/**
	* Allows to subract two Vector2's.
	* This is not a function that you call, but operator overloads the - symbol so you can
	* express a subtraction operation like Vector2 - Vector2. This returns a new Vector2 as it
	* is only a - and not a -=
	*
	* @return Vector2 The difference of the two Vector2's
	*/
	Vector2 operator- (const Vector2 otherVec) const;

	/**
	* Allows to multiply a Vector2 and a float.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like Vector2 * float. This returns a new Vector2
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* Vector2 * float
	* for this function to work
	*
	* @return Vector2 The product of the Vector2 and the float
	*/
	Vector2 operator* (float number);

	/**
	* Allows to multiply a float and a Vector2.
	* This is not a function that you call, but operator overloads the * symbol so you can
	* express a multiplication operation like float * Vector2. This returns a new Vector2
	* as it is only a * and not a *=. The float has to come after the Vector e.g.
	* float * Vector2
	* for this function to work
	*
	* @return Vector2 The product of the Vector2 and the float
	*/
	friend Vector2 operator* (float number, const Vector2 & otherVec);

	/**
	* Allows you to cast the Vector2 and get all the axis of the Vector in a float[]
	* @return float* Returns the starting element of an array of all the axis 
	*/
	operator float*();

	/**
	* Test to see if two Vector2's are not equal to each other
	* @return bool Tests to see if the two Vector2's are not equal to each other
	*/
	bool operator!= (const Vector2 otherVec) const;

	/**
	* Test to see if two Vector2's are equal to each other
	* @return bool Tests to see if the two Vector2's are equal to each other
	*/
	bool operator== (const Vector2 otherVec) const;

	/**
	* Gets the String respresentation of the Vector2. This is in the form of (X, Y)
	* @return string The string respresentation of the Vector2
	*/
	std::string toString() const;
};


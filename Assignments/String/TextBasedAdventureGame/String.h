////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-03-03
// Brief:			A alternative String class.
////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
class String
{
	//All the public methods and variables
public:
	//The Max Console Input size
	static const int MAX_ISTREAM_SIZE = 32768;

	//Constructors / Decontructors
	String();
	String(const char other);
	String(const char other[]);
	String(String *copy);
	~String();

	//Standard Methods
	int GetLength() const;
	bool Equals(const String* other) const;
	void Append(const String* other);
	void Prepend(const String* other);
	char At(const int index) const;
	String* ToUpperCase();
	String* ToLowerCase();
	bool Set(const char string[]);
	const char* GetRaw() const;
	int Find(const String* other) const;
	int Find(const int startIndex, const String* neddle) const;
	bool Replace(const String* neddle, const String* replace);

	//Operator Overloads
	String operator = (const char* other[]);
	friend std::ostream& operator << (std::ostream &os, String* s);
	friend std::istream& operator >> (std::istream &is, String* s);
	//All the public methods and variables
private:
	//Sets the character array to the size of 1
	char* m_data = new char[1];
	//Private kill functions that dellocates the memory for the char array
	void Kill();
};
////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-03-04
// Brief:			A alternative String class.
////////////////////////////////////////////////////////////

// Includes the Header file for the String CPP
#include "String.h"

// Default Constructor. Makes a String with the size of 0
String::String()
{
	// Puts a Null terminator at the end of the string. This case as the string is the size of
	// 1, we just put the null terminator at the first index
	m_data[0] = '\0';
}

// Constructor to make a string with a size of 1 with the character being the only element in 
// array
String::String(const char a_other)
{
	// Calls functions to request removal of the char array memory allocation
	Kill();
	// Initialize the char array with a size of 2. Then set the first index to the character
	// and set the last index to a null terminator
	m_data = new char[2];
	m_data[0] = a_other;
	m_data[1] = '\0';
}

//Creates a String with the character array given
String::String(const char a_other[])
{
	// Passes the char array to the Set function to be copied into the char array inside the
	// class
	Set(a_other);
}

//Creates a string based off another string.
String::String(String * a_copy)
{
	// Gets the raw C style String from the array and then calls the Set function for it to be
	// copied into the char array inside the class.
	const char* copyRaw = a_copy->GetCStyleString();
	Set(copyRaw);
	//Delete the Raw C style string memory reference.
	delete[] copyRaw;
}

// Deconstructor kills the memory reference of the string
String::~String()
{
	// Calls the Kill function to deallocate the memory for the internal char array
	Kill();
}

// Gets the length of the array excluding the null terminator
int String::GetLength() const
{
	// Couts the internal char array using a while loop until it finds the Null Terminator.
	// Returns the number if characters before the null terminator
	int index = 0;
	while (m_data[index] != '\0')
	{
		index++;
	}

	return index;
}

// Tests to see if another string is the same as this string
bool String::Equals(const String * a_other) const
{
	// Checks to see if the length if the same as the other. If not they are not equal.
	// Character Mismatchs
	if (a_other->GetLength() != GetLength())
	{
		return false;
	}

	// Loops through each index of both strings to see if the character is the same at each
	// index. If not the strings aren't equal
	for (int i = 0; i < GetLength(); i++)
	{
		if (a_other->At(i) != At(i))
		{
			return false;
		}
	}
	return true;
}

// Adds another string to the end of this string
void String::Append(const String * a_other)
{
	// Gets the c style string of the this object
	const char* temp = GetCStyleString();

	// Get the length of this object and the other string and adds 1 to the end for the null
	// terminator
	int length = GetLength() + a_other->GetLength() + 1;

	// Stores the this string length
	int lengthOld = GetLength();

	// Requests the memory for this char array to be dellocated
	Kill();

	// Creates a new char array with the length from before combining both + 1
	m_data = new char[length];

	// Adds all the old characters into the array first as this is a append. This uses that
	// length of the original string.
	for (int i = 0; i < lengthOld; i++)
	{
		m_data[i] = temp[i];
	}

	// Adds the characters from the appending string to this string object.
	for (int i = 0; i < a_other->GetLength(); i++)
	{
		m_data[lengthOld + i] = a_other->At(i);
	}

	// Sets the last the character, the reason for the plus 1 is so I can add the null
	// terminator
	m_data[length - 1] = '\0';

	//Deletes the Get raw memory allocation which is used above
	delete[] temp;
}

// Adds another string to the front of this string
void String::Prepend(const String * a_other)
{
	// Gets the c style string of the this object
	const char* temp = GetCStyleString();

	// Get the length of this object and the other string and adds 1 to the end for the null
	// terminator
	int length = GetLength() + a_other->GetLength() + 1;

	// Stores the this string length
	int lengthOld = GetLength();

	// Requests the memory for this char array to be dellocated
	Kill();

	// Creates a new char array with the length from before combining both + 1
	m_data = new char[length];

	// Adds the characters from the prepending string to this string object.
	for (int i = 0; i < a_other->GetLength(); i++)
	{
		m_data[i] = a_other->At(i);
	}

	// Adds all the old characters into the array last as this is a prepend. This uses that
	// length of the original string.
	for (int i = 0; i < lengthOld; i++)
	{
		m_data[a_other->GetLength() + i] = temp[i];
	}

	// Sets the last the character, the reason for the plus 1 is so I can add the null
	// terminator
	m_data[length - 1] = '\0';

	//Deletes the Get raw memory allocation which is used above
	delete[] temp;
}

// Gets the character at a particular index
char String::At(const int a_index) const
{
	return m_data[a_index];
}

// Convets the entire string to Uppercase and returns as a new String
String* String::ToUpperCase()
{
	// Creates a temp memory allocation for the char array
	char* temp = new char[GetLength() + 1];
	for (int i = 0; i < GetLength(); i++)
	{
		// Checks to see if the character is a lower case character. If it is it makes it a
		// upper case character otherwise just add it to the array.
		if ((int)m_data[i] >= 97 && (int)m_data[i] <= 122)
		{
			temp[i] = (((int)m_data[i] - 65) % 32) + 65;
		}
		else
		{
			temp[i] = m_data[i];
		}
	}

	// Set the last character of the array to a null terminator
	temp[GetLength()] = '\0';

	//Creates a new string based off that c style string
	String* allUpper = new String(temp);

	//Deletes the temp array
	delete temp;
	return allUpper;
}

// Convers the entire string to Lowercase and returns as a new String
String* String::ToLowerCase()
{
	// Creates a temp memory allocation for the char array
	char* temp = new char[GetLength() + 1];
	for (int i = 0; i < GetLength(); i++)
	{
		// Checks to see if the character is a upper case character. If it is it makes it a
		// lower case character otherwise just add it to the array.
		if ((int)m_data[i] >= 65 && (int)m_data[i] <= 90)
		{
			temp[i] = (((int)m_data[i] - 65) % 32) + 97;
		}
		else
		{
			temp[i] = m_data[i];
		}
	}

	// Set the last character of the array to a null terminator
	temp[GetLength()] = '\0';

	// Creates a new string based off that c style string
	String* allLower = new String(temp);

	// Deletes the temp array
	delete temp;
	return allLower;
}

// Removes the memory reference for the string character array
void String::Kill()
{
	// Checks to make sure that the pointer is not already null
	if (m_data != nullptr) 
	{
		// Delete the Memory Allocation for the char array
		delete[] m_data;

		// Set the pointer to Null Pointer
		m_data = nullptr;
	}
}

// Sets the string to a particular character array
bool String::Set(const char a_other[])
{
	// Requests for the memory allocation to be removed
	Kill();

	// Get the length of the c style string
	int index = 0;
	while (a_other[index] != '\0') 
	{
		index++;
	}

	// Create a new char array with the size of the c style string + 1
	m_data = new char[index + 1];

	// Adds all the characters to the array
	for (int i = 0; i < index; i++)
	{
		m_data[i] = a_other[i];
	}

	// Adds the null terminator to the end of the array
	m_data[index] = '\0';
	return true;
}

// Gets the raw character array of the String
// The Array this method creates needs to be deleted from another side
const char* String::GetCStyleString() const
{
	// Create a clone array with the length of the object array
	char* clone = new char[GetLength() + 1];

	// Add all the characters from the object array to the clone array
	for (int i = 0; i < GetLength(); i++)
	{
		clone[i] = m_data[i];
	}

	// Set the last element of the array to the null terminator
	clone[GetLength()] = '\0';
	return clone;
}

// Finds the starting index of a particular string in the string. -1 meaning it can't be found
int String::Find(const String* a_neddle) const
{
	//Call one of the other Find methods
	return Find(0, a_neddle);
}

// Finds the starting index of a particular string in the string starting from a particular 
// index. -1 meaning it can't be found
int String::Find(const int startIndex, const String * neddle) const
{
	// Checks to make sure that the starting index is not more than the string length and 
	// less than 0
	if (startIndex >= GetLength() || startIndex < 0)
	{
		return -1;
	}


	// Start at the starting index
	for (int i = startIndex; i < GetLength(); i++)
	{
		// Checks to see if the current index character matches the first index of the
		// neddle
		if (At(i) == neddle->At(0))
		{
			// Sets the current index to be the for index
			int currentIndex = i;

			// For to go through the needle length to check to see if the remaining characters
			// match the neddle from the object char array
			for (int ii = 0; ii < neddle->GetLength();)
			{
				//Checks each charatcer
				if (At(currentIndex) == neddle->At(ii)) {
					currentIndex++;
					ii++;

					// Checks to make sure that we are not going to go past the last index of
					// the length object char array and to see if the current index of the
					// neddle has not surpassed the length of the neddle. This just checks to
					// make sure that the neddle length is not more than the number of
					// elements left in the array
					if (currentIndex >= GetLength() && ii < neddle->GetLength()) {
						break;
					}

					// Checks to see if we have passed or at the neddle length. If we have, we
					// have successfully found the neddle in the string and return the
					// starting index which it's at.
					if (ii >= neddle->GetLength()) {
						return i;
					}
				}
				// Exit check cause characters didn't match up so it continues to search the 
				// array
				else
				{
					break;
				}
			}
		}
	}
	return -1;
}

// Replaces a certain part of a string with another string
bool String::Replace(const String * a_neddle, const String * a_replace)
{
	// Gets the stating index of the neddle found in the string.
	int startingIndex = Find(a_neddle);

	// Checks to make sure that neddle can be found by seeing if the find method returned -1 or
	// or not
	if (startingIndex == -1)
	{
		return false;
	}

	// Creates a temp string
	String* temp = new String();

	// Appends the first part of the string before the neddle was found
	for (int i = 0; i < startingIndex; i++)
	{
		temp->Append(&String(m_data[i]));
	}

	// Adds the replaced characters to the temp string
	temp->Append(a_replace);

	// Then the index starts from the the starting index plus the length of the neddle. It
	// then appends the rest of the original to the end of the string
	for (int i = startingIndex + a_neddle->GetLength(); i < GetLength(); i++) 
	{
		temp->Append(&String(m_data[i]));
	}

	// Gets the c style string
	const char* tempRaw = temp->GetCStyleString();

	//Sets this string to the c style string
	Set(tempRaw);

	// Deletes the memory allocations
	delete tempRaw;
	delete temp;

	return true;
}

// Creates a new String from a character array using the = sign
String String::operator=(const char * a_other[])
{
	// Returns a new string using the the c style string constructor
	return String(*a_other);
}

// Outputs the Raw version of a string
std::ostream & operator<<(std::ostream & a_os, String* a_s)
{
	//Just the char array to the out stream and returns the reference
	return a_os << a_s->m_data;
}

// Gets input from the console and converts it to a string
std::istream & operator>>(std::istream & a_is, String * a_s)
{
	// Creates an arary with the the const MAX_ISTREAM_SIZE
	char inputData[String::MAX_ISTREAM_SIZE];

	// Get the line with the max of the const MAX_ISTREAM_SIZE
	a_is.getline(inputData, String::MAX_ISTREAM_SIZE);

	// Sets the string object to the string object to what the console input was
	a_s->Set(inputData);
	return a_is;
}
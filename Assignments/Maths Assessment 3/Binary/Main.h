#pragma once
#include <iostream>

class Main
{
public:
	Main();
	~Main();

	bool IsLeftMostBitSet(unsigned int value);
	bool IsRightMostBitSet(unsigned int value);
	bool IsBitSet(unsigned int value, unsigned char bit_to_check);
	unsigned GetRightMostSetBit(int value);
	void PrintBinary(unsigned char value);
	bool IsPowerOf2(unsigned int value);
};


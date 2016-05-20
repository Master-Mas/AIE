#include "Main.h"

void main()
{
	Main main;

	uint32_t test = 10000001000000000000;

	std::cout << std::boolalpha << main.IsLeftMostBitSet(test) << "\n";

	system("pause");
}

Main::Main()
{
}


Main::~Main()
{
}

bool Main::IsLeftMostBitSet(unsigned int value)
{
	return (value & (1 << 31)) != 0;
}

bool Main::IsRightMostBitSet(unsigned int value)
{
	return (value & (1 << 0)) != 0;
}

bool Main::IsBitSet(unsigned int value, unsigned char bit_to_check)
{
	return (value & bit_to_check) != 0;
}

int Main::GetRightMostSetBit(unsigned int value)
{
	return (value << 0) & 1;
}

void Main::PrintBinary(unsigned char value)
{
	for (unsigned i = 1 << 31; i > 0; i = i / 2)
	{
		(value & i) ? printf("1") : printf("0");
	}
}

bool Main::IsPowerOf2(unsigned int value)
{
	while (((value % 2) == 0) && value > 1)
	{
		value /= 2;
	}

	return (value == 1);
}

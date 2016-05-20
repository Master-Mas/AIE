#include "Main.h"

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
	return (value & bit_to_check);
}

unsigned Main::GetRightMostSetBit(int value)
{
	return log2(value&-value);
}

void Main::PrintBinary(unsigned char value)
{
	for (unsigned i = 1 << 31; i > 0; i = i / 2)
	{
		(value & i) ? printf("1") : printf("0");
	}

	printf("\n");
}

bool Main::IsPowerOf2(unsigned int value)
{
	return value << 2;
}

void main()
{
	Main main;

	int test = 01010000;

	std::cout << main.GetRightMostSetBit(test) << "\n";

	std::cout << std::boolalpha << main.IsBitSet(00000001, '1') << "\n";

	main.PrintBinary('b');

	system("pause");
}
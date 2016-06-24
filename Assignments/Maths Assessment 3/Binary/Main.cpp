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
	return (value & (1 << bit_to_check));
}

int Main::GetRightMostSetBit(unsigned value)
{
	for (int i = 0; i < 32; ++i)
	{
		if (IsBitSet(value, i))
		{
			return i;
		}
	}

	return -1;
}

void Main::PrintBinary(unsigned char value)
{
	std::bitset<8> x(value);
	std::cout << x << "\n";
}

bool Main::IsPowerOf2(unsigned int value)
{
	return ((value != 0) && !(value & (value - 1)));
}

void main()
{
	Main main;

	std::cout << std::bitset<5>(~0b10101) << "\n";

	unsigned test = 0b00000001;
	std::cout << main.GetRightMostSetBit(test) << "\n";

	test = 0b10011100;
	std::cout << main.GetRightMostSetBit(test) << "\n";

	test = 0b01010000;
	std::cout << main.GetRightMostSetBit(test) << "\n";

	test = 0b00000000;
	std::cout << main.GetRightMostSetBit(test) << "\n";

	main.PrintBinary('b');

	std::cout << ~0b11111 << std::endl;

	system("pause");
}
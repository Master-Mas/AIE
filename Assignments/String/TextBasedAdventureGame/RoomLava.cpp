#include "RoomLava.h"

RoomLava::RoomLava(int a_seed) : Room(new String("Firerly Caves"), a_seed)
{
	for (int i = 0; i < 4; i++)
	{
		paths[i] = GetExit(i + 1);
	}
}

RoomLava::~RoomLava()
{
}

void RoomLava::GeneratePathDirections()
{
}

void RoomLava::OutputRoomEnterMessage()
{
	std::cout << &String("Wow this room is hot and bright. \"Pop sssssssss\n Oh. This room is full of hot lava. There are some paths, but\nthey look like they") << std::endl;
}

int RoomLava::GetExit(int direction)
{
	return paths[direction - 1] && exits[direction - 1];
}

bool RoomLava::InputProccessor(int direction)
{
	if (paths[direction - 1])
	{
		std::cout << &String("I can go along this way, but the path looks like it's going to crumble behind me. I need to make a choice?") << std::endl << &String("Say Yes or No") << std::endl << "> ";
		String input = String();
		std::cin >> &input;

		input.ToLowerCase();
		if (input.Find(&String("y")) >= 0) 
		{
			paths[direction] = 0;
			return true;
		}
		else 
		{
			return false;
		}
	}
	else
	{
		std::cout << &String("Looks like this path has already crubbled. I should look for another path.") << std::endl;
		return false;
	}
}



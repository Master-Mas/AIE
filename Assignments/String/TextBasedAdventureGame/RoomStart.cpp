#include "RoomStart.h"

RoomStart::RoomStart(int a_seed) : Room(new String("Where it started?"), a_seed)
{
	SetExit(1, 1);
	SetExit(2, 1);
	SetExit(3, 1);
	SetExit(4, 1);
}

RoomStart::~RoomStart()
{
}


void RoomStart::OutputRoomEnterMessage()
{	
	if (hasStarted)
	{
		std::cout << &String("Hmmmm. I seem to of found where I started again. I have only gone in circle. Oh no. I probably should choose another way") << std::endl << std::endl;
	}
	else
	{
		std::cout << &String("You awake to find yourself sitting in a cold hole. You see 4 exits, 1 to the") << std::endl <<
			&String("north, another to the south and ones to the east and west. You get a feeling by looking into the dark corridors that this won't just be a easy exit, there will be danger ahead. ");

		std::cout << &String("You can move you by typing in the commands Move North, ") << std::endl << &String("Move East, Move South, Move West") << std::endl << std::endl;
		hasStarted = true;
	}
}

bool RoomStart::InputProccessor(int direction)
{
	switch (direction)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		return false;
	}

	return Room::InputProccessor(direction);
}
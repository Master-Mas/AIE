#include "Room.h"

Room::Room(String * a_name, int a_seed)
{
	name = a_name;
	seed = a_seed;

	CreateExits();
}

Room::~Room()
{
	delete name;
}

void Room::OutputRoomEnterMessage()
{
	std::cout << &String("Not Yet Implemented") << std::endl;
}

String* Room::GetRoomName()
{
	return name;
}

bool Room::InputProccessor(int direction)
{
	return true;
}

String* Room::GetInput()
{
	return nullptr;
}

bool const Room::CheckExitDirection(int direction)
{
	if (direction > 0 && direction < 5)
	{
		return exits[direction - 1];
	}
	else
	{
		return false;
	}
}

void const Room::SetExit(int direction, int open)
{
	int i = 0;
	exits[direction - 1] = open;
}

void const Room::CreateExits()
{
	for (int i = 0; i < 4; i++)
	{
		exits[i] = (rand() % 4 == 1) ? 1 : 0;
	}
}

int Room::GetExit(int direction)
{
	return exits[direction - 1];
}

int const Room::GetRoomIndex()
{
	return index;
}

void Room::SetRoomIndex(int a_index)
{
	index = a_index;
}

int Room::getSeed()
{
	return seed;
}

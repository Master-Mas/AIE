#include "RoomMonster.h"

RoomMonster::RoomMonster(String* name, int a_seed) : Room(name, a_seed)
{
	
}

RoomMonster::~RoomMonster()
{
}

void RoomMonster::OutputRoomEnterMessage()
{
	std::cout << &String("Not Yet Implemented") << std::endl;
}

bool RoomMonster::InputProccessor(int direction)
{
	return true;
}

int RoomMonster::GetNumberofMonsters()
{
	return numberOfMonsters = rand() % RoomMonster::MAX_NUMBER_OF_MONSTER_PER_ROOM;
}


float RoomMonster::GetDamage()
{
	return 0.0f;
}

int RoomMonster::GetExit(int direction)
{
	return exits[direction - 1];
}

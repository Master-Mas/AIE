#include "RoomMonsterZombie.h"

RoomMonsterZombie::RoomMonsterZombie(int a_seed) : RoomMonster(new String("Zombie Graves"), a_seed)
{
	int numberOfZombies = rand() % MAX_NUMBER_OF_MONSTER_PER_ROOM;
	for (int i = 0; i < numberOfZombies; i++)
	{
		zombieBlocking[i] = rand() % 2;
	}
}

RoomMonsterZombie::~RoomMonsterZombie()
{
}

void RoomMonsterZombie::OutputRoomEnterMessage()
{
	std::cout << &String("This room has a lot of groans in it. It could be Zombies. I should be careful\nmoving through this room, I don't want my brain to be eaten") << std::endl;
}

int RoomMonsterZombie::GetExit(int direction)
{
	return !zombieBlocking[direction - 1] && exits[direction - 1];
}

bool RoomMonsterZombie::InputProccessor(int direction)
{
	if (zombieBlocking[direction - 1])
	{
		std::cout << &String("I hear groans that way. \"Ooooorrrraaaaaaaaaagghooooooooooooooo\" I don't think I should encounter that") << std::endl;
	}
	return !zombieBlocking[direction - 1];
}
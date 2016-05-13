#include "RoomMonsterGhost.h"

RoomMonsterGhost::RoomMonsterGhost(int a_seed) : RoomMonster(new String("Ghostly Halls"), a_seed)
{
	int numberOfGhosts = rand() % MAX_NUMBER_OF_MONSTER_PER_ROOM;
	for (int i = 0; i < numberOfGhosts; i++)
	{
		ghostBlocking[i] = rand() % 2;
	}
}

RoomMonsterGhost::~RoomMonsterGhost()
{
}

void RoomMonsterGhost::OutputRoomEnterMessage()
{
	std::cout << &String("You enter a room. There seems to be a strange sense in this room. There seems to be these things floating around the room. In the faint amount I light, I see an outline. Arrr, it's a ghost. I probably should avoid it") << std::endl;
}

bool RoomMonsterGhost::InputProccessor(int direction)
{
	if (ghostBlocking[direction - 1]) 
	{
		std::cout << &String("I can see a door on that side, but I can see ghosts. Maybe I shouldn't go that way") << std::endl;
	}
	return !ghostBlocking[direction - 1];
}

int RoomMonsterGhost::GetExit(int direction)
{
	return !ghostBlocking[direction - 1] && exits[direction - 1];
}

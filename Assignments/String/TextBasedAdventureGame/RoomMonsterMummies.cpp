#include "RoomMonsterMummies.h"



RoomMonsterMummies::RoomMonsterMummies(int a_seed) : RoomMonster(new String("Tombs of Mummies"), a_seed)
{
	int numberOfMummies = rand() % MAX_NUMBER_OF_MONSTER_PER_ROOM;
	for (int i = 0; i < numberOfMummies; i++)
	{
		mummyBlocking[i] = rand() % 2;
	}
}


RoomMonsterMummies::~RoomMonsterMummies()
{
}

void RoomMonsterMummies::OutputRoomEnterMessage()
{
	std::cout << &String("You enter a room. There seems to be a strange sense in this room. There seems tobe these things floating around the room. In the faint amount I light, I see an\noutline. Arrr, it's a ghost. I probably should avoid it") << std::endl;
}

int RoomMonsterMummies::GetExit(int direction)
{
	return !mummyBlocking[direction - 1] && exits[direction - 1];
}

//I look down and I see paper on the floor. This is strange, I would of thought that no one would of 

bool RoomMonsterMummies::InputProccessor(int direction)
{
	if (mummyBlocking[direction - 1])
	{
		std::cout << &String("I see a couple of arms sticking out that way. I don't think that way is advisable") << std::endl;
	}
	return !mummyBlocking[direction - 1];
}
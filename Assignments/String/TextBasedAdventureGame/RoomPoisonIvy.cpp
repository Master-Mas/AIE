#include "RoomPoisonIvy.h"

RoomPoisonIvy::RoomPoisonIvy(int a_seed) : Room(new String("Haunted Woods"), a_seed)
{
	for (int i = 0; i < 4; i++)
	{
		changeOrder();
	}
}

RoomPoisonIvy::~RoomPoisonIvy()
{
}

bool RoomPoisonIvy::InputProccessor(int direction)
{
	if (currentlyWhereIvyIs[direction - 1]) 
	{
		//std::cout << &String("There seems to be ivy at that door, I shouldn't go that way") << std::endl;
		return true;
	}
	else
	{
		return true;
	}
}

void RoomPoisonIvy::OutputRoomEnterMessage()
{
	if (hasPassedThrough) 
	{
		std::cout << &String("I have already been here before. Though it seems like some of the ivy has died and regrown in new places.") << std::endl;
	}
	else 
	{
		hasPassedThrough = true;
		std::cout << &String("What's touching me!... Oh, it's only this bush here. As you make your decision, you feel your leg start to get itchy. This must be poison ivy. I really\nshouldn't go through that again.") << std::endl;
	}
}

int RoomPoisonIvy::GetExit(int direction)
{
	return !currentlyWhereIvyIs[direction - 1] && exits[direction - 1];
}

void RoomPoisonIvy::changeOrder()
{
	currentlyWhereIvyIs[rand() % 4] = rand() % 2;
}


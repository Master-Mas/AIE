#include "RoomClear.h"

RoomClear::RoomClear(int a_seed) : Room(new String("All Clear"), a_seed)
{
}


RoomClear::~RoomClear()
{
}

bool RoomClear::InputProccessor(int direction)
{
	return true;
}

void RoomClear::OutputRoomEnterMessage()
{
	std::cout << &String("Wow. For once this room seems to be clear. The problem still stands though, I'm not out of here") << std::endl;
}

#pragma once
#include "Room.h"
class RoomClear :
	public Room
{
public:
	RoomClear(int a_seed);
	~RoomClear();
	bool InputProccessor(int direction);
	virtual void OutputRoomEnterMessage();
};


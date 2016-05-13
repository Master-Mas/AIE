#pragma once
#include "Room.h"
class RoomStart :
	public Room
{
public:
	RoomStart(int a_seed);
	~RoomStart();
	virtual void OutputRoomEnterMessage();
	bool InputProccessor(int direction);
private:
	bool hasStarted = false;
};


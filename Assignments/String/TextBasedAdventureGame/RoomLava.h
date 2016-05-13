#pragma once
#include "Room.h"
class RoomLava : public Room
{
public:
	RoomLava(int a_seed);
	~RoomLava();
private:
	bool paths[4] = {0,0,0,0};
	
public:
	void GeneratePathDirections();
	virtual bool InputProccessor(int direction);
	void OutputRoomEnterMessage();
	virtual	int GetExit(int direction);
};

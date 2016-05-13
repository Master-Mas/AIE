#pragma once
#include "Room.h"
class RoomPoisonIvy :
	public Room
{
public:
	RoomPoisonIvy(int a_seed);
	~RoomPoisonIvy();
	virtual bool InputProccessor(int direction);
	virtual void OutputRoomEnterMessage();
	virtual	int GetExit(int direction);
private:
	bool currentlyWhereIvyIs[4] = { 0,0,0,0 };
	bool hasPassedThrough = false;
	void changeOrder();
};


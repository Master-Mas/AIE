#pragma once
#include "RoomMonster.h"
class RoomMonsterZombie : public RoomMonster
{
public:
	RoomMonsterZombie(int a_seed);
	~RoomMonsterZombie();
	virtual bool InputProccessor(int direction);
	void OutputRoomEnterMessage();
	virtual	int GetExit(int direction);
private:
	bool zombieBlocking[4] = { false, false, false, false };
};


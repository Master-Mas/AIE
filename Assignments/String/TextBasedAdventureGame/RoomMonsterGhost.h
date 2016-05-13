#pragma once
#include "RoomMonster.h"
class RoomMonsterGhost : public RoomMonster
{
public:
	RoomMonsterGhost(int a_seed);
	~RoomMonsterGhost();
	virtual void OutputRoomEnterMessage();
	bool InputProccessor(int direction);
	virtual	int GetExit(int direction);
private:
	bool ghostBlocking[4] = { false, false, false, false };
};


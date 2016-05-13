#pragma once
#include "RoomMonster.h"
class RoomMonsterMummies : public RoomMonster
{
public:
	RoomMonsterMummies(int a_seed);
	~RoomMonsterMummies();
	virtual bool InputProccessor(int direction);
	virtual void OutputRoomEnterMessage();
	virtual	int GetExit(int direction);
private:
	bool mummyBlocking[4] = { false, false, false, false };
};


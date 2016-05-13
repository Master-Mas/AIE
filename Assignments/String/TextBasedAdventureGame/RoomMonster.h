#pragma once
#include "Room.h"
#include "String.h"
class RoomMonster :
	public Room
{
public:
	static const int NUMBER_OF_MONSTER_TYPES = 3;
	static const int MAX_NUMBER_OF_MONSTER_PER_ROOM = 3;
	enum MONSTER_TYPES
	{
		GHOST,
		MUMMIES,
		ZOMBIE
	};

	RoomMonster(String* name, int a_seed);
	~RoomMonster();
	virtual void OutputRoomEnterMessage();
	virtual bool InputProccessor(int direction);

	virtual float GetDamage();
	virtual	int GetExit(int direction);
private:
	int numberOfMonsters;

	int GetNumberofMonsters();
};


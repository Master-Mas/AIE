#pragma once
#include "String.h"
class Room
{
public:
	static const int NUMBER_OF_ROOM_TYPES = 4;

	Room(String* a_name, int a_seed);
	~Room();

	virtual void OutputRoomEnterMessage();
	String* GetRoomName();

	virtual bool InputProccessor(int direction);
	String* GetInput();

	bool const CheckExitDirection(int direction);
	void const SetExit(int direction, int open);
	virtual	int GetExit(int direction);
	int const GetRoomIndex();
	void SetRoomIndex(int a_index);

protected:
	int getSeed();
	int exits[4] = { 0,0,0,0 };

private:
	String* name = &String("Not Yet Implemented");
	int seed = 0;
	int index = -1;

	void const CreateExits();
};

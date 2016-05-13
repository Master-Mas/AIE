#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include "RoomLava.h";
#include "RoomPoisonIvy.h"
#include "RoomMonsterGhost.h"
#include "RoomMonsterMummies.h"
#include "RoomMonsterZombie.h"
#include "RoomStart.h"
#include "RoomClear.h"
class Launcher
{
public:
	//Constructors
	Launcher();
	~Launcher();
private:
	//Must be a Squared Rootable Number
	static const int NUMBER_OF_ROOMS = 81;
	Room* rooms[Launcher::NUMBER_OF_ROOMS];
	Player* player = nullptr;
	int seed = time(NULL);
	//int seed = 0;
	bool wasHere[Launcher::NUMBER_OF_ROOMS];
	bool correctPath[Launcher::NUMBER_OF_ROOMS];
	int numberOfRooms = 0;

	void ChooseRandomRooms();
	Room* generateRoom(int index);
	int FindCentreBlock();
	String* InputProcessor();
	void RoomInputChecker(int direction, bool* accepted, Room* currentRoom);
	void RoomExitSmoothing();
	void CreateLevelExit();
	bool recursiveSolve(int x, int y);

	//Dialog
	void SeedDialog();
	void StartGameDialog();
	void GameRunner();
	void EndGame();
};


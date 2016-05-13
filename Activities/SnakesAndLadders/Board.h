#pragma once
#include "MyStruct.h"
#include "Player.h"

class Board
{
public:
	Board(int numOfPlayers);
	
	~Board();

	void Play();

	void DisplayBoard();

	bool GetWin(Player somePlayer);

	bool CheckAllPlayers();

	MyStruct * CheckSquare(MyStruct *position);

	MyStruct * GetStructFromID(int ID);

	MyStruct GetNewPosition(Player *somePlayer, int roll);
	
	void MovePlayerTo(Player *somePlayer, MyStruct position);

	int GetRandomRoll();

private:
	MyStruct **board;
	int m_num;
	Player * playerArray;

};


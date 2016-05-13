#include "Board.h"

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

Board::Board(int numOfPlayers)
{
	srand(time(NULL));

	m_num = numOfPlayers;
	playerArray = new Player[m_num];

	board = new MyStruct*[10];
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		board[i] = new MyStruct[10];
		for (int ii = 0; ii < 10; ii++)
		{
			counter++;
			board[i][ii].SetID(counter);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int randPos = rand() % 50 + 1;

		GetStructFromID(randPos)->SetNext(GetStructFromID(randPos + (rand() % 25 + 1)));
	}

	for (int i = 0; i < 4; i++)
	{
		int randPos = rand() % 50 + 1;
		int randPos2 = rand() % 50 + 49;

		GetStructFromID(randPos2)->SetNext(GetStructFromID(randPos));
	}

	DisplayBoard();

}



		


Board::~Board()
{
	for (int i = 0; i < 10; i++)
	{
		delete[] board[i];
	}

	delete[] board;
	delete[] playerArray;

	std::cout << "Destructor for Board" << std::endl;
}

void Board::Play()
{
	//MyStruct temp;
	//std::cout << "First test" << std::endl;
	//temp.GetNext();

	int moves = 0;

	for (int player = 0; player < m_num;)
	{

		std::cout << "Number of Moves: " << ++moves << std::endl;
		std::cout << std::endl << "Press enter to roll for this player " << player + 1 << "." << std::endl;
		std::cin.ignore();
		int roll = GetRandomRoll();
		MyStruct temp = GetNewPosition(&playerArray[player], roll);
		MovePlayerTo(&playerArray[player], temp);

		DisplayBoard();

		if (GetWin(playerArray[player]))
		{
			std::cout << "\nPlayer " << player + 1 << " wins!" << std::endl;
			return;
		}

		player++;

		if (player >= m_num)
		{
			player = 0;
		}
	}
}

int Board::GetRandomRoll()
{
	int roll = rand() % 6 + 1;
	//std::cout << "Roll Number: " << roll << std::endl;
	return roll;
}

void Board::DisplayBoard() //hard
{
	//PSEUDOCODE
	//Goal: Print P if player is at position, print dot otherwise, flip every second row
	//PLAYER ARRAY = []
	//FOR I IN 10:
		//IF I IS ODD
			//FOR II IN 1-10
			//LOOP THROUGH PLAYER ARRAY
			//PRINT P OR .

		//ELSE IF EVEN
			//FOR II IN 10-1
			//LOOP THROUGH PLAYER ARRAY
			//PRINT P OR .

	system("cls");

	for (int i = 9; i >= 0; i--)
	{
		std::cout << '\n';
		if (i % 2 != 0)
		{
			for (int ii = 0; ii < 10; ii++)
			{
				bool foundPlayer = false;
				for (int item = 0; item < m_num; item++)
				{
					if (playerArray[item].GetID() == board[i][ii].GetID())
						foundPlayer = true;
				}
				if (foundPlayer) 
				{
					std::cout << 'P';
				}
				else
				{
					std::cout << '.';
				}
					
			}
		}

		else
		{
			for (int ii = 9; ii >= 0; ii--)
			{
				bool foundPlayer = false;
				for (int item = 0; item < m_num; item++)
				{
					if (playerArray[item].GetID() == board[i][ii].GetID())
						foundPlayer = true;
				}
				if (foundPlayer)
				{
					std::cout << 'P';
				}
				else
				{
					std::cout << '.';
				}
			}
		}
	}
}

bool Board::GetWin(Player somePlayer)
{
	if (somePlayer.GetID() == 100) { return true; } return false;
}

bool Board::CheckAllPlayers()
{
	for (int i = 0; i < m_num; i++)
	{
		if (GetWin(playerArray[i]))
			return true;
	}
	return false;
}

MyStruct * Board::CheckSquare(MyStruct *position)
{
	if (position->GetNext() != nullptr) {
		std::cout << std::endl << "Jumping" << std::endl;
		return position->GetNext();
	}
	else
		return position;
}

MyStruct * Board::GetStructFromID(int ID)
{
	for (int i = 0; i < 10; i++)
	{
		for (int ii = 0; ii < 10; ii++)
		{
			if (board[i][ii].GetID() == ID)
				return &board[i][ii];
		}
	}
}

MyStruct Board::GetNewPosition(Player *somePlayer, int roll) //easy
{
	int newPos = somePlayer->GetID() + roll;
	if (newPos > 100)
	{
		newPos = 100;
	}

	return *GetStructFromID(newPos);

}

void Board::MovePlayerTo(Player * somePlayer, MyStruct position)
{
	MyStruct* newPos = CheckSquare(&position);
	somePlayer->SetID(newPos->GetID());
}

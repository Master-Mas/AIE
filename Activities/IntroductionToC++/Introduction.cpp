#include <iostream>
using namespace std;

struct Player 
{
	int health = 0;
	char name[255] = "";
};

void main()
{

	int* myNumber = new int;
	int* myNumberArray = new int[5];

	Player* playerOne = new Player;
	Player* players = new Player[16];

	delete myNumber;
	delete myNumberArray;
	delete playerOne;
	delete players;

	system("pause");
}
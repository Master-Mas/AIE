#include <iostream>
#include "Board.h"

void main() {

	std::cout << "Input number of players: " << std::endl;
	int num = 0;
	std::cin >> num;

	Board gameBoard(num);
	gameBoard.Play();


	system("pause");
}
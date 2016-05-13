#include "Position.h"
using namespace std;

void main() 
{
	Position pos1 = Position(25, 30);

	cout << pos1 << endl;

	pos1 += Position(5, 10);

	cout << pos1 << endl;

	system("pause");
}
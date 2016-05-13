#include <iostream>
#include <ctype.h>
#include <time.h>
using namespace std;

int GetInput();

int main()
{
	int guessingCount = 1;
	srand(time(NULL));
	int randomNumber = rand() % 1001;

	int number = 0;
	bool guessed = false;
	for (int i = 0; i < 10; i++)
	{
		cout << "Please say a number between 0 - 1000" << endl;
		number = GetInput();
		if (number > randomNumber) 
		{
			cout << "Go Lower" << endl;
		}
		else if (number < randomNumber) 
		{
			cout << "Go Higher" << endl;
		}
		else 
		{
			guessed = true;
			cout << "You got it :)" << endl;
			break;
		}
	}

	if (!guessed) {
		cout << "You ran out of guesses. The number is: " << randomNumber << endl;
	}

	system("pause");
}

int GetInput()
{
	char input[255];
	do
	{
		cin >> input;
		int length = strlen(input);
		bool isNumber = true;
		for (int i = 0; i < length; i++)
		{
			if (!isdigit(input[i])) 
			{
				isNumber = false;
				break;
			}
		}
		if (isNumber) 
		{
			int number = atoi(input);
			if (!(number < 0 || number > 1000))
			{
				return number;
			}
		}

		cout << "You need to enter a number between 0 - 1000" << endl;

	} while (true);

}

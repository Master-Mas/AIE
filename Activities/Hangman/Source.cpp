#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

const int NUMBER_OF_WORDS = 7;

char* GetInput();
void display(int turns);

std::string words[NUMBER_OF_WORDS] = { "fort", "possibly", "image", "swung", "discussion", "breeze", "remarkable" };
bool solved = false;

void main()
{
	srand(time(NULL));
	int randomWord = rand() % NUMBER_OF_WORDS;
	
	char guessedLetters[255] = {};
	int currentEnder = 0;
	guessedLetters[0] = '\0';

	display(0);
	while (!solved) {
		char *guesses = GetInput();
		system("cls");

		int index = 0;
		while (guesses[index] != '\0') {
			index++;
		}

		for (int i = 0; i < index; i++)
		{
			int checker = 0;
			bool alreadyGuessed = false;
			while (guessedLetters[checker] != '\0') 
			{
				if (guessedLetters[checker] == guesses[i]) 
				{
					alreadyGuessed = true;
					break;
				}
				checker++;
			}

			if (!alreadyGuessed) 
			{
				guessedLetters[currentEnder] = guesses[i];
				currentEnder++;
				guessedLetters[currentEnder] = '\0';
			}
		}

		int amountOfCorrectLetters = 0;
		char* wordOutput = new char[words[randomWord].length() + 1];
		for (int i = 0; i < words[randomWord].length(); i++)
		{
			char partOfWord = words[randomWord].at(i);
			int counter = 0;
			while (guessedLetters[counter] != '\0') {
				if (guessedLetters[counter] == partOfWord) {
					wordOutput[i] = partOfWord;
					amountOfCorrectLetters++;
					break;
				}
				counter++;
			}

			if (guessedLetters[counter] == '\0') {
				wordOutput[i] = '_';
			}
		}
		wordOutput[words[randomWord].length()] = '\0';

		for (int i = 0; i < words[randomWord].length(); i++)
		{
			std::cout << wordOutput[i] << " ";
		}

		std::cout << std::endl;

		for (int i = 0; i < currentEnder; i++)
		{
			std::cout << guessedLetters[i] << " ";
		}

		std::cout << std::endl;
		
		display(currentEnder - amountOfCorrectLetters);

		if (words[randomWord].length() == amountOfCorrectLetters) 
		{
			std::cout << "You Win :)" << std::endl;
			break;
		}

		delete wordOutput;
		delete guesses;
	}
	
	system("pause");
}

void display(int turns) {
	switch (turns)
	{
	case 0:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	case 1:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	case 2:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	case 3:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|        /|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	case 4:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|        /|\\" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	case 5:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|        /|\\" << std::endl;
		std::cout << "|        /" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
		break;
	default:
		std::cout << " _________" << std::endl;
		std::cout << "|         |" << std::endl;
		std::cout << "|         0" << std::endl;
		std::cout << "|        /|\\" << std::endl;
		std::cout << "|        / \\" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;

		std::cout << "You Lose :(" << std::endl;

		solved = true;
		break;
	}
}

char* GetInput()
{
	char input[255];
	std::cin.getline(input, 255);
	std::cout << std::endl;

	int index = 0;
	int length = 0;
	char* filtered = new char[255];

	while (input[index] != '\0') {
		if ((int)input[index] != 32 && isalpha(input[index])) {
			if ((int)input[index] >= 65 && (int)input[index] <= 90)
			{
				input[index] = (((int)input[index] - 65) % 32) + 97;
			}
			filtered[length] = input[index];
			length++;
		}
		index++;
	}

	filtered[length] = '\0';

	return filtered;
}
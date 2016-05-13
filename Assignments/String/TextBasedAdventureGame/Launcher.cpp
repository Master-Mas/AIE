#include "Launcher.h"

void main()
{
	Launcher();
	system("pause");
}

Launcher::~Launcher()
{
}

Launcher::Launcher()
{
	StartGameDialog();
	ChooseRandomRooms();
	RoomExitSmoothing();
	CreateLevelExit();
	GameRunner();
}

void Launcher::ChooseRandomRooms()
{
	srand(seed);

	int centreBlock = FindCentreBlock() - 1;
	for (int i = 0; i < NUMBER_OF_ROOMS; i++)
	{
		int index = rand() % 4;
		if (i == centreBlock)
		{
			index = 999;
		}

		//std::cout << "Creating Room " << i << " : " << index << std::endl;
		rooms[i] = generateRoom(index);
		rooms[i]->SetRoomIndex(i);
	}
}

Room* Launcher::generateRoom(int index)
{
	switch (index)
	{
	case 0:
		return new RoomLava(seed);
	case 1:
		switch (rand() % RoomMonster::NUMBER_OF_MONSTER_TYPES)
		{
		case 0:
			//std::cout << "Creating Room Monster: 0" << std::endl;
			return new RoomMonsterGhost(seed);
		case 1:
			//std::cout << "Creating Room Monster: 1" << std::endl;
			return new RoomMonsterMummies(seed);
		case 2:
			//std::cout << "Creating Room Monster: 2" << std::endl;
			return new RoomMonsterZombie(seed);
		}
	case 2:
		return new RoomPoisonIvy(seed);
	case 3:
		return new RoomClear(seed);
	case 999:
		return new RoomStart(seed);
	default:
		return nullptr;
	}
}


int Launcher::FindCentreBlock()
{
	return ceil((float)Launcher::NUMBER_OF_ROOMS / 2);
}

void Launcher::SeedDialog()
{
	std::cout << &String("Please input a seed which you would like?") << std::endl << "> ";
	String input = String();
	std::cin >> &input;

	float lettersToSize = input.GetLength() / 10;
	int total = 0;

	int currentLetterCounter = 0;
	int currentTotal = 0;
	for (int i = 0; i < input.GetLength(); i++)
	{
		currentTotal += (int)input.At(i);
		currentLetterCounter++;
		if (currentLetterCounter >= 3) 
		{
			total += currentTotal;
			currentLetterCounter = 0;
		}
	}

	total += currentTotal;
	seed = total;
	system("cls");
	StartGameDialog();
}

void Launcher::StartGameDialog()
{
	std::cout << &String("And here it all starts. Once a while ago there was a lone member of this tribe.") << std::endl <<
		&String("An adventurer he was. He loved to travel the slient lands of the evil, finding ") << std::endl <<
		&String("the forever mistaken land puzzles that hadn't been worked out. This one puzzle") << std::endl <<
		&String("he stumbleupon wasn't so forgiving in his favour. This is the last we heard of ") << std::endl <<
		&String("this brave warrior.") << std::endl << std::endl <<
		&String("He was known as ");
	String playerName = String();
	std::cin >> &playerName;

	system("cls");
	if (playerName.Equals(&String("seed"))) 
	{
		SeedDialog();
		
	}
	else
	{
		int gridCentre = ceil(sqrt(Launcher::NUMBER_OF_ROOMS) / 2);
		player = new Player(&playerName, new Vector2((float)gridCentre, (float)gridCentre));
	}
}

void Launcher::GameRunner()
{
	bool gameRunning = true;

	while (gameRunning)
	{
		numberOfRooms++;
		int currentIndexofRoom = player->GetRoomNumber() - 1;
		Room* currentRoom = rooms[currentIndexofRoom];
		std::cout << &String("You have entered the room: ") << currentRoom->GetRoomName() << " : " << currentRoom->GetRoomIndex() << std::endl << std::endl;
		currentRoom->OutputRoomEnterMessage();

		bool acceptedInput = false;

		while (!acceptedInput)
		{
			String* inputData = InputProcessor();
			if (inputData->Equals(&String("move north")))
			{
				RoomInputChecker(1, &acceptedInput, currentRoom);
			}
			else if (inputData->Equals(&String("move east")))
			{
				RoomInputChecker(2, &acceptedInput, currentRoom);
			}
			else if (inputData->Equals(&String("move south")))
			{
				RoomInputChecker(3, &acceptedInput, currentRoom);
			}
			else if (inputData->Equals(&String("move west")))
			{
				RoomInputChecker(4, &acceptedInput, currentRoom);
			}
			else
			{
				std::cout << &String("Hmmmm. I can't seem to work out what to do now.\nPlease enter your command again") << std::endl;
			}
		}

		//system("pause");
		system("cls");
	}
}

void Launcher::EndGame()
{
	system("cls");
	std::cout << &String("You see the bright daylight ahead of you. The struggle is over. Working my way\nthrough all these rooms inside this maze. ") << numberOfRooms << &String(" rooms to be exact. From now on you\nthink that you're going to keep to the village and not go wandering where you\ndon't know what lies.") << std::endl;
	system("pause");
	exit(0);
}

void Launcher::RoomInputChecker(int direction, bool * accepted, Room* currentRoom)
{
	if (currentRoom->CheckExitDirection(direction))
	{
		switch (direction)
		{
		case 1:
			if (currentRoom->GetRoomIndex() < sqrt(Launcher::NUMBER_OF_ROOMS))
			{
				EndGame();
			}
			break;
		case 2:
			if (currentRoom->GetRoomIndex() % (int)sqrt(Launcher::NUMBER_OF_ROOMS) == (int)sqrt(Launcher::NUMBER_OF_ROOMS) - 1)
			{
				EndGame();
			}
			break;
		case 3:
			if (currentRoom->GetRoomIndex() > (sqrt(Launcher::NUMBER_OF_ROOMS) * (sqrt(Launcher::NUMBER_OF_ROOMS) - 1)) - 1)
			{
				EndGame();
			}
			break;
		case 4:
			if (currentRoom->GetRoomIndex() % (int)sqrt(Launcher::NUMBER_OF_ROOMS) == 0)
			{
				EndGame();
			}
			break;
		}
		if (currentRoom->InputProccessor(direction))
		{
			switch (direction)
			{
			case 1:
				player->MoveRoom(0, -1);
				break;
			case 2:
				player->MoveRoom(1, 0);
				break;
			case 3:
				player->MoveRoom(0, 1);
				break;
			case 4:
				player->MoveRoom(-1, 0);
				break;
			default:
				break;
			}
			*accepted = true;
		}
	}
	else
	{
		std::cout << &String("That Exit seems to be blocked. I should try another way") << std::endl;
	}
}

void Launcher::RoomExitSmoothing()
{
	for (int i = 0; i < Launcher::NUMBER_OF_ROOMS; i++)
	{

		if (i == 71) 
		{
			int test = 0;
		}

		int x = (i + 1) % ((int)sqrt(Launcher::NUMBER_OF_ROOMS));
		if (i == 0)
		{
			x = 1;
		}
		else if (x == 0)
		{
			x = (int)sqrt(Launcher::NUMBER_OF_ROOMS);
		}

		int y = ceil((i + 1) / sqrt(Launcher::NUMBER_OF_ROOMS));

		//Left
		if (rooms[i]->GetExit(4) == 1)
		{
			if (x != 1)
			{
				rooms[i - 1]->SetExit(2, 1);
			}
			else
			{
				rooms[i]->SetExit(4, 0);
			}
		}

		//Right
		if (rooms[i]->GetExit(2) == 1)
		{
			if (x != sqrt(Launcher::NUMBER_OF_ROOMS))
			{
				rooms[i + 1]->SetExit(4, 1);
			}
			else
			{
				rooms[i]->SetExit(2, 0);
			}
		}

		//Top
		if (rooms[i]->GetExit(1) == 1)
		{
			if (y != 1)
			{
				rooms[(y - 2) * (int)sqrt(Launcher::NUMBER_OF_ROOMS) + x]->SetExit(3, 1);
			}
			else
			{
				rooms[i]->SetExit(1, 0);
			}
		}

		//Bottom
		if (rooms[i]->GetExit(3) == 1)
		{
			if (y != sqrt(Launcher::NUMBER_OF_ROOMS))
			{

				//This line on index 71 is causing a crash. Hmmmmm This happens when we change the Number Types from 3 - 4
				rooms[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + x]->SetExit(1, 1);
			}
			else
			{
				rooms[i]->SetExit(3, 0);
			}
		}
	}
}

void Launcher::CreateLevelExit()
{
	int index = FindCentreBlock();
	int x = ceil(sqrt(Launcher::NUMBER_OF_ROOMS) / 2);
	int y = x;

	for (int i = 0; i < Launcher::NUMBER_OF_ROOMS; i++)
	{
		wasHere[i] = false;
		correctPath[i] = false;
	}

	bool solved = recursiveSolve(x, y);

	if (!solved)
	{
		std::cout << "No Path out of Maze found, please restart program" << std::endl;
		system("pause");
		exit(0);
	}

	for (int i = 0; i < Launcher::NUMBER_OF_ROOMS; i++) 
	{
		if(correctPath[i])
		{
			if (i < sqrt(Launcher::NUMBER_OF_ROOMS))
			{
				rooms[i]->SetExit(1, 1);
			} 
			else if (i > (sqrt(Launcher::NUMBER_OF_ROOMS) * (sqrt(Launcher::NUMBER_OF_ROOMS) - 1)) - 1)
			{
				rooms[i]->SetExit(3, 1);
			} 
			else if (i % (int)sqrt(Launcher::NUMBER_OF_ROOMS) == 0)
			{
				rooms[i]->SetExit(4, 1);
			}
			else if (i % (int)sqrt(Launcher::NUMBER_OF_ROOMS) == (int)sqrt(Launcher::NUMBER_OF_ROOMS) - 1)
			{
				rooms[i]->SetExit(2, 1);
			}
		}
	}
}

bool Launcher::recursiveSolve(int x, int y)
{
	if (x == 1 || x == sqrt(Launcher::NUMBER_OF_ROOMS) || y == 1 || y == sqrt(Launcher::NUMBER_OF_ROOMS)) 
	{ 
		correctPath[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
		return true;
	}

	if (wasHere[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)]) { return false; }

	wasHere[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
	if (x != 1) 
	{
		if (rooms[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)]->GetExit(4))
		{
			if (recursiveSolve(x - 1, y)) 
			{
				correctPath[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
				return true;
			}
		}
	}

	if (x != sqrt(Launcher::NUMBER_OF_ROOMS))
	{
		if (rooms[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)]->GetExit(2))
		{
			if (recursiveSolve(x + 1, y))
			{
				correctPath[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
				return true;
			}
		}
	}

	if (y != 1)
	{
		if (rooms[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)]->GetExit(1))
		{
			if (recursiveSolve(x, y - 1))
			{
				correctPath[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
				return true;
			}
		}
	}

	if (y != sqrt(Launcher::NUMBER_OF_ROOMS))
	{
		if (rooms[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)]->GetExit(3))
		{
			if (recursiveSolve(x, y + 1))
			{
				correctPath[((y - 1) * (int)sqrt(Launcher::NUMBER_OF_ROOMS)) + (x - 1)] = true;
				return true;
			}
		}
	}

	return false;
}

String* Launcher::InputProcessor()
{
	bool gettingInput = true;
	String* inputData = new String();
	String* temp;
	
	while (gettingInput)
	{
		std::cout << "> ";
		std::cin >> inputData;

		temp = inputData->ToLowerCase();

		if (inputData->Equals(&String("help")))
		{

		}
		else if (inputData->Equals(&String("?")))
		{

		}
		else if (inputData->Equals(&String("health")))
		{

		}
		else if (inputData->Equals(&String("exit")))
		{
			exit(0);
		}
		else 
		{
			gettingInput = false;
		}
	}

	delete inputData;
	return temp;
}

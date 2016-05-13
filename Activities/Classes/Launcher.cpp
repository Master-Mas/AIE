#include <cstdlib>
#include <iostream>
#include "Zombie.cpp"

void round(Zombie *zombies)
{
	if (rand() % 2 == 0)
	{
		Zombie zom = zombies[std::rand() % 5];
		zom->getHealth();
		//zom->setHealth( - 10);
	}
}

void main()
{
	Zombie *zombies = new Zombie[5];

	for (int i = 0; i < 5; i++)
	{
		//zombies[i] = new Zombie();
	}

	round(zombies);

	for (int i = 0; i < 5; i++)
	{
		delete zombies;
	}
}
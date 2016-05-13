#include "Zombie.h"



Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::SetHealth(float health)
{
	this->health = health;
}

void Zombie::SetAttack(float attack)
{
	if (attack < 0) {
		this->attack = attack;
	}
}

float Zombie::GetAttack()
{
	return this->attack;
}

float Zombie::GetHealth()
{
	return this->health;
}

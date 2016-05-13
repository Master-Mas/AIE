#pragma once
class Zombie
{
public:
	Zombie();
	~Zombie();
	void SetHealth(float health);
	void SetAttack(float attack);
	float GetAttack();
	float GetHealth();
private:
	float health = 100;
	float attack = 10;
	char occupation[255] = "";
};


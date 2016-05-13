class Zombie
{
private:
	float health = 100;
	int attack = 10;
public:
	Zombie() 
	{
		
	}

	void Destory()
	{
		/*delete health;
		delete attack;*/
	}

	float GetHealth() 
	{
		return health;
	}

	int GetAttack()
	{
		return attack;
	}

	void SetHealth(float health) 
	{
		this->health = health;
	}

	void SetAttack(int attack) 
	{
		this->attack = attack;
	}
};
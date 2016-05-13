#pragma once
class Player
{
public:
	Player();
	~Player();

	void SetID(int otherID)
	{
		m_ID = otherID;
	}

	int GetID()
	{
		return m_ID;
	}

private:
	int m_ID;
};


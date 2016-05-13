#pragma once
#include "String.h"
#include "Vector2.h"

class Player
{
public:
	Player(String* a_name, Vector2* position);
	~Player();

	bool IsDead();
	String* GetName();
	const Vector2* GetPos();
	int GetRoomNumber();
	void MoveRoom(float x, float y);
private:
	float m_health = 100.00f;
	String* m_name;
	Vector2 m_position = Vector2();
};


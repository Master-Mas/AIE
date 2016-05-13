#include "Player.h"

Player::Player(String * a_name, Vector2* position)
{
	const char *name = a_name->GetRaw();
	m_name = new String(name);
	delete[] name;
	m_position.SetX(position->GetX());
	m_position.SetY(position->GetY());
}

Player::~Player()
{
}

bool Player::IsDead()
{
	return m_health <= 0.00f;
}

String* Player::GetName()
{
	return m_name;
}

const Vector2* Player::GetPos()
{
	return &m_position;
}

int Player::GetRoomNumber()
{
	return m_position.GetX() + ((m_position.GetY() - 1) * 9);
}

void Player::MoveRoom(float x, float y)
{
	m_position.AddToX(x);
	m_position.AddToY(y);
}

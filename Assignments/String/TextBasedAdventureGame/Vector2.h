#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	void AddToX(float x);
	void AddToY(float y);
private:
	float m_x;
	float m_y;
};


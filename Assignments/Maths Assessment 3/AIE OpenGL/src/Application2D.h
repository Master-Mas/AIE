#pragma once

#include "BaseApplication.h"
#include "GamesMath.h"
#include <string>
#include <fstream>

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	void save();
	void load();

protected:
	SpriteBatch* m_spriteBatch;

private:
	Texture* m_bat1;
	Texture* m_bat2;
	Texture* m_ball;
	Texture* m_shield;
	Texture** numbers;

	Matrix3** transforms;

	Matrix3* transform1;
	Matrix3* transform2;
	Matrix3* transform3;
	Matrix3* transform4;

	Font* font;

	float batMoveSpeed = 200;
	float ballMoveSpeed = 400;
	int score[2] = { 0,0 };
	Vector2* ballDir = new Vector2();

	Vector2* recA1;
	Vector2* recB1;
	Vector2* recA2;
	Vector2* recB2;

	std::ifstream inFile;
	bool lifecycleTick = false;

	void resetBall();
};
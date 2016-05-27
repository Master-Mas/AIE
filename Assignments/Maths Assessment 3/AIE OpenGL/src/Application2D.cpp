#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

Application2D::Application2D() 
{
	srand(time(NULL));
}

Application2D::~Application2D() 
{
	
}

bool Application2D::startup() 
{
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_ball = new Texture("./bin/textures/ball.png");
	m_bat1 = new Texture("./bin/textures/bat1.png");
	m_bat2 = new Texture("./bin/textures/bat2.png");

	transforms = new Matrix3*[3];

	transforms[0] = new Matrix3();
	transforms[0]->setPosition(Vector2(32, (720 / 2) - 64));

	transforms[1] = new Matrix3();
	transforms[1]->setPosition(Vector2(1280 - 32, (720 / 2) - 64));

	transforms[2] = new Matrix3();
	transforms[2]->setPosition(Vector2((1280 / 2) - 16, (720 / 2) - 16));

	resetBall();

	return true;
}

void Application2D::shutdown() 
{
	delete m_spriteBatch;

	delete m_bat1;
	delete m_bat2;
	delete m_ball;

	for (int i = 0; i < 3; i++)
	{
		delete transforms[i];
	}

	delete[] transforms;
	delete ballDir;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	Vector2 velBat1 = Vector2();
	Vector2 velBat2 = Vector2();

	if (isKeyPressed(GLFW_KEY_W))
	{
		velBat1.y += batMoveSpeed * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_S))
	{
		velBat1.y -= batMoveSpeed * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_UP))
	{
		velBat2.y += batMoveSpeed * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_DOWN))
	{
		velBat2.y -= batMoveSpeed * deltaTime;
	}

	float* bat1Pos = (float*)transforms[0];
	float* bat2Pos = (float*)transforms[1];

	float* ballPos = (float*)transforms[2];

	Matrix3 rotation = Matrix3();
	rotation.setRotateZ(5.0f * deltaTime);

	*transforms[2] *= rotation;

	transforms[0]->setPosition(bat1Pos[6] + velBat1.x, bat1Pos[7] + velBat1.y);
	transforms[1]->setPosition(bat2Pos[6] + velBat2.x, bat2Pos[7] + velBat2.y);

	Vector2 ballVel = *ballDir * ballMoveSpeed * deltaTime;
	Vector2 newBallPos = Vector2(ballPos[6] + ballVel.x, ballPos[7] + ballVel.y);
	if (newBallPos.x < 0 + 16)
	{
		resetBall();
		newBallPos = Vector2((1280 / 2) - 16, (720 / 2) - 16);
	}
	else if (newBallPos.x > 1280 - 16)
	{
		resetBall();
		newBallPos = Vector2((1280 / 2) - 16, (720 / 2) - 16);
	}

	if (newBallPos.y < 0 + 16)
	{
		newBallPos.y = 16;
		ballDir->y = ballDir->y * -1;
	}
	else if (newBallPos.y > 720 - 16)
	{
		newBallPos.y = 720 - 16;
		ballDir->y = ballDir->y * -1;
	}

	bat1Pos = (float*)transforms[0];
	bat2Pos = (float*)transforms[1];

	
	if (newBallPos.intersects(newBallPos, Vector2(32, 32), Vector2(bat1Pos[7], bat1Pos[8]), Vector2(32, 128)))
	{
		*ballDir * -1;
	}
	else if (newBallPos.intersects(newBallPos, Vector2(32, 32), Vector2(bat1Pos[7], bat1Pos[8]), Vector2(32, 128))) 
	{
		*ballDir * -1;
	}

	transforms[2]->setPosition(newBallPos);

	return true;
}

void Application2D::draw() {

	clearScreen();

	m_spriteBatch->begin();

	m_spriteBatch->drawSpriteTransformed3x3(m_bat1, (float*)transforms[0]);
	m_spriteBatch->drawSpriteTransformed3x3(m_bat2, (float*)transforms[1]);
	m_spriteBatch->drawSpriteTransformed3x3(m_ball, (float*)transforms[2]);

	m_spriteBatch->end();
}

void Application2D::resetBall()
{
	ballDir->x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
	ballDir->y = (rand() % 100) * (rand() % 2 ? 1 : -1);
	ballDir->normalise();
}

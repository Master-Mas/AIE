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
	
	createWindow("Maths Library Graphics Test", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_ball = new Texture("./bin/textures/ball.png");
	m_bat1 = new Texture("./bin/textures/bat1.png");
	m_bat2 = new Texture("./bin/textures/bat2.png");

	child = new Matrix3();
	child->setPosition(200, 200);
	child->id = 1;

	transforms = new Matrix3*[3];

	transforms[0] = new Matrix3();
	transforms[0]->setPosition(Vector2(32, (720 / 2) - 64));

	transforms[1] = new Matrix3();
	transforms[1]->setPosition(Vector2(1280 - 32, (720 / 2) - 64));

	transforms[2] = new Matrix3();
	transforms[2]->setPosition(Vector2((1280 / 2) - 16, (720 / 2) - 16));
	//transforms[2]->id = 2;
	//transforms[2]->addChild(*child);

	numbers = new Texture*[10];

	numbers[0] = new Texture("./bin/textures/numbers/0.png");
	numbers[1] = new Texture("./bin/textures/numbers/1.png");
	numbers[2] = new Texture("./bin/textures/numbers/2.png");
	numbers[3] = new Texture("./bin/textures/numbers/3.png");
	numbers[4] = new Texture("./bin/textures/numbers/4.png");
	numbers[5] = new Texture("./bin/textures/numbers/5.png");
	numbers[6] = new Texture("./bin/textures/numbers/6.png");
	numbers[7] = new Texture("./bin/textures/numbers/7.png");
	numbers[8] = new Texture("./bin/textures/numbers/8.png");
	numbers[9] = new Texture("./bin/textures/numbers/9.png");

	font = new Font("./bin/font/consolas.ttf", 32);

	resetBall();

	return true;
}

void Application2D::shutdown() 
{
	delete font;
	delete m_spriteBatch;

	delete m_bat1;
	delete m_bat2;
	delete m_ball;

	delete child;

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

	Matrix3 rotation = Matrix3();
	rotation.setRotateZ(4.5f * deltaTime);

	*transforms[2] *= rotation;

	Vector2 bat1PosV = Vector2(bat1Pos[6] + velBat1.x, bat1Pos[7] + velBat1.y);
	if (bat1PosV.y < 64) 
	{
		bat1PosV.y = 64;
	}
	else if (bat1PosV.y > 720 - 64) 
	{
		bat1PosV.y = 720 - 64;
	}

	Vector2 bat2PosV = Vector2(bat2Pos[6] + velBat2.x, bat2Pos[7] + velBat2.y);
	if (bat2PosV.y < 64)
	{
		bat2PosV.y = 64;
	}
	else if (bat2PosV.y > 720 - 64)
	{
		bat2PosV.y = 720 - 64;
	}

	transforms[0]->setPosition(bat1PosV);
	transforms[1]->setPosition(bat2PosV);

	bat1Pos = (float*)(transforms[0]);
	bat2Pos = (float*)(transforms[1]);
	float* ballPos = (float*)(transforms[2]);
	Vector2 newBallPos = Vector2(ballPos[6], ballPos[7]);
	Vector2 newBat1Pos = Vector2(bat1Pos[6], bat1Pos[7]) - Vector2(16, 64);
	Vector2 newBat2Pos = Vector2(bat2Pos[6], bat2Pos[7]) - Vector2(16, 64);

	Vector2 ballVel = *ballDir * ballMoveSpeed * deltaTime;
	//newBallPos += ballVel;

	if (newBallPos.intersects(newBallPos - Vector2(16, 16), Vector2(16, 16), newBat1Pos, Vector2(16, 64)))
	{
		ballDir->x *= -1.0f;
		newBallPos.x += 8;
		ballMoveSpeed = ballMoveSpeed * 1.05f;
	}
	else if (newBallPos.intersects(newBallPos - Vector2(16, 16), Vector2(16, 16), newBat2Pos, Vector2(16, 64)))
	{
		ballDir->x *= -1;
		newBallPos.x -= 8;
		ballMoveSpeed = ballMoveSpeed * 1.05f;
	}

	if (newBallPos.x < 0 + 16)
	{
		std::cout << "Score" << std::endl;
		//resetBall();
		newBallPos = Vector2(624, (720 / 2) - 16);
		//score[1]++;
	}
	else if (newBallPos.x > 1280 - 16)
	{
		resetBall();
		newBallPos = Vector2((1280 / 2) - 16, (720 / 2) - 16);
		score[0]++;
	}

	if (newBallPos.y < 0 + 16)
	{
		newBallPos.y = 16;
		ballDir->y *= -1;
	}
	else if (newBallPos.y > 720 - 16)
	{
		newBallPos.y = 720 - 16;
		ballDir->y *= -1;
	}

	std::cout << newBallPos.toString() << std::endl;
	transforms[2]->setPosition(newBallPos);

	return true;
}

void Application2D::draw() 
{
	clearScreen();

	m_spriteBatch->begin();

	/*m_spriteBatch->drawSpriteTransformed3x3(m_bat1, (float*)transforms[0]);
	m_spriteBatch->drawSpriteTransformed3x3(m_bat2, (float*)transforms[1]);*/
	m_spriteBatch->drawSpriteTransformed3x3(m_ball, (float*)transforms[2]->transpose());

	//m_spriteBatch->drawSprite(numbers[score[0]], 128, 624, 64, 64);
	//m_spriteBatch->drawSprite(numbers[score[0]], 1152, 624, 64, 64);

	//m_spriteBatch->drawSpriteTransformed3x3(m_bat1, (float*)child);

	m_spriteBatch->end();
}

void Application2D::resetBall()
{
	std::cout << "Reset Ball" << std::endl;
	ballMoveSpeed = 400;
	ballDir->x = (rand() % 100 + 50) * (rand() % 2 ? 1 : -1);
	ballDir->y = ((rand() % 25) + 50) * (rand() % 2 ? 1 : -1);
	ballDir->normalise();
}


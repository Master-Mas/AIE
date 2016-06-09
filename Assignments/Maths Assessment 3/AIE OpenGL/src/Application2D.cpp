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
	m_shield = new Texture("./bin/textures/shield.png");

	inFile.open("loadgame.txt");

	if (inFile.good())
	{
		load();
	}
	else
	{
		transform1 = new Matrix3();
		transform1->setScale(Vector2(0.25f, 0.25f));
		transform1->setPosition(Vector2(32, (720 / 2) - 64));

		transform2 = new Matrix3();
		transform2->setScale(Vector2(0.25f, 0.25f));
		transform2->setPosition(Vector2(1280 - 32, (720 / 2) - 64));

		transform3 = new Matrix3();
		transform3->setPosition(Vector2((1280 / 2) - 16, (720 / 2) - 16));

		transform4 = new Matrix3();
		transform4->setScale(Vector2(0.5f, 0.5f));
		transform4->setPosition(Vector2(0, 10));
		transform4->addParent(transform3);
	}

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
	save();

	delete m_spriteBatch;

	delete m_bat1;
	delete m_bat2;
	delete m_ball;
	delete m_shield;

	delete font;
	delete transform1;
	delete transform2;
	delete transform3;
	delete transform4;

	delete ballDir;

	destroyWindow();
}

bool Application2D::update(float deltaTime)
{
	if (!lifecycleTick)
	{
		lifecycleTick = true;
		deltaTime = 0;
	}

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

	float* bat1Pos = (float*)transform1;
	float* bat2Pos = (float*)transform2;
	float* ballPos = (float*)transform3;

	Matrix3 rotation = Matrix3();
	rotation.setRotateZ(4.5f * deltaTime);
	*transform3 *= rotation;

	rotation = Matrix3();
	rotation.setRotateZ(10.0f * deltaTime);
	//*transform4 *= rotation;

	transform1->setPosition(bat1Pos[6] + velBat1.x, bat1Pos[7] + velBat1.y);
	transform2->setPosition(bat2Pos[6] + velBat2.x, bat2Pos[7] + velBat2.y);

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

	transform1->setPosition(bat1PosV);
	transform2->setPosition(bat2PosV);

	bat1Pos = (float*)(transform1->getGlobal());
	bat2Pos = (float*)(transform2->getGlobal());
	ballPos = (float*)(transform3->getGlobal());
	Vector2 newBallPos = Vector2(ballPos[6], ballPos[7]);
	Vector2 newBat1Pos = Vector2(bat1Pos[6], bat1Pos[7]) - Vector2(16, 64);
	Vector2 newBat2Pos = Vector2(bat2Pos[6], bat2Pos[7]) - Vector2(16, 64);

	Vector2 ballVel = *ballDir * ballMoveSpeed * deltaTime;
	newBallPos += ballVel;

	if (newBallPos.intersects(newBallPos - Vector2(16, 16), Vector2(16, 16), newBat1Pos, Vector2(140 * 0.25f, 520 * 0.25f)))
	{
		ballDir->x *= -1.0f;
		newBallPos.x += 8;
		ballMoveSpeed = ballMoveSpeed * 1.05f;
	}
	else if (newBallPos.intersects(newBallPos - Vector2(16, 16), Vector2(16, 16), newBat2Pos, Vector2(140 * 0.25f, 520 * 0.25f)))
	{
		ballDir->x *= -1;
		newBallPos.x -= 8;
		ballMoveSpeed = ballMoveSpeed * 1.05f;
	}

	if (newBallPos.x < 0 + 16)
	{
		std::cout << "Score" << std::endl;
		std::cout << newBallPos.x;
		resetBall();
		newBallPos = Vector2((1280 / 2) - 16, (720 / 2) - 16);
		score[1]++;
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

	transform3->setPosition(newBallPos);

	return true;
}

void Application2D::draw() {

	clearScreen();

	m_spriteBatch->begin();

	m_spriteBatch->setSpriteColor(1, 1, 1, 1);
	m_spriteBatch->drawSpriteTransformed3x3(m_bat1, (float*)transform1);
	m_spriteBatch->drawSpriteTransformed3x3(m_bat2, (float*)transform2);
	m_spriteBatch->drawSpriteTransformed3x3(m_ball, (float*)transform3);
	Matrix3* transfrom4Temp = transform4->getGlobal();
	m_spriteBatch->drawSpriteTransformed3x3(m_shield, (float*)transfrom4Temp);
	delete transfrom4Temp;

	m_spriteBatch->setSpriteColor(222.0f / 255, 16.0f / 255, 16.0f / 255, 1);
	m_spriteBatch->drawSprite(numbers[score[0]], 128, 624, 64, 64);
	m_spriteBatch->setSpriteColor(30.0f / 255, 167.0f / 255, 255.0f / 255, 1);
	m_spriteBatch->drawSprite(numbers[score[1]], 1152, 624, 64, 64);

	m_spriteBatch->end();
}

void Application2D::save()
{
	std::fstream file;

	file.open("loadgame.txt", std::ios_base::out);

	float* data = (float*)transform1;
	for (int i = 0; i < 9; ++i)
	{
		file << data[i] << "\n";
	}

	data = (float*)transform2;
	for (int i = 0; i < 9; ++i)
	{
		file << data[i] << "\n";
	}

	data = (float*)transform3;
	for (int i = 0; i < 9; ++i)
	{
		file << data[i] << "\n";
	}

	data = (float*)transform4;
	for (int i = 0; i < 9; ++i)
	{
		file << data[i] << "\n";
	}

	file << score[0] << "\n";
	file << score[1] << "\n";

	file.close();
}

void Application2D::load()
{
	float data[9] = { 0,0,0,0,0,0,0,0,0 };
	int index = 1;
	int subIndex = 0;

	std::string str;
	while (std::getline(inFile, str))
	{
		data[subIndex] = stof(str);

		if (index % 9 == 0)
		{
			switch (index / 8)
			{
			case 1:
				transform1 = new Matrix3(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
				break;
			case 2:
				transform2 = new Matrix3(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
				break;
			case 3:
				transform3 = new Matrix3(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
				break;
			case 4:
				transform4 = new Matrix3(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
				transform4->addParent(transform3);
				break;
			}

			subIndex = 0;
		}
		else
		{
			subIndex++;
		}

		if (index >= 36)
		{
			break;
		}

		index++;
	}
}

void Application2D::resetBall()
{
	ballMoveSpeed = 400;
	ballDir->x = (rand() % 100 + 1) * (rand() % 2 ? 1 : -1);
	ballDir->y = ((rand() % 25) + 50) * (rand() % 2 ? 1 : -1);
	ballDir->normalise();
}

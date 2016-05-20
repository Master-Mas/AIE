#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include <iostream>

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{
	/*for (int i = 0; i < 3; ++i)
	{
		delete transforms[i];
	}*/
}

bool Application2D::startup() 
{
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_ball = new Texture("./bin/textures/ball.png");
	m_bat1 = new Texture("./bin/textures/bat1.png");
	m_bat2 = new Texture("./bin/textures/bat2.png");

	transforms = new Matrix3[3];

	transforms[0] = Matrix3();
	transforms[0].setScale(1, 1);
	transforms[0].setPosition(Vector2(100, 100));

	/*transforms[1] = Matrix3();
	transforms[1].setPosition(Vector2(1280 - 32, (720 / 2) - 32));

	transforms[2] = Matrix3();
	transforms[2].setPosition(Vector2(0, (720 / 2) - 32));*/

	return true;
}

void Application2D::shutdown() 
{
	delete m_spriteBatch;

	delete m_bat1;
	delete m_bat2;
	delete m_ball;

	delete[] transforms;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	Vector2 vel = Vector2();

	if (isKeyPressed(GLFW_KEY_A))
	{
		vel.x -= 50 * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_D))
	{
		vel.x += 50 * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_W))
	{
		vel.y += 50 * deltaTime;
	}

	if (isKeyPressed(GLFW_KEY_S))
	{
		vel.y -= 50 * deltaTime;
	}

	std::cout << vel.toString() << std::endl;

	/*float* matrixData = (float*)matrix;
	matrix->setPosition(Vector2(matrixData[6], matrixData[7]) + vel);*/

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	m_spriteBatch->drawSpriteTransformed3x3(m_bat1, (float*)transforms[0]);
	/*m_spriteBatch->drawSpriteTransformed3x3(m_bat2, (float*)transforms[1]);
	m_spriteBatch->drawSpriteTransformed3x3(m_ball, (float*)transforms[2]);*/

	// done drawing sprites
	m_spriteBatch->end();
}
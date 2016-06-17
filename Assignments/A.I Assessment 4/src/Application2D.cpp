#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

Application2D::Application2D() {

}

Application2D::~Application2D() 
{

}

bool Application2D::startup() 
{
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	//m_texture = new Texture("./bin/textures/crate.png");

	//m_font = new Font("./bin/font/consolas.ttf", 32);

	return true;
}

void Application2D::shutdown() 
{

	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) 
{
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	m_spriteBatch->end();	
}
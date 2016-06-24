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
	textureManager = new TextureManager();

	int xSize = 39;
	int yize = 22;
	int spacing = 32;
	float scale = 0.5f;
	for (int i = 0; i < (yize * xSize); i++)
	{
		GameObject* obj = new Node();
		obj->setTexture(textureManager->getTexture(0));
		obj->getTransform()->setScale(glm::vec2(scale, scale));
		obj->getTransform()->setPosition(glm::vec2(spacing * ((i % xSize) + 1), spacing * ((i / xSize) + 1)));
		objects.push_back(obj);
	}

	return true;
}

void Application2D::shutdown() 
{


	delete textureManager;
	delete m_spriteBatch;

	destroyWindow();
}

int index = 0;
int textureID = 1;

bool Application2D::update(float deltaTime) 
{
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;


	/*if (index == objects.size())
	{
		index = 0;
		textureID++;
		if (textureID == 3)
		{
			textureID = 0;
		}
	}*/
	int counter = 0;
	for each(GameObject* obj in objects)
	{
		/*if (counter == index) 
		{
			obj->setTexture(textureManager->getTexture(textureID));
		}*/
		obj->update(deltaTime);
		counter++;
	}

	//index++;

	return true;
}

void Application2D::draw() {

	clearScreen();

	m_spriteBatch->begin();
	for each(GameObject* obj in objects)
	{
		obj->draw(m_spriteBatch);
	}
	m_spriteBatch->end();	
}
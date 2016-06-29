#include "Application2D.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <algorithm>
#include <time.h>

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

	
	for (int i = 0; i < (ySize * xSize); i++)
	{
		GameObject* obj = new GameObject();
		obj->setTexture(textureManager->getTexture(0));
		obj->getTransform()->setScale(glm::vec2(scale, scale));
		obj->getTransform()->setPosition(glm::vec2(spacing * ((i % xSize) + 1), spacing * ((i / xSize) + 1)));

		nodePoints.push_back(obj);
		objects.push_back(obj);
	}

	srand(time(NULL));

	glm::vec2 start = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);
	glm::vec2 goal = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);

	std::list<GameObject*>::iterator it = nodePoints.begin();
	std::advance(it, start.x + (start.y * xSize));

	(*it)->setTexture(textureManager->getTexture(1));

	it = nodePoints.begin();
	std::advance(it, goal.x + (goal.y * xSize));

	(*it)->setTexture(textureManager->getTexture(2));

	astar(new Node(start), new Node(goal));

	return true;
}

void Application2D::astar(Node* start, Node* goal)
{
	std::vector<Node*> closed;
	std::vector<Node*> open;
	open.push_back(start);

	while (open.size() > 0)
	{
		Node* current = open[0];
		for (int i = 0; i < open.size(); i++) 
		{
			if (open[i]->fScore < current->fScore)
			{
				current = open[i];
			}
		}

		if (current->pos == goal->pos)
		{
			return reconstructPath(current);
		}

		open.erase(std::remove(open.begin(), open.end(), current), open.end());
		closed.push_back(current);

		for (int i = 0; i < 8; i++)
		{
			glm::vec2 pos = glm::vec2(current->pos.x + (i % 3), current->pos.y + (int)(i / 3));
			//auto point = nodePoints.find(pos);
			if (/*point != nodePoints.end()*/true)
			{
				bool markContinue = false;
				for (int ii = 0; ii < closed.size(); i++)
				{
					if (closed[ii]->pos == pos)
					{
						markContinue = true;
						break;
					}
				}

				if (markContinue)
				{
					continue;
				}

				int localDistance;
				if (i == 0 || i == 2 || i == 6 || i == 8)
				{
					localDistance = 14;
				}
				else
				{
					localDistance = 10;
				}
				int gScore = current->gScore + localDistance;

				markContinue = false;
				for (int ii = 0; ii < closed.size(); i++)
				{
					if (open[ii]->pos == pos)
					{
						markContinue = true;
						break;
					}
				}

				Node* temp;
				if (!markContinue)
				{
					open.push_back(temp = new Node(pos));
				}
				else if(gScore >= current->gScore)
				{
					continue;
				}

				temp->gScore = gScore;
				temp->parent = current;
				temp->fScore = gScore + (abs(pos.x - goal->pos.x) + abs(pos.y - goal->pos.y));
			}
		}
	}
}

void Application2D::reconstructPath(Node * fromPoint)
{
	Node* currentPoint = fromPoint;
	while (currentPoint->parent != nullptr)
	{
		for (std::list<GameObject*>::iterator it = nodePoints.begin(); it != nodePoints.end(); it++)
		{
			if ((*it)->getTransform()->getPosition() == glm::vec2(currentPoint->pos.x * spacing, currentPoint->pos.x * spacing))
			{
				(*it)->setTexture(textureManager->getTexture(1));
				currentPoint = currentPoint->parent;
				break;
			}
		}
	}
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
	}
	int counter = 0;*/
	for each(GameObject* obj in objects)
	{
		/*if (counter == index) 
		{
			obj->setTexture(textureManager->getTexture(textureID));
		}*/
		obj->update(deltaTime);
		//counter++;
	}

	//index++;

	std::cout << deltaTime << "\n";

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
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

	xSize = (int)(1280 / spacing);
	ySize = (int)(720 / spacing);

	pathFinding = new PathFinding(&nodePoints, xSize, ySize);

	srand(time(NULL));

	std::vector<GridPoint*>* currentXRow;
	for (int i = 0; i < (ySize * xSize); i++)
	{
		if (i % xSize == 0)
		{
			currentXRow = new std::vector<GridPoint*>();
			nodePoints.insert(std::pair<int, std::vector<GridPoint*>*>((int)i / xSize, currentXRow));
		}

		GridPoint* obj = new GridPoint(glm::vec2(spacing * ((i % xSize) + 1), spacing * ((i / xSize) + 1)));
		obj->setTexture(textureManager->getTexture(0));
		obj->getTransform()->setScale(glm::vec2(scale, scale));
		obj->gridPos = glm::vec2(i % xSize, (int)i / xSize);
		obj->walkable = rand() % 5 == 0 ? false : true;
		if (!obj->walkable)
		{
			obj->setTexture(textureManager->getTexture(2));
		}

		objects.push_back(obj);
		currentXRow->push_back(obj);
	}

	glm::vec2 start = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);
	glm::vec2 goal = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);

	std::vector<GridPoint*>* array = nodePoints.find((int)start.y - 1)->second;
	GridPoint* startNode = array->at((int)start.x - 1);
	startNode->walkable = true;
	startNode->setTexture(textureManager->getTexture(4));
	player = startNode;

	array = nodePoints.find((int)goal.y - 1)->second;
	GridPoint* goalNode = array->at((int)goal.x - 1);
	goalNode->walkable = true;
	goalNode->setTexture(textureManager->getTexture(1));
	target = goalNode;

	astar(startNode, goalNode);

	return true;
}

void Application2D::astar(GridPoint* start, GridPoint* goal)
{
	reconstructPath(pathFinding->findPath(start, goal));
}

void Application2D::reconstructPath(Node * fromPoint)
{
	if (fromPoint == nullptr)
	{
		return;
	}
	Node* currentPoint = fromPoint;
	while (currentPoint->parent != nullptr)
	{
		currentPoint->gameObject->setTexture(textureManager->getTexture(1));
		currentPoint = currentPoint->parent;
		if (currentPoint->parent != nullptr)
		{
			nextPos = currentPoint->gameObject;
		}
	}
}

void Application2D::clearPathFinding()
{
	for (int i = 0; i < ySize; i++)
	{
		for (int ii = 0; ii < xSize; ii++)
		{
			GridPoint* location = nodePoints.find(i)->second->at(ii);
			if (location->walkable && location != player)
			{
				location->setTexture(textureManager->getTexture(0));
			}
		}
	}
}

void Application2D::moveTarget() 
{
	glm::vec2 avoid = player->getTransform()->getPosition() - target->getTransform()->getPosition();
	avoid = glm::normalize(avoid);

	if (avoid.x > -0.5 && avoid.x < 0.5)
	{
		avoid.x = 0;
	} 
	else if (avoid.x <= -0.5)
	{
		avoid.x = -1;
	}
	else
	{
		avoid.x = 1;
	}

	if (avoid.y > -0.5 && avoid.y < 0.5)
	{
		avoid.y = 0;
	}
	else if (avoid.y <= -0.5)
	{
		avoid.y = -1;
	}
	else
	{
		avoid.y = 1;
	}

	std::vector<GridPoint*> possibleMoves;
	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			int xCoord = target->gridPos.x + x;
			int yCoord = target->gridPos.y + y;

			if (xCoord <= -1 || xCoord >= xSize || yCoord <= -1 || yCoord >= ySize || (x == 1 && y == 1))
			{
				continue;
			}

			/*if (x == (int)avoid.x && y == (int)avoid.y)
			{
				continue;
			}*/

			if (nodePoints.find(yCoord)->second->at(xCoord)->walkable && nodePoints.find(yCoord)->second->at(xCoord)->getTexture() == textureManager->getTexture(0))
			{
				possibleMoves.push_back(nodePoints.find(yCoord)->second->at(xCoord));
			}
		}
	}

	if (possibleMoves.size() >= 0)
	{
		int random = rand();
		if (random == 0)
		{
			return;
		}
		target = possibleMoves.at(random % possibleMoves.size());
		target->setTexture(textureManager->getTexture(1));
	}
	
}

void Application2D::shutdown() 
{
	delete textureManager;
	delete m_spriteBatch;

	destroyWindow();
}

float elapsedTime = 0;
bool trigger = false;

bool Application2D::update(float deltaTime) 
{
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	elapsedTime += deltaTime;

	for each(GameObject* obj in objects)
	{
		obj->update(deltaTime);
	}

	if (elapsedTime >= 0.25)
	{
		elapsedTime = 0;
		trigger = true;
		if (nextPos != nullptr)
		{
			moveTarget();
		}

		clearPathFinding();
		player->setTexture(textureManager->getTexture(0));
		player = nextPos;
		player->setTexture(textureManager->getTexture(4));
		astar(player, target);
	}

	if (elapsedTime >= 1.0)
	{

		elapsedTime = 0;
		trigger = false;
	}


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
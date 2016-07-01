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

	std::vector<GridPoint*>* currentXRow;

	srand(time(NULL));

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
		obj->walkable = rand() % 10 == 0 ? false : true;
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
	startNode->setTexture(textureManager->getTexture(1));

	array = nodePoints.find((int)goal.y - 1)->second;
	GridPoint* goalNode = array->at((int)goal.x - 1);
	goalNode->walkable = true;
	goalNode->setTexture(textureManager->getTexture(1));
	astar(startNode, goalNode);

	return true;
}

void Application2D::astar(GridPoint* start, GridPoint* goal)
{
	std::vector<Node*> closed;
	std::vector<Node*> open;

	Node*** nodeCalcPoints = new Node**[ySize];
	for (int i = 0; i < ySize; ++i)
	{
		nodeCalcPoints[i] = new Node*[xSize];
	}

	for (int i = 0; i < ySize; ++i)
	{
		for (int ii = 0; ii < xSize; ++ii)
		{
			nodeCalcPoints[i][ii] = new Node(nodePoints.find(i)->second->at(ii));
		}
	}

	Node* goalNode = nodeCalcPoints[(int)goal->gridPos.y][(int)goal->gridPos.x];
	open.push_back(nodeCalcPoints[(int)start->gridPos.y][(int)start->gridPos.x]);

	std::cout << "Start Walkable" << open.at(0)->gameObject->walkable << "\n";
	std::cout << "Start Walkable" << goalNode->gameObject->walkable << "\n";

	while (open.size() > 0)
	{
		Node* current = open.at(0);
		for (int i = 0; i < open.size(); i++) 
		{
			std::cout << "IT: " << i << std::endl;
			if (open.at(i)->calcFScore() < current->calcFScore())
			{
				current = open[i];
			}
		}

		open.erase(std::remove(open.begin(), open.end(), current));
		closed.push_back(current);

		if (goalNode == current)
		{
			std::cout << "Found Path" << std::endl;
			reconstructPath(current);
			std::cout << "Found Path" << std::endl;

			for (int i = 0; i < ySize; ++i)
			{
				for (int ii = 0; ii < xSize; ++ii)
				{
					delete nodeCalcPoints[i][ii];
				}
				delete[] nodeCalcPoints[i];
			}
			delete[] nodeCalcPoints;

			return;
		}

		for (int y = -1; y < 2; y++)
		{
			for (int x = -1; x < 2; x++)
			{
				/*if (
					(x == -1 && y == -1) ||
					(x == -1 && y == 1) ||
					(x == 1 && y == -1) ||
					(x == 1 && y == 1)
					)
				{
					continue;
				}*/

				int yCoord = current->gameObject->gridPos.y + y;
				int xCoord = current->gameObject->gridPos.x + x;

				if (xCoord <= -1 || xCoord >= xSize || yCoord <= -1 || yCoord >= ySize || (yCoord == 1 && xCoord == 1))
				{
					continue;
				}

				Node* neighbour = nodeCalcPoints[yCoord][xCoord];

				if (!neighbour->gameObject->walkable)
				{
					continue;
				}

				if (std::find(closed.begin(), closed.end(), neighbour) != closed.end())
				{
					continue;
				}

				int moveCostToNeighbour = current->gScore + nodeDistance(current, neighbour);
				if (moveCostToNeighbour < neighbour->gScore || std::find(open.begin(), open.end(), neighbour) == open.end())
				{
					neighbour->gScore = moveCostToNeighbour;

					neighbour->hScore = nodeDistance(neighbour, goalNode);
					neighbour->parent = current;

					if (std::find(open.begin(), open.end(), neighbour) == open.end())
					{
						open.push_back(neighbour);
					}
				}
			}
		}
	}
}

void Application2D::reconstructPath(Node * fromPoint)
{
	Node* currentPoint = fromPoint;
	while (currentPoint->parent != nullptr)
	{
		currentPoint->gameObject->setTexture(textureManager->getTexture(1));
		currentPoint = currentPoint->parent;
	}
}

int Application2D::nodeDistance(Node * start, Node * goal)
{
	int dstX = abs(start->gameObject->gridPos.x - goal->gameObject->gridPos.x);
	int dstY = abs(start->gameObject->gridPos.y - goal->gameObject->gridPos.y);
	int dst;

	if (dstX > dstY)
	{
		dst = 14 * dstY + 10 * (dstX - dstY);
	}
	else
	{
		dst = 14 * dstX + 10 * (dstY - dstX);
	}

	return dst;
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

	for each(GameObject* obj in objects)
	{
		obj->update(deltaTime);
	}

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
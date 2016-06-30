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

		objects.push_back(obj);
		currentXRow->push_back(obj);
	}

	srand(time(NULL));

	glm::vec2 start = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);
	glm::vec2 goal = glm::vec2((int)(rand() % xSize) + 1, (int)(rand() % ySize) + 1);

	std::vector<GridPoint*>* array = nodePoints.find((int)start.y - 1)->second;
	GridPoint* startNode = array->at((int)start.x - 1);
	startNode->setTexture(textureManager->getTexture(1));

	array = nodePoints.find((int)goal.y - 1)->second;
	GridPoint* goalNode = array->at((int)goal.x - 1);
	goalNode->setTexture(textureManager->getTexture(2));
	astar(startNode, goalNode);

	return true;
}

void Application2D::astar(GridPoint* start, GridPoint* goal)
{
	std::vector<Node*> closed;
	std::vector<Node*> open;
	open.push_back(new Node(start));

	while (open.size() > 0)
	{
		Node* current = open[0];
		for (int i = 0; i < open.size(); i++) 
		{
			if (open[i]->calcFScore() < current->calcFScore())
			{
				current = open[i];
			}
		}

		open.erase(std::remove(open.begin(), open.end(), current));
		closed.push_back(current);

		if (goal == current->gameObject)
		{
			std::cout << "Found Path" << std::endl;
			reconstructPath(current);
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int yFinder = current->gameObject->gridPos.y + (i <= 2 ? -1 : i <= 5 ? 0 : 1);
			int xFinder = current->gameObject->gridPos.x + (i % 3 == 0 ? -1 : i % 3 == 1 ? 0 : 1);

			if (yFinder <= -1 || yFinder >= ySize || xFinder <= -1 || xFinder >= xSize)
			{
				continue;
			}

			GridPoint* point = nodePoints.find(yFinder)->second->at(xFinder);
			Node* neighbour = new Node(point);
			if (!point->walkable)
			{
				delete neighbour;
				continue;
			}

			for (int i = 0; i < closed.size(); ++i)
			{
				if (closed.at(i) == neighbour)
				{
					closed.erase(std::remove(closed.begin(), closed.end(), closed.at(i)));
				}
			}

			int dstX = abs(current->gameObject->gridPos.x - point->gridPos.x);
			int dstY = abs(current->gameObject->gridPos.y - point->gridPos.y);
			int dst;
			if (dstX > dstY)
			{
				dst = 14 * dstY + 10 * (dstX - dstY);
			}
			else
			{
				dst = 14 * dstX + 10 * (dstY - dstX);
			}

			int moveCostToNeighbour = current->gScore + dst;
			if (moveCostToNeighbour < neighbour->gScore || std::find(open.begin(), open.end(), neighbour) == open.begin())
			{
				neighbour->gScore = moveCostToNeighbour;

				int dstXGoal = abs(point->gridPos.x - goal->gridPos.x);
				int dstYGoal = abs(point->gridPos.y - goal->gridPos.y);
				int dstGoal;

				if (dstXGoal > dstYGoal)
				{
					dstGoal = 14 * dstY + 10 * (dstXGoal - dstYGoal);
				}
				else
				{
					dstGoal = 14 * dstXGoal + 10 * (dstYGoal - dstXGoal);
				}

				neighbour->hScore = dstGoal;
				neighbour->parent = current;

				if (std::find(open.begin(), open.end(), neighbour) == open.end())
				{
					open.push_back(neighbour);
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
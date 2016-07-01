#include "PathFinding.h"

PathFinding::PathFinding(std::map<int, std::vector<GridPoint*>*>* gridPoints, int widthUnits, int heightUnits)
{
	m_widthUnits = widthUnits;
	m_heightUnits = heightUnits;
	m_gridPoints = gridPoints;
}

PathFinding::~PathFinding()
{
}

Node * PathFinding::findPath(GridPoint * start, GridPoint * target)
{
	std::vector<Node*> closed;
	std::vector<Node*> open;

	Node*** nodeCalcPoints = new Node**[m_heightUnits];
	for (int i = 0; i < m_heightUnits; ++i)
	{
		nodeCalcPoints[i] = new Node*[m_widthUnits];
	}

	for (int i = 0; i < m_heightUnits; ++i)
	{
		for (int ii = 0; ii < m_widthUnits; ++ii)
		{
			nodeCalcPoints[i][ii] = new Node(m_gridPoints->find(i)->second->at(ii));
		}
	}

	Node* goalNode = nodeCalcPoints[(int)target->gridPos.y][(int)target->gridPos.x];
	open.push_back(nodeCalcPoints[(int)start->gridPos.y][(int)start->gridPos.x]);

	while (open.size() > 0)
	{
		Node* current = open.at(0);
		for (int i = 0; i < open.size(); i++)
		{
			if (open.at(i)->calcFScore() < current->calcFScore())
			{
				current = open.at(i);
			}
		}

		open.erase(std::remove(open.begin(), open.end(), current));
		closed.push_back(current);

		if (goalNode == current)
		{
			Node* finalNode = current->cloneStack();

			for (int i = 0; i < m_heightUnits; ++i)
			{
				for (int ii = 0; ii < m_widthUnits; ++ii)
				{
					delete nodeCalcPoints[i][ii];
				}
				delete[] nodeCalcPoints[i];
			}
			delete[] nodeCalcPoints;

			return finalNode;
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

				if (xCoord <= -1 || xCoord >= m_widthUnits || yCoord <= -1 || yCoord >= m_heightUnits || (y == 1 && x == 1))
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

int PathFinding::nodeDistance(Node * start, Node * goal)
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

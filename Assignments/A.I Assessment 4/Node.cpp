#include "Node.h"

Node::Node()
{
}

Node::Node(GridPoint * node)
{
	gameObject = node;
}


Node::~Node()
{
}

bool Node::operator==(const Node * nodeCalc)
{
	if (nodeCalc->gScore == gScore)
	{
		if(nodeCalc->hScore == hScore)
		{
			if (nodeCalc->gameObject->gridPos.x == gameObject->gridPos.x && nodeCalc->gameObject->gridPos.y == gameObject->gridPos.y)
			{
				return true;
			}
		}
	}

	return false;
}

int Node::calcFScore()
{
	return gScore + hScore;
}

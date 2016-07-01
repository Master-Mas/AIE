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

Node * Node::cloneStack()
{
	Node* finalNode = new Node(gameObject);

	Node* settingNode = finalNode;
	Node* location = this;

	while (true)
	{
		if (location->parent == nullptr)
		{
			return finalNode;
		}
		settingNode->parent = new Node(location->parent->gameObject);
		settingNode = settingNode->parent;
		location = location->parent;
	}

	return nullptr;
}

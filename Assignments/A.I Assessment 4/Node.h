#pragma once
#include "GridPoint.h"

struct Node
{
public:
	Node();
	Node(GridPoint* node);
	~Node();

	float hScore = 0;
	float gScore = 0;

	Node* parent = nullptr;
	GridPoint* gameObject = nullptr;

	bool operator==(const Node*);

	int calcFScore();
};


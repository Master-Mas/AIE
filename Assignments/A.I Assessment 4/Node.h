#pragma once
#include "GameObject.h"
class Node :
	public GameObject
{
public:
	Node();
	~Node();

private:
	Node * parent;
	Node * origin;

	int degreeOfSeporation;
	float gScore;
	float hScore;
	float fScore;
};


#pragma once
#include <glm/vec2.hpp>
struct Node
{
public:
	Node(glm::vec2 vec);
	~Node();

public:
	glm::vec2 pos;

	float gScore = 0;
	float hScore = 0;
	float fScore = 0;

	Node* parent = nullptr;
};


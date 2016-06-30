#pragma once
#include <glm/vec2.hpp>
#include "GameObject.h"
class GridPoint : public GameObject
{
public:
	GridPoint(glm::vec2 position);
	~GridPoint();

public:
	bool walkable = true;
	glm::vec2 gridPos;
};


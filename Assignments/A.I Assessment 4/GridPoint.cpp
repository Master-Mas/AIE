#include "GridPoint.h"

GridPoint::GridPoint(glm::vec2 vec)
{
	getTransform()->setPosition(vec);
}

GridPoint::~GridPoint()
{
}

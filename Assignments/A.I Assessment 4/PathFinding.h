#pragma once

#include "GridPoint.h"
#include "Node.h"
#include <map>
#include <vector>
#include <algorithm>

class PathFinding
{
public:
	PathFinding(std::map<int, std::vector<GridPoint*>*>* gridPoints, int widthUnits, int heightUnits);
	~PathFinding();

	Node* findPath(GridPoint* start, GridPoint* target);
	int nodeDistance(Node * start, Node * goal);

private:
	int m_widthUnits = 0;
	int m_heightUnits = 0;
	std::map<int, std::vector<GridPoint*>*>* m_gridPoints;
};


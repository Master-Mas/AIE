#pragma once

#include <vector>
#include <list>
#include <memory>

#include "BaseApplication.h"
#include "../TextureManager.h"
#include "../GameObject.h"
#include "../GridPoint.h"
#include "../Node.h"
#include "../PathFinding.h"

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	void moveTarget();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	void astar(GridPoint* start, GridPoint* goal);
	void reconstructPath(Node * fromPoint);

protected:
	SpriteBatch* m_spriteBatch;
	TextureManager* textureManager;

private:
	std::vector<GameObject*> objects;
	std::map<int, std::vector<GridPoint*>*> nodePoints;

	int xSize = 0;
	int ySize = 0;
	int spacing = 8;
	float scale = 0.25f;

	GridPoint* target;
	GridPoint* player;
	GridPoint* nextPos;

	PathFinding* pathFinding;

	void clearPathFinding();
};

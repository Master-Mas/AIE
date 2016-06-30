#pragma once

#include <vector>
#include <list>
#include <memory>

#include "BaseApplication.h"
#include "../TextureManager.h"
#include "../GameObject.h"
#include "../GridPoint.h"
#include "../Node.h"


class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
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

	int xSize = 19;
	int ySize = 11;
	int spacing = 64;
	float scale = 1.0f;
};

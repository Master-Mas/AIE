#pragma once

#include <vector>
#include <list>

#include "BaseApplication.h"
#include "../TextureManager.h"
#include "../GameObject.h"
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

	void astar(Node* start, Node* goal);
	void reconstructPath(Node* fromPoint);

protected:
	SpriteBatch* m_spriteBatch;
	TextureManager* textureManager;

private:
	std::vector<GameObject*> objects;
	std::list<GameObject*> nodePoints;

	int xSize = 19;
	int ySize = 11;
	int spacing = 64;
	float scale = 1.0f;
};

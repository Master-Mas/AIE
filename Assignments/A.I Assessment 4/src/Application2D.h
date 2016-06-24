#pragma once

#include "BaseApplication.h"
#include "../TextureManager.h"
#include "../GameObject.h"
#include "../Node.h"
#include <vector>

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

protected:
	SpriteBatch* m_spriteBatch;
	TextureManager* textureManager;

private:
	std::vector<GameObject*> objects;
};
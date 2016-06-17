#pragma once

#include "Transform.h"
#include "src/Texture.h"
#include "src/SpriteBatch.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void draw(SpriteBatch * spriteBatch);
	virtual void update(float delta);

	Transform * getTransform();

private:
	Transform transform;
	Texture * texture = nullptr;
};


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

	void setColor(float r, float g, float b);
	void setColor(float r, float g, float b, float a);
	void setAlpha(float a);

	void setTexture(Texture* texture);

	Texture * getTexture();

	bool operator==(GameObject* other);

private:
	Transform transform;
	Texture * texture = nullptr;
	float color[4] = { 1,1,1,1 };
	bool render = true;
};


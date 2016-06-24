#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::draw(SpriteBatch * spriteBatch)
{
	if (texture != nullptr && render)
	{
		spriteBatch->setSpriteColor(color[0], color[1], color[2], color[3]);
		spriteBatch->drawSpriteTransformed3x3(texture, (float*)glm::value_ptr(*(transform.getMatrix())));
	}
}

void GameObject::update(float delta)
{

}

Transform * GameObject::getTransform()
{
	return &transform;
}

void GameObject::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void GameObject::setColor(float r, float g, float b, float a)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
}

void GameObject::setAlpha(float a)
{
	color[3] = a;
}

void GameObject::setTexture(Texture * texture)
{
	this->texture = texture;
}

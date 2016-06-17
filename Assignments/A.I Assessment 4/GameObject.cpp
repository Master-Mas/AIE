#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::draw(SpriteBatch * spriteBatch)
{

	spriteBatch->drawSpriteTransformed3x3(texture, (float*)glm::value_ptr(*(transform.getMatrix())));

}

void GameObject::update(float delta)
{

}

Transform * GameObject::getTransform()
{
	return &transform;
}

#include "Transform.h"

Transform::Transform()
{

}


Transform::~Transform()
{
	for each (Transform* child in children)
	{
		delete child;
	}
}

glm::vec2 Transform::getPosition()
{
	return glm::vec2(matrix[2][0], matrix[2][1]);
}

glm::vec2 Transform::getScale()
{
	return glm::vec2(matrix[0][0], matrix[1][1]);
}

glm::vec2 Transform::getEulerAngles()
{
	return glm::vec2(atan2(matrix[1][2], matrix[2][2]), atan2(matrix[0][1], matrix[0][0]));
}

glm::mat3* Transform::getMatrix()
{
	if (parent != nullptr)
	{
		return &(matrix * *(parent->getMatrix()));
	}
	else
	{
		return &matrix;
	}
}

glm::mat3 * Transform::getLocalMatrix()
{
	return &matrix;
}

void Transform::setPosition(glm::vec2 positionAmount)
{
	matrix[2][0] = positionAmount.x;
	matrix[2][1] = positionAmount.y;
}

void Transform::setScale(glm::vec2 scaleAmount)
{
	matrix[0][0] = scaleAmount.x;
	matrix[1][1] = scaleAmount.y;
}

void Transform::setRotationZ(float rotationAmount)
{
	
}

Transform & Transform::getParent()
{
	return *parent;
}

std::vector<Transform*> Transform::getChildren()
{
	return children;
}

void Transform::setParent(Transform * parent)
{
	this->parent = parent;
}

void Transform::addChild(Transform* child)
{
	children.push_back(child);
}

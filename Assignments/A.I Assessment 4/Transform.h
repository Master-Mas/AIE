#pragma once

#include <glm/vec2.hpp>
#include <glm/mat3x3.hpp>
#include <memory>
#include <vector>
#include <math.h>

class Transform
{
public:
	Transform();
	~Transform();

	glm::vec2 getPosition();
	glm::vec2 getScale();
	glm::vec2 getEulerAngles();
	glm::mat3* getMatrix();
	glm::mat3* getLocalMatrix();

	void setPosition(glm::vec2 positionAmount);
	void setScale(glm::vec2 scaleAmount);
	void setRotationZ(float rotationAmount);

	Transform * getParent();
	std::vector<std::unique_ptr<Transform>> getChildren();

	void setParent(Transform * parent);
	void addChild(std::unique_ptr<Transform> child);
private:
	Transform * parent = nullptr;
	std::vector<std::unique_ptr<Transform>> children;
	glm::mat3 matrix;
};


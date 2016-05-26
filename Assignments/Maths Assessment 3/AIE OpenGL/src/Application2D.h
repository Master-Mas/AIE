#pragma once

#include "BaseApplication.h"
#include "GamesMath.h"

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

private:
	Texture* m_bat1;
	Texture* m_bat2;
	Texture* m_ball;

	Matrix3** transforms;

	float batMoveSpeed = 200;
	float ballMoveSpeed = 400;
	Vector2* ballDir = new Vector2();

	void resetBall();
};
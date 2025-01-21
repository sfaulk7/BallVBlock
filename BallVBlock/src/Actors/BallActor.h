#pragma once
#include "raylib.h"
#include "Engine/Actor.h"

class BallActor : public Actor
{
public:
	BallActor();
	~BallActor();

	bool goingRight;
	bool goingLeft;
	bool goingUp;
	bool goingDown;

	bool collidedOnce = false;
	float Speed = 50;
	void Start();
	void Update(double deltaTime);

	void OnCollision(Actor* other);
private:
	Color m_color = Color(RED);
protected:
};
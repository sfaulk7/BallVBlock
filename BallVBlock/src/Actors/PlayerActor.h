#pragma once
#include "raylib.h"
#include "Engine/Actor.h"

class PlayerActor : public Actor
{
public:
	PlayerActor();
	~PlayerActor();

	float Speed = 50;
	void Start();
	void Update(double deltaTime);
	void End();

	void OnCollision(Actor* other);

private:
	Color m_color = Color(RED);
protected:
};
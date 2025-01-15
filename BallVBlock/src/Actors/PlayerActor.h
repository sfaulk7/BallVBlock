#pragma once
#include "raylib.h"
#include "Engine/Actor.h"

class PlayerActor : public Actor
{
public:
	PlayerActor();
	~PlayerActor();

	float Speed = 50;
	virtual void Update(double deltaTime);
private:
	Color m_color = Color(RED);
protected:
};
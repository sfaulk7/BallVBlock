#pragma once
#include "raylib.h"
#include "Engine/Actor.h"

class Player : public Actor
{
public:
	float Speed = 50;
	virtual void Update(double deltaTime);
private:
	Color m_color = Color(RED);
protected:
};
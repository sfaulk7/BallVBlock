#pragma once
#include "raylib.h"
#include "Actor.h"


class Player : public Actor
{
public:
	float Speed = 50;
	void Update(double deltaTime);
private:
	Color m_color = Color(RED);
protected:

};
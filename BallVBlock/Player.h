#pragma once
#include "raylib.h"

class Actor;

class Player
{
public:
	float Speed = 50;
	virtual void Update(double deltaTime);
private:
	Color m_color = Color(RED);
protected:

};
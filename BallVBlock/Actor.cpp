#include "Actor.h"
#include "Transform2D.h"
#include "math.h"
#include "Vector2.h"

Actor::Actor()
{

}


void Actor::Instantiate(

	Actor actor,
	Transform2D parent = nullptr,
	MathLibrary::Vector2 position = MathLibrary::Vector2(),
	float rotation = 0,
	const char* m_name = "Actor")
{
	
}

void Actor::Destroy(Actor actor)
{
	// Remove all the children
}

void Actor::OnEnable()
{

}

void Actor::OnDisable()
{

}

void Actor::Start()
{

}

void Actor::Update(double deltatime)
{

}

void Actor::End()
{

}

void Actor::OnCollision(Actor other)
{

}
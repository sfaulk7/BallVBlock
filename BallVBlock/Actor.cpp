#include "Actor.h"
#include "Transform2D.h"
#include "math.h"
#include "Vector2.h"

void Actor::Instantiate(

	Actor actor,
	Transform2D parent = null,
	Vector2 position = new Vector2(),
	float rotation = 0,
	const char* m_name = "Actor")
{
	actor.Transform.LocalPosition = position;
	actor.Transform.Rotate(rotation);
	

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
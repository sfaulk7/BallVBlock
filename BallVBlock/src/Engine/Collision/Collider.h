#pragma once
class Actor;
class CircleCollider;
class Collider
{
public:

	Collider(Actor* owner);
	~Collider();

	

	bool CheckCollision(Actor* other);

	virtual bool CheckCollisionCircle(CircleCollider* collider);

	virtual void Draw();

	Actor* Owner;
};

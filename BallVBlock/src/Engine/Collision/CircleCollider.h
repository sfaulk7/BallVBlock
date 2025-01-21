#pragma once
#include "Collider.h"

class Actor;

class CircleCollider : public Collider
{
public:
	~CircleCollider();
	float CollisionRadius;
	CircleCollider(Actor* owner, float radius);
	bool CheckCollisionCircle(CircleCollider* collider);
	void Draw();
	void EnableDraw(bool draw);
private:
	bool m_enableDraw;
};
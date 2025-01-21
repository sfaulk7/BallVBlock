#pragma once
#include "Collider.h"
#include "Vector2.h"

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
	void SetOffset(MathLibrary::Vector2 offset);
private:
	bool m_enableDraw;
	MathLibrary::Vector2 m_offset;
};
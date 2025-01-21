#include "Collider.h"
#include "Engine/Actor.h"
#include "CircleCollider.h"
#include "Engine/Component.h"

Collider::~Collider()
{
}

Collider::Collider(Actor* owner)
{
	Owner = owner;
}

bool Collider::CheckCollision(Actor* other)
{
	if (other->m_collider != nullptr && dynamic_cast<CircleCollider*>(other->m_collider) != nullptr)
		return CheckCollisionCircle(dynamic_cast<CircleCollider*>(other->m_collider));
	return false;
}

bool Collider::CheckCollisionCircle(CircleCollider* collider)
{
	return false;
}

void Collider::Draw()
{
}

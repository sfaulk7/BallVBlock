#include "CircleCollider.h"
#include "Engine/Actor.h"
#include "raylib.h"
#include "Vector2.h"


CircleCollider::~CircleCollider()
{
}

CircleCollider::CircleCollider(Actor* owner, float radius) : Collider::Collider(owner)
{
	CollisionRadius = radius;
	m_offset = { 0, 0 };
}

bool CircleCollider::CheckCollisionCircle(CircleCollider* collider)
{
	float sumRadii = collider->CollisionRadius + CollisionRadius;
	MathLibrary::Vector2 left = { collider->Owner->Transform->GetGlobalPosition() };
	MathLibrary::Vector2 right = { Owner->Transform->GetGlobalPosition() + m_offset };


	float distance = (left - right).getMagnitude();

	return sumRadii >= distance;
}

void CircleCollider::Draw()
{

	if (m_enableDraw)
		DrawCircleLines(Owner->Transform->GetGlobalPosition().x + m_offset.x, Owner->Transform->GetGlobalPosition().y + m_offset.y, CollisionRadius, GREEN);
}

void CircleCollider::EnableDraw(bool draw)
{
	m_enableDraw = draw;
}

void CircleCollider::SetOffset(MathLibrary::Vector2 offset)
{
	m_offset = offset;
}

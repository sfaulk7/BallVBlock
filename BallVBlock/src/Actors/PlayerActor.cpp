#include "PlayerActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Engine/Collision/CircleCollider.h"

PlayerActor::PlayerActor()
{
}

PlayerActor::~PlayerActor()
{
}

void PlayerActor::Start()
{
	Actor::Start();

	m_collider = new CircleCollider(this, 20);
	dynamic_cast<CircleCollider*>(m_collider)->EnableDraw(true);
}

void PlayerActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	// Player Movement
	Vector2* movementInput = new Vector2();
	if (IsKeyDown(KEY_LEFT))
		Transform->Translate(-5, 0);
	if (IsKeyDown(KEY_RIGHT))
		Transform->Translate(5, 0);

	MathLibrary::Vector2 deltaMovement = MathLibrary::Vector2().getNormalized() * Speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		Transform->SetLocalPosition(deltaMovement);

	DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9), 100, 10, m_color);
	m_collider->Draw();
	// Collision
}

void PlayerActor::End()
{
	Actor::End();
}
#include "PlayerActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Engine/Collision/CircleCollider.h"

PlayerActor::PlayerActor()
{
	MathLibrary::Vector2 PlayerSpawn = MathLibrary::Vector2((GetScreenWidth() * .45), (GetScreenHeight() * .9));
	Transform->SetLocalPosition(PlayerSpawn);
}

PlayerActor::~PlayerActor()
{

}

void PlayerActor::Start()
{
	Actor::Start();

	if (Transform->GetLocalPosition().y != (GetScreenHeight() * .9))
	{
		Transform->SetLocalPosition(MathLibrary::Vector2((GetScreenWidth() * .45), (GetScreenHeight() * .9)));
	}

	m_collider = new CircleCollider(this, 50);
	dynamic_cast<CircleCollider*>(m_collider)->SetOffset(MathLibrary::Vector2(50,0));
	dynamic_cast<CircleCollider*>(m_collider)->EnableDraw(true);
}

void PlayerActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	// Player Movement
	Vector2* movementInput = new Vector2();
	if (IsKeyDown(KEY_A) && Transform->GetLocalPosition().x > 5)
		Transform->Translate(-5, 0);
	if (IsKeyDown(KEY_D) && Transform->GetLocalPosition().x < GetScreenWidth() * .86)
		Transform->Translate(5, 0);

	MathLibrary::Vector2 deltaMovement = MathLibrary::Vector2().getNormalized() * Speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		Transform->SetLocalPosition(deltaMovement);


	DrawRectangle(Transform->GetLocalPosition().x, Transform->GetLocalPosition().y, 100, 10, m_color);

	//m_collider->Draw();
	// Collision
}

void PlayerActor::End()
{
	Actor::End();
}

void PlayerActor::OnCollision(Actor* other)
{

}

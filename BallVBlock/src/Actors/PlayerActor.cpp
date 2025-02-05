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

	// Adding the collider to the player
	m_collider = new CircleCollider(this, 55);
	dynamic_cast<CircleCollider*>(m_collider)->SetOffset(MathLibrary::Vector2(50,0));
	dynamic_cast<CircleCollider*>(m_collider)->EnableDraw(true);
}

void PlayerActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	// Player Movement
	MathLibrary::Vector2 movementInput = MathLibrary::Vector2();
	if (IsKeyDown(KEY_A) && Transform->GetLocalPosition().x > 5)
		movementInput.x -= 1;
	if (IsKeyDown(KEY_D) && Transform->GetLocalPosition().x < GetScreenWidth() * .86)
		movementInput.x += 1;

	MathLibrary::Vector2 deltaMovement = movementInput.getNormalized() * Speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		Transform->SetLocalPosition(Transform->GetLocalPosition() + deltaMovement);

	// Drawing the Rectangle
	DrawRectangle(Transform->GetLocalPosition().x, Transform->GetLocalPosition().y, 100, 10, m_color);

	m_collider->Draw();
	// Collision

	DrawText(TextFormat("Score: %i", m_score), 320, 40, 40, YELLOW);
	
}

void PlayerActor::End()
{
	Actor::End();
}

void PlayerActor::OnCollision(Actor* other)
{
	if (other->Transform->GetLocalPosition().y == this->Transform->GetLocalPosition().y)
	{
		m_score += 1;
	}
}

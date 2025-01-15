#include "Player.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>

void Player::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	// Movement
	Vector2 *movementInput = new Vector2();
	if (IsKeyDown(KEY_A))
		Transform->Translate(-5, 0);
	if (IsKeyDown(KEY_S))
		Transform->Translate(5, 0);

	MathLibrary::Vector2 deltaMovement = MathLibrary::Vector2().getNormalized() * Speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		Transform->SetLocalPosition(deltaMovement);

	DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9), 100, 10, m_color);
}
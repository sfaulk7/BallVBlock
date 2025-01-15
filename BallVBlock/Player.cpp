#include "Player.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Actor.h"

void Player::Update(double deltaTime)
{
	base.Update(deltaTime);

	// Movement
	Vector2 movementInput = new Vector2();
	if (IsKeyDown(KEY_A)

	movementInput.x += Raylib.IsKeyDown(KeyboardKey.D);
	Vector2 deltaMovement = movementInput.Normalized * Speed * (float)deltaTime;

	if (deltaMovement.Magnitude != 0)
		Transform.LocalPosition += (deltaMovement);

	Raylib.DrawCircleV(Transform.GlobalPosition, (Transform.GlobalScale.x / 2 * 100), m_color);
}
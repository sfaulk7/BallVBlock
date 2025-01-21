#include "BallActor.h"
#include "PlayerActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Scenes/PlayScene.h"
#include "Engine/Collision/CircleCollider.h"


BallActor::BallActor()
{

}

BallActor::~BallActor()
{

}

void BallActor::Start()
{
	Actor::Start();

	goingRight = true;
	goingLeft = false;
	goingUp = false;
	goingDown = true;

	m_collider = new CircleCollider(this, 10);
	dynamic_cast<CircleCollider*>(m_collider)->EnableDraw(true);
}

void BallActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	// Movement
	//Translate down 5
	if (goingDown == true)
	{
		Transform->Translate(0, 5);
	}
	//Translate up 5
	if (goingUp == true)
	{
		Transform->Translate(0, -5);
	}
	//Translate left 5
	if (goingLeft == true)
	{
		Transform->Translate(-5, 0);
	}
	//Translate right 5
	if (goingRight == true)
	{
		Transform->Translate(5, 0);
	}

	//Direction changes
	//Change From Left to right
	if (Transform->GetLocalPosition().x <= 0)
	{
		goingLeft = false;
		goingRight = true;
		collidedOnce = false;
	}
	//Change From Right to left
	if (Transform->GetLocalPosition().x >= GetScreenWidth())
	{
		goingRight = false;
		goingLeft = true;
		collidedOnce = false;
	}
	//Change From Up to Down
	if (Transform->GetLocalPosition().y <= 0)
	{
		goingUp = false;
		goingDown = true;
		collidedOnce = false;
	}
	//Change From Down to Up
	if (Transform->GetLocalPosition().y == GetScreenHeight() * .9)
	{
		goingDown = false;
		goingUp = true;
	}

	DrawCircle((Transform->GetLocalPosition().x), (Transform->GetLocalPosition().y), 10, m_color);

	m_collider->Draw();
}

void BallActor::OnCollision(Actor* other)
{
	
	if (!(dynamic_cast<BallActor*>(other) != nullptr) && collidedOnce == false)
	{
		Actor::Instantiate(new BallActor(), nullptr, MathLibrary::Vector2(10, 10), 0, "The BallActor");
		collidedOnce = true;
	}
}

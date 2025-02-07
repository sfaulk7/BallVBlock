#include <iostream>
#include "BallActor.h"
#include "PlayerActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Scenes/PlayScene.h"
#include "Engine/Collision/CircleCollider.h"
#include "Game.h"
#include "random"


BallActor::BallActor()
{

}

BallActor::~BallActor()
{

}

void BallActor::Start()
{
	Actor::Start();

	SetEnabled(true);

	goingRight = true;
	goingLeft = false;
	goingUp = false;
	goingDown = true;
	collidedOnce = false;


	m_collider = new CircleCollider(this, 20);
	dynamic_cast<CircleCollider*>(m_collider)->EnableDraw(true);

	int ballSpawnRandom = GetRandomValue(0, GetScreenWidth());
	ballSpawn = MathLibrary::Vector2(ballSpawnRandom, 0);

	ballAngle = GetRandomValue(1, 3);
}

void BallActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	
		// Movement
		//Translate down 5
		if (goingDown == true)
		{
			Transform->Translate(0, 2 + ballAngle);
		}
		//Translate up 5
		if (goingUp == true)
		{
			Transform->Translate(0, -2 - ballAngle);
		}
		//Translate left 5
		if (goingLeft == true)
		{
			Transform->Translate(-7 - ballAngle, 0);
		}
		//Translate right 5
		if (goingRight == true)
		{
			Transform->Translate(7 + ballAngle, 0);
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
		//Delete if goes past player
		if (Transform->GetLocalPosition().y > GetScreenHeight())
		{
			//SetEnabled(false);
			Transform->SetLocalPosition(MathLibrary::Vector2(0, 0));
			Game::GetCurrentScene()->RemoveActor(this);
		
		}

		DrawCircle((Transform->GetLocalPosition().x), (Transform->GetLocalPosition().y), 15, m_color);

		m_collider->Draw();
	
}

void BallActor::OnCollision(Actor* other)
{
	
	if (!(dynamic_cast<BallActor*>(other) != nullptr) && collidedOnce == false && Transform->GetLocalPosition().y == other->Transform->GetLocalPosition().y)
	{
	std::cout << "Collide" << std::endl;
		Actor::Instantiate(new BallActor(), nullptr, ballSpawn, 0, "The BallActor");
		collidedOnce = true;
		goingDown = false;
		goingUp = true;

	}
}

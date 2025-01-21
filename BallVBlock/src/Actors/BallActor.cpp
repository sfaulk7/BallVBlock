#include "BallActor.h"
#include "PlayerActor.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Scenes/PlayScene.h"


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
	}
	//Change From Right to left
	if (Transform->GetLocalPosition().x >= GetScreenWidth())
	{
		goingRight = false;
		goingLeft = true;
	}
	//Change From Up to Down
	if (Transform->GetLocalPosition().y <= 0)
	{
		goingUp = false;
		goingDown = true;
	}
	//Change From Down to Up
	if (Transform->GetLocalPosition().y == GetScreenHeight() * .9)
	{
		goingDown = false;
		goingUp = true;
	}

	DrawCircle((Transform->GetLocalPosition().x), (Transform->GetLocalPosition().y), 10, m_color);
}
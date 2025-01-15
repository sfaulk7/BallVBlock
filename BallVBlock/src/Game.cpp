#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "math.h"
#include "Game.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"


Game::Game()
{

}

Game::~Game()
{

}

Scene Game::CurrentScene()
{
	return Scene();
}

void Game::AddScene(Scene scene)
{
}

bool Game::RemoveScene(Scene scene)
{
	return false;
}

Scene Game::GetScene(int index)
{
	return Scene();
}

void Game::Start()
{
	InitWindow(800, 800, "Game");

	SetTargetFPS(60);

	Run();
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
}

void Game::Update(float deltaTime)
{



}

void Game::End()
{

}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9) , 100, 10, WHITE);

	EndDrawing();
}
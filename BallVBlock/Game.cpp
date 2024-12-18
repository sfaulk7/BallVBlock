#include "Game.h"
#include "raylib.h"


Game::Game()
{

}

Game::~Game()
{

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

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9) , 100, 10, WHITE);

	EndDrawing();
}
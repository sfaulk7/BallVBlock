#include "StartScene.h"
#include "raylib.h"
#include "Engine/Scene.h"
#include "Game.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Start()
{
	Scene::Start();
}

void StartScene::Update(double deltatime)
{
	Scene::Update(deltatime);
	
	// If enter key is pressed add playScene to the game.
	
	// Intro to the game
	DrawText("Welcome to Ball V Block!", 240, 120, 30, YELLOW);
	DrawText("Press Enter To Play!", 240, 150, 30, YELLOW);
}

void StartScene::End()
{
	Scene::End();
}

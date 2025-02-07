#include "StartScene.h"
#include "raylib.h"
#include "Engine/Scene.h"
#include "Game.h"
#include "PlayScene.h"

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
	
	// If enter key is pressed set the current scene to the playScene.
	if (IsKeyPressed(KEY_ENTER))
	{
		Game::SetCurrentScene(Game::GetScene(1));
	}
	
	// Intro to the game
	DrawText("Welcome to Ball V Block!", 190, 120, 30, YELLOW);
	DrawText("Press Enter To Play!", 200, 150, 30, YELLOW);

}

void StartScene::End()
{
	Scene::End();
}

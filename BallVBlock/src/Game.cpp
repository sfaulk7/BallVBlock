#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"
#include "Scenes/StartScene.h"

Scene* Game::m_currentScene = nullptr;
DynamicArray<Scene*> Game::m_scenes;

Game::Game()
{
	if (m_currentScene == nullptr)
	{
		m_currentScene = this->m_currentScene;
	}
	m_playScene = new PlayScene();
	//m_startScene = new StartScene();
}

Game::~Game()
{

}

Scene* Game::CurrentScene()
{
	return m_currentScene;
}

Scene* Game::GetCurrentScene()
{
	return m_currentScene;
}

void Game::SetCurrentScene(Scene* value)
{
	if (m_currentScene != nullptr)
	{
		m_currentScene->End();
	}
	m_currentScene = value;
	m_currentScene->Start();
}

void Game::AddScene(Scene* scene)
{
	if (!m_scenes.Contains(scene))
	{
		m_scenes.Add(scene);
	}

	if (m_currentScene == nullptr)
	{
		m_currentScene = scene;
	}
}

bool Game::RemoveScene(Scene* scene)
{
	m_scenes.Remove(scene);

	if (m_currentScene == scene)
	{
		m_currentScene = GetScene(0);
	}

	return true;
}

Scene* Game::GetScene(int index)
{
	//If scene count is <= 0 or if scene count is <= index or index is < 0
	if (m_scenes.Length() <= 0 || m_scenes.Length() <= index || index < 0)
	{
		return nullptr;
	}

	return m_scenes[index];
}

void Game::Start()
{
	InitWindow(800, 1000, "Game");

	SetTargetFPS(60);

	Run();
}

void Game::Run()
{
	//Timing
	long currentTime = 0;
	long lastTime = 0;
	double deltaTime = 1;

	
	AddScene(m_startScene);
	AddScene(m_playScene);

	SetCurrentScene(m_playScene);
	//SetCurrentScene(m_startScene);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		m_currentScene->Update(deltaTime);

		//DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9), 100, 10, WHITE);

		EndDrawing();
		Update(GetFrameTime());
	}

	m_currentScene->End();

	CloseWindow();
}

void Game::Update(float deltaTime)
{



}

void Game::End()
{

}

void Game::Draw()
{

}
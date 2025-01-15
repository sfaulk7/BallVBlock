#pragma once

#include "Engine/DynamicArray.h"
#include "raylib.h"

class Actor;
class Scene;

class Game
{
public:

	Game();
	~Game();

	Scene* CurrentScene(); 
	Scene* GetCurrentScene();
	void SetCurrentScene(Scene* value);

	void AddScene(Scene* scene);
	bool RemoveScene(Scene* scene);

	Scene* GetScene(int index);

	void Start();
	void Update(float deltaTime);
	void End();
	void Run();

private:

	DynamicArray<Scene*> m_scenes;
	Scene* m_currentScene;

	//Scenes
	Scene* m_playScene;

	void Draw();

};
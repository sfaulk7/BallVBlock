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
	static Scene* GetCurrentScene();
	static void SetCurrentScene(Scene* value);

	void AddScene(Scene* scene);
	bool RemoveScene(Scene* scene);
	static Game* Instance();

	static Scene* GetScene(int index);

	void Start();
	void Update(float deltaTime);
	void End();
	void Run();

private:
	static DynamicArray<Scene*> m_scenes;
	static Scene* m_currentScene;

	//Scenes
	Scene* m_playScene;
	Scene* m_startScene;

	void Draw();

};
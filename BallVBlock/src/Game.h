#pragma once

#include "raylib.h"

class Actor;
class Scene;

class Game
{
public:

	Game();
	~Game();

	Scene CurrentScene();
	void AddScene(Scene scene);
	bool RemoveScene(Scene scene);
	Scene GetScene(int index);
	void Start();
	void Update(float deltaTime);
	void End();
	void Run();

private:

	void Draw();

};
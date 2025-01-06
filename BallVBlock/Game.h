#pragma once

#include "raylib.h"

class Game
{
public:

	Game();
	~Game();

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
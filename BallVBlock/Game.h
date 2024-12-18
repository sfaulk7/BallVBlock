#pragma once

#include "raylib.h"

class Game
{
public:

	Game();
	~Game();

	void Start();
	void Update(float deltaTime);
	void End();
	void Run();

private:

	void Draw();

};
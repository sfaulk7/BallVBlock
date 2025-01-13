#pragma once

#include "raylib.h"

class BlockActor
{
public:

	BlockActor();
	~BlockActor();

private:

	void Load();
	void Unload();

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

private:

	int m_windowWidth = 800;
	int m_windowHeight = 800;

	static const int ROWS = 5;
	static const int COLS = 15;

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 40;
	int m_tileHeight = 20;
};
#pragma once
#include "raylib.h"
#include "Engine/Actor.h"

class BlockActor : public Actor
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


	Color m_color;

	static const int ROWS = 5;
	static const int COLS = 15;

	int m_tiles[ROWS * COLS];

	int m_tileWidth = 40;
	int m_tileHeight = 20;
};
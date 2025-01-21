#include "BlockActor.h"
#include "raylib.h"
#include <stdlib.h>
#include "Engine/Actor.h"


BlockActor::BlockActor()
{
	int colorValue = rand() % 6;
	m_color = GetTileColor(colorValue);
}

BlockActor::~BlockActor()
{

}

void BlockActor::Update(float deltaTime)
{
	Actor::Update(deltaTime);

	Vector2 mousePos = GetMousePosition();


	int rowIndex = mousePos.x / m_tileWidth + 1;
	int colIndex = mousePos.y / m_tileHeight;

	DrawCircle(rowIndex, colIndex, 10, RED);


	int tileIndex = colIndex * COLS + rowIndex;

	m_tiles[tileIndex] += 1;
	if (m_tiles[tileIndex] >= 5)
		m_tiles[tileIndex] = 0;

	Draw();
}

void BlockActor::Draw()
{
	int colorIncrement = 0;
	for (int i = 0; i < ROWS; i++)
	{
		float yPos = i * m_tileHeight;

		for (int j = 0; j < COLS; j++)
		{
			colorIncrement++;
			float xPos = j * m_tileWidth;

			Color color = GetTileColor(m_tiles[colorIncrement]); // pass in the tilevalue

			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}
	}
}

Color BlockActor::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}

	return BLACK;
}
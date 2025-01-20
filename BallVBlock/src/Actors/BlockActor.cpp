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
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int rowIndex = mousePos.x / m_tileWidth + 1;
		int colIndex = mousePos.y / m_tileHeight;

		DrawCircle(rowIndex, colIndex, 10, RED);

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = colIndex * COLS + rowIndex;

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 5)
			m_tiles[tileIndex] = 0;
	}
}

void BlockActor::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
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


	// --------------------------------------------------------------------

	EndDrawing();
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
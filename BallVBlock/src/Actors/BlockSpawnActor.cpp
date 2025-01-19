#include "BlockSpawnActor.h"

AddComponent<BlockSpawnComponent>(new BlockSpawnComponent(this));

BlockSpawnActor::BlockSpawnActor()
{

}

BlockSpawnActor::~BlockSpawnActor()
{

}

void BlockSpawnActor::SetRandomColor(Color color)
{
	int colorNumber = GetRandomValue(1, 6);

	switch (colorNumber)
	{
	case 1: color = RED;
	case 2: color = GREEN;
	case 3: color = BLUE;
	case 4: color = YELLOW;
	case 5: color = WHITE;
	case 6: color = BLACK;
	}
}

void BlockSpawnActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	SetRandomColor(m_color);

	DrawRectangle((GetScreenWidth() * .45), (GetScreenHeight() * .9), 100, 10, m_color);
}

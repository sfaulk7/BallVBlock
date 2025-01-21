#include "BlockSpawnComponent.h"
#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"
#include "Actors/BlockActor.h"

BlockSpawnComponent::BlockSpawnComponent()
{
	Enabled = true;
}

BlockSpawnComponent::BlockSpawnComponent(Actor* owner) : Component::Component(m_owner)
{
	Enabled = true;
}

BlockSpawnComponent::~BlockSpawnComponent()
{

}

Color BlockSpawnComponent::GetColor()
{
    return Color();
}

Color BlockSpawnComponent::SetColor()
{
    return Color();
}


void BlockSpawnComponent::SetRandomColor(Color color)
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

void BlockSpawnComponent::Update(double deltaTime)
{
	if (Enabled == true)
	{
		for (int i = -1; i <= 1; i++)
		{

			MathLibrary::Vector2 offset = MathLibrary::Vector2(100 + (i * 15), 100 + (i * 15));

			block = Actor::Instantiate(new BlockActor(), nullptr, offset, 0, "Block");

		}

		Enabled = false;
	}

	

}

void BlockSpawnComponent::End()
{

}

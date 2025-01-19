#pragma once
#include "raylib.h"
#include "Engine/Actor.h"
#include "Components/BlockSpawnComponent.h"

void Actor::AddComponent<BlockSpawnComponent>(BlockSpawnComponent());

class BlockSpawnActor : public Actor
{
public:


	BlockSpawnActor();
	~BlockSpawnActor();

	void SetRandomColor(Color color);

	virtual void Update(double deltaTime);

private:
	Color m_color;

protected:

};
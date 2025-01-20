#pragma once
#include "raylib.h"
#include "Engine/Actor.h"
#include "Components/BlockSpawnComponent.h"

class BlockSpawnActor : public Actor
{
public:


	BlockSpawnActor();
	~BlockSpawnActor();

	virtual void Start();
	virtual void Update(double deltaTime);

private:
	Color m_color;

protected:

};
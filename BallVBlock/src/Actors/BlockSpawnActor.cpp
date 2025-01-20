#include "BlockSpawnActor.h"

BlockSpawnActor::BlockSpawnActor()
{

}

BlockSpawnActor::~BlockSpawnActor()
{

}



void BlockSpawnActor::Start()
{

	Actor::AddComponent<BlockSpawnComponent>(BlockSpawnComponent(this));

}

void BlockSpawnActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

}

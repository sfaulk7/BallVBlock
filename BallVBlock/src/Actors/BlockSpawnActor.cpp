#include "BlockSpawnActor.h"

BlockSpawnActor::BlockSpawnActor()
{

}

BlockSpawnActor::~BlockSpawnActor()
{

}



void BlockSpawnActor::Start()
{
	Actor::Start();
	AddComponent<BlockSpawnComponent>(new BlockSpawnComponent(this));

}

void BlockSpawnActor::Update(double deltaTime)
{
	Actor::Update(deltaTime);

}

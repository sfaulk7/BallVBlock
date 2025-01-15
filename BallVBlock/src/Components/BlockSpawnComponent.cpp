#include "BlockSpawnComponent.h"
#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"
#include "Actors/BlockActor.h"

Color BlockSpawnComponent::GetColor()
{
    return Color();
}

Color BlockSpawnComponent::SetColor()
{
    return Color();
}

BlockSpawnComponent::BlockSpawnComponent(Actor* owner)
{

}

void BlockSpawnComponent::Update(double deltaTime)
{
    if (Enabled)
    {
        Update(deltaTime);

        if (waveStarted == false)
        {
            //First Line of defense
            for (int i = -1; i <= 1; i++)
            {
                MathLibrary::Vector2 offset = MathLibrary::Vector2(100, 100);
                //Actor Block = Actor.Instantiate(new BlockActor(), Owner.Transform, offset);

                Actor* Block = Block->Instantiate(BlockActor(), GetOwner()->Transform, offset, 0, "Block");



                //Block.Collider = new CircleCollider(Block, 25);
            }

            waveStarted = true;
        }

        if (waveFinished == true)
        {
            waveFinished = false;
        }
    }
}
#include "BlockSpawnComponent.h"
#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"

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
                MathLibrary::Vector2 offset = MathLibrary::Vector2(50 * i, 100);
                //Actor Block = Actor.Instantiate(new BlockActor(), Owner.Transform, offset);

                Actor* Block = Block->Instantiate(Block, GetOwner()->Transform, offset);



                //Block.Collider = new CircleCollider(Block, 25);
            }

            for (int i = -1; i <= 1; i++)
            {
                MathLibrary::Vector2 offset = new MathLibrary::Vector2(50 * i, 150);
                Actor Block = Actor.Instantiate(new BlockActor(), Owner.Transform, offset);
                Block.Collider = new CircleCollider(Block, 25);
            }

            waveStarted = true;
        }

        if (waveFinished == true)
        {
            waveFinished = false;
        }
    }
}
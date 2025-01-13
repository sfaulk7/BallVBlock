#include "BlockSpawnComponent.h"

Color EnemySpawnComponent::GetColor()
{
    return Color();
}

Color EnemySpawnComponent::SetColor()
{
    return Color();
}

EnemySpawnComponent::EnemySpawnComponent(Actor* owner)
{
}

void EnemySpawnComponent::Update(double deltaTime)
{
    if (Enabled)
    {
        base.Update(deltaTime);

        if (waveStarted == false)
        {
            //First Line of defense
            for (int i = -1; i <= 1; i++)
            {
                MathLibrary::Vector2 offset = new MathLibrary::Vector2(50 * i, 100);
                Actor enemy = Actor.Instantiate(new EnemyActor(), Owner.Transform, offset);
                enemy.Collider = new CircleCollider(enemy, 25);
            }

            for (int i = -1; i <= 1; i++)
            {
                MathLibrary::Vector2 offset = new MathLibrary::Vector2(50 * i, 150);
                Actor enemy = Actor.Instantiate(new EnemyActor(), Owner.Transform, offset);
                enemy.Collider = new CircleCollider(enemy, 25);
            }

            waveStarted = true;
        }

        if (waveFinished == true)
        {
            waveFinished = false;
        }
    }
}
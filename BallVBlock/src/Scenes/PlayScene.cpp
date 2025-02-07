#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"
#include "Actors/PlayerActor.h"
#include "Actors/BallActor.h"
#include "Actors/BlockSpawnActor.h"
#include <string>

void PlayScene::Start()
{
    Scene::Start();

    SetTargetFPS(60);

    //Instantiating the actors into the playscene
    m_theBallActor = Actor::Instantiate(new BallActor(), nullptr, MathLibrary::Vector2(10, 10), 0, "The BallActor");
    m_thePlayerActor = Actor::Instantiate(new PlayerActor(), nullptr, MathLibrary::Vector2(450, 400), 0, "The PlayerActor");
    m_blockSpawnActor = Actor::Instantiate(new BlockSpawnActor(), nullptr, MathLibrary::Vector2(50, 100), 0, "BlockSpawnActor");
}


void PlayScene::Update(double deltaTime)
{
    Scene::Update(deltaTime);

    

    if (m_theBallActor->Transform->GetLocalPosition().y >= GetScreenHeight())
    {
        m_ballsMissed++;
    }

    DrawText(TextFormat("Balls Missed / 10: %i", m_ballsMissed), 320, 80, 40, GREEN);
}

void PlayScene::End()
{
    Scene::End();

}
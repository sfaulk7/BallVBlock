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


void PlayScene::Start()
{
    Scene::Start();

    SetTargetFPS(60);


    m_theBallActor = Actor::Instantiate(new BallActor(), nullptr, MathLibrary::Vector2(10, 10), 0, "The BallActor");
    m_thePlayerActor = Actor::Instantiate(new PlayerActor(), nullptr, MathLibrary::Vector2(450, 400), 0, "The PlayerActor");
    m_blockSpawnActor = Actor::Instantiate(new BlockSpawnActor(), nullptr, MathLibrary::Vector2(50, 100), 0, "BlockSpawnActor");
    //PlayScene::AddActor(m_thePlayerActor);
}


void PlayScene::Update(double deltaTime)
{
    Scene::Update(deltaTime);


}

void PlayScene::End()
{
    Scene::End();

}
#include "Game.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"
#include "Scenes/PlayScene.h"
#include "Actors/PlayerActor.h"


void PlayScene::Start()
{
    SetTargetFPS(60);


    Actor* m_thePlayerActor = Actor::Instantiate(new PlayerActor(), nullptr, MathLibrary::Vector2(450, 400), 0, "The PlayerActor");
    //PlayScene::AddActor(m_thePlayerActor);
}


void PlayScene::Update(double deltaTime)
{
    Scene::Update(deltaTime);

}

void PlayScene::End()
{
    
}
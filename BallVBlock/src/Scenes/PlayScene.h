#pragma once
#include "raylib.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Engine/Scene.h"

class Actor;

class PlayScene : public Scene
{
public:

    float timeAlive;
    float waveCountDown;
    float waveTimer;

    Actor* m_thePlayerActor;
    Actor* m_theBallActor;
    Actor* m_blockSpawnActor;

    void Start();

    void Update(double deltaTime);

    void End();
  
};
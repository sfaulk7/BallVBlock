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
    int waveCount;

    void Start();

    void Update(double deltaTime);

    void End()
    {
        End();
    }
};
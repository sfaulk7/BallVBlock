#pragma once
#include "raylib.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Engine/Component.h"

class BlockSpawnComponent : public Component
{
public:

    bool waveStarted = false;
    bool waveFinished = false;

    Color GetColor();
    Color SetColor();

    BlockSpawnComponent(Actor* owner);

    void Update(double deltaTime);

    void End()
    {
        End();
        Enabled = false;
    }

private:

    float m_size = 0.0f;
    Color m_color = Color(BLANK);
    MathLibrary::Vector2 m_offset = MathLibrary::Vector2(0, 0);
};
#pragma once
#include "Actor.h"

class Scene {
private:
	actor** m_actors;
public:
	void AddActor(Actor actor);
	bool RemoveActor(Actor actor);
	void Start();
	void Update();
	void End();
};
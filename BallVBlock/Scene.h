#pragma once
#include "Actor.h"
#include "DynamicArray.h"

class Actor;

class Scene {
public:
	Scene();
	~Scene();

	bool gameOver = false;
	void AddActor(Actor* actor);
	bool RemoveActor(Actor* actor);
	void Start();
	void Update();
	void End();
protected:
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToBeRemoved;
}; 
#pragma once
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
	void Update(double deltatime);
	void End();
	

private:
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToBeRemoved;
}; 
#pragma once
#include "DynamicArray.h"


class Actor;

class Scene {
public:
	Scene();
	~Scene();


	
	bool gameOver = false;
	bool hit = false;
	void AddActor(Actor* actor);
	bool RemoveActor(Actor* actor);
	static void Start();
	void Update(double deltatime);
	void End();
	

private:
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToBeRemoved;
}; 
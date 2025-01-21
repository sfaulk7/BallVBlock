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
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
	

private:
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToBeRemoved;
}; 
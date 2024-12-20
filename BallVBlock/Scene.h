#pragma once
#include "Actor.h"

class Actor;

class Scene {
private:
	// Two pointers for a list
    Actor** m_actors;
	
public:
	Scene();
	~Scene();

	void AddActor(Actor actor);
	bool RemoveActor(Actor actor);
	void Start();
	void Update();
	void End();
};
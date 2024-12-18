#include "Scene.h"
#include <iostream>
#include "Actor.h"



Scene::Scene()
{
	m_actors = new Actor * [0];
}

Scene::~Scene()
{
	delete m_actors;
}
void Scene::AddActor(Actor other)
{
	if (!m_actors.Contains(actor))
		m_actors.Add(actor);
}

bool Scene::RemoveActor(Actor other)
{
	//return m_actors*->Remove(actor);
	return m_actors.Remove(actor);
	
}

void Scene::Start()
{
	// Two pointers for a list
	Actor** m_actors;
}

void Scene::Update()
{
	for (int i = 0; i < m_actors.Count; i++)
	{
		Actor actor = m_actors[i];

		if (!actor.Started)
			actor.Start();

		actor.Update(deltaTime);
		if (actor.Collider != null)
			actor.Collider.Draw();
	}
}

void Scene::End()
{
	for each (Actor actor in m_actors)
	{
		actor.End();
	}
}
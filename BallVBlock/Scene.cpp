#include "Scene.h"
#include <iostream>
#include "Actor.h"
#include "DynamicArray.h"

	//Actor** m_actors = new Actor * [0];
	//List<Actor> _actors;


	Scene::Scene()
	{
		//Actor** m_actors = new Actor * [0];
	}

	Scene::~Scene()
	{
		//delete m_actors;
	}

	void Scene::Contains(Actor* actor)
	{
		if (m_actors.Length() = 1)
			Contains = true;
	}

	void Scene::AddActor(Actor* actor)
	{
		if (!m_actors.Contains(actor))
			m_actors.Add(actor);
	}

	bool Scene::RemoveActor(Actor* actor)
	{
		//return m_actors*->Remove(actor);
		m_actorsToBeRemoved.Remove(actor);

	}

	void Scene::Start()
	{
		// Two pointers for a list
		Actor** m_actors;
	}

	void Scene::Update(double deltaTime)
	{
		for (int i = 0; i < m_actors.Length(); i++)
		{
			Actor* actor = m_actors[i];

			if (!actor.Started())
				actor.Started();

			actor.Update(deltaTime);
			/*if (actor.Collider != null)
				actor.Collider.Draw();*/
		}
	}

	void Scene::End()
	{
		for each(Actor* actor :: in m_actors)
		{
			Actor* End();
			//actor.End();
		}
	}

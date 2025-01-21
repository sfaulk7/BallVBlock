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


	void Scene::AddActor(Actor* actor)
	{
		if (!(m_actors.Contains(actor)))
		{
			m_actors.Add(actor);
		}
	}

	bool Scene::RemoveActor(Actor* actor)
	{
		//return m_actors*->Remove(actor);
		m_actorsToBeRemoved.Remove(actor);

		return true;
	}

	void Scene::Start()
	{

	}

	void Scene::Update(double deltaTime)
	{
		for (int i = 0; i < m_actors.Length(); i++)
		{

			if (!m_actors[i]->GetStarted())
				m_actors[i]->Start();

			m_actors[i]->Update(deltaTime);
			/*if (actor.Collider != null)
				actor.Collider.Draw();*/
		}

		// Check for collision here
	}

	void Scene::End()
	{
		for (int i = 0; i < m_actors.Length(); i++)
		{
			m_actors[i]->End();
		}
	}

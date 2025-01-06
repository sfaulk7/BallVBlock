#include "Scene.h"
#include <iostream>
#include "Actor.h"
#include "list"

class Scene
{
public:
	//Actor** m_actors = new Actor * [0];
	//List<Actor> _actors;

	Scene()
	{
		//Actor** m_actors = new Actor * [0];
	}

	~Scene()
	{
		//delete m_actors;
	}
	void AddActor(Actor* actor)
	{
		if (!m_actors.Contains(actor))
			m_actors.Add(actor);
	}

	bool RemoveActor(Actor* actor)
	{
		//return m_actors*->Remove(actor);
		return m_actors.Remove(actor);

	}

	void Start()
	{
		// Two pointers for a list
		Actor** m_actors;
	}

	void Update(double deltaTime)
	{
		for (int i = 0; i < m_actors.Count; i++)
		{
			Actor actor = m_actors[i];

			if (!actor.Started)
				actor.Start();

			actor.Update(deltaTime);
			/*if (actor.Collider != null)
				actor.Collider.Draw();*/
		}
	}

	void End()
	{
		for (Actor* actor : in m_actors)
		{
			actor.End();
		}
	}
};

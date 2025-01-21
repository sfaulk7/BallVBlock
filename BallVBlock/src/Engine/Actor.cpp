#include "Game.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Scene.h"
#include "DynamicArray.h"
#include "Component.h"
#include "Scenes/PlayScene.h"


	/*MathLibrary::Matrix3 GetLocalRotation()
	{
		return m_localRotation;
	}
	void SetLocalRotation()
	{
		m_localRotationAngle = -(float)atan2(m_localRotation.m01, m_localRotation.m00);
		UpdateTransforms();
	}*/

	

Actor::Actor()
{
	const char* Name;
	//Transform2D* Transform;
	Name = "Actor";
	Transform = new Transform2D();
}

Actor::Actor(const char* name = "Actor")
	{
		const char* Name;
		//Transform2D* Transform;
		Name = name;
		Transform = new Transform2D();

		//COMPONENTS
		//m_componets = new Component[0];
		//m_componetsToRemove = new Component[0];

	}

	void Actor::SetTransform()
	{

	}

	Actor::~Actor()
	{
		delete Transform;
	}

	const char* Actor::Name(const char* name)
	{
		return name;
	}

	Actor* Actor::Instantiate(Actor* actor,
		Transform2D* parent,
		MathLibrary::Vector2 position,
		float rotation,
		const char* Name)
	{
		if (parent != nullptr)
			//Transform2D* parent.AddChild(actor->Transform);
			actor->GetTransform()->GetParent()->AddChild(actor->Transform);

		// Set the actor transfrom values
		//actor->Transform.SetLocalPosition = position;
		actor->GetTransform()->SetLocalPosition(position);
		actor->GetTransform()->Rotate(rotation);
		actor->Name(Name);
		


		// Add actor to the current scene
		Game().CurrentScene()->AddActor(actor);

		return actor;
	}



	void Actor::Destroy(Actor* actor)
	{
		// Remove all the children
		for (Transform2D* child : actor->Transform->GetChildren())
		{
			actor->Transform->RemoveChild(child);
		}

		if (actor->Transform->GetParent() != nullptr)
			actor->Transform->GetParent()->RemoveChild(actor->Transform);

		Game().CurrentScene()->RemoveActor(actor);
	}

	void Actor::OnEnable()
	{

	}

	void Actor::OnDisable()
	{
		
	}


	// Get and set the collider

	void Actor::Start()
	{
		m_started = true;

		Transform->UpdateTransforms();
		
	}

	void Actor::Update(double deltatime)
	{
		// Need component for update function
		for (int i = 0; i < m_components.Length(); i++)
		{
			if (!m_components[i]->Started)
				m_components[i]->Start();

			m_components[i]->Update(deltatime);
		}
		m_components.Remove(m_componentsToBeRemoved);
	}

	void Actor::End()
	{
		// Need component for end function
		for (size_t i = 0; i < m_components.Length(); i++)
		{
			m_components[i]->End();
		}
	}

	void Actor::OnCollision(Actor* other)
	{

	}

	void SetEnabled(bool value)
	{

	}

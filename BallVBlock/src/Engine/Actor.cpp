#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "math.h"
#include "Game.h"
#include "Engine/Scene.h"
#include "Engine/DynamicArray.h"
#include "Engine/Component.h"


	/*MathLibrary::Matrix3 GetLocalRotation()
	{
		return m_localRotation;
	}
	void SetLocalRotation()
	{
		m_localRotationAngle = -(float)atan2(m_localRotation.m01, m_localRotation.m00);
		UpdateTransforms();
	}*/

	

	Actor::Actor(const char* name = "Actor") 
	{
		const char* Name;
		Transform2D* Transform;
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
		// Set the actor transfrom values
		//actor->Transform.SetLocalPosition = position;
		actor->Transform->SetLocalPosition(position);
		actor->Transform->Rotate(rotation);
		actor->Name(Name);
		if (parent != nullptr)
			//Transform2D* parent.AddChild(actor->Transform);
			actor->Transform->GetParent()->AddChild(actor->Transform);


		// Add actor to the current scene
		Game().CurrentScene().AddActor(actor);

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

		Game().CurrentScene().RemoveActor(actor);
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
		for (size_t i = 0; i < m_components.Length(); i++)
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

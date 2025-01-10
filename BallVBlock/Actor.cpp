#include "Actor.h"
#include "Transform2D.h"
#include "math.h"
#include "Game.h"
#include "Scene.h"
#include "DynamicArray.h"
#include "Component.h"


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


	Actor* Instantiate(

		Actor* actor,
		Transform2D* parent = nullptr,
		MathLibrary::Vector2 position = MathLibrary::Vector2(),
		float rotation = 0,
		const char* Name = "Actor")
	{

		// Set the actor transfrom values
		//actor->Transform.SetLocalPosition = position;
		actor->Transform->SetLocalPosition(position);
		actor->Transform->Rotate(rotation);
		actor->Name = Name;
		if (parent != nullptr)
			Game().CurrentScene().parent.AddChild(actor->Transform);

		// Add actor to the current scene
		Game().CurrentScene().AddActor(actor);

		return actor;
	}

	void Actor::Destroy(Actor* actor)
	{
		// Remove all the children
		for (Transform2D* child : actor->Transform->GetChildren())
		{
			actor->Transform->RemoveChild();
		}

		if (actor->Transform.GetParent() != nullptr)
			actor->Transform.GetParent().RemoveChild(actor->Transform);

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
	}

	void Actor::End()
	{
		// Need component for end function
	}

	void Actor::OnCollision(Actor* other)
	{

	}

	// Component functions below


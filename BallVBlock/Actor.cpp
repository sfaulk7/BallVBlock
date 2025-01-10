#include "Actor.h"
#include "Transform2D.h"
#include "math.h"
#include "Vector2.h"
#include "Game.h"
#include "Scene.h"

class Actor
{
public:

	/*MathLibrary::Matrix3 GetLocalRotation()
	{
		return m_localRotation;
	}
	void SetLocalRotation()
	{
		m_localRotationAngle = -(float)atan2(m_localRotation.m01, m_localRotation.m00);
		UpdateTransforms();
	}*/

	const char* Name;
	Transform2D* Transform;

	Actor(const char* name = "Actor") 
	{
		Name = name;
		Transform = new Transform2D();

		//COMPONENTS
		//m_componets = new Component[0];
		//m_componetsToRemove = new Component[0];

	}

	void SetTransform()
	{

	}

	~Actor()
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

	void Destroy(Actor* actor)
	{
		// Remove all the children
		for (Transform2D* element : actor->Transform.GetChildren())
		{
			actor->Transform->RemoveChild();
		}

		if (Actor* actor->Transform.GetParent != nullptr)
			actor->Transform.GetParent.RemoveChild(actor->Transform);

		Game().CurrentScene().RemoveActor(actor);
	}

	void OnEnable()
	{

	}

	void OnDisable()
	{

	}


	// Get and set the collider

	void Start()
	{
		m_started = true;

		Transform->UpdateTransforms();
		
	}

	void Update(double deltatime)
	{
		// Need component for update function
	}

	void End()
	{
		// Need component for end function
	}

	void OnCollision(Actor other)
	{

	}

	// Component functions below
};

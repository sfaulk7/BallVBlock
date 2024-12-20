#include "Actor.h"
#include "Transform2D.h"
#include "math.h"
#include "Vector2.h"

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
		actor->Transform->GetLocalPosition() = position;
		actor->Transform->Rotate(rotation);

		return actor;
	}

	void Destroy(Actor actor)
	{
		// Remove all the children
	}

	void OnEnable()
	{

	}

	void OnDisable()
	{

	}

	void Start()
	{

	}

	void Update(double deltatime)
	{

	}

	void End()
	{

	}

	void OnCollision(Actor other)
	{

	}
};

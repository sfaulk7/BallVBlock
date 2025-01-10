#include "Component.h"
#include "math.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Transform2D.h"
#include "DynamicArray.h"
#include "Actor.h"


//Actor* m_owner;
//Actor* Owner;
//bool Enabled;
//bool Started;
//bool m_enabled;
//bool m_started;

Component::Component(Actor* owner = nullptr)
{
	m_owner = owner;
	m_enabled = true;
	m_started = false;
}
Component::~Component()
{

}

Actor* Component::GetOwner()
{
	return m_owner;
}
void Component::SetOwner(Actor* Owner)
{
	m_owner = Owner;
}
	
bool Component::GetEnabled()
{
	return m_enabled;
}
void Component::SetEnabled(bool value)
{
	//if enables would not change, do nothing
	if (m_enabled == value) return;

	m_enabled = value;
	//If value is true, call OnEnable
	if (m_enabled)
	{
		OnEnable();
	}
	//If value is false, call on OnDisable
	else
	{
		OnDisable();
	}
}

bool Component::GetStarted()
{
	return m_started;
}



void Component::OnEnable()
{

}
void Component::OnDisable()
{

}

void Component::Start()
{
	m_started = true;
}
void Component::Update(double deltatime)
{
	if (m_owner = nullptr)
	{
		End();
	}
}
void Component::End()
{
	m_enabled = false;
}



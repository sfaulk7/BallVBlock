#pragma once
#include "Engine/Transform2D.h"
#include "Engine/Component.h"
#include "Engine/Collision/CircleCollider.h"

class Collider;
class Scene;
class Component;

class Actor
{
	

private:
	bool m_started;
	bool m_enabled;

	DynamicArray<Component*> m_components;
	DynamicArray<Component*> m_componentsToBeRemoved;

protected:

public:
	template <typename T>
	T* AddComponent(T* component);
	template <typename T>
	T* RemoveComponent(T* component);
	template <typename T>
	T* GetComponent(T* component);
	
	Actor();
	Actor(const char* name);
	~Actor();
	Transform2D* GetTransform()
	{
		return Transform;
	}
	void SetTransform();
	const char* Name(const char* name);
	static Actor* Instantiate(Actor* actor,
		Transform2D* parent,
		MathLibrary::Vector2 position,
		float rotation,
		const char* Name);
    void Destroy(Actor* other);
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
	virtual void OnCollision(Actor* other);
	Collider* m_collider;
	
	bool GetStarted()
	{
		return m_started;
	}
	bool GetEnabled()
	{
		return m_enabled;
	}
	void SetEnabled(bool value);
	
	Transform2D* Transform;
};

template<typename T>
inline T* Actor::AddComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr)
		return nullptr;
	else
	{
		m_components.Add(component);
		return component;
	}
}

template<typename T>
inline T* Actor::RemoveComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr)
		return false;
	else
	{
		return true;
	}
}

template<typename T>
inline T* Actor::GetComponent(T* component)
{
	Component ptr = dynamic_cast<Component*>(component);
	if (ptr = nullptr)
		return false;
	else
	{
		for (Component* element : m_components)
		{
			if (element = component)
			{
				return element;
			}
		}
	}
}
#pragma once
#include "Engine/Transform2D.h"
#include "Engine/Component.h"

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
	/*void Started(bool started) { m_started = started; }
	void Enabled(bool enabled) { m_enabled = enabled; }*/
	

public:
	template <typename T>
	void AddComponent(const T& value)
	{
		T component = new T();
		component.Owner = this;
		return AddComponent(component);
	}
	template <typename T>
	bool RemoveComponent(const T& value)
	{
		T component = GetComponent<T>();
		if (component != nullptr)
			return RemoveComponent(component);
		return false;
	}
	template <typename T>
	void GetComponent()
	{
		/*T[] temp = new T[m_components.Length];*/
		T* temp = new T[m_components.Length];

		int count = 0;
		for (int i = 0; i < m_components.Length(); i++)
		{
			if (m_components[i] == T)
			{
				temp[count] = (T)m_components[i];
				count++;
			}
		}

		//T[] result = new T[count];
		T* result = new T[count];
		for (int i = 0; i < count; i++)
		{
			result[i] = temp[i];
		}

		return result;
	}
	
	
	Actor(const char* name);
	~Actor();
	Transform2D GetTransform();
	void SetTransform();
	const char* Name(const char* name);
	Actor* Instantiate(Actor* actor,
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

	//bool Started(bool started) { m_started = started; }
	//bool Enabled(bool enabled) { m_enabled = enabled; }
	
	bool GetStarted()
	{
		return m_started;
	}
	bool GetEnabled()
	{
		return m_enabled;
	}
	void SetEnabled(bool value);

	//void AddComponentToRemove(Component comp);
	//void RemoveComponentsToBeRemoved();
	
	Transform2D* Transform;
};
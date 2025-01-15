#pragma once
#include "Engine/Transform2D.h"

class Scene;
class Component;

class Actor
{
private:
	bool m_started;
	bool m_enabled;

	DynamicArray<Component*> m_components;
	DynamicArray<Component*> m_componentsToBeRemove;

protected:
	/*void Started(bool started) { m_started = started; }
	void Enabled(bool enabled) { m_enabled = enabled; }*/
	

public:
	
	
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
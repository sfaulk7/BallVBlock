#pragma once
#include "Transform2D.h"

class Scene;

class Actor
{
private:
	bool m_started;
	bool m_enabled;

	/*Component[] _components;
	Component[] _componentsToRemove;*/

protected:
	/*void Started(bool started) { m_started = started; }
	void Enabled(bool enabled) { m_enabled = enabled; }*/
	

public:
	
	
	Actor(const char* name = nullptr);
	~Actor();
	Transform2D GetTransform();
	void SetTransform();
	const char* Name(const char* name);
	virtual void Instantiate();
    void Destroy(Actor* other);
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
	virtual void OnCollision(Actor* other);
	bool Started(bool started) { m_started = started; }
	bool Enabled(bool enabled) { m_enabled = enabled; }
	//void AddComponentToRemove(Component comp);
	//void RemoveComponentsToBeRemoved();
	
	Transform2D* Transform;
};
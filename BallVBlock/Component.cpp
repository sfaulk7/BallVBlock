#pragma once
#include "Component.h"

class Actor
{

};

class Component
{
public:
	Actor* m_owner;
	Actor* Owner;
	bool Enabled;
	bool Started;

	Actor* GetOwner()
	{
		return m_owner;
	}
	void SetOwner(Actor* Owner)
	{
		m_owner = Owner;
	}
	
	bool GetEnabled()
	{
		return m_enabled;
	}
	void SetEnabled(bool value)
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

	bool GetStarted()
	{
		return m_started;
	}

	Component(Actor* owner = nullptr)
	{
		m_owner = owner;
		m_enabled = true;
		m_started = false;
	}

	virtual void OnEnable()
	{

	}
	virtual void OnDisable()
	{

	}

	virtual void Start()
	{
		m_started = true;
	}
	virtual void Update(double deltatime)
	{
		if (Owner = nullptr)
		{
			End();
		}
	}
	virtual void End()
	{
		m_enabled = false;
	}

private:
	bool m_enabled;
	bool m_started;

};
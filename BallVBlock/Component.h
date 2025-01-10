#pragma once

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

	}
	void SetOwner(Actor* Owner)
	{

	}

	bool GetEnabled()
	{

	}
	void SetEnabled(bool value)
	{

	}

	bool GetStarted()
	{

	}

	Component(Actor* owner = nullptr)
	{
		
	}

	virtual void OnEnable()
	{

	}
	virtual void OnDisable()
	{

	}

	virtual void Start()
	{

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

	}

private:
	bool m_enabled;
	bool m_started;

};
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

	Actor* GetOwner();
	void SetOwner();
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
			throw NullReferenceException();
		}
	}
	virtual void End()
	{

	}

private:
	bool _enabled;
	bool _started;

};
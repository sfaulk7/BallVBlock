#pragma once

class Actor;

class Component
{

public:
	Component(Actor* owner = nullptr);
	~Component();

	Actor* Owner;

	bool Enabled;
	bool Started;

	Actor* GetOwner();
	void SetOwner(Actor* Owner);

	bool GetEnabled();
	void SetEnabled(bool value);

	bool GetStarted();


	virtual void OnEnable();
	virtual void OnDisable();

	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();

private:
	Actor* m_owner;
	bool m_enabled;
	bool m_started;

};
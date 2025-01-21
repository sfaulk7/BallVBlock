#pragma once

class Actor;

class Component
{

public:
	Component(Actor* owner = nullptr);
	~Component();

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

protected:
	Actor* m_owner;


private:
	bool m_enabled;
	bool m_started;

};
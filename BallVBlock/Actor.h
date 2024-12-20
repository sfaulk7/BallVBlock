#pragma once

class Actor
{
private:
	bool m_started;
	bool m_enabled;

	/*Component[] _components;
	Component[] _componentsToRemove;*/

protected:
	void Started(bool started) { m_started = started; }
	void Enabled(bool enabled) { m_enabled = enabled; }

public:
	
	const char* Name();
	static void Instantiate();
	void Destroy(Actor other);
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();
	virtual void OnCollision(Actor other);
	
};
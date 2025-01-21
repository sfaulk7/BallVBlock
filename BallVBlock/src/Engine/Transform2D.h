#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include "DynamicArray.h"

/// <summary>
	/// Summary
	/// </summary>
	/// <returns></returns>

class Actor;

class Transform2D
{

public:
	Transform2D(Actor* owner = nullptr);
	~Transform2D();

	//Getters and Setters
	MathLibrary::Matrix3* GetLocalRotation();
	void SetLocalRotation();

	MathLibrary::Vector2 GetLocalPosition();
	void SetLocalPosition(MathLibrary::Vector2 value);

	MathLibrary::Vector2 GetLocalScale();
	void SetLocalScale(MathLibrary::Vector2 value);

	MathLibrary::Vector2 GetGlobalPosition();

	MathLibrary::Vector2 GetGlobalScale();

	Actor* GetOwner()
	{
		return m_owner;
	}

	MathLibrary::Vector2 GetForward();
	MathLibrary::Vector2 GetRight();

	float GetLocalRotationAngle();
	float GetGlobalRotationAngle();

	Transform2D* GetParent();
	DynamicArray<Transform2D*> GetChildren()
	{
		return m_children;
	}

	//Matrix and Vector manipulation
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);

	//Parent child relationship advise
	void AddChild(Transform2D* child);
	bool RemoveChild(Transform2D* child);

	//Update
	void UpdateTransforms();



private:

	MathLibrary::Matrix3* m_localMatrix;
	MathLibrary::Matrix3* m_globalMatrix;

	MathLibrary::Matrix3* m_localTranslation;
	MathLibrary::Matrix3* m_localRotation;
	MathLibrary::Matrix3* m_localScale;

	Actor* m_owner;

	Transform2D* m_parent;
	DynamicArray<Transform2D*> m_children;

	float m_localRotationAngle;
	
};
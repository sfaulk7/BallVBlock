#pragma once
#include "Matrix3.h"

/// <summary>
	/// Summary
	/// </summary>
	/// <returns></returns>

namespace MathLibrary 
{
	class Vector2
	{

	};
}

class Actor;

class Transform2D
{
protected:


public:
	//Getters and Setters
	MathLibrary::Matrix3 GetLocalRotation();
	void SetLocalRotation();

	int GetLocalPosition();
	void SetLocalPosition();

	int GetLocalScale();
	void SetLocalScale();

	int GetGlobalPosition();

	int GetGlobalScale();

	MathLibrary::Vector2 GetForward();
	MathLibrary::Vector2 GetRight();

	MathLibrary::Vector2 GetLocalRotationAngle();
	MathLibrary::Vector2 GetGlobalRotationAngle();

	//Matrix and Vector manipulation
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);

	//Parent child relationship advise
	void AddChild(Transform2D child);
	void RemoveChild(Transform2D child);

	//Update
	void UpdateTransforms();



private:

	MathLibrary::Matrix3 m_localMatrix;
	MathLibrary::Matrix3 m_globalMatrix;

	MathLibrary::Matrix3 m_localTranslation;
	MathLibrary::Matrix3 m_localRotation;
	MathLibrary::Matrix3 m_localScale;

	Actor* m_owner;

	Transform2D* m_parent;
	DynamicArray<Transform2D*> m_children;

	float m_localRotationAngle;
	
};
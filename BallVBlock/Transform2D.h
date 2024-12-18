#pragma once
#include "Vector2.h"

namespace MathLibrary 
{
	class Matrix3 
	{

	};
}
class Actor;

class Transform2D
{
protected:


public:
	/// <summary>
	/// Getters and Setters
	/// </summary>
	/// <returns></returns>
	MathLibrary::Matrix3 GetLocalRotation();
	void SetLocalRotation();

	int GetLocalPosition();
	void SetLocalPosition();

	int GetLocalScale();
	void SetLocalScale();

	int GetGlobalPosition();

	int GetGlobalScale();

	Vector2 GetForward();
	Vector2 GetRight();

	Vector2 GetLocalRotationAngle();
	Vector2 GetGlobalRotationAngle();

	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);
	void AddChild(Transform2D child);
	void RemoveChild(Transform2D child);

	void UpdateTransforms();


private:

	MathLibrary::Matrix3 m_localMatrix;
	MathLibrary::Matrix3 m_globalMatrix;

	MathLibrary::Matrix3 m_localTranslation;
	MathLibrary::Matrix3 m_localRotation;
	MathLibrary::Matrix3 m_localScale;

	Actor m_owner;

	Transform2D m_parent;
	Transform2D[] m_children;

	float m_localRotationAngle;
	
};
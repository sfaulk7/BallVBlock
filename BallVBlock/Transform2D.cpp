#include "math.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "Transform2D.h"
#include "DynamicArray.h"
#include "Actor.h"

//Getters and Setters
Transform2D::Transform2D(Actor* owner)
{
	m_owner = owner;
	DynamicArray<Transform2D*> m_children;
}
Transform2D::~Transform2D()
{

}

MathLibrary::Matrix3 Transform2D::GetLocalRotation() 
{
	return m_localRotation;
}
void Transform2D::SetLocalRotation()
{
	m_localRotationAngle = -(float)atan2(m_localRotation.m01, m_localRotation.m00);
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::GetLocalPosition()
{
	return MathLibrary::Vector2(m_localTranslation.m02, m_localTranslation.m12);
}
void Transform2D::SetLocalPosition(MathLibrary::Vector2 value)
{
	m_localTranslation.m02 = value.x;
	m_localTranslation.m12 = value.y;
	Transform2D::UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::GetLocalScale()
{
	return MathLibrary::Vector2(m_localMatrix.m00, m_localMatrix.m11);
}
void Transform2D::SetLocalScale(MathLibrary::Vector2 value)
{
	m_localScale.m00 = value.x;
	m_localScale.m11 = value.y;
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::GetGlobalPosition()
{
	return MathLibrary::Vector2(m_globalMatrix.m02, m_globalMatrix.m12);
}
MathLibrary::Vector2 Transform2D::GetGlobalScale()
{
	MathLibrary::Vector2 xAxis = MathLibrary::Vector2(m_globalMatrix.m00, m_globalMatrix.m10);
	MathLibrary::Vector2 yAxis = MathLibrary::Vector2 (m_globalMatrix.m01, m_globalMatrix.m11);

	return MathLibrary::Vector2(xAxis.getMagnitude(), yAxis.getMagnitude());
}

MathLibrary::Vector2 Transform2D::GetForward()
{
	return MathLibrary::Vector2(m_globalMatrix.m00, m_globalMatrix.m10).normalize();
}
MathLibrary::Vector2 Transform2D::GetRight()
{
	return MathLibrary::Vector2(m_globalMatrix.m01, m_globalMatrix.m11).normalize();
}

float Transform2D::GetLocalRotationAngle()
{
	return m_localRotationAngle;
}
float Transform2D::GetGlobalRotationAngle()
{
	return (float)atan2(m_globalMatrix.m01, m_globalMatrix.m00);
}

Transform2D* Transform2D::GetParent()
{
	return m_parent;
}

//Translates LocalPosition using a Vector2 called direction
void Transform2D::Translate(MathLibrary::Vector2 direction)
{
	SetLocalPosition(GetLocalPosition() + direction);
}
//Translates LocalPosition using two floats x and y
void Transform2D::Translate(float x, float y)
{
	SetLocalPosition(GetLocalPosition() + MathLibrary::Vector2(x, y));
}
void Transform2D::Rotate(float radians)
{
	m_localRotation = MathLibrary::Matrix3::createRotation(m_localRotationAngle + radians);
}

void Transform2D::AddChild(Transform2D* child)
{
	// Do not add the child if it is this transform's parents
	if (child == m_parent)
	{
		return;
	}

	child->m_parent = this;
	m_children.Add(child);
}
bool Transform2D::RemoveChild(Transform2D* child)
{
	bool childRemoved = false;

	//if no children
	if (m_children.Length() <= 0)
	{
		return false;
	}

	if (m_children.Length() == 1 && m_children[0] == child)
	{
		m_children.Clear();
		return true;
	}

	else
	{
		m_children.Remove(child);
		return true;
	}
}

void Transform2D::UpdateTransforms()
{
	m_localMatrix = m_localTranslation * m_localRotation * m_localScale;

	// if parent is not null
	if (m_parent != nullptr)
	{
		// Global transform = parent global transform * local transform
		m_globalMatrix = m_parent->m_globalMatrix * m_localMatrix;
	}
	//else
	else
	{
		//global transform - local transform
		m_globalMatrix = m_localMatrix;
	}

	//Update Children
	for (int i = 0;i < m_children.Length(); i++)
	{
		m_children[i]->UpdateTransforms();
	}
}

//MathLibrary::Matrix3 m_localMatrix;
//MathLibrary::Matrix3 m_globalMatrix;
//
//MathLibrary::Matrix3 m_localPosition;
//MathLibrary::Matrix3 m_localTranslation;
//MathLibrary::Matrix3 m_localRotation;
//MathLibrary::Matrix3 m_localScale;
//
//Actor* m_owner;
//
//Transform2D* m_parent;
//DynamicArray<Transform2D*> m_children;
//
//float m_localRotationAngle;
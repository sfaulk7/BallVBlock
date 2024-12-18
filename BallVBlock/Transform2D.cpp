#include "Vector2.h"
#include "Matrix3.h"
#include "Transform2D.h"
#include "math.h"

namespace MathLibrary
{
	class Matrix3
	{

	};
}


class Transform2D
{
protected:


public:
	/// <summary>
	/// Getters and Setters
	/// </summary>
	/// <returns></returns>
	MathLibrary::Matrix3 GetLocalRotation() 
	{
		return m_localRotation;
	}
	void SetLocalRotation() 
	{
		float m_localRotationAngle = -(float)atan2(m_localRotation.m01, m_localRotation.m00);
		UpdateTransforms();
	}

	MathLibrary::Vector2 GetLocalPosition() 
	{
		return MathLibrary::Vector2(m_localTranslation.m02, m_localTranslation.m12)
	}
	void SetLocalPosition() 
	{
		m_localTranslation.m02 = value.x;
		m_localTranslation.m12 = value.y;
		UpdateTransforms();
	}

	MathLibrary::Vector2 GetLocalScale()
	{
		return MathLibrary::Vector2(m_localMatrix.m00, m_localMatrix.m11);
	}
	void SetLocalScale() 
	{
		m_localScale.m00 = value.x;
		m_localScale.m11 = value.y;
		UpdateTransforms();
	}

	MathLibrary::Vector2 GetGlobalPosition() 
	{
		return MathLibrary::Vector2(m_globalMatrix.m02, m_globalMatrix.m12);
	}
	MathLibrary::Vector2 GetGlobalScale()
	{
		MathLibrary::Vector2 xAxis = MathLibrary::Vector2(m_globalMatrix.m00, m_globalMatrix.m10);
		MathLibrary::Vector2 yAxis = MathLibrary::Vector2 (m_globalMatrix.m01, m_globalMatrix.m11);

		return MathLibrary::Vector2(xAxis.getMagnitude(), yAxis.getMagnitude());
	}

	//Actor owner
	//{
	//	return m_owner;
	//}

	MathLibrary::Vector2 GetForward()
	{
		//MathLibrary::Vector2 forward = MathLibrary::Vector2(m_globalMatrix.m00, m_globalMatrix.m10);
		//return forward.normalize();

		return MathLibrary::Vector2(m_globalMatrix.m00, m_globalMatrix.m10).normalize();
	}
	MathLibrary::Vector2 GetRight() 
	{
		return MathLibrary::Vector2(m_globalMatrix.m01, m_globalMatrix.m11).normalize();
	}

	float GetLocalRotationAngle() 
	{
		return m_localRotationAngle;
	}
	float GetGlobalRotationAngle() 
	{
		return (float)atan2(m_globalMatrix.m01, m_globalMatrix.m00);
	}

	Transform2D GetParent() 
	{
		return m_parent;
	}
	//Transform2D[] GetChildren()
	//{
	//	return m_children;
	//}

	//Transform2D(Actor owner) 
	//{
	//	m_owner = owner;
	//	m_children = Transform2D[0];
	//}

	//Translates LocalPosition using a Vector2 called direction
	void Translate(MathLibrary::Vector2 direction) 
	{
		LocalPosition += direction;
	}
	//Translates LocalPosition using two floats x and y
	void Translate(float x, float y) 
	{
		LocalPosition += MathLibrary::Vector2(x, y);
	}
	void Rotate(float radians) 
	{
		LocalRotation = MathLibrary::Matrix3::createRotation(m_localRotationAngle + radians);
	}
	void AddChild(Transform2D child)
	{
		//old array is _children

		// Do not add the child if it is this transform's parents
		if (child == m_parent)
		{
			return;
		}

		//arr tempArray set to new array[old.length + 1]
		Transform2D[] temp = Transform2D[m_children.Length + 1];

		//for each child in old array
		for (int i = 0; i < m_children.Length; i++)
		{
			//copy child to new array
			temp[i] = m_children[i];
		}

		//tempArray[old.length] set to new child
		temp[m_children.Length] = child;

		//set child parent to this instance
		child.m_parent = this;

		//set old array to new array
		m_children = temp;
	}
	bool RemoveChild(Transform2D child)
	{
		bool childRemoved = false;

		//if no children
		if (m_children.Length <= 0)
		{
			return false;
		}

		//Make temp array (it is after the no children check to garentee that there is at least one child)
		Transform2D[] temp = Transform2D[m_children.Length - 1];

		//if only one child and that child is the corrent child
		if (m_children.Length == 1 && m_children[0] == child)
		{
			childRemoved = true;
		}

		//j is basically i for the temp array
		int j = 0;
		for (int i = 0; j < m_children.Length - 1; i++)
		{
			//If the current child isn't the one that is being removed; copy
			if (m_children[i] != child)
			{
				temp[j] = m_children[i];
				j++;
			}
			//If the current child is the one being removed
			else
			{
				childRemoved = true;
			}
		}

		//Copy the temp array into as the new _children array
		if (childRemoved)
		{
			m_children = temp;
			child.m_parent = null;
		}

		return childRemoved;
	}

	void UpdateTransforms()
	{
		m_localMatrix = m_localTranslation * m_localRotation * m_localScale;

		// if parent is not null
		if (m_parent != null)
		{
			// Global transform = parent global transform * local transform
			m_globalMatrix = m_parent.m_globalMatrix * m_localMatrix;
		}
		//else
		else
		{
			//global transform - local transform
			m_globalMatrix = m_localMatrix;
		}

		//Update Children
		for (int i = 0;i < m_children.Length; i++)
		{
			m_children[i].UpdateTransforms()
		}

		//foreach(Transform2D child in _children)
		//{
		//	child.UpdateTransforms();
		//}
	}


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
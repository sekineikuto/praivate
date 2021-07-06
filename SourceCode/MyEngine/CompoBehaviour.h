//*************************************************************************************************************
//
// �R���|�[�l���g�r�w�C�r�A����[CompoBehaviour.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _COMPOBEHAVIOUR_H_
#define _COMPOBEHAVIOUR_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "../mystd/mystd.h"
#include "Component.h"
#include <vector>

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// �C���^�[�t�F�C�X�N���X��`
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour
{
public:
	// �R���X�g���N�^
	CCompoBehaviour()
	{

	}

	// �f�X�g���N�^
	~CCompoBehaviour()
	{
		for (auto compo : CompoList)
		{
			delete compo;
			compo = nullptr;
		}
	}

	// �R���|�[�l���g�̒ǉ�
	template<typename T>
	T* AddComponent()
	{
		for (auto compo : CompoList)
		{
			if (dynamic_cast<T*>(compo) != nullptr)
			{
				return nullptr;
			}
		}

		T* pNew = new T();
		IComponent* pComponent = static_cast<IComponent*>(pNew);
		if (pComponent != nullptr)
		{
			pComponent->parent = this;
			CompoList.push_back(pComponent);
			return pNew;
		}

		return nullptr;
	}

	// �R���|�[�l���g�̎擾
	template<typename T>
	T* GetComponent()
	{
		for (auto compo : CompoList)
		{
			T* component = dynamic_cast<T*>(compo);
			if (component != nullptr)
			{
				return component;
			}
		}
		return nullptr;
	}

	// �R���|�[�l���g���폜
	template<typename T>
	void RemoveComponent()
	{

	}

	// �R���|�[�l���g���폜
	template<typename T>
	void Destroy(T* src)
	{
		IComponent* pComponent = static_cast<IComponent*>(src);
		
		if (pComponent == nullptr)
			return;

		delete src;

		int nIdx = CompoList.front() - pComponent;
		CompoList.erase(CompoList.begin() + nIdx);
		
		src = nullptr;
	}

private:
	std::vector<IComponent*> CompoList;	// �R���|�[�l���g���X�g
}; 


_END_MYSTD

#endif
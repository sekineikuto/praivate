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
#include <unordered_map>

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// �C���^�[�t�F�C�X�N���X��`
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour
{
public:
	using hash_map = std::unordered_map<std::string, IComponent*>;

	// �R���X�g���N�^
	CCompoBehaviour()
	{

	}

	// �f�X�g���N�^
	~CCompoBehaviour()
	{
		for (auto itr : compoList)
		{
			delete itr.second;
			itr.second = nullptr;
		}
	}

	// �R���|�[�l���g�̒ǉ�
	template<typename T>
	T* AddComponent()
	{
		auto addTypeName = typeid(T).name();

		for (auto itr : compoList)
			if (itr.first == addTypeName)
				return nullptr;

		T* pNew = new T();

		auto pComponent = static_cast<IComponent*>(pNew);

		if (pComponent == nullptr)
			return nullptr;

		pComponent->parent = this;

		pComponent->Start();

		compoList.insert(hash_map::value_type(addTypeName, pComponent));

		return pNew;
	}

	// �R���|�[�l���g�̎擾
	template<typename T>
	T* GetComponent()
	{
		auto base = compoList[typeid(T).name()];

		if (base == nullptr)
			return nullptr;

		T* pComp = dynamic_cast<T*>(base);

		return pComp;
	}

	// �R���|�[�l���g���폜
	template<typename T>
	void RemoveComponent()
	{
		auto key = typeid(T).name();

		auto base = compoList[key];

		if (base == nullptr)
			return;

		delete base;

		compoList.erase(key);

		base = nullptr;
	}

	// �R���|�[�l���g���폜
	template<typename T>
	void Destroy(T* src)
	{
	}

private:
	//std::vector<IComponent*> CompoList;	// �R���|�[�l���g���X�g
	hash_map compoList;
}; 


_END_MYSTD

#endif
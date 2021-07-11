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
	using hash_map = std::unordered_map<std::string, u32_t>;

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
		//for (auto compo : CompoList)
		//{
		//	if (typeid(*compo) == typeid(T))
		//	{
		//		return nullptr;
		//	}
		//}

		map.insert(hash_map::value_type(typeid(T).name(), CompoList.size()));

		for (hash_map::const_iterator it = map.begin(); it != map.end(); ++it)
			std::cout << " [" << it->first.data() << ", " << it->second << "]";
		std::cout << "\n";

		//u32_t nCnt = 10;
		//for (hash_map::const_iterator it = map.begin(); it != map.end(); ++it)
		//{
		//	map[it->first.data()] = nCnt;
		//	nCnt++;
		//}

		//for (hash_map::const_iterator it = map.begin(); it != map.end(); ++it)
		//	std::cout << " [" << it->first.data() << ", " << it->second << "]";
		//std::cout << "\n";


		T* pNew = new T();
		IComponent* pComponent = static_cast<IComponent*>(pNew);
		if (pComponent != nullptr)
		{
			pComponent->parent = this;
			pComponent->Start();
			//for (auto compo : CompoList)
			//{
			//	compo->AttachComponent(pNew);
			//}
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
		//int nMapIdx = map.at(typeid(T).name());

		//// �}�b�v�������
		//map.erase(nMapIdx);

		//int nCnt = 0;
		//for (hash_map::const_iterator it = map.begin(); it != map.end(); ++it)
		//{
		//	it->second = nCnt;
		//	++nCnt;
		//}


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
	hash_map map;
}; 


_END_MYSTD

#endif
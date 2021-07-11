//*************************************************************************************************************
//
// コンポーネントビヘイビア処理[CompoBehaviour.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _COMPOBEHAVIOUR_H_
#define _COMPOBEHAVIOUR_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "../mystd/mystd.h"
#include "Component.h"
#include <vector>
#include <unordered_map>

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// インターフェイスクラス定義
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour
{
public:
	using hash_map = std::unordered_map<std::string, u32_t>;

	// コンストラクタ
	CCompoBehaviour()
	{

	}

	// デストラクタ
	~CCompoBehaviour()
	{
		for (auto compo : CompoList)
		{
			delete compo;
			compo = nullptr;
		}
	}

	// コンポーネントの追加
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

	// コンポーネントの取得
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

	// コンポーネントを削除
	template<typename T>
	void RemoveComponent()
	{

	}

	// コンポーネントを削除
	template<typename T>
	void Destroy(T* src)
	{
		//int nMapIdx = map.at(typeid(T).name());

		//// マップから消す
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
	std::vector<IComponent*> CompoList;	// コンポーネントリスト
	hash_map map;
}; 


_END_MYSTD

#endif
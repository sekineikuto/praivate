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
	using hash_map = std::unordered_map<std::string, IComponent*>;

	// コンストラクタ
	CCompoBehaviour()
	{

	}

	// デストラクタ
	~CCompoBehaviour()
	{
		for (auto itr : compoList)
		{
			delete itr.second;
			itr.second = nullptr;
		}
	}

	// コンポーネントの追加
	template<typename T>
	T* AddComponent()
	{
		auto key = typeid(T).name();

		auto itr = compoList.find(key);

		if (itr != compoList.end())
			return nullptr;

		T* pNew = new T();

		auto pComponent = static_cast<IComponent*>(pNew);

		if (pComponent == nullptr)
			return nullptr;

		pComponent->parent = this;

		pComponent->Start();

		compoList.insert(hash_map::value_type(key, pComponent));

		std::cout << "AddComponent => " << key << std::endl;

		return pNew;
	}

	// コンポーネントの取得
	template<typename T>
	T* GetComponent()
	{
		auto key = typeid(T).name();

		auto itr = compoList.find(key);

		if (itr != compoList.end())
		{
			auto base = compoList.at(key);

			if (base == nullptr)
				return nullptr;

			T* pComp = dynamic_cast<T*>(base);

			return pComp;
		}
		else
		{
			return nullptr;
		}
	}

	// コンポーネントの取得
	IComponent* GetComponent(const char * typeName)
	{
		auto itr = compoList.find(typeName);

		if (itr != compoList.end())
		{
			auto base = compoList.at(typeName);

			if (base == nullptr)
				return nullptr;

			return base;
		}
		return nullptr;
	}

	// コンポーネントを削除
	template<typename T>
	void RemoveComponent()
	{
		auto key = typeid(T).name();

		auto itr = compoList.find(key);

		if (itr != compoList.end())
		{
			auto base = compoList.at(key);

			if (base == nullptr)
				return;

			delete base;

			compoList.erase(key);

			base = nullptr;
		}
	}

	// コンポーネントを削除
	template<typename T>
	void Destroy(T* src)
	{
		if (src == nullptr)
			return;

		delete src;
		src = nullptr;

		compoList.erase(typeid(T).name());
	}

private:
	//std::vector<IComponent*> CompoList;	// コンポーネントリスト
	hash_map compoList;
}; 


_END_MYSTD

#endif
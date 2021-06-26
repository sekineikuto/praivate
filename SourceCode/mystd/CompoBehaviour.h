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
#include "mystd.h"
#include "Component.h"
#include <vector>

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// インターフェイスクラス定義
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour
{
public:
	// コンストラクタ
	CCompoBehaviour() {}
	// デストラクタ
	~CCompoBehaviour() {}

	// コンポーネントの追加
	template<typename T>
	T* AddComponent()
	{
		for (auto& compo : CompoList)
		{
			if (dynamic_cast<T*>(compo) != nullptr)
			{
				return nullptr;
			}
		}

		T* t = new T();
		IComponent* pComponent = static_cast<IComponent*>(t);
		if (pComponent != nullptr)
		{
			pComponent->parent = this;
			CompoList.push_back(pComponent);
			return t;
		}

		return nullptr;
	}

	// コンポーネントの取得
	template<typename T>
	T* GetComponent()
	{
		for (auto &compo : CompoList)
		{
			T* component = dynamic_cast<T*>(&compo);
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
		for (auto& compo : CompoList)
		{
			T* Component = dynamic_cast<T*>(compo);
			if (Component != nullptr)
			{
				CompoList.erase(i);
			}
		}
	}
private:
	std::vector<IComponent> CompoList;	// コンポーネントリスト
}; 


_END_MYSTD

#endif
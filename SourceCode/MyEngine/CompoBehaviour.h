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

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// インターフェイスクラス定義
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour
{
public:
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
}; 


_END_MYSTD

#endif
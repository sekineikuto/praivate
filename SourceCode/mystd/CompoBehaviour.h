//*************************************************************************************************************
//
// コンポーネントビヘイビア処理[CompoBehaviour.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
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
	CCompoBehaviour() {}
	~CCompoBehaviour() {}

	template<typename T>
	T* AddComponent()
	{
		for (int i = 0; i < (int)CompoList.size(); i++)
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
			CompoList.push_back(pComponent);
			return t;
		}

		return nullptr;
	}

	template<typename T>
	T* GetComponent()
	{
		for (IComponent& compo : CompoList)
		{
			T* component = dynamic_cast<T*>(compo);
			if (component != nullptr)
			{
				return component;
			}
		}
		return nullptr;
	}

	template<typename T>
	void RemoveComponent()
	{
		for (IComponent& compo : CompoList)
		{
			T* Component = dynamic_cast<T*>(compo);
			if (Component != nullptr)
			{
				CompoList.erase(i);
			}
		}
	}
private:
	std::vector<IComponent> CompoList;
}; 


_END_MYSTD

#endif
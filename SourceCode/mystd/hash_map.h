//*************************************************************************************************************
//
// 軌道処理 [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MYSTD_HASH_MAP_H_
#define _MYSTD_HASH_MAP_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "mystd.h"

//-------------------------------------------------------------------------------------------------------------
// 名前空間定義
//-------------------------------------------------------------------------------------------------------------
_BEGIN_MYSTD


template<class T>
class hash_map
{

public:
	class cell
	{
	public:
		cell(std::string inkey, T indata)
		{
			key = inkey;
			data = indata;
			pNext = nullptr;
		}

		std::string key;
		T data;
		cell *pNext;
	};

public:
	hash_map(std::string str, T data)
	{

	}

	template < typename input >
	hash_map(input first, input last)
	{
		for (auto i = first; i != last; ++i)
		{
			int n = 0;
			n++;
		}
	}

	hash_map(std::initializer_list<cell> init) :
		hash_map(std::begin(init),std::end(init))
	{

	}
};

_END_MYSTD

#endif // _MYSTD_H_
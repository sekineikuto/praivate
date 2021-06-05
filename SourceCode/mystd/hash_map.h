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
	typedef typename T type;
	typedef typename type data_type;
	typedef typename std::string key_type;
public:
	// 内部クラス
	class cell
	{
	public:
		cell() {}
		cell(key_type inkey, data_type indata)
		{
			key = inkey;
			data = indata;
		}
		~cell()
		{
		}

		key_type key;	// キー
		data_type data;	// データ
	};

public:
	// コンストラクタ
	hash_map() {}
	hash_map(std::initializer_list<cell> init) :
		hash_map(std::begin(init), std::end(init)) {}

	template<class init>
	hash_map(init first, init last)
	{
		// バケット数
		m_nNumBucket = (int)((last - first) * 1.25f);
		// ハッシュテーブルの作成
		MakeHashtable(m_nNumBucket);

		for (auto itr = first; itr != last; ++itr)
		{
			this->entry(*itr);
		}
	}

	// デストラクタ
	~hash_map()
	{
		DestroyHashtable();
	}

	// ハッシュ値の取得
	int HashValue(key_type key)
	{
		int nHashval = 0;

		for (auto cha : key)
		{
			nHashval += cha;
		}

		// ハッシュ値をサイズの余剰を返す
		return nHashval % m_nNumBucket;
	}

	// 登録
	void entry(cell in)
	{
		int nIdx = HashValue(in.key);

		while (m_pCell[nIdx].key.empty() == false)
		{
			nIdx = (nIdx + 1) % m_nNumBucket;
		}
		m_pCell[nIdx].key = in.key;
		m_pCell[nIdx].data = in.data;
		++m_nNumEntry;
	}

	// 登録
	void entry(key_type inkey, data_type indata)
	{
		int nIdx = HashValue(inkey);

		while (m_pCell[nIdx].key.empty() == false)
		{
			nIdx = (nIdx + 1) % m_nNumBucket;
		}
		m_pCell[nIdx].key = inkey;
		m_pCell[nIdx].data = indata;

		++m_nNumEntry;
	}

	// 検索
	data_type search(key_type key)
	{
		int nIdx = HashValue(key);

		while (m_pCell[nIdx].key.empty() == false)
		{
			if (m_pCell[nIdx].key.compare(key) == 0)
			{
				return m_pCell[nIdx].data;
			}
			nIdx = (nIdx + 1) % m_nNumBucket;
		}

		return (data_type)-1;
	}

private:

	// ハッシュテーブルの作成
	void MakeHashtable(int nNum)
	{
		m_pCell = new cell[nNum];
	}

	// ハッシュテーブルの破棄
	void DestroyHashtable(void)
	{
		delete[]m_pCell;
		m_pCell = nullptr;
	}

	int m_nNumBucket;	// テーブルのバケット数
	int m_nNumEntry;	// エントリー数
	cell *m_pCell;		// データ
};

_END_MYSTD

#endif
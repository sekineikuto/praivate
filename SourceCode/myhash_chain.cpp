//*************************************************************************************************************
//
// ハッシュチェイン処理 [myhash_chain.cpp]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "myhash_chain.h"


//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CHash_chain * CHash_chain::Create(void)
{
	// 生成
	CHash_chain *pHsh = new CHash_chain;
	// ハッシュテーブルの作成
	pHsh->MakeHashtable();
	return pHsh;
}

//-------------------------------------------------------------------------------------------------------------
// ハッシュテーブルの作成
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::MakeHashtable(void)
{
	// ハッシュテーブルの領域の確保
	m_ppCell = new HASHCELL*[MYHASH_CHAIN_BUCKET_SIZE];
	// ハッシュの初期化
	Init();
}

//-------------------------------------------------------------------------------------------------------------
// ハッシュテーブルの開放
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::ReleaseHashtable(void)
{
	// ハッシュテーブルを解放する
	ListFree();

	// ハッシュテーブルの領域開放
	delete[]m_ppCell;
	m_ppCell = nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化関数
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::Init(void)
{
	// ハッシュテーブルをNULLで初期化する
	for (int nCntSize = 0; nCntSize < MYHASH_CHAIN_BUCKET_SIZE; nCntSize++)
	{
		m_ppCell[nCntSize] = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// リストの開放処理
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::ListFree(void)
{
	// 変数宣言
	HASHCELL *pTemp = nullptr;		// 一時格納用ポインタ
	HASHCELL *pSwap = nullptr;		// 交換用ポインタ

	// サイズ分ループ
	for (int nCntSize = 0; nCntSize < MYHASH_CHAIN_BUCKET_SIZE; nCntSize++)
	{
		// 一時的に格納
		pTemp = m_ppCell[nCntSize];

		// リストの開放
		while (pTemp != nullptr)
		{
			// 次のポインタを交換用に代入
			pSwap = pTemp->pNext;
			// テーブル情報の開放
			HashCellFree(pTemp);
			// 交換用を代入
			pTemp = pSwap;
		}
	}

	// ハッシュテーブルの初期化
	Init();

}

//-------------------------------------------------------------------------------------------------------------
// ハッシュを探索して、データを取得する
//-------------------------------------------------------------------------------------------------------------
void * CHash_chain::Search(char * pKey)
{
	// 変数宣言
	HASHCELL *pHash = m_ppCell[GetHashValue(pKey)];		// ハッシュポインタ

	// NULLになるまでループ
	while (pHash != nullptr)
	{// キーと同じ時
		if (strcmp(pKey, pHash->pKey) == 0)
		{// データを返す
			return pHash->pData;
		}
		// 次のポインタを代入
		pHash = pHash->pNext;
	}

	return nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// ハッシュテーブルに登録する
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::Insert(char * pKey, void * pData)
{
	// 変数宣言
	HASHCELL *pRegis = nullptr;		// 登録
	int       nHashvalue = 0;		// ハッシュ値

	// 同じキーがすでに登録されているか確認する
	if (Search(pKey) != nullptr)
	{
		return;
	}

	// セル領域を確保する
	pRegis = new HASHCELL;
	if (pRegis == nullptr)
	{
		return;
	}

	// キーをセルに保存する
	if (StrAllocAndCopy(&(pRegis->pKey), pKey) != 0)
	{
		return;
	}
	
	// データのアドレスを代入
	pRegis->pData = pData;

	// ハッシュテーブルに登録する
	nHashvalue = GetHashValue(pKey);
	// 次のポインタに代入する
	pRegis->pNext = m_ppCell[nHashvalue];
	// セルに代入する
	m_ppCell[nHashvalue] = pRegis;

	return;

}

//-------------------------------------------------------------------------------------------------------------
// ハッシュテーブルから削除する
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::Delete(char * pKey)
{
	// 変数宣言
	HASHCELL *pTarget = nullptr;				// ターゲット用ポインタ
	HASHCELL *pChain = nullptr;				// チェイン用ポインタ
	int nHashValue = GetHashValue(pKey);	// ハッシュ値

											// ターゲットポインタの設定
	pTarget = m_ppCell[nHashValue];
	// ターゲットがNULLの時
	if (pTarget == nullptr)
	{
		return;
	}
	// チェイン用のポインタの設定
	pChain = pTarget->pNext;

	// リストの先頭要素を削除する場合
	if (strcmp(pKey, pTarget->pKey) == 0)
	{// チェイン用のポインタを代入
		m_ppCell[nHashValue] = pChain;
		// ターゲットを開放
		HashCellFree(pTarget);
		return;
	}

	// 先頭以外の要素を削除する場合
	while (pTarget != nullptr)
	{// キーが同じとき
		if (strcmp(pKey, pTarget->pKey) == 0)
		{// 次のポインタつなぐ
			pChain->pNext = pTarget->pNext;
			// ターゲットの開放
			HashCellFree(pTarget);
			return;
		}
		// ターゲットをチェイン用に代入
		pChain = pTarget;
		// 次のターゲットポインタを設定する
		pTarget = pTarget->pNext;
	}

	return;
}

//-------------------------------------------------------------------------------------------------------------
// ハッシュセルの開放
//-------------------------------------------------------------------------------------------------------------
void CHash_chain::HashCellFree(HASHCELL * pCell)
{
	// キーの開放
	if (pCell->pKey != nullptr)
	{
		delete[]pCell->pKey;
	}

	// セルの開放
	delete pCell;
}

//-------------------------------------------------------------------------------------------------------------
//  ハッシュ値の取得
//-------------------------------------------------------------------------------------------------------------
int CHash_chain::GetHashValue(char * pKey)
{
	// 変数宣言
	int nHashval = 0;	// ハッシュ値
#ifdef MYHASH_CHAIN_VALUE_BASE_PRIME
	int nCntKey;		// キーカウント
	for (nCntKey = 0; pKey[nCntKey] != '\0'; nCntKey++)
	{
		nHashval = (nHashval * MYHASH_CHAIN_VALUE_BASE_PRIME + (pKey[nCntKey] & 0xff)) % MYHASH_CHAIN_BUCKET_SIZE;
	}
	return nHashval;
#else 
						// キーポインタがNULLになるまで
	while (*pKey != MYLIB_CHAR_UNSET)
	{
		// ハッシュ値に代入
		nHashval += *pKey;
		// ポインタを進める
		*pKey++;
	}
	// ハッシュ値をサイズの余剰を返す
	return nHashval % MYHASH_CHAIN_BUCKET_SIZE;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// 文字列の領域を確保してコピーする
//-------------------------------------------------------------------------------------------------------------
int CHash_chain::StrAllocAndCopy(char ** pOut, char * pSource)
{
	// 変数宣言
	int nLength = 0;	// 文字列の長さ

	// 文字列の長さを算出 + NULL
	nLength = strlen(pSource) + 1;
	// 文字列の長さが0以下の時エラーを返す
	if (nLength <= 0)
	{
		return MYLIB_FAILURE;
	}
	// アウトプットの生成
	*pOut = new char[nLength];
	// 生成に失敗した時エラーを返す
	if (*pOut == nullptr)
	{
		return MYLIB_FAILURE;
	}
	// 文字列のコピー(失敗した時エラーを返す)
	if (strncpy(*pOut, pSource, nLength) == nullptr)
	{
		return MYLIB_FAILURE;
	}
	//　無事処理完了
	return MYLIB_SUCCESS;
}

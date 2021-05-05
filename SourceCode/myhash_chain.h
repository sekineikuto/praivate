//*************************************************************************************************************
//
// ハッシュチェイン処理 [myhash_chain.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MYHASH_CHAIN_H_
#define _MYHASH_CHAIN_H_

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //_CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
/* ハッシュテーブルの要素数 */
#define MYHASH_CHAIN_BUCKET_SIZE         19
// ハッシュ値を生成する時の素数
#define MYHASH_CHAIN_VALUE_BASE_PRIME    3571
//#undef MYHASH_CHAIN_VALUE_BASE_PRIME

//-------------------------------------------------------------------------------------------------------------
// ハッシュクラス
//-------------------------------------------------------------------------------------------------------------
class CHash_chain
{
public:
	typedef struct _HASHCELL
	{
		char*      pKey;		// キー
		void*      pData;		// データ
		_HASHCELL* pNext;		// 次のポインタ
	} HASHCELL;

	/* メンバ関数 */
	static CHash_chain* Create(void);						// 生成
	void                MakeHashtable(void);				// ハッシュテーブルの作成
	void                ReleaseHashtable(void);				// ハッシュテーブルの開放
	void                Init(void);							// 初期化関数
	void                ListFree(void);						// リストの開放処理
	void*               Search(char *pKey);					// ハッシュを探索して、データを取得する
	void                Insert(char *pKey, void *pData);	// ハッシュテーブルに登録する
	void                Delete(char *pKey);					// ハッシュテーブルから削除する

private:
	/* 内部関数 */
	static void         HashCellFree(HASHCELL* pTable);					// ハッシュセルの開放
	static int          GetHashValue(char *pKey);						// ハッシュ値の取得
	static int          StrAllocAndCopy(char **pOut, char *pSource);	// 文字列の領域を確保してコピーする
	
	/* メンバ変数 */
	HASHCELL  **m_ppCell;												// セルのダブルポインタ

};
#endif //_MYHASH_CHAIN_H_
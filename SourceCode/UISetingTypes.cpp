//*************************************************************************************************************
//
// 2DUI設定する構造体の処理[UISetingTypes.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "UISetingTypes.h"
#include "myhash.h"

//-------------------------------------------------------------------------------------------------------------
//
// UserInterface2Dの処理
//
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
CHash * ui2d::CFunctions::m_pMaskHash = nullptr;

//-------------------------------------------------------------------------------------------------------------
// 関数群を使うための宣言
//-------------------------------------------------------------------------------------------------------------
void ui2d::CFunctions::DeclarationToUse(void)
{
	// マスクのハッシュの生成
	MakeMaskHash();
}

//-------------------------------------------------------------------------------------------------------------
// 関数群の終了宣言
//-------------------------------------------------------------------------------------------------------------
void ui2d::CFunctions::DeclarationToEnd(void)
{
	// マスクのハッシュのテーブルの開放
	m_pMaskHash->ReleaseHashtable();

	if (m_pMaskHash != nullptr)
	{
		delete m_pMaskHash;
		m_pMaskHash = nullptr;
	}

}

//-------------------------------------------------------------------------------------------------------------
// 文字列からマスク値の取得
//-------------------------------------------------------------------------------------------------------------
inline int ui2d::CFunctions::GetMaskToString(STRING str)
{
	// 変数宣言
	STRING WordEnd = &str[0];		// ワードの最後
	STRING Word    = WordEnd;		// ワード
	STRING KeyWord = nullptr;		// キーワード
	int    nMask   = MASK_NONE;		// マスクの値

	while (true)
	{
		if (*WordEnd == '\n')
		{
			break;
		}
		else if (*WordEnd == '|')
		{
			*WordEnd = '\0';
			WordEnd++;
			nMask |= atoi(m_pMaskHash->Search(Word));
			Word = WordEnd;
		}
		WordEnd++;
	}
	return nMask;
}

//-------------------------------------------------------------------------------------------------------------
// マスクのハッシュの作成
//-------------------------------------------------------------------------------------------------------------
void ui2d::CFunctions::MakeMaskHash(void)
{
	char * Key[FLAG_MAX] =
	{
		{ UISETING_ABILITY_NUMBER },
		{ UISETING_ABILITY_FLASHING },
		{ UISETING_ABILITY_FADE },
	};
	char * Data[FLAG_MAX] =
	{
		{ "1" },		// MASK_NUMBER
		{ "2" },		// MASK_FLASHING
		{ "4" },		// MASK_FADE
	};

	// ハッシュの作成
	m_pMaskHash = CHash::Create();

	// ハッシュに挿入する
	for (int nCntHash = 0; nCntHash < FLAG_MAX; nCntHash++)
	{
		m_pMaskHash->Insert(Key[nCntHash], Data[nCntHash]);
	}

}

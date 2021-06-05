//*************************************************************************************************************
//
// 2DUI設定する構造体の処理[UISetingTypes.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _UISETINGTYPES_H_
#define _UISETINGTYPES_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"


//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define UISETING_ABILITY_DEFAULT  "default"
#define UISETING_ABILITY_NUMBER   "number"
#define UISETING_ABILITY_FLASHING "flashing"
#define UISETING_ABILITY_FADE     "fade"

//-------------------------------------------------------------------------------------------------------------
// 前方宣言
//-------------------------------------------------------------------------------------------------------------
class CHash;

//-------------------------------------------------------------------------------------------------------------
// 名前空間定義
//-------------------------------------------------------------------------------------------------------------
namespace ui2d
{
	/* 列挙型定義 */
	// マスクの設定値
	enum
	{
		MASK_NONE     = 0b00000000,
		MASK_NUMBER   = 0b00000001,
		MASK_FLASHING = 0b00000010,
		MASK_FADE     = 0b00000100,
		MASK_MAX      = 0b00000111,
	};
	// フラグの設定値
	enum
	{
		FLAG_NONE = -1,
		FLAG_NUMBER,
		FLAG_FLASHING,
		FLAG_FADE,
		FLAG_MAX
	};

	// 2DUIの設定用の構造体
	typedef struct SETING
	{
		SETING() {}
		SETING(int  nTextureID, bool bDisp, D3DXVECTOR3 pos, D3DXCOLOR col, D3DXVECTOR2 size, float fRotation, int nOriginType)
		{
			this->nTextureID = nTextureID;
			this->bDisp = bDisp;
			this->pos = pos;
			this->col = col;
			this->size = size;
			this->fRotation = fRotation;
			this->nOriginType = nOriginType;
		}
		int         nTextureID;		// テクスチャID
		bool        bDisp;			// 描画フラグ
		D3DXVECTOR3 pos;			// 位置
		D3DXCOLOR   col;			// 色
		D3DXVECTOR2 size;			// サイズ
		float       fRotation;		// 回転量
		int         nOriginType;	// 原点タイプ
	} SETING;
}
#endif
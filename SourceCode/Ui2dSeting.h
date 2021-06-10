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
#include "TextfileController.h"
#include "manager.h"

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
		SETING(int  nTextureID, bool bDisp, D3DXVECTOR3& pos, D3DXVECTOR2& size, float fRotation, int nOriginType, D3DXCOLOR& col) :
			nTextureID(nTextureID), bDisp(bDisp), pos(pos), size(size), fRotation(fRotation), nOriginType(nOriginType), col(col)
		{}
		// コピーコンストラクタ
		SETING(SETING &CopySource)
		{
			this->nTextureID  = CopySource.nOriginType;	// テクスチャID
			this->bDisp       = CopySource.bDisp;		// 描画フラグ
			this->pos         = CopySource.pos;			// 位置
			this->size        = CopySource.size;		// サイズ
			this->fRotation   = CopySource.fRotation;	// 回転量
			this->nOriginType = CopySource.nOriginType;	// 原点タイプ
			this->col         = CopySource.col;			// 色
		}
		// コピー
		SETING &operator = (SETING &CopySource)
		{
			this->nTextureID  = CopySource.nOriginType;	// テクスチャID
			this->bDisp       = CopySource.bDisp;		// 描画フラグ
			this->pos         = CopySource.pos;			// 位置
			this->size        = CopySource.size;		// サイズ
			this->fRotation   = CopySource.fRotation;	// 回転量
			this->nOriginType = CopySource.nOriginType;	// 原点タイプ
			this->col         = CopySource.col;			// 色
		}

		/* メンバ変数 */
		int         nTextureID;		// テクスチャID
		bool        bDisp;			// 描画フラグ
		D3DXVECTOR3 pos;			// 位置
		D3DXVECTOR2 size;			// サイズ
		float       fRotation;		// 回転量
		int         nOriginType;	// 原点タイプ
		D3DXCOLOR   col;			// 色
	} SETING;

	class CLoadinfo
	{
	public:
		// 設定情報をロードする
		inline static void LoadSetingInfo(const char *pFileName, std::vector<SETING> *output)
		{
			// 情報を初期化
			CLoadinfo info;
			info.bSeting = false;
			info.output = output;

			// 1行ずつ指定された関数に送る
			mystd::CLoadFile::GetLine(pFileName, &info, ReadFromLine);
		}
	private:
		// 一行から情報を読み取る
		inline static void ReadFromLine(const char * info, CLoadinfo* load)
		{
			if (strcmp(info, "SET_UI") == 0)
			{
			}
			else
			{// パラメータを設定
				ReadFromLineSetParam(info, load);
			}
		}
		// 読み取った行からパラメータを設定する
		inline static void ReadFromLineSetParam(const char * line, CLoadinfo* load)
		{

		}
		bool bSeting;
		std::vector<std::string> item;
		std::vector<SETING> *output;
	};



}
#endif
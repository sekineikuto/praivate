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
#include <unordered_map>

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define UISETING_ABILITY_DEFAULT  "default"
#define UISETING_ABILITY_NUMBER   "number"
#define UISETING_ABILITY_FLASHING "flashing"
#define UISETING_ABILITY_FADE     "fade"

//-------------------------------------------------------------------------------------------------------------
// 名前空間定義
//-------------------------------------------------------------------------------------------------------------
namespace ui2d
{
	//-------------------------------------------------------------------------------------------------------------
	// 列挙型定義
	//-------------------------------------------------------------------------------------------------------------
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

	//-------------------------------------------------------------------------------------------------------------
	// 構造体定義
	//-------------------------------------------------------------------------------------------------------------
	// 2DUIの設定用の構造体
	typedef struct SETING
	{
		/* メンバ関数 */
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

	//-------------------------------------------------------------------------------------------------------------
	// クラス定義
	//-------------------------------------------------------------------------------------------------------------
	class CLoadinfo
	{
	public:
		/* メンバ関数 */

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

		// マップの設定
		static void SetMap();

		// マップの削除
		static void UnsetMap();

	private:
		/* メンバ関数 */

		// 一行から情報を読み取る
		inline static void ReadFromLine(const char * info, CLoadinfo* load)
		{
			if (strcmp(info, "SET_UI") == 0)
			{
				load->item.push_back(info);
			}
			else if (load->item.empty())
			{
				if (strcmp(info, "{") == 0)
				{
					load->bSeting = true;
				}
				else if (strcmp(info, "}") == 0)
				{
					load->item.pop_back();
					load->bSeting = false;
				}
			}
			else
			{// パラメータを設定
				ReadFromLineSetParam(info, load);
			}
		}

		// 読み取った行からパラメータを設定する
		inline static void ReadFromLineSetParam(const char * line, CLoadinfo* load)
		{
			// 変数宣言
			char aData[MYLIB_STRINGSIZE] = {};
			int nData = 0;
			D3DXCOLOR float4 = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

			// 終了ポインタが来た時
			// UIタイプ
			if (sscanf(line, "UI_TYPE = %s", aData) == 1)
			{

			}
			// 原点ID
			else if (sscanf(line, "ORIGINTYPEID = %d", &nData) == 1)
			{
			}
			// 位置
			else if (sscanf(line, "POS = %f %f %f", &float4.r, &float4.g, &float4.b) == 3)
			{
			}
			// サイズ
			else if (sscanf(line, "SIZE = %f %f", &float4.r, &float4.g) == 2)
			{
			}
			// 回転
			else if (sscanf(line, "ROTATION = %f", &float4.r) == 1)
			{
			}
			// 色
			else if (sscanf(line, "COL = %f %f %f %f", &float4.r, &float4.g, &float4.b, &float4.a) == 4)
			{
			}
			// テクスチャタイプの設定
			else if (sscanf(line, "TEXTURETYPE = %d", &nData) == 1)
			{
			}
			// スクリプトファイル
			else if (sscanf(line, "SCRIPTFILE = %s", aData) == 1)
			{

			}
		}

		/* メンバ変数 */
		static std::unordered_map<std::string, int> *m_pMap; // ロード用のマップ
		bool bSeting;
		std::vector<std::string> item;
		std::vector<SETING> *output;
	};



}
#endif
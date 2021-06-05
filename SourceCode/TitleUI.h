//*************************************************************************************************************
//
// タイトルUI処理 [TitleUI.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _TITLEUI_H_
#define _TITLEUI_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "TextfileController.h"
#include "Mylibrary.h"

#include "Ui2d.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CTitleUI
{
public:
	/* 列挙型定義 */
	enum
	{
		TYPE_NONE = -1,																	// 無し
		TYPE_TITLENAME,																	// タイトル名
		TITLEUI_PLEASEKEY,																// キーを押してください
		TYPE_MAX																		// 最大数
	};

	/* メンバ関数 */
	inline           CTitleUI() {};														// コンストラクタ
	inline           ~CTitleUI() {};													// デストラクタ

	static CTitleUI* Create(void);														// 生成
	void             Init(void);														// 初期化
	void             Uninit(void);														// 終了
	void             Update(void);														// 更新
	void             Draw(void);														// 描画

	// 取得関数
	CUi2d*          Get2dui(int nIndex = TYPE_TITLENAME);								// 2DUiの取得
private:
	/* メンバ関数 */
	static void     ReadFromLine(CLoadInitFile::READINFO& info, std::vector<CUi2d*> *p2dui);						// 1行ずつ読み込む
	static void     ReadFromLineSetParam(CONST_STRING line, std::vector<CUi2d*> *p2dui);	// パラメータに設定
	/* メンバ変数 */
	static ui2d::SETING m_Seting;													// 設定
	static bool             m_bSetingUI;												// UI設定フラグ
	std::vector<CUi2d*>     m_2dui;															// ２DUIポインタ

};

#endif
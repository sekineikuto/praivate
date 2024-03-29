//*************************************************************************************************************
//
// デバッグ表示の処理[DebugProc.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"
#include "DebugProc.h"
#include "renderer.h"

#ifdef _DEBUG

//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
LPD3DXFONT CDebugProc::m_pFont = nullptr;			// フォント情報
char CDebugProc::m_aStr[DEBUGPROC_NUMARRAY] = {};	// 文字列

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CDebugProc::CDebugProc()
{
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
CDebugProc::~CDebugProc()
{
}

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CDebugProc * CDebugProc::Create(void)
{
	// デバッグ処理の生成
	CDebugProc *pDebugProc = new CDebugProc;
	// 初期化
	pDebugProc->Init();
	return pDebugProc;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
HRESULT CDebugProc::Init(void)
{
	// デバッグ表示用フォントを設定
	D3DXCreateFont(CManager::GetRenderer().GetDevice(), 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "ＭＳ ゴシック", &m_pFont);
	return E_NOTIMPL;
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CDebugProc::Uninit(void)
{
	if (m_pFont != nullptr)
	{// フォントの開放
		m_pFont->Release();
		m_pFont = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// プリント
//-------------------------------------------------------------------------------------------------------------
void CDebugProc::print(char * fmt, ...)
{
	va_list list;
	va_start(list, fmt);
	vsprintf(&m_aStr[strlen(m_aStr)], fmt, list);
	va_end(list);
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CDebugProc::Draw(void)
{
	// 変数宣言
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
#ifdef _DEBUG
	// テキスト描画
	m_pFont->DrawText(NULL, &m_aStr[0], -1, &rect, DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
#endif // _DEBUG

	m_aStr[0] = '\0';

}
#endif // _DEBUG
//*************************************************************************************************************
//
// タイトルUI処理 [TitleUI.cpp]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "TitleUI.h"
#include "manager.h"


//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
ui2d::SETING CTitleUI::m_Seting;						// 設定
bool CTitleUI::m_bSetingUI = false;

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CTitleUI * CTitleUI::Create(void)
{
	CTitleUI *pTitleUI = new CTitleUI;
	pTitleUI->Init();
	return pTitleUI;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Init(void)
{
	// ファイルから読み込み
	mystd::CLoadInitFile::LoadFile(CManager::GetFIleName(CManager::FILE_TITLEUI), &m_2dui, ReadFromLine);


	std::vector<std::string> test;
	mystd::CLoadFile::GetSplit(CManager::GetFIleName(CManager::FILE_TITLEUI), test);
	test.clear();
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Uninit(void)
{
	m_2dui.clear();
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 2DUiの取得
//-------------------------------------------------------------------------------------------------------------
CUi2d * CTitleUI::Get2dui(int nIndex)
{
#ifdef _DEBUG
	if (CTitleUI::TYPE_NONE >= nIndex &&nIndex >= CTitleUI::TYPE_MAX)
	{
		return nullptr;
	}
#endif
	return m_2dui[nIndex];
}

//-------------------------------------------------------------------------------------------------------------
// 1行ずつ読み込む
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::ReadFromLine(mystd::CLoadInitFile::READINFO& info, std::vector<CUi2d*> *p2dui)
{
	// 変数宣言
	std::vector<CUi2d*> *pSet = p2dui;
	if (strcmp(info.line, "SET_UI") == 0)
	{
		m_bSetingUI = true;
	}
	else
	{// パラメータを設定
		ReadFromLineSetParam(info.line, pSet);
	}
}

//-------------------------------------------------------------------------------------------------------------
// パラメータを設定
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::ReadFromLineSetParam(CONST_STRING line, std::vector<CUi2d*> *p2dui)
{
	char aData[MYLIB_STRINGSIZE] = {};
	int nData = 0;
	D3DXCOLOR float4 = D3DXCOLOR(0.0f,0.0f,0.0f,0.0f);

	// 終了ポインタが来た時
	if (strcmp(line, "}") == 0)
	{
		if (m_bSetingUI)
		{
			m_bSetingUI = false;
			p2dui->push_back(CUi2d::Create(m_Seting));
		}
	}
	else
	{
		// UIタイプ
		if (sscanf(line, "UI_TYPE = %s", aData) == 1)
		{

		}
		// 原点ID
		else if (sscanf(line, "ORIGINTYPEID = %d", &nData) == 1)
		{
			m_Seting.nOriginType = nData;
 		}
		// 位置
		else if (sscanf(line, "POS = %f %f %f", &float4.r, &float4.g, &float4.b) == 3)
		{
			m_Seting.pos = D3DXVECTOR3(float4.r , float4.g, float4.b);
		}
		// サイズ
		else if (sscanf(line, "SIZE = %f %f", &float4.r, &float4.g) == 2)
		{
			m_Seting.size = D3DXVECTOR2(float4.r, float4.g);
		}
		// 回転
		else if (sscanf(line, "ROTATION = %f", &float4.r) == 1)
		{
			m_Seting.fRotation = float4.r;
		}
		// 色
		else if (sscanf(line, "COL = %f %f %f %f", &float4.r, &float4.g, &float4.b, &float4.a) == 4)
		{
			m_Seting.col = float4;
		}
		// テクスチャタイプの設定
		else if (sscanf(line, "TEXTURETYPE = %d", &nData) == 1)
		{
			m_Seting.nTextureID = nData;
		}
		// スクリプトファイル
		else if (sscanf(line, "SCRIPTFILE = %s", aData) == 1)
		{

		}
	}
}

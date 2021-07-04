//*************************************************************************************************************
//
// 2DUI処理[2DUI.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Ui2d.h"
#include "keyboard.h"
#include "TextureManager.h"
#include "Component\transform.h"

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CUi2d * CUi2d::Create(ui2d::SETING &seting, PRIORITY pri)
{
	CUi2d * pC2dui = new CUi2d(pri);
	pC2dui->Init(seting, pri);
	return pC2dui;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CUi2d::Init(ui2d::SETING & seting, PRIORITY pri)
{
	AddComponent<_MYSTD Transform2D>();
	auto test = GetComponent<_MYSTD Transform2D>();
	Destroy(test);
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CUi2d::Init(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CUi2d::Uninit(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void CUi2d::Update(void)
{

}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CUi2d::Draw(void)
{
}
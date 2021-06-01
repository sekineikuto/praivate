//*************************************************************************************************************
//
// ポリゴン処理[Polygon.cpp]
// Author:Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
int CScene::m_nNumAll = 0;
CScene *CScene::m_pTop[PRIORITY::PRIORITY_MAX] = { nullptr };		// 先頭へのオブジェクトポインタ
CScene *CScene::m_pCur[PRIORITY::PRIORITY_MAX] = { nullptr };		// 最後尾オブジェクトへのポインタ

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CScene::CScene(PRIORITY priority)
{
	m_bDie = false;
	m_priority = priority;
	++m_nNumAll;

	if (m_pTop[priority] == nullptr&&m_pCur[priority] == nullptr)
		m_pTop[priority] = this;

	m_pNext = nullptr;
	m_pPrev = m_pCur[priority];

	if (m_pPrev != nullptr)
		m_pPrev->m_pNext = this;

	m_pCur[priority] = this;
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
CScene::~CScene()
{
	// 総数を減らす
	m_nNumAll--;
}

//-------------------------------------------------------------------------------------------------------------
// 更新処理
//-------------------------------------------------------------------------------------------------------------
void CScene::UpdataAll(void)
{
	for (auto pScene : m_pTop)
	{
		if (pScene == nullptr)
			continue;

		while (pScene != nullptr)
		{
			CScene * pSceneNext = pScene->m_pNext;
			pScene->Update();
			pScene = pSceneNext;
		}
	}

	for (auto pScene : m_pTop)
	{
		if (pScene == nullptr)
			continue;

		while (pScene != nullptr)
		{
			CScene * pSceneNext = pScene->m_pNext;
			if (pScene->m_bDie)
				pScene->ListRelease();
			pScene = pSceneNext;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// 描画処理
//-------------------------------------------------------------------------------------------------------------
void CScene::DrawAll(void)
{
	for (auto pScene : m_pTop)
	{
		if (pScene == nullptr)
			continue;

		while (pScene != nullptr)
		{
			CScene * pSceneNext = pScene->m_pNext;
			pScene->Draw();
			pScene = pSceneNext;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// 開放処理
//-------------------------------------------------------------------------------------------------------------
void CScene::ReleaseAll(void)
{
	for (auto pScene : m_pTop)
	{
		if (pScene == nullptr)
			continue;

		while (pScene != nullptr)
		{
			CScene * pSceneNext = pScene->m_pNext;
			pScene->ListRelease();
			pScene = pSceneNext;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// 開放処理
//-------------------------------------------------------------------------------------------------------------
void CScene::Release(void)
{
	if (m_bDie == false)
	{
		m_bDie = true;
	}
}

//-------------------------------------------------------------------------------------------------------------
// リストからの開放処理
//-------------------------------------------------------------------------------------------------------------
void CScene::ListRelease(void)
{
	// 終了処理
	Uninit();

	// 最後の時
	if (this == m_pCur[m_priority] && this == m_pTop[m_priority]) {
		m_pCur[m_priority] = nullptr;
		m_pTop[m_priority] = nullptr;
	}
	// 先頭の時
	else if (this == m_pTop[m_priority]) {
		m_pTop[m_priority] = m_pNext;
		m_pNext->m_pPrev = nullptr;
	}
	// 最後尾の時
	else if (this == m_pCur[m_priority]) {
		m_pCur[m_priority] = m_pPrev;
		m_pPrev->m_pNext = nullptr;
	}
	else {
		m_pNext->m_pPrev = m_pPrev;
		m_pPrev->m_pNext = m_pNext;
	}

	// 破棄
	delete this;
}

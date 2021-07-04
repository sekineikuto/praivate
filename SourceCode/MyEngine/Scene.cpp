//*************************************************************************************************************
//
// �|���S������[Polygon.cpp]
// Author:Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// �ÓI�����o�ϐ��̏�����
//-------------------------------------------------------------------------------------------------------------
int CScene::m_nNumAll = 0;
CScene *CScene::m_pTop[PRIORITY::PRIORITY_MAX] = { nullptr };		// �擪�ւ̃I�u�W�F�N�g�|�C���^
CScene *CScene::m_pCur[PRIORITY::PRIORITY_MAX] = { nullptr };		// �Ō���I�u�W�F�N�g�ւ̃|�C���^

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CScene::~CScene()
{
	// ���������炷
	m_nNumAll--;
}

//-------------------------------------------------------------------------------------------------------------
// �X�V����
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
// �`�揈��
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
// �J������
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
// �J������
//-------------------------------------------------------------------------------------------------------------
void CScene::Release(void)
{
	if (m_bDie == false)
	{
		m_bDie = true;
	}
}

//-------------------------------------------------------------------------------------------------------------
// ���X�g����̊J������
//-------------------------------------------------------------------------------------------------------------
void CScene::ListRelease(void)
{
	// �I������
	Uninit();

	// �Ō�̎�
	if (this == m_pCur[m_priority] && this == m_pTop[m_priority]) {
		m_pCur[m_priority] = nullptr;
		m_pTop[m_priority] = nullptr;
	}
	// �擪�̎�
	else if (this == m_pTop[m_priority]) {
		m_pTop[m_priority] = m_pNext;
		m_pNext->m_pPrev = nullptr;
	}
	// �Ō���̎�
	else if (this == m_pCur[m_priority]) {
		m_pCur[m_priority] = m_pPrev;
		m_pPrev->m_pNext = nullptr;
	}
	else {
		m_pNext->m_pPrev = m_pPrev;
		m_pPrev->m_pNext = m_pNext;
	}

	// �j��
	delete this;
}

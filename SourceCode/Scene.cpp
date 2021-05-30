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
CScene *CScene::m_pTop[PRIORITY::PRIORITY_MAX] = {};		// �擪�ւ̃I�u�W�F�N�g�|�C���^
CScene *CScene::m_pCur[PRIORITY::PRIORITY_MAX] = {};		// ����(�Ō��)�I�u�W�F�N�g�ւ̃|�C���^
std::list<CScene*> CScene::m_list[PRIORITY_MAX];

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CScene::CScene(PRIORITY order)
{

	this->m_nPriority = order;		//�`��D�揇�ʂ̔ԍ�
	m_priority = order;

	CScene *pScene = m_pTop[m_nPriority];

	if (m_pTop[m_nPriority] == nullptr&&
		m_pCur[m_nPriority] == nullptr)
	{
		m_pTop[m_nPriority] = this;
	}

	m_pNext = nullptr;

	m_pPrev = m_pCur[m_nPriority];

	if (m_pPrev != nullptr)
	{
		m_pPrev->m_pNext = this;
	}

	m_pCur[m_nPriority] = this;
	m_nNumAll++;

	// ���X�g�^�ɑ}������
	m_list[order].push_back(this);
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CScene::~CScene()
{
}

//-------------------------------------------------------------------------------------------------------------
// �X�V����
//-------------------------------------------------------------------------------------------------------------
void CScene::UpdataAll(void)
{
	//for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	//{
	//	if (m_pTop[nCntPriority] != nullptr)
	//	{
	//		CScene * pScene = m_pTop[nCntPriority];
	//		while (pScene != nullptr)
	//		{
	//			CScene * pSceneNext = pScene->m_pNext;
	//			pScene->Update();
	//			pScene = pSceneNext;
	//		}
	//	}
	//}

	//for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	//{
	//	if (m_pTop[nCntPriority] != nullptr)
	//	{
	//		CScene * pScene = m_pTop[nCntPriority];
	//		while (pScene != nullptr)
	//		{
	//			CScene * pSceneNext = pScene->m_pNext;
	//			if (pScene->m_bDie)
	//			{
	//				pScene->ListRelease();
	//			}
	//			pScene = pSceneNext;
	//		}
	//	}
	//}

	for (auto list : m_list)
	{
		for (auto scene : list)
		{
			scene->Update();
		}
	}

	for (auto list : m_list)
	{
		for (auto it = list.begin(); it != list.end();)
		{
			if (((CScene *)it._Ptr)->m_bDie)
			{
				// �폜���ꂽ�v�f�̎����w���C�e���[�^���Ԃ����B
				it = list.erase(it);
			}
			// �v�f�폜�����Ȃ��ꍇ�ɁA�C�e���[�^��i�߂�
			else
			{
				++it;
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// �`�揈��
//-------------------------------------------------------------------------------------------------------------
void CScene::DrawAll(void)
{
	//for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	//{
	//	if (m_pTop[nCntPriority] != nullptr)
	//	{
	//		CScene * pScene = m_pTop[nCntPriority];
	//		while (pScene != nullptr)
	//		{
	//			CScene * pSceneNext = pScene->m_pNext;
	//			pScene->Draw();
	//			pScene = pSceneNext;
	//		}
	//	}
	//}
	for (auto list : m_list)
	{
		for (auto scene : list)
		{
			scene->Draw();
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// �J������
//-------------------------------------------------------------------------------------------------------------
void CScene::ReleaseAll(void)
{
	//for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	//{
	//	if (m_pTop[nCntPriority] != nullptr)
	//	{
	//		CScene * pScene = m_pTop[nCntPriority];
	//		while (pScene != nullptr)
	//		{
	//			CScene * pSceneNext = pScene->m_pNext;
	//			pScene->ListRelease();
	//			pScene = pSceneNext;
	//		}
	//	}
	//}

	for (auto list : m_list)
	{
		for (auto it = list.begin(); it != list.end();)
		{
			it = list.erase(it);
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// �v���C���[�̃V�[����Ԃ�
//-------------------------------------------------------------------------------------------------------------
CScene * CScene::GetPlayerScene(void)
{
	for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	{
		if (m_pTop[nCntPriority] != nullptr)
		{
			CScene * pScene = m_pTop[nCntPriority];
			while (pScene != nullptr)
			{
				CScene * pSceneNext = pScene->m_pNext;
				if (pScene->GetObjectTyoe() == TYPE::TYPE_PLAYER)
				{
					return pScene;
				}
				pScene = pSceneNext;
			}
		}
	}
	return nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// �V�[���̎擾
//-------------------------------------------------------------------------------------------------------------
CScene * CScene::GetScene(TYPE type)
{
	for (int nCntPriority = 0; nCntPriority < PRIORITY::PRIORITY_MAX; nCntPriority++)
	{
		if (m_pTop[nCntPriority] != nullptr)
		{
			CScene * pScene = m_pTop[nCntPriority];
			while (pScene != nullptr)
			{
				CScene * pSceneNext = pScene->m_pNext;
				if (pScene->GetObjectTyoe() == type)
				{
					return pScene;
				}
				pScene = pSceneNext;
			}
		}
	}
	return nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// �擪�̃|�C���^�̎擾
//-------------------------------------------------------------------------------------------------------------
CScene * CScene::GetTop(int nPriority)
{
	return m_pTop[nPriority];
}

//-------------------------------------------------------------------------------------------------------------
// ���̃|�C���^
//-------------------------------------------------------------------------------------------------------------
CScene * CScene::GetNext(void)
{
	return m_pNext;
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
	this->Uninit();
	if (this == m_pCur[this->m_nPriority] && this == m_pTop[this->m_nPriority])
	{	//�Ō�̈��
		m_pCur[this->m_nPriority] = nullptr;
		m_pTop[this->m_nPriority] = nullptr;
	}
	else if (this == m_pTop[this->m_nPriority])
	{	//Top�̎�
		m_pTop[m_nPriority] = this->m_pNext;
		this->m_pNext->m_pPrev = nullptr;
	}
	else if (this == m_pCur[this->m_nPriority])
	{	//Cur�̎�
		m_pCur[m_nPriority] = this->m_pPrev;
		this->m_pPrev->m_pNext = nullptr;
	}
	else
	{	//����
		this->m_pNext->m_pPrev = this->m_pPrev;
		this->m_pPrev->m_pNext = this->m_pNext;
	}
	//�t���O���������������
	delete this;
	m_nNumAll--;
}

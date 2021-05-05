//*************************************************************************************************************
//
// �n�b�V������ [myhash.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "myhash.h"

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CHash * CHash::Create(void)
{
	// ����
	CHash *pHsh = new CHash;
	// �n�b�V���e�[�u���̍쐬
	pHsh->MakeHashtable();
	return pHsh;
}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���e�[�u���̍쐬
//-------------------------------------------------------------------------------------------------------------
void CHash::MakeHashtable(void)
{
	// �n�b�V���e�[�u���̗̈�̊m��
	m_ppCell = new HASHCELL*[MYHASH_BUCKET_SIZE];
	// �n�b�V���̏�����
	Init();
}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���e�[�u���̊J��
//-------------------------------------------------------------------------------------------------------------
void CHash::ReleaseHashtable(void)
{
	// �n�b�V���e�[�u�����������
	ListFree();

	// �n�b�V���e�[�u���̗̈�J��
	delete[]m_ppCell;
	m_ppCell = nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// �������֐�
//-------------------------------------------------------------------------------------------------------------
void CHash::Init(void)
{
	// �n�b�V���e�[�u����NULL�ŏ���������
	for (int nCntSize = 0; nCntSize < MYHASH_BUCKET_SIZE; nCntSize++)
	{
		m_ppCell[nCntSize] = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// ���X�g�̊J��
//-------------------------------------------------------------------------------------------------------------
void CHash::ListFree(void)
{
	// �ϐ��錾
	HASHCELL *pTemp = nullptr;		// �ꎞ�i�[�p�|�C���^
	HASHCELL *pSwap = nullptr;		// �����p�|�C���^

	// �T�C�Y�����[�v
	for (int nCntSize = 0; nCntSize < MYHASH_BUCKET_SIZE; nCntSize++)
	{
		// �ꎞ�I�Ɋi�[
		pTemp = m_ppCell[nCntSize];

		// ���X�g�̊J��
		while (pTemp != nullptr)
		{
			// ���̃|�C���^�������p�ɑ��
			pSwap = pTemp->pNext;
			// �e�[�u�����̊J��
			HashCellFree(pTemp);
			// �����p����
			pTemp = pSwap;
		}
	}

	// �n�b�V���e�[�u���̏�����
	Init();
}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V����T�����āA�f�[�^���擾����
//-------------------------------------------------------------------------------------------------------------
char *CHash::Search(char * pKey)
{
	// �ϐ��錾
	HASHCELL *pHash = m_ppCell[GetHashValue(pKey)];		// �n�b�V���|�C���^

	// NULL�ɂȂ�܂Ń��[�v
	while (pHash != nullptr)
	{// �L�[�Ɠ�����
		if (strcmp(pKey, pHash->pKey) == 0)
		{// �f�[�^��Ԃ�
			return pHash->pData;
		}
		// ���̃|�C���^����
		pHash = pHash->pNext;
	}

	return nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���e�[�u���ɓo�^����
//-------------------------------------------------------------------------------------------------------------
void CHash::Insert(char * pKey, char * pData)
{
	// �ϐ��錾
	HASHCELL *pRegis = nullptr;		// �o�^
	int       nHashvalue = 0;		// �n�b�V���l

	// �����L�[�����łɓo�^����Ă��邩�m�F����
	if (Search(pKey) != nullptr)
	{
		return;
	}

	// �Z���̈���m�ۂ���
	pRegis = new HASHCELL;
	if (pRegis == nullptr)
	{
		return;
	}

	// �L�[���Z���ɕۑ�����
	if (StrAllocAndCopy(&(pRegis->pKey), pKey) != 0)
	{
		return;
	}
	// �f�[�^���Z���ɕۑ�����
	if (StrAllocAndCopy(&(pRegis->pData), pData) != 0)
	{
		return;
	}

	// �n�b�V���e�[�u���ɓo�^����
	nHashvalue = GetHashValue(pKey);
	// ���̃|�C���^�ɑ������
	pRegis->pNext = m_ppCell[nHashvalue];
	// �Z���ɑ������
	m_ppCell[nHashvalue] = pRegis;

	return;

}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���e�[�u������폜����
//-------------------------------------------------------------------------------------------------------------
void CHash::Delete(char * pKey)
{
	// �ϐ��錾
	HASHCELL *pTarget = nullptr;				// �^�[�Q�b�g�p�|�C���^
	HASHCELL *pChain = nullptr;				// �`�F�C���p�|�C���^
	int nHashValue = GetHashValue(pKey);	// �n�b�V���l

	// �^�[�Q�b�g�|�C���^�̐ݒ�
	pTarget = m_ppCell[nHashValue];
	// �^�[�Q�b�g��NULL�̎�
	if (pTarget == nullptr)
	{
		return;
	}
	// �`�F�C���p�̃|�C���^�̐ݒ�
	pChain = pTarget->pNext;

	// ���X�g�̐擪�v�f���폜����ꍇ
	if (strcmp(pKey, pTarget->pKey) == 0)
	{// �`�F�C���p�̃|�C���^����
		m_ppCell[nHashValue] = pChain;
		// �^�[�Q�b�g���J��
		HashCellFree(pTarget);
		return;
	}

	// �擪�ȊO�̗v�f���폜����ꍇ
	while (pTarget != nullptr)
	{// �L�[�������Ƃ�
		if (strcmp(pKey, pTarget->pKey) == 0)
		{// ���̃|�C���^�Ȃ�
			pChain->pNext = pTarget->pNext;
			// �^�[�Q�b�g�̊J��
			HashCellFree(pTarget);
			return;
		}
		// �^�[�Q�b�g���`�F�C���p�ɑ��
		pChain = pTarget;
		// ���̃^�[�Q�b�g�|�C���^��ݒ肷��
		pTarget = pTarget->pNext;
	}

	return;
}


//=============================================================================================================
// �����֐�
//=============================================================================================================

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���Z���̊J��
//-------------------------------------------------------------------------------------------------------------
void CHash::HashCellFree(HASHCELL *pCell)
{
	// �L�[�̊J��
	if (pCell->pKey != nullptr)
	{
		delete[]pCell->pKey;
	}
	// �f�[�^�̊J��
	if (pCell->pData != nullptr)
	{
		delete[]pCell->pData;
	}
	// �Z���̊J��
	delete pCell;
}

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���l�̎擾
//-------------------------------------------------------------------------------------------------------------
int CHash::GetHashValue(char *pKey)
{
	// �ϐ��錾
	int nHashval = 0;	// �n�b�V���l
#ifdef HASHVALUE_BASE_PRIME
	int nCntKey;		// �L�[�J�E���g
	for (nCntKey = 0; pKey[nCntKey] != '\0'; nCntKey++)
	{
		nHashval = (nHashval * HASHVALUE_BASE_PRIME + (pKey[nCntKey] & 0xff)) % MYHASH_BUCKET_SIZE;
	}
	return nHashval;
#else 
	// �L�[�|�C���^��NULL�ɂȂ�܂�
	while (*pKey != MYLIB_CHAR_UNSET)
	{
		// �n�b�V���l�ɑ��
		nHashval += *pKey;
		// �|�C���^��i�߂�
		*pKey++;
	}
	// �n�b�V���l���T�C�Y�̗]���Ԃ�
	return nHashval % MYHASH_BUCKET_SIZE;
#endif
}

//-------------------------------------------------------------------------------------------------------------
// ������̗̈���m�ۂ��ăR�s�[����
//-------------------------------------------------------------------------------------------------------------
int CHash::StrAllocAndCopy(char **pOut, char *pSource)
{
	// �ϐ��錾
	int nLength = 0;	// ������̒���

	// ������̒������Z�o + NULL
	nLength = strlen(pSource) + 1;
	// ������̒�����0�ȉ��̎��G���[��Ԃ�
	if (nLength <= 0)
	{
		return MYLIB_FAILURE;
	}
	// �A�E�g�v�b�g�̐���
	*pOut = new char[nLength];
	// �����Ɏ��s�������G���[��Ԃ�
	if (*pOut == nullptr)
	{
		return MYLIB_FAILURE;
	}
	// ������̃R�s�[(���s�������G���[��Ԃ�)
	if (strncpy(*pOut, pSource, nLength) == nullptr)
	{
		return MYLIB_FAILURE;
	}
	//�@������������
	return MYLIB_SUCCESS;
}

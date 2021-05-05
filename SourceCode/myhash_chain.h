//*************************************************************************************************************
//
// �n�b�V���`�F�C������ [myhash_chain.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MYHASH_CHAIN_H_
#define _MYHASH_CHAIN_H_

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //_CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
/* �n�b�V���e�[�u���̗v�f�� */
#define MYHASH_CHAIN_BUCKET_SIZE         19
// �n�b�V���l�𐶐����鎞�̑f��
#define MYHASH_CHAIN_VALUE_BASE_PRIME    3571
//#undef MYHASH_CHAIN_VALUE_BASE_PRIME

//-------------------------------------------------------------------------------------------------------------
// �n�b�V���N���X
//-------------------------------------------------------------------------------------------------------------
class CHash_chain
{
public:
	typedef struct _HASHCELL
	{
		char*      pKey;		// �L�[
		void*      pData;		// �f�[�^
		_HASHCELL* pNext;		// ���̃|�C���^
	} HASHCELL;

	/* �����o�֐� */
	static CHash_chain* Create(void);						// ����
	void                MakeHashtable(void);				// �n�b�V���e�[�u���̍쐬
	void                ReleaseHashtable(void);				// �n�b�V���e�[�u���̊J��
	void                Init(void);							// �������֐�
	void                ListFree(void);						// ���X�g�̊J������
	void*               Search(char *pKey);					// �n�b�V����T�����āA�f�[�^���擾����
	void                Insert(char *pKey, void *pData);	// �n�b�V���e�[�u���ɓo�^����
	void                Delete(char *pKey);					// �n�b�V���e�[�u������폜����

private:
	/* �����֐� */
	static void         HashCellFree(HASHCELL* pTable);					// �n�b�V���Z���̊J��
	static int          GetHashValue(char *pKey);						// �n�b�V���l�̎擾
	static int          StrAllocAndCopy(char **pOut, char *pSource);	// ������̗̈���m�ۂ��ăR�s�[����
	
	/* �����o�ϐ� */
	HASHCELL  **m_ppCell;												// �Z���̃_�u���|�C���^

};
#endif //_MYHASH_CHAIN_H_
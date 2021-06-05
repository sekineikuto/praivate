//*************************************************************************************************************
//
// �e�N�X�`���}�l�[�W���[����[TextureManager.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mystd\types.h"
#include "TextfileController.h"
#include <vector>
#include <iostream>
#include "d3dx9.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CTextureManager
{
public:
	/* �����o�֐� */
	CTextureManager();													// �R���X�g���N�^
	~CTextureManager();													// �f�X�g���N�^

	static CTextureManager* Create(void);								// �쐬
	static void Release(CTextureManager * src);							// �J��

	void               Load(void);										// �ǂݍ���
	void               Unload(void);									// �J��
	LPDIRECT3DTEXTURE9 GetTextureInfo(int nIndex);						// �e�N�X�`���̎擾
	int                GetNumTextureMax(void);							// �e�N�X�`�����̍ő�
	CSTRING            GetFileName(const int nIndex);					// �t�@�C�����̎擾
private:
	/* �����o�֐� */
	static void ReadFromLine(CLoadInitFile::READINFO& info, std::vector<std::string> *filename);	// 1�s���ǂݍ���

	/* �����o�ϐ� */
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;							// �e�N�X�`�����̃|�C���^
	std::vector<std::string>        m_pFileName;						// �t�@�C�����̃|�C���^
	int                             m_nNumTextureMax;					// �ő�e�N�X�`����
};
#endif
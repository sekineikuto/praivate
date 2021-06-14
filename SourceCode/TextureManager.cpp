//*************************************************************************************************************
//
// �e�N�X�`���}�l�[�W���[����[TextureManager.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "TextureManager.h"
#include "manager.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CTextureManager::CTextureManager()
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CTextureManager::~CTextureManager()
{
	Unload();
}

//-------------------------------------------------------------------------------------------------------------
// �쐬
//-------------------------------------------------------------------------------------------------------------
CTextureManager * CTextureManager::Create(void)
{
	CTextureManager * ptr = new CTextureManager;
	ptr->Load();
	return ptr;
}

//-------------------------------------------------------------------------------------------------------------
// �J��
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Release(CTextureManager * src)
{
	if (src == nullptr)
		return;
	delete src;
	src = nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`�����̃��[�h
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Load(void)
{
	// �ϐ��錾
	LPDIRECT3DDEVICE9 pDevice;						// �f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer().GetDevice();		// �f�o�C�X�̎擾

	// �e�N�X�`�������擾
	mystd::CLoadInitFile::LoadFile(CManager::GetFIleName(CManager::FILE_TEXTURE), &m_pFileName, ReadFromLine);

	// �e�N�X�`�����̐��v�f�𑝂₷
	m_pTexture.reserve(m_pFileName.size());

	// �e�N�X�`�����쐬
	for (std::string str : m_pFileName)
	{
		LPDIRECT3DTEXTURE9 SetingTexture;
		// �e�N�X�`���̓ǂݍ���
		if (D3DXCreateTextureFromFile(pDevice, str.data(), &SetingTexture) != D3D_OK)
		{

		}
		// �v�f�̑}��
		m_pTexture.push_back(SetingTexture);
	}

	m_nNumTextureMax = m_pTexture.size();
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`�������A�����[�h
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Unload(void)
{
	// �t�@�C�������폜
	for (auto & str : m_pFileName)
	{
		str.clear();
		str.shrink_to_fit();
	}
	m_pFileName.clear();
	m_pFileName.shrink_to_fit();

	// �e�N�X�`�����̊J��
	for (auto& texture : m_pTexture)
	{
		if (texture != nullptr)
		{
			texture->Release();
			texture = nullptr;
		}
	}

	m_pTexture.clear();
	m_pTexture.shrink_to_fit();
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`�����̎擾
//-------------------------------------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 CTextureManager::GetTextureInfo(int nIndex)
{
	return m_pTexture[nIndex];
}

//-------------------------------------------------------------------------------------------------------------
// �ő�e�N�X�`�����̎擾
//-------------------------------------------------------------------------------------------------------------
int CTextureManager::GetNumTextureMax(void)
{
	return m_nNumTextureMax;
}

//-------------------------------------------------------------------------------------------------------------
// �t�@�C�����̎擾
//-------------------------------------------------------------------------------------------------------------
_MYSTD CSTRING CTextureManager::GetFileName(const int nIndex)
{
	return m_pFileName[nIndex].data();
}

//-------------------------------------------------------------------------------------------------------------
// ��s����ǂݎ��
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::ReadFromLine(mystd::CLoadInitFile::READINFO & info, std::vector<std::string>* filename)
{
	char aData[128] = { '\0' };
	int nNumber = 0;

	if (info.entrydata == nullptr ||
		info.entrydata == nullptr)
	{
		return;
	}

	if (sscanf(info.line, "FILENAME = %s", &aData[0]) == 1)
	{
		filename->push_back(std::string(aData));
	}
	else if (sscanf(info.line, "NUMBER = %d", &nNumber) == 1)
	{
		// ���e�ʂ�ύX����
		filename->reserve(nNumber);
	}
}

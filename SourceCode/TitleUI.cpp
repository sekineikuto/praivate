//*************************************************************************************************************
//
// �^�C�g��UI���� [TitleUI.cpp]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "TitleUI.h"
#include "manager.h"


//-------------------------------------------------------------------------------------------------------------
// �ÓI�����o�ϐ��̏�����
//-------------------------------------------------------------------------------------------------------------
ui2d::SETING CTitleUI::m_Seting;						// �ݒ�
bool CTitleUI::m_bSetingUI = false;

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CTitleUI * CTitleUI::Create(void)
{
	CTitleUI *pTitleUI = new CTitleUI;
	pTitleUI->Init();
	return pTitleUI;
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Init(void)
{
	// �t�@�C������ǂݍ���
	mystd::CLoadInitFile::LoadFile(CManager::GetFIleName(CManager::FILE_TITLEUI), &m_2dui, ReadFromLine);


	std::vector<std::string> test;
	mystd::CLoadFile::GetSplit(CManager::GetFIleName(CManager::FILE_TITLEUI), test);
	test.clear();
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Uninit(void)
{
	m_2dui.clear();
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 2DUi�̎擾
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
// 1�s���ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::ReadFromLine(mystd::CLoadInitFile::READINFO& info, std::vector<CUi2d*> *p2dui)
{
	// �ϐ��錾
	std::vector<CUi2d*> *pSet = p2dui;
	if (strcmp(info.line, "SET_UI") == 0)
	{
		m_bSetingUI = true;
	}
	else
	{// �p�����[�^��ݒ�
		ReadFromLineSetParam(info.line, pSet);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �p�����[�^��ݒ�
//-------------------------------------------------------------------------------------------------------------
void CTitleUI::ReadFromLineSetParam(CONST_STRING line, std::vector<CUi2d*> *p2dui)
{
	char aData[MYLIB_STRINGSIZE] = {};
	int nData = 0;
	D3DXCOLOR float4 = D3DXCOLOR(0.0f,0.0f,0.0f,0.0f);

	// �I���|�C���^��������
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
		// UI�^�C�v
		if (sscanf(line, "UI_TYPE = %s", aData) == 1)
		{

		}
		// ���_ID
		else if (sscanf(line, "ORIGINTYPEID = %d", &nData) == 1)
		{
			m_Seting.nOriginType = nData;
 		}
		// �ʒu
		else if (sscanf(line, "POS = %f %f %f", &float4.r, &float4.g, &float4.b) == 3)
		{
			m_Seting.pos = D3DXVECTOR3(float4.r , float4.g, float4.b);
		}
		// �T�C�Y
		else if (sscanf(line, "SIZE = %f %f", &float4.r, &float4.g) == 2)
		{
			m_Seting.size = D3DXVECTOR2(float4.r, float4.g);
		}
		// ��]
		else if (sscanf(line, "ROTATION = %f", &float4.r) == 1)
		{
			m_Seting.fRotation = float4.r;
		}
		// �F
		else if (sscanf(line, "COL = %f %f %f %f", &float4.r, &float4.g, &float4.b, &float4.a) == 4)
		{
			m_Seting.col = float4;
		}
		// �e�N�X�`���^�C�v�̐ݒ�
		else if (sscanf(line, "TEXTURETYPE = %d", &nData) == 1)
		{
			m_Seting.nTextureID = nData;
		}
		// �X�N���v�g�t�@�C��
		else if (sscanf(line, "SCRIPTFILE = %s", aData) == 1)
		{

		}
	}
}

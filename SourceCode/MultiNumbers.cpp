//*************************************************************************************************************
//
// ���������񏈗�[NumericString.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "MultiNumbers.h"
#include "number.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CMultiNumbers::CMultiNumbers() : CScene(CScene::PRIORITY_2DUI)
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CMultiNumbers::~CMultiNumbers()
{
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CMultiNumbers * CMultiNumbers::Create(D3DXVECTOR3 pos, D3DXCOLOR col, D3DXVECTOR2 size, float fRotation, int nValue)
{
	CMultiNumbers *pMultiNUmbers = new CMultiNumbers(CScene::PRIORITY_2DUI);
	pMultiNUmbers->Init(pos, col, size, fRotation, nValue);
	pMultiNUmbers->SetObjectType(CScene::TYPE::TYPE_UI);
	return pMultiNUmbers;
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::Init(D3DXVECTOR3 & pos, D3DXCOLOR & col, D3DXVECTOR2 & size, float & fRotation, int & nValue)
{
	m_col = col;			// �F
	m_pos = pos;			// �ʒu
	m_size = size;			// �傫��
	m_nValue = nValue;		// ���Ԃ̒l
	m_nAddSign = -1;		// ���Z���镄��
	m_fRotation = fRotation;

	// ��������g�������Z�o
	m_nDigits = 0;
	CMylibrary::GetDigits(m_nDigits, m_nValue);
	m_nNumNumber = m_nDigits;

	// ���������m��
	m_pNumber = new CNumber[m_nNumNumber];

	// �g�����������[�v
	for (int nCntNumber = 0; nCntNumber < m_nNumNumber; nCntNumber++)
	{// ���̐������Z�o
		int nDigits =
			m_nValue %
			(int)powf(10.0f, (float)m_nNumNumber - nCntNumber) /
			(int)powf(10.0f, (float)m_nNumNumber - 1.0f - nCntNumber);
		// �ʒu�̐ݒ�
		D3DXVECTOR3 pos;
		pos.x = m_pos.x + (sinf(m_fRotation + D3DX_PI*0.5f)*nCntNumber*(m_size.x * 2.0f));
		pos.y = m_pos.y + (cosf(m_fRotation + D3DX_PI*0.5f)*nCntNumber*(m_size.x * 2.0f));
		pos.z = 0.0f;
		// ������
		m_pNumber[nCntNumber].Init(m_size.x, m_size.y, nDigits, m_fRotation, pos, m_col);
	}
	// �������o��
	m_nNumDiff = m_nNumNumber - m_nDigits;
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::Uninit(void)
{
	if (m_pNumber != nullptr)
	{
		m_pNumber->Unint();
		delete[]m_pNumber;
		m_pNumber = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::Update(void)
{
	// �������������l�ɂ���
	m_nDigits = 0;
	// ���������߂�
	CMylibrary::GetDigits(m_nDigits, m_nValue);
	// ���������[�v
	for (int nCntNumber = 0; nCntNumber < m_nNumNumber; nCntNumber++)
	{// ���̐������Z�o
		int nDigits =
			m_nValue %
			(int)powf(10.0f, (float)m_nNumNumber - nCntNumber) /
			(int)powf(10.0f, (float)m_nNumNumber - 1.0f - nCntNumber);
		// ���_���̐ݒ�
		m_pNumber[nCntNumber].SetVaetex(&nDigits);
	}

	// �������o��
	m_nNumDiff = m_nNumNumber - m_nDigits;
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::Draw(void)
{
	// �g���������[�v
	for (int nCntNumber = 0; nCntNumber < m_nNumNumber; nCntNumber++)
	{//�������J�E���g�ȉ���������
	 //if (m_nNumDiff <= nCntNumber)
		{// �`��
			m_pNumber[nCntNumber].Draw();
		}
	}
}

//-------------------------------------------------------------------------------------------------------------
// �l�̉��Z
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::AddValue(void)
{
	// �J�n�l�ɕ��������Z
	m_nValue += m_nAddSign;
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`���̘A��
//-------------------------------------------------------------------------------------------------------------
void CMultiNumbers::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	for (int nCntNumber = 0; nCntNumber < m_nNumNumber; nCntNumber++)
	{
		m_pNumber[nCntNumber].BindTexture(pTexture);
	}
}

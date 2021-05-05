//*************************************************************************************************************
//
// �������� [number.cpp]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "number.h"
#include "manager.h"
#include "Scene2D.h"

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CNumber::CNumber(int nNumOrder)
{

}

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CNumber::CNumber()
{

}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CNumber::~CNumber()
{

}

//-------------------------------------------------------------------------------------------------------------
// �ǂݍ���
//-------------------------------------------------------------------------------------------------------------
HRESULT CNumber::Load(void)
{
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �J��
//-------------------------------------------------------------------------------------------------------------
void CNumber::Unload(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �쐬
//-------------------------------------------------------------------------------------------------------------
CNumber * CNumber::Create(float fSizeX, float fSizeY, D3DXVECTOR3 pos, float fRot, int nNumber, D3DXCOLOR col)
{
	// �i���o�[�̐���
	CNumber *pNumber = new CNumber;
	// ������
	pNumber->Init(fSizeX, fSizeY, nNumber, fRot, pos ,col);
	return pNumber;
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
HRESULT CNumber::Init(float fSizeX, float fSizeY, int nNumber, float fRot, D3DXVECTOR3 pos, D3DXCOLOR col)
{
	m_nNumber	= nNumber;		// ����
	m_size.x	= fSizeX;		// �傫��X
	m_size.y	= fSizeY;		// �傫��Y
	m_fRot		= fRot;			// ��]��
	m_pos		= pos;			// �ʒu 

	// �ӑ��錾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();	// �f�o�C�X�̃|�C���^

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(CRenderer::VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,									// ���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	// ���_���ւ̃|�C���^
	CRenderer::VERTEX_2D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_�̐ݒ�
	pVtx[0].pos.x = (pos.x + sinf(D3DX_PI + fRot)*fSizeY) + sinf(D3DX_PI*-0.5f + fRot)*fSizeX;
	pVtx[0].pos.y = (pos.y + cosf(D3DX_PI + fRot)*fSizeY) + cosf(D3DX_PI*-0.5f + fRot)*fSizeX;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = (pos.x + sinf(D3DX_PI + fRot)*fSizeY) + sinf(D3DX_PI*0.5f + fRot)*fSizeX;
	pVtx[1].pos.y = (pos.y + cosf(D3DX_PI + fRot)*fSizeY) + cosf(D3DX_PI*0.5f + fRot)*fSizeX;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = (pos.x + sinf(0.0f + fRot)*fSizeY) + sinf(D3DX_PI*-0.5f + fRot)*fSizeX;
	pVtx[2].pos.y = (pos.y + cosf(0.0f + fRot)*fSizeY) + cosf(D3DX_PI*-0.5f + fRot)*fSizeX;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = (pos.x + sinf(0.0f + fRot)*fSizeY) + sinf(D3DX_PI*0.5f + fRot)*fSizeX;
	pVtx[3].pos.y = (pos.y + cosf(0.0f + fRot)*fSizeY) + cosf(D3DX_PI*0.5f + fRot)*fSizeX;
	pVtx[3].pos.z = 0.0f;
	// �������W�̐ݒ�
	pVtx[0].rhw = 1.0f;		//  1.0f�ŌŒ�
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;
	// ���_�J���[�̐ݒ�
	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;
	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2((nNumber * 0.1f), 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f + (nNumber * 0.1f), 0.0f);
	pVtx[2].tex = D3DXVECTOR2((nNumber * 0.1f), 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + (nNumber * 0.1f), 1.0f);

	// ���_�f�[�^���A�����b�N
	m_pVtxBuff->Unlock();

	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CNumber::Unint(void)
{
	// ���_�o�b�t�@��NULL����Ȃ���
	if (m_pVtxBuff != NULL)
	{// ���_�o�b�t�@�̊J��
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CNumber::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void CNumber::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	// ���_�o�b�t�@���X�g���[���Ƀo�C���h
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(CRenderer::VERTEX_2D));

	// ���_�t�H�[�}�b�g�ݒ�
	pDevice->SetTexture(0, m_pTexture);

	// �e�N�X�`���̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �|���S���`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//-------------------------------------------------------------------------------------------------------------
// �����̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CNumber::SetNumber(int nNumber)
{
	m_nNumber = nNumber;
}

//-------------------------------------------------------------------------------------------------------------
// ���_�̍X�V
//-------------------------------------------------------------------------------------------------------------
void CNumber::SetVaetex(int * nNumber, D3DXVECTOR3 * pos, D3DXCOLOR * col)
{
	// ���_���ւ̃|�C���^
	CRenderer::VERTEX_2D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// �����|�C���^��NULL����Ȃ���
	if (nNumber != NULL)
	{// �e�N�X�`���̐ݒ�
		pVtx[0].tex = D3DXVECTOR2((*nNumber*0.1f), 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f + (*nNumber*0.1f), 0.0f);
		pVtx[2].tex = D3DXVECTOR2((*nNumber*0.1f), 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f + (*nNumber*0.1f), 1.0f);
	}
	// �ʒu�|�C���^��NULL����Ȃ���
	if (pos != NULL)
	{// �ʒu�̐ݒ�
		m_pos = *pos;
		pVtx[0].pos.x = (pos->x + sinf(D3DX_PI + m_fRot)*m_size.y) + sinf(D3DX_PI*-0.5f + m_fRot)*m_size.x;
		pVtx[0].pos.y = (pos->y + cosf(D3DX_PI + m_fRot)*m_size.y) + cosf(D3DX_PI*-0.5f + m_fRot)*m_size.x;
		pVtx[0].pos.z = 0.0f;
		pVtx[1].pos.x = (pos->x + sinf(D3DX_PI + m_fRot)*m_size.y) + sinf(D3DX_PI*0.5f + m_fRot)*m_size.x;
		pVtx[1].pos.y = (pos->y + cosf(D3DX_PI + m_fRot)*m_size.y) + cosf(D3DX_PI*0.5f + m_fRot)*m_size.x;
		pVtx[1].pos.z = 0.0f;
		pVtx[2].pos.x = (pos->x + sinf(0.0f + m_fRot)*m_size.y) + sinf(D3DX_PI*-0.5f + m_fRot)*m_size.x;
		pVtx[2].pos.y = (pos->y + cosf(0.0f + m_fRot)*m_size.y) + cosf(D3DX_PI*-0.5f + m_fRot)*m_size.x;
		pVtx[2].pos.z = 0.0f;
		pVtx[3].pos.x = (pos->x + sinf(0.0f + m_fRot)*m_size.y) + sinf(D3DX_PI*0.5f + m_fRot)*m_size.x;
		pVtx[3].pos.y = (pos->y + cosf(0.0f + m_fRot)*m_size.y) + cosf(D3DX_PI*0.5f + m_fRot)*m_size.x;
		pVtx[3].pos.z = 0.0f;
	}
	// �J���[�|�C���^��NULL����Ȃ���
	if (col != NULL)
	{// �F�̍X�V
		m_col = *col;
		pVtx[0].col = *col;
		pVtx[1].col = *col;
		pVtx[2].col = *col;
		pVtx[3].col = *col;
	}
	// ���_�f�[�^���A�����b�N
	m_pVtxBuff->Unlock();
}
//-------------------------------------------------------------------------------------------------------------
// ���_�J���[�ݒ�
//-------------------------------------------------------------------------------------------------------------
void CNumber::SetVeatexColor(void)
{
	// ���_���ւ̃|�C���^
	CRenderer::VERTEX_2D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	// ���_�f�[�^���A�����b�N
	m_pVtxBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// �傫���̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CNumber::SetSize(D3DXVECTOR2 * size)
{
	m_size = *size;
}

//-------------------------------------------------------------------------------------------------------------
// ��]�ʂ̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CNumber::SetRotation(float fRot)
{
	m_fRot = fRot;
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`�����̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CNumber::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

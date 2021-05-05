//*************************************************************************************************************
//
// �t�F�[�h�̏���[fade.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "fade.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// �ÓI�����o�ϐ��̏�����
//-------------------------------------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 CFade::m_pTexture = nullptr;
LPDIRECT3DVERTEXBUFFER9 CFade::m_pVtxBuff = nullptr;

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CFade::CFade()
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CFade::~CFade()
{
}

//-------------------------------------------------------------------------------------------------------------
// �ǂݍ���
//-------------------------------------------------------------------------------------------------------------
HRESULT CFade::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	// �e�N�X�`���̓ǂݍ���		
	if (FAILED(D3DXCreateTextureFromFile(pDevice, TEXTURE, &m_pTexture)))
	{
		return E_FAIL;
	}
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �J��
//-------------------------------------------------------------------------------------------------------------
void CFade::Unload(void)
{
	// �e�N�X�`���̊J��
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
HRESULT CFade::Init(CManager::MODE mode)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	// �I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(CRenderer::VERTEX_2D) * 4,	// �K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY, FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL)))
	{
		return E_FAIL;
	}

	m_fadeState = FADE_OUT;
	m_modeNext = mode;
	m_col = { 0.0f,0.0f,0.0f,1.0f };
	m_pos = { 0.0f,0.0f,0.0f };

	// ���_���ւ̃|�C���^
	CRenderer::VERTEX_2D *pVtx;

	// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	// ���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);
	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;
	// ���_�J���[�̐ݒ�
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;
	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	// ���_�f�[�^���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CFade::Uninit(void)
{
	// ���_�o�b�t�@�̊J��
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CFade::Update(void)
{
	// ���_���ւ̃|�C���^
	CRenderer::VERTEX_2D *pVtx;
	// �������Ă����Ԃ̎�
	if (m_fadeState != FADE_NONE)
	{
		// �t�F�[�h�C�����Ă���Ƃ�
		if (m_fadeState == FADE_IN)
		{
			m_col.a -= 0.05f;
			if (m_col.a <= 0.0f)
			{
				m_fadeState = FADE_NONE;
				m_col.a = 0.0f;
			}
			//m_pos.x += 21.0f;
			//if (m_pos.x > 1280.0f)
			//{
			//	// �t�F�[�h�I��
			//	m_pos.x = 1280.0f;
			//	m_fadeState = FADE_NONE;
			//}
		}
		// �t�F�[�h�A�E�g���Ă��鎞
		else if (m_fadeState == FADE_OUT)
		{
			m_col.a += 0.05f;
			if (m_col.a >= 1.0f)
			{
				m_col.a = 1.0f;
				m_fadeState = FADE_IN;
				CManager::SetMode(m_modeNext);
			}
			//m_pos.x += 20.0f;
			//if (m_pos.x > 0.0f)
			//{
			//	// �t�F�[�h�I��
			//	m_pos.x = 0.0f;
			//	m_fadeState = FADE_IN;
			//	CManager::SetMode(m_modeNext);
			//}
		}
		// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
		// ���_�J���[�̐ݒ�
		pVtx[0].col = m_col;
		pVtx[1].col = m_col;
		pVtx[2].col = m_col;
		pVtx[3].col = m_col;

		//pVtx[0].pos = D3DXVECTOR3(m_pos.x, 0.0f, 0.0f);
		//pVtx[1].pos = D3DXVECTOR3(m_pos.x + SCREEN_WIDTH, 0.0f, 0.0f);
		//pVtx[2].pos = D3DXVECTOR3(m_pos.x, SCREEN_HEIGHT, 0.0f);
		//pVtx[3].pos = D3DXVECTOR3(m_pos.x + SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);
		// ���_�f�[�^���A�����b�N����
		m_pVtxBuff->Unlock();
	}

}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void CFade::Draw(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();
	// ���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���Ƀo�C���h
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(CRenderer::VERTEX_2D));
	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);
	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);
	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CFade * CFade::Create(void)
{
	CFade *pFade = new CFade;
	return pFade;
}

//-------------------------------------------------------------------------------------------------------------
// �t�F�[�h�ݒ�
//-------------------------------------------------------------------------------------------------------------
bool CFade::SetFade(CManager::MODE mode)
{
	if (m_fadeState == FADE_NONE)
	{
		m_fadeState = FADE_OUT;
		m_modeNext = mode;
		m_col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);	// ������ʁi����)
		//m_pos = D3DXVECTOR3(-1280.0f, 0.0f, 0.0f);			// �ʒu
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------------
// �t�F�[�h��Ԃ̎擾
//-------------------------------------------------------------------------------------------------------------
CFade::FADE CFade::GetFadeState(void)
{
	return m_fadeState;
}

//*************************************************************************************************************
//
// �O������ [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "orbit.h"
#include "DebugProc.h"
#include "manager.h"
#include "TextureManager.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define ORBIT_NUM_HEIGHT			(1)		// �����̌�

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
COrbit::COrbit(CScene::PRIORITY priority) : CScene(priority)
{
}

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
COrbit::COrbit() :CScene(CScene::PRIORITY_3DEFFECT)
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
COrbit::~COrbit()
{
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
COrbit * COrbit::Create(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size, int nTextureID, D3DXCOLOR &col)
{
	// �N���X�̐���
	COrbit *pOrbit = new COrbit;
	// �e�N�X�`���}�l�[�W���[�̎擾
	CTextureManager*pTexManager = CManager::GetTextureManager();
	// �e�N�X�`���̐ݒ�
	pOrbit->BindTexture(pTexManager->GetTextureInfo(nTextureID));
	// ���̐ݒ�
	pOrbit->SetInfo(pMtxParent, nNumWidht, size, col);
	// ������
	pOrbit->Init();
	return pOrbit;
}

//-------------------------------------------------------------------------------------------------------------
// ���̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void COrbit::SetInfo(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size, D3DXCOLOR &col)
{
	m_nNumWidht		= nNumWidht;		// ���̌�
	m_size			= size;				// �傫��
	m_pMtxParent	= pMtxParent;		// �e�̃}�g���b�N�X���
	m_posOriggin = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);	// ���_
	m_posEdge = D3DXVECTOR3(0.0f, m_size.y, 0.0f);											// �[�̈ʒu
	m_col = col;						// �F
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void COrbit::Init(void)
{
	m_nNumVertex	= (m_nNumWidht + 1)*(ORBIT_NUM_HEIGHT + 1);									// �����_��
	m_nNumIndex		= ((m_nNumWidht + 1) * 2) * ORBIT_NUM_HEIGHT + 2 * (ORBIT_NUM_HEIGHT - 1);	// ���C���f�b�N�X��
	m_nNumPolygon	= ((m_nNumWidht * ORBIT_NUM_HEIGHT * 2) + 4 * (ORBIT_NUM_HEIGHT - 1));		// ���|���S����
	m_bDisp			= false;																	// �`��t���O

	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();
	// ���_���̍쐬
	MakeVatex(pDevice);
	// �C���f�b�N�X���̍쐬
	MakeIndex(pDevice);

	m_pPosOld     = new D3DXVECTOR3[m_nNumWidht];		// �O��̈ʒu
	m_pPosEdgeOld = new D3DXVECTOR3[m_nNumWidht];	// �؂���̑O��̈ʒu
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void COrbit::Uninit(void)
{
	if (m_pPosOld != NULL)
	{// �O��̈ʒu�̊J��
		delete[]m_pPosOld;
		m_pPosOld = NULL;
	}
	if (m_pPosEdgeOld != NULL)
	{// �؂���̑O��̈ʒu�̊J��
		delete[]m_pPosEdgeOld;
		m_pPosEdgeOld = NULL;
	}
	if (m_pVtexBuff != NULL)
	{// ���_�o�b�t�@�̊J��
		m_pVtexBuff->Release();
		m_pVtexBuff = NULL;
	}
	if (m_pIdxBuff != NULL)
	{// �C���f�b�N�X�o�b�t�@�̊J��
		m_pIdxBuff->Release();
		m_pIdxBuff = NULL;
	}
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void COrbit::Update(void)
{
	// ���_���̃|�C���^
	CRenderer::VERTEX_3D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_���̕ύX
	pVtx[0].pos = m_posOriggin;
	// �e�̃}�g���b�N�X����ݒ�
	pVtx[m_nNumWidht + 1].pos = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

	// �O��̈ʒu�Ɠ���ւ����Ă���
	for (int nCntOrbit = 0; nCntOrbit < m_nNumWidht; nCntOrbit++)
	{
		pVtx[nCntOrbit + 1].pos = m_pPosEdgeOld[nCntOrbit];
		pVtx[nCntOrbit + m_nNumWidht + 2].pos  = m_pPosOld[nCntOrbit];
	}

	for (int nCntOld = m_nNumWidht - 1; nCntOld > 0; nCntOld--)
	{
		m_pPosEdgeOld[nCntOld] = m_pPosEdgeOld[nCntOld - 1];
		m_pPosOld[nCntOld] = m_pPosOld[nCntOld - 1];
	}
	m_pPosEdgeOld[0] = m_posOriggin;
	m_pPosOld[0] = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

	// ���_�f�[�^���A�����b�N
	m_pVtexBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void COrbit::Draw(void)
{
	// �ϐ��錾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans , mtxWork;		// �v�Z�p�}�g���b�N�X

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// ����(�����)���J�����O����
	// �����_�[�X�e�[�g(���Z��������)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);				// ���u�����h���s��
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// ���\�[�X�J���[�̎w��
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�B�X�e�B�l�[�V�����J���[�̎w��

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);
	D3DXMatrixIdentity(&mtxWork);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld
		, &m_mtxWorld
		, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld
		, &m_mtxWorld
		, &mtxTrans);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans,
		m_posEdge.x,
		m_posEdge.y,
		m_posEdge.z);

	D3DXMatrixMultiply(&mtxWork
		, &mtxWork
		, &mtxTrans);

	// �e�̃}�g���b�N�X���Ɗ|����
	D3DXMatrixMultiply(&mtxWork
		, &mtxWork
		, m_pMtxParent);

	m_posOriggin = D3DXVECTOR3(mtxWork._41, mtxWork._42, mtxWork._43);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtexBuff, 0, sizeof(CRenderer::VERTEX_3D));

	// �C���f�b�N�X�o�b�t�@���f�[�^�X�g���[����ݒ�
	pDevice->SetIndices(m_pIdxBuff);

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	if (m_bDisp == true)
	{// �`��t���O���I���̎�
		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture);
		// �|���S���̕`��
		pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, m_nNumVertex, 0, m_nNumPolygon);
	}
	// �����_�[�X�e�[�g(�ʏ�u�����h����)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);				// ���u�����h���s��
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// ���\�[�X�J���[�̎w��
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// ����(�����)���J�����O����
}

//-------------------------------------------------------------------------------------------------------------
// �`��J�n
//-------------------------------------------------------------------------------------------------------------
void COrbit::DrawStart(void)
{
	// �`��t���O�I������Ȃ���
	if (m_bDisp != true)
	{// �`��t���O�I��
		m_bDisp = true;

		// ���_���̃|�C���^
		CRenderer::VERTEX_3D *pVtx;

		// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
		m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

		// ���_���̕ύX
		pVtx[0].pos = m_posOriggin;

		// �e�̃}�g���b�N�X����ݒ�
		pVtx[m_nNumWidht + 1].pos = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

		// ���_����������
		for (int nCntOrbit = 0; nCntOrbit < m_nNumWidht; nCntOrbit++)
		{
			pVtx[nCntOrbit + 1].pos = m_posOriggin;
			pVtx[nCntOrbit + m_nNumWidht + 2].pos = pVtx[m_nNumWidht + 1].pos;
		}

		// ���_�f�[�^���A�����b�N
		m_pVtexBuff->Unlock();
	}
}

//-------------------------------------------------------------------------------------------------------------
// �`��I��
//-------------------------------------------------------------------------------------------------------------
void COrbit::DrawEnd(void)
{
	// �`��t���O�I�t����Ȃ���
	if (m_bDisp != false)
	{// �`��t���O�I�t
		m_bDisp = false;
	}
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`�����̍S��
//-------------------------------------------------------------------------------------------------------------
void COrbit::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

//-------------------------------------------------------------------------------------------------------------
// ���_���̍쐬
//-------------------------------------------------------------------------------------------------------------
HRESULT COrbit::MakeVatex(LPDIRECT3DDEVICE9 pDevice)
{

	// ���_�o�b�t�@�𐶐�
	if ((FAILED(pDevice->CreateVertexBuffer(
		sizeof(CRenderer::VERTEX_3D) * m_nNumVertex,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,									// ���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&m_pVtexBuff,
		NULL))))
	{
		std::cout << "COrbit == ���_���̍쐬�Ɏ��s���܂���\n";
		return E_FAIL;
	}

	// ���_���̃|�C���^
	CRenderer::VERTEX_3D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

	float fTexWidth = 1.0f / m_nNumWidht;
	for (int nCntHeight = 0; nCntHeight < ORBIT_NUM_HEIGHT + 1; nCntHeight++)
	{
		for (int nCntWidth = 0; nCntWidth < m_nNumWidht + 1; nCntWidth++)
		{
			pVtx[0].pos = MYLIB_3DVECTOR_ZERO;
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[0].col = m_col;
			pVtx[0].tex = D3DXVECTOR2(fTexWidth*nCntWidth, (float)nCntHeight);
			pVtx++;
		}
	}
	// ���_�f�[�^���A�����b�N
	m_pVtexBuff->Unlock();
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �C���f�b�N�X���̍쐬
//-------------------------------------------------------------------------------------------------------------
HRESULT COrbit::MakeIndex(LPDIRECT3DDEVICE9 pDevice)
{
	// �C���f�b�N�X�o�b�t�@�̐���
	if ((FAILED(pDevice->CreateIndexBuffer(
		sizeof(WORD) * m_nNumIndex,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuff,
		NULL))))
	{
		std::cout << "COrbit == �C���f�b�N�X���̍쐬�Ɏ��s���܂���\n";
		return E_FAIL;
	}

	// �C���f�b�N�X�f�[�^�ւ̃|�C���^
	WORD *pIdx;

	// �C���f�b�N�X�o�b�t�@�����b�N���A�C���f�b�N�X�o�b�t�@�̃|�C���^�擾
	m_pIdxBuff->Lock(0, 0, (void**)&pIdx, 0);

	// �C���f�b�N�X�̐ݒ�
	// ���s�̌�
	for (int nCntVertical = 0; nCntVertical < ORBIT_NUM_HEIGHT; nCntVertical++)
	{
		// �ŏ������͂���Ȃ��悤�ɂ��邽��
		if (nCntVertical > 0)
		{
			// �k�ރ|���S����
			pIdx[0] = (nCntVertical*(m_nNumWidht + 1) + m_nNumWidht + 1);
			pIdx++;
		}
		// ���̌�
		for (int nCntInd = 0; nCntInd < m_nNumWidht + 1; nCntInd++)
		{
			// �k�ރ|���S������������
			pIdx[0] = nCntVertical*(m_nNumWidht + 1) + nCntInd + m_nNumWidht + 1;
			pIdx[1] = nCntVertical*(m_nNumWidht + 1) + nCntInd;
			pIdx += 2;
		}
		// �Ōゾ������Ȃ��悤�ɂ���
		if (nCntVertical <ORBIT_NUM_HEIGHT - 1)
		{
			// �k�ރ|���S����
			pIdx[0] = (nCntVertical*(m_nNumWidht + 1) + m_nNumWidht);
			pIdx++;
		}
	}

	// �C���f�b�N�X�o�b�t�@���A�����b�N
	m_pIdxBuff->Unlock();
	return S_OK;
}

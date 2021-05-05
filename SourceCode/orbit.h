//*************************************************************************************************************
//
// �O������ [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _ORBIT_H_
#define _ORBIT_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class COrbit :public CScene
{
public:
	COrbit(CScene::PRIORITY priority);	// �R���X�g���N�^
	COrbit();						// �R���X�g���N�^
	~COrbit();						// �f�X�g���N�^
	// ����
	static COrbit *Create(D3DXMATRIX *pMtxParent,int nNumWidht,D3DXVECTOR2 size ,int nTextureID, D3DXCOLOR &col);
	// ���̐ݒ�
	void SetInfo(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size , D3DXCOLOR &col);
	void Init(void);		// ������
	void Uninit(void);		// �I��
	void Update(void);		// �X�V
	void Draw(void);		// �`��
	// �`��J�n
	void DrawStart(void);
	// �`��I��
	void DrawEnd(void);
	// �e�N�X�`�����̍S��
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
private:
	/* -- �����o�֐� -- */
	HRESULT MakeVatex(LPDIRECT3DDEVICE9 pDevice);		// ���_���̍쐬
	HRESULT MakeIndex(LPDIRECT3DDEVICE9 pDevice);		// �C���f�b�N�X���̍쐬

	/* -- �����o�ϐ� -- */
	LPDIRECT3DTEXTURE9		m_pTexture = NULL;	// �e�N�X�`���̃|�C���^
	LPDIRECT3DVERTEXBUFFER9	m_pVtexBuff = NULL;	// ���_�o�b�t�@�̃|�C���^
	LPDIRECT3DINDEXBUFFER9	m_pIdxBuff = NULL;	// �C���f�b�N�X�̃o�b�t�@�̃|�C���^
	D3DXVECTOR3				m_pos;				// �ʒu
	D3DXVECTOR3				m_rot;				// ����(��])
	D3DXVECTOR2				m_size;
	bool					m_bDisp;			// �`��t���O

	D3DXMATRIX				m_mtxWorld;			// ���[���h�}�g���b�N�X
	D3DXVECTOR3				*m_pPosOld;			// �O��̈ʒu
	D3DXVECTOR3				*m_pPosEdgeOld;		// �؂���̑O��̈ʒu
	D3DXMATRIX				*m_pMtxParent;		// �e�̃}�g���b�N�X���

	D3DXVECTOR3				m_posEdge;			// �[�̈ʒu

	D3DXVECTOR3				m_posOriggin;		// ���_
	int						m_nNumWidht;		// ���̌�
	int						m_nNumVertex;		// �����_��
	int						m_nNumIndex;		// ���C���f�b�N�X��
	int						m_nNumPolygon;		// ���|���S����

	D3DXCOLOR				m_col;				// �F�̐ݒ�
};

#endif
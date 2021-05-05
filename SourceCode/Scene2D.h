//*************************************************************************************************************
//
// �V�[��2D����[scene2D.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CScene2D :public CScene
{
public:
	CScene2D(CScene::PRIORITY priority);											// �R���X�g���N�^
	~CScene2D();																	// �f�X�g���N�^

	static CScene2D *Create(														// ����
		CScene::PRIORITY priority,													// �`��D�揇��
		D3DXVECTOR3      pos,														// �ʒu
		D3DXCOLOR        col,														// �F
		ORIGINVERTEXTYPE OriginType,												// ���_�^�C�v
		D3DXVECTOR2      size,														// �傫��
		float            fRadius = 0.0f,											// ���a
		float            fRotation = 0.0f,											// ��]��
		SETING_UV        TexUVInfo = SETING_UV(0, 1, 0, 1));						// �e�N�X�`��UV�ݒ�

	static CScene2D *Create(														// ����
		CScene::PRIORITY priority,													// �`��D�揇��
		D3DXVECTOR3      pos,														// �ʒu
		ORIGINVERTEXTYPE OriginType,												// �F
		D3DXVECTOR2      size,														// �T�C�Y
		float            fRadius = 0.0f);											// ���a

	void Init(void);																// ������
	void Uninit(void);																// �I��
	void Update(void);																// �X�V
	void Draw(void);																// �`��

	void UpdateVertex(																// ���_�̍X�V
		D3DXVECTOR3 *pPos = NULL,													// �ʒu�̃|�C���^
		D3DXVECTOR2 *pSize = NULL,													// �傫���̃|�C���^
		float       *pRadius = NULL,												// ���a�̃|�C���^
		D3DXCOLOR   *pCol = NULL,													// �F�̃|�C���^
		SETING_UV   *pTexVari = NULL);												// UV���W�ݒ�̃|�C���^

	void UpdateVertex(																// ���_�̍X�V
		bool bUpdatePos = false,													// �ʒu�X�V�t���O
		bool bUpdateCol = false,													// �F�X�V�t���O
		bool bUpdateUVTex = false);													// UV���W�X�V�t���O

	void                    UpdateVatexPosition(void);								// ���_�ʒu�̍X�V
	void                    UpdateVatexColor(void);									// ���_�J���[�̍X�V
	void                    UpdateVatexTexture(void);								// ���_�e�N�X�`���̍X�V

	void                    ChangeVertexOrigin(ORIGINVERTEXTYPE OriginType);		// ���_�̕ύX
	void                    BindTexture(LPDIRECT3DTEXTURE9 pTexture);				// �e�N�X�`�����֘A�t����
	LPDIRECT3DVERTEXBUFFER9 GetpVtxBuff(void);										// ���_�o�b�t�@�̎擾
	void                    SetOriginType(ORIGINVERTEXTYPE OriginType);				// ���_�^�C�v�̐ݒ�
	ORIGINVERTEXTYPE*       GetOriginType(void);									// ���_�^�C�v�̎擾
	void                    SetPosition(D3DXVECTOR3& pos);							// �ʒu�̐ݒ�
	D3DXVECTOR3*            GetPosition(void);										// �ʒu�̎擾
	void                    SetColor(D3DXCOLOR& col);								// �F�̐ݒ�
	D3DXCOLOR*              GetColor(void);											// �F�̎擾
	void                    SetSize(D3DXVECTOR2& size);								// �傫���̐ݒ�
	void                    SetSizeX(float fSize);									// �傫��X�̐ݒ�
	void                    SetSizeY(float fSize);									// �傫��Y�̐ݒ�
	D3DXVECTOR2*            GetSize(void);											// �傫���̎擾
	void                    SetSetingUV(SETING_UV& SetingUV);						// �e�N�X�`����UV���W�̐ݒ�p�̏��̐ݒ�
	void                    SetSetingUVCountU(int nCntU);							// �e�N�X�`����UV���W�̐ݒ�p�̏�񉡂̃J�E���g�̐ݒ�
	void                    SetSetingUVCountV(int nCntV);							// �e�N�X�`����UV���W�̐ݒ�p�̏��c�̃J�E���g�̐ݒ�
	SETING_UV*              GetSetingUV(void);										// �e�N�X�`����UV���W�̐ݒ�p�̏��̎擾
	void                    SetAnimTexVariables(TEXTUREANIMEINFO& TextureAnimeInfo);	// �e�N�X�`���A�j���[�V�������̐ݒ�
	void                    SetAnimTexVariFrame(int nFrame);						// �e�N�X�`���A�j���[�V�����t���[�����̐ݒ�
	void                    SetAnimTexVariFrameMax(int nFrameMax);					// �e�N�X�`���A�j���[�V�����̍ő�t���[�����̐ݒ�
	TEXTUREANIMEINFO*       GetAnimTexVariables(void);								// �e�N�X�`���A�j���[�V�������̎擾
	void                    SetRadius(float fRadius);								// ���a�̐ݒ�
	float                   GetRadius(void);										// ���a�̎擾
	void                    SetRotation(float fRotation);							// ��]�ʂ̐ݒ�
	float                   GetRotation(void);										// ��]�ʂ̎擾
	int                     CalculatVatexUVMap(bool bLoop, int nFrameMax, int &nFrame, int nNumWidht, int nNumHight, int &nCountWidht, int &nCountHight);
	void                    CalSelectionUVMap(bool bIteration, int nFrameMax, int &nFrame, int nNumWidht, int &nCountWidht, int nCountHight, int &m_nIteration);
	void                    CalTurnBackUVMap(int nFrameMax, int &nFrame, int nNumWidht, int &nCountWidht, int nCountHight, int &m_nIteration);
	inline void             SetDisp(const bool bDisp) { m_bDisp = bDisp; }
	inline bool &           GetDisp(void) { return m_bDisp; }
protected:
	/* -- �����o�֐� -- */
	HRESULT                 MakeVatex(LPDIRECT3DDEVICE9 pDevice);					// ���_�̍쐬
	void                    SetVatexPosition(CRenderer::VERTEX_2D *pVtx);			// ���_�ʒu�̐ݒ�
	void                    SetVatexColor(CRenderer::VERTEX_2D *pVtx);				// ���_�J���[�̐ݒ�
	void                    SetVatexTexture(CRenderer::VERTEX_2D *pVtx);			// ���_�e�N�X�`���̐ݒ�
																					/* -- �����o�ϐ� -- */
	LPDIRECT3DTEXTURE9      m_pTexture;												// �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;												// ���_�o�b�t�@�ւ̃|�C���^
	ORIGINVERTEXTYPE        m_OriginType;											// ���_�̎��
	D3DXVECTOR3             m_pos;													// �ʒu
	D3DXCOLOR               m_col;													// �F
	D3DXVECTOR2             m_size;													// �傫��
	SETING_UV               m_TexUVInfo;											// �e�N�X�`����UV���W�̐ݒ�p�̏��
	TEXTUREANIMEINFO        m_TexAnimInfo;											// �e�N�X�`���A�j���[�V�������
	float                   m_fRadius;												// ���a
	float                   m_fRotation;											// ��]��
	bool                    m_bDisp;												// �`��t���O
};

#endif
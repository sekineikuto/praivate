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
	// �\���̒�`
	typedef struct UPDATEFLAG
	{
		union {
			struct {
				bool pos : 1;
				bool col : 1;
				bool tex : 1;
			};
			UINT data;
		};
	} UPDATEFLAG;

	CScene2D(CScene::PRIORITY priority);															// �R���X�g���N�^
	~CScene2D();																					// �f�X�g���N�^

	static CScene2D *Create(																		// ����
		CScene::PRIORITY priority,																	// �`��D�揇��
		D3DXVECTOR3      pos,																		// �ʒu
		D3DXVECTOR2      size,																		// �傫��
		D3DXCOLOR        col,																		// �F
		float            fRotation = 0.0f,															// ��]��
		ORIGINVERTEXTYPE OriginType = ORIGINVERTEXTYPE_CENTER,										// ���_�^�C�v
		SETING_UV        TexUVInfo = SETING_UV(0, 1, 0, 1));										// �e�N�X�`��UV�ݒ�

	void Init(void);																				// ������
	void Uninit(void);																				// �I��
	void Update(void);																				// �X�V
	void Draw(void);																				// �`��

	void UpdateVertex(																				// ���_�̍X�V
		bool bUpdatePos = false,																	// �ʒu�X�V�t���O
		bool bUpdateCol = false,																	// �F�X�V�t���O
		bool bUpdateUVTex = false);																	// UV���W�X�V�t���O

	void                    ChangeVertexOrigin(CONST ORIGINVERTEXTYPE OriginType);					// ���_�̕ύX

	LPDIRECT3DVERTEXBUFFER9 GetpVtxBuff(void) const;												// ���_�o�b�t�@�̎擾
	void                    BindTexture(LPDIRECT3DTEXTURE9 pTexture);								// �e�N�X�`�����֘A�t����

	void                    SetOriginType(CONST ORIGINVERTEXTYPE OriginType);						// ���_�^�C�v�̐ݒ�
	ORIGINVERTEXTYPE        GetOriginType(void) const;												// ���_�^�C�v�̎擾
	ORIGINVERTEXTYPE&       GetOriginTypeRef(void);													// ���_�^�C�v�Q�Ƃ̎擾
	ORIGINVERTEXTYPE*       GetOriginTypePtr(void);													// ���_�^�C�v�|�C���^�̎擾

	void                    SetPosition(CONST D3DXVECTOR3& pos);									// �ʒu�̐ݒ�
	void                    SetPosition(const float x, const float y, const float z);				// �ʒu�̐ݒ�
	void                    SetPositionX(const float x);											// �ʒuX�̐ݒ�
	void                    SetPositionY(const float y);											// �ʒuY�̐ݒ�
	void                    SetPositionZ(const float z);											// �ʒuZ�̐ݒ�
	D3DXVECTOR3             GetPosition(void) const;												// �ʒu�̎擾
	D3DXVECTOR3&            GetPositionRef(void);													// �ʒu�Q�Ƃ̎擾
	D3DXVECTOR3*            GetPositionPtr(void);													// �ʒu�|�C���^�̎擾

	void                    SetColor(CONST D3DXCOLOR& col);											// �F�̐ݒ�
	void                    SetColor(const float r, const float g, const float b, const float a);	// �F�̐ݒ�
	void                    SetColorR(const float r);												// �FR�̐ݒ�
	void                    SetColorG(const float g);												// �FG�̐ݒ�
	void                    SetColorB(const float b);												// �FB�̐ݒ�
	void                    SetColorA(const float a);												// �FA�̐ݒ�
	D3DXCOLOR               GetColor(void) const;													// �F�̎擾
	D3DXCOLOR&              GetColorRef(void);														// �F�Q�Ƃ̎擾
	D3DXCOLOR*              GetColorPtr(void);														// �F�|�C���^�̎擾

	void                    SetSize(CONST D3DXVECTOR2& size);										// �傫���̐ݒ�
	void                    SetSize(const float x, const float y);									// �傫���̐ݒ�
	void                    SetSizeX(const float x);												// �傫��X�̐ݒ�
	void                    SetSizeY(const float y);												// �傫��Y�̐ݒ�
	D3DXVECTOR2*            GetSize(void);															// �傫���̎擾

	void                    SetRotation(float fRotation);											// ��]�ʂ̐ݒ�
	float                   GetRotation(void);														// ��]�ʂ̎擾
	float&                  GetRotationRef(void);													// ��]�ʎQ�Ƃ̎擾
	float*                  GetRotationPtr(void);													// ��]�ʃ|�C���^�̎擾

	void                    SetDisp(const bool bDisp);												// �`��t���O�̐ݒ�
	bool                    GetDisp(void);															// �`��t���O�̎擾
	bool&                   GetDispRef(void);														// �`��t���O�Q�Ƃ̎擾
	bool*                   GetDispPtr(void);														// �`��t���O�|�C���^�̎擾

protected:
	/* -- �����o�֐� -- */
	HRESULT                 MakeVatex(LPDIRECT3DDEVICE9 pDevice);									// ���_�̍쐬
	void                    SetVatexPosition(CRenderer::VERTEX_2D *pVtx);							// ���_�ʒu�̐ݒ�
	void                    SetVatexColor(CRenderer::VERTEX_2D *pVtx);								// ���_�J���[�̐ݒ�
	void                    SetVatexTexture(CRenderer::VERTEX_2D *pVtx);							// ���_�e�N�X�`���̐ݒ�

	/* -- �����o�ϐ� -- */
	LPDIRECT3DTEXTURE9      m_pTexture;																// �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;																// ���_�o�b�t�@�ւ̃|�C���^
	UPDATEFLAG              m_UpdateFlags;															// �X�V�t���O
	ORIGINVERTEXTYPE        m_OriginType;															// ���_�̎��
	D3DXVECTOR3             m_pos;																	// �ʒu
	D3DXCOLOR               m_col;																	// �F
	D3DXVECTOR2             m_size;																	// �傫��
	float                   m_fRotation;															// ��]��
	bool                    m_bDisp;																// �`��t���O
};

#endif
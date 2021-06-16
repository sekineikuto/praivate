//*************************************************************************************************************
//
// �摜2D����[Image2d.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _IMAGE2D_H_
#define _IMAGE2D_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Component.h"
#include "types.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class Image2D : public IVisualComponent
{
public:
	/* �����o�֐� */
	// �R���X�g���N�^
	Image2D();

	// �f�X�g���N�^
	~Image2D();

	// �J�n����
	void Start(void);

	// �X�V
	void Update(void);

	// �`��
	void Draw(void);

private:
	// ���_���̍쐬
	HRESULT MakeVertex(void);

	// ���_�ʒu�̐ݒ�
	void SetVertexPosition(void);

	// ���_�J���[�̐ݒ�
	void SetVertexColor(void);

	// �e�N�X�`���ʒu�̐ݒ�
	void SetTexturePosition(void);

public:
	/* �����o�ϐ� */
	LPDIRECT3DVERTEXBUFFER9 pVtxBuff;	// ���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9      pTexture;	// �e�N�X�`���ւ̃|�C���^
	D3DXCOLOR               color;		// �J���[
	Transform2D *           pTransform;	// �g�����X�t�H�[���|�C���^
};
_END_MYSTD



#endif
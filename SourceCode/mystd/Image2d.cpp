//*************************************************************************************************************
//
// �摜2D����[Image2d.cpp]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Image2d.h"
#include "utility.h"

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
mystd::Image2D::Image2D()
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
mystd::Image2D::~Image2D()
{
}

//-------------------------------------------------------------------------------------------------------------
// �����̊J�n
//------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Start(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// ���_���̍쐬
//-------------------------------------------------------------------------------------------------------------
HRESULT mystd::Image2D::MakeVertex(void)
{
	return E_NOTIMPL;
}

//-------------------------------------------------------------------------------------------------------------
// ���_�ʒu�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetVertexPosition(VERTEX_2D *pVtx)
{
	// �ϐ��錾
	D3DXVECTOR2 halfsize = D3DXVECTOR2(pTransform->Size.Width * mystd::fHalfSize, pTransform->Size.Height * mystd::fHalfSize);	// �����̑傫��
	float		fInvRot = -pTransform->Rotation;																	// �t�̉�]
	float		fSin_size_x = sinf(mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;					// sin������xX���̑傫���̌v�Z����
	float		fCos_size_x = cosf(mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;					// cos������xX���̑傫���̌v�Z����

	// ���_�^�C�v�ɉ����Ē��_[0]�̈ʒu��ݒ肷��
	switch (pTransform->Pivot)
	{
	case PIVOTTYPE_LOWERLEFT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height;
		break;
	case PIVOTTYPE_LOWERCENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_LOWERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	case PIVOTTYPE_CENTERLEFT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*halfsize.y;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*halfsize.y;
		break;
	case PIVOTTYPE_CENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_CENTERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(D3DX_PI - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(D3DX_PI - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	case PIVOTTYPE_UPPERLEFT:
		pVtx[0].pos.x = pTransform->Position.x;
		pVtx[0].pos.y = pTransform->Position.y;
		break;
	case PIVOTTYPE_UPPERCENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_UPPERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	}


	// ���_[2]�̐ݒ�
	pVtx[2].pos.x = pVtx[0].pos.x + sinf(fInvRot)*pTransform->Size.Height;
	pVtx[2].pos.y = pVtx[0].pos.y + cosf(fInvRot)*pTransform->Size.Height;

	// ���_[1]�̐ݒ�
	pVtx[1].pos.x = pVtx[0].pos.x + fSin_size_x;
	pVtx[1].pos.y = pVtx[0].pos.y + fCos_size_x;

	// ���_[3]�̐ݒ�
	pVtx[3].pos.x = pVtx[2].pos.x + fSin_size_x;
	pVtx[3].pos.y = pVtx[2].pos.y + fCos_size_x;
}

//-------------------------------------------------------------------------------------------------------------
// ���_�J���[�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetVertexColor(VERTEX_2D *pVtx)
{
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`���ʒu�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetTexturePosition(VERTEX_2D *pVtx)
{
}

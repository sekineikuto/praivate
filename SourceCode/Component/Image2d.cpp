//*************************************************************************************************************
//
// �摜2D����[Image2d.cpp]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "../manager.h"
#include "../renderer.h"
#include "Image2d.h"
#include "CompoBehaviour.h"
#include "transform.h"
#include "../mystd/utility.h"

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
mystd::Image2D::Image2D()
{
	// �g�����X�R���|�[�l���g�|�C���^�̎擾
	pTransform = parent->GetComponent<Transform2D>();
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
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,									// ���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,
		&pVtxBuff,
		NULL);

	// ���_���ւ̃|�C���^
	VERTEX_2D *pVtx;

	// ���_�f�[�^�͈̔̓��b�N���A���_�o�b�t�@�ւ̃|�C���^�擾
	pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_�ʒu�̐ݒ�
	SetVertexPosition(pVtx);

	// Z���͎g���K�v�Ȃ��̂�0.0f
	pVtx[0].pos.z =
		pVtx[1].pos.z =
		pVtx[2].pos.z =
		pVtx[3].pos.z = 0.0f;

	// �������W�̐ݒ�
	pVtx[0].rhw =
		pVtx[1].rhw =
		pVtx[2].rhw =
		pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	SetVertexColor(pVtx);

	// �e�N�X�`�����W
	SetTexturePosition(pVtx);

	// ���_�f�[�^���A�����b�N
	pVtxBuff->Unlock();

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
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height;
		break;
	case PIVOTTYPE_LOWERCENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_LOWERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	case PIVOTTYPE_CENTERLEFT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y;
		break;
	case PIVOTTYPE_CENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_CENTERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
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
	pVtx[0].col = pVtx[1].col = pVtx[2].col = pVtx[3].col = color;
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`���ʒu�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetTexturePosition(VERTEX_2D *pVtx)
{
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}

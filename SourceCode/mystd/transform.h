//*************************************************************************************************************
//
// �g�����X�t�H�[������[transform.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#pragma once
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Component.h"
#include "types.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
// �g�����X�t�H�[��2D
class Transform2D : public IComponent
{
public:
	/* �����o�֐� */
	// �R���X�g���N�^
	Transform2D() {}
	// �R���X�g���N�^
	Transform2D(float fPosX, float fPosY, float fPosZ, float fSizeX, float fSizeY, PIVOTTYPE inPivot, float fRotation, float fScaleX, float fScaleY)
		: Position(fPosX, fPosY, fPosZ), Size(fSizeX, fSizeY), Pivot(inPivot), Rotation(fRotation), Scale(fScaleX, fScaleY) {}
	// �R���X�g���N�^
	Transform2D(D3DXVECTOR3 inPos, RECTSIZE niSize, PIVOTTYPE inPivot, float inRotation, D3DXVECTOR2 inScale)
		:Position(inPos), Size(niSize), Pivot(inPivot), Rotation(inRotation), Scale(inScale) {}

	// �f�X�g���N�^
	~Transform2D() {}

	void Start(void) {}
	void Update(void) {}
	void Draw(void) {}

	/* �����o�ϐ� */
	D3DXVECTOR3 Position;	// �ʒu
	RECTSIZE    Size;		// �T�C�Y
	PIVOTTYPE   Pivot;		// �s�{�b�g���
	float       Rotation;	// ��]
	D3DXVECTOR2 Scale;		// �X�P�[��
};

_END_MYSTD

#endif

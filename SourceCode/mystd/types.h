//*************************************************************************************************************
//
// ����̕W�����C�u�����̃��[�e�B���e�B���� [mystd_utility.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#pragma once
#ifndef _MYSTD_TYPES_H_
#define _MYSTD_TYPES_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mystd.h"
#include "d3dx9.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// �񋓌^��`
//-------------------------------------------------------------------------------------------------------------
// ���_�_�̌��_(�΃L�[�p�b�h)
typedef enum
{
	PIVOTTYPE_NONE = 0,			// �Ȃ�
	PIVOTTYPE_LOWERLEFT,			// ����
	PIVOTTYPE_LOWERCENTER,		// ������
	PIVOTTYPE_LOWERRIGHT,		// �E��
	PIVOTTYPE_CENTERLEFT,		// ������
	PIVOTTYPE_CENTER,			// ����
	PIVOTTYPE_CENTERRIGHT,		// �E����
	PIVOTTYPE_UPPERLEFT,			// ����
	PIVOTTYPE_UPPERCENTER,		// ������
	PIVOTTYPE_UPPERRIGHT,		// �E��
	PIVOTTYPE_MAX				// �ő吔
} PIVOTTYPE;

//-------------------------------------------------------------------------------------------------------------
// �ϐ���`
//-------------------------------------------------------------------------------------------------------------
typedef const char * CSTRING;
typedef char *       STRING;

//-------------------------------------------------------------------------------------------------------------
// �\���̒�`
//-------------------------------------------------------------------------------------------------------------


// 2D�|���S�����_�t�H�[�}�b�g�ɍ��킹���\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;						// ���_�̍��W
	float		rhw;						// 1.0�ŌŒ蓯�����W
	D3DCOLOR	col;						// ���_�J���[
	D3DXVECTOR2	tex;						// �e�N�X�`�����W
} VERTEX_2D;

// 3D�|���S�����_�t�H�[�}�b�g�ɍ��킹���\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;	// ���_���W
	D3DXVECTOR3 nor;	// �@���x�N�g��
	D3DCOLOR	col;	// ���_�J���[
	D3DXVECTOR2 tex;	// �e�N�X�`�����W
} VERTEX_3D;

// ��`�̃T�C�Y
typedef struct _RECTSIZE
{
	inline _RECTSIZE() {};
	inline _RECTSIZE(const float fWidth, const float fHeight) : Width(fWidth), Height(fHeight) {}
	inline _RECTSIZE(CONST _RECTSIZE &src) : Width(src.Width), Height(src.Height) {}
	inline _RECTSIZE(D3DXVECTOR2 &src) : Width(src.x), Height(src.y) {}
	
	// casting
	//inline operator D3DXVECTOR2& () { return D3DXVECTOR2(Width, Height); }
	//inline operator CONST D3DXVECTOR2& () const { return D3DXVECTOR2(Width, Height); }

	// assignment operators
	inline _RECTSIZE& operator += (CONST _RECTSIZE& src) { this->Width += src.Width; this->Height += src.Height; return *this; }
	inline _RECTSIZE& operator -= (CONST _RECTSIZE& src) { this->Width -= src.Width; this->Height -= src.Height; return *this; }
	inline _RECTSIZE& operator *= (FLOAT src) { this->Width *= src; this->Height *= src; return *this; }
	inline _RECTSIZE& operator /= (FLOAT src) { this->Width /= src; this->Height /= src; return *this; }

	// unary operators
	inline _RECTSIZE operator + () const { return *this; }
	inline _RECTSIZE operator - () const { return _RECTSIZE(-this->Width, -this->Width); }

	// binary operators
	inline _RECTSIZE operator + (CONST _RECTSIZE& src) const { return _RECTSIZE(this->Width + src.Width, this->Height + src.Height); }
	inline _RECTSIZE operator - (CONST _RECTSIZE& src) const { return _RECTSIZE(this->Width - src.Width, this->Height - src.Height); }
	inline _RECTSIZE operator * (FLOAT src) const { return _RECTSIZE(this->Width * src, this->Height * src); }
	inline _RECTSIZE operator / (FLOAT src) const { return _RECTSIZE(this->Width / src, this->Height / src); }

	//inline friend _RECTSIZE operator * (FLOAT srcA, CONST _RECTSIZE& srcB) { return _RECTSIZE(srcB.Width * srcA, srcB.Height * srcA); }

	inline BOOL operator == (CONST _RECTSIZE& src) const { return this->Width == src.Width && this->Height == src.Height; }
	inline BOOL operator != (CONST _RECTSIZE& src) const { return this->Width != src.Width || this->Height != src.Height; }

	float Width, Height;
}RECTSIZE;

// �g�����X�t�H�[��2D
typedef struct Transform2D
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

	/* �����o�ϐ� */
	D3DXVECTOR3 Position;	// �ʒu
	RECTSIZE    Size;		// �T�C�Y
	PIVOTTYPE   Pivot;		// �s�{�b�g���
	float       Rotation;	// ��]
	D3DXVECTOR2 Scale;		// �X�P�[��
}Transform2D;



_END_MYSTD

#endif

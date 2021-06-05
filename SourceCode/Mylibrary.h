//*************************************************************************************************************
//
// �����̃��C�u�����̏���[Mylibrary.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _MYLIBRARY_H_
#define _MYLIBRARY_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include <windows.h>
#include <stdio.h>
#include "d3dx9.h"
#include "XAudio2.h"
#define DIRECTINPUT_VERSION (0x0800)	// �x���Ώ��p
#include "dinput.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <time.h>
#include <vector>
#include <list>
#include <iostream>

//-------------------------------------------------------------------------------------------------------------
// ���C�u�����̃����N
//-------------------------------------------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dinput8.lib")

//-------------------------------------------------------------------------------------------------------------
// �S�̃���
//-------------------------------------------------------------------------------------------------------------
/* �R�����g�� */
// * [contents]
// * [output]
// * [input]
// * [return]
/*
�ioperator�j�I�[�o�[���[�h�ł��鉉�Z�q
+		-		*		/		%		^
!		=		<		>		+=		-=
^=		&=		|=		<<		>>		<<=
<=		>=		&&		||		++		--
( )		[ ]		new		delete	&		|
~		*=		/=		%=		>>=		==
!=		,		->		->*
*/
/*
* [enm] enum�̗�
* [stm] statement�̗�
* [pIt] iterator�̗�(�|�C���^)
* [src] source�̗�
* [rhs] right-hand side�̗�
* [lhs] left-hand side�̗�
* [str] string�̗�
* [tmp] temporary�̗�
* [b]   bool�^�̗�
* [t]   true(�^)�̗�
* [f]   false(�U)�̗�
* [o]   output�̗�
* [r]   resource�̗�
*/

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define MYLIB_MEASURE								// �v������

#define MYLIB_SUCCESS			0					// ����
#define MYLIB_FAILURE			-1					// ���s

#define MYLIB_TRUE				1
#define MYLIB_FALSE				0

#define MYLIB_STRINGSIZE		128					// ������̊�{�̒���

#define MYLIB_PNG				".png" ,".PNG"
#define MYLIB_JPG				".jpg" ,".JPG"
#define MYLIB_JPEG				".jpeg" ,".JPEG"
#define MYLIB_IMAGE_EXTENSION	MYLIB_PNG ,MYLIB_JPG ,MYLIB_JPEG

#define MYLIB_TXT				".txt" ,".TXT"
#define MYLIB_INI				".ini" ,".INI"
#define MYLIB_TXT_EXTENSION		MYLIB_TXT ,MYLIB_INI

#define MYLIB_X					".x" ,".X"

#define MYLIB_CLEARARRAYONDECLA	{ NULL }						// �錾���̔z����N���A

#define MYLIB_INITSTRUCT_WITHCONST	{ }							// �R���X�g���N�^�̂���\���̂̏�����

#define MYLIB_D3DXCOR_UNSET			D3DXCOLOR(0.0f,0.0f,0.0f,0.0f)	// �F�ݒ�Ȃ�
#define MYLIB_D3DXCOR_SET			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f)	// �F�ݒ�

#define MYLIB_3DVECTOR_ZERO			D3DXVECTOR3(0.0f,0.0f,0.0f)		// 3D�x�N�g�����[���ɐݒ�
#define MYLIB_SCALE_UNSET			D3DXVECTOR3(1.0f,1.0f,1.0f)		// �X�P�[���̏�����
#define MYLIB_VEC3_XONE				D3DXVECTOR3(1.0f,0.0f,0.0f)		// 3D�x�N�g��X����1.0f
#define MYLIB_VEC3_YONE				D3DXVECTOR3(0.0f,1.0f,0.0f)		// 3D�x�N�g��Y����1.0f
#define MYLIB_VEC3_ZONE				D3DXVECTOR3(0.0f,0.0f,1.0f)		// 3D�x�N�g��Z����1.0f
#define MYLIB_VEC3_UNSET			D3DXVECTOR3(0.0f,0.0f,0.0f)		// 3D�x�N�g���̏�����

#define MYLIB_2DVECTOR_ZERO			D3DXVECTOR2(0.0f,0.0f)			// 2D�x�N�g�����[���ɐݒ�
#define MYLIB_VEC2_XONE				D3DXVECTOR2(1.0f,0.0f)			// 2D�x�N�g��X����1.0f
#define MYLIB_VEC2_YONE				D3DXVECTOR2(0.0f,1.0f)			// 2D�x�N�g��Y����1.0f
#define MYLIB_VEC2_UNSET			D3DXVECTOR2(0.0f,0.0f)			// 2D�x�N�g���̏�����

#define MYLIB_INT2_UNSET			INTEGER2(0,0)					// INT2�ݒ�Ȃ�

#define MYLIB_RANGE_UNSET			RANGE(0,0)						// �����W�̐ݒ�Ȃ�

#define MYLIB_FLOAT_UNSET			(0.0f)							// float�^�̏�����
#define MYLIB_INT_UNSET				(0)								// int�^�̏�����
#define MYLIB_INT_NOELEM			(-1)							// int�^�v�f�Ȃ�
#define MYLIB_CHAR_UNSET			'\0'							// char�^�̏�����(������̈�Ԗڂ̏�����)
#define MYLIB_STRING_UNSET			{ 0 }							// ������̏�����

#define MYLIB_HALF_SIZE				(0.5f)							// �����̃T�C�Y
#define MYLIB_ONEQUARTER_SIZE		(0.25f)							// 4����1�̃T�C�Y
#define MYLIB_THREEQUARTERS_SIZE	(0.75f)							// 4����3�̃T�C�Y

#define MYLIB_VSHORT_UNSET			(0x000)							// 1�o�C�g���̕ϐ��ݒ�Ȃ�

#define MYLIB_ERRORCOUNT_MAX		(1048576)						// �G���[�J�E���g

#define MYLIB_VSHORT_UNSET			(0x000)							// 

#define MYLIB_HALFSECONDCOUNT		(30)							// 1�t���[���J�E���g�����̃J�E���g

#define MYLIB_D3DXCORR_BIT			(0)								// ��
#define MYLIB_D3DXCORG_BIT			(8)								// ��
#define MYLIB_D3DXCORB_BIT			(16)							// ��
#define MYLIB_D3DXCORA_BIT			(24)							// �����x

#define MYLIB_S8BYTES				(64)							// ������8�o�C�g��
#define MYLIB_S4BYTES				(32)							// ������4�o�C�g��

#define MYLIB_BRACKETS_L					"========================================================== \n"		// ��؂�̊���(��)
#define MYLIB_BRACKETS_M					"---------------------------------------------------------- \n"		// ��؂�̊���(��)
#define MYLIB_BRACKETS_S					"#*\n"																// ��؂�̊���(��)

#define MYLIB_OX_EPSILON			0.000001f							// �덷

//-------------------------------------------------------------------------------------------------------------
// �}�N���֐�
//-------------------------------------------------------------------------------------------------------------
# ifdef _DEBUG
#define Mybfunc_Debug_brackets_L		cout << MYLIB_BRACKETS_L			// ��؂�̊���(��)�̏o��
#define Mybfunc_Debug_brackets_M		cout << MYLIB_BRACKETS_M			// ��؂�̊���(��)�̏o��
#define Mybfunc_Debug_brackets_S		cout << MYLIB_BRACKETS_S			// ��؂�̊���(��)�̏o��
#define Mybfunc_Debug_start(str)		cout << str << " == start!!\n"		// �J�n(start!!)�̏o��
#define Mybfunc_Debug_end(str)			cout << str << " == end!!\n"		// �I��(end!!)�̏o��
#define Mybfunc_Debug_open(str)			cout << str << " == open!!\n"		// �J����(open!!)�̏o��
#define Mybfunc_Debug_openfailed(str)	cout << str << " == open failed!!\n"// �J���̎��s(open failed!!)�̏o��
#define Mybfunc_Debug_close(str)		cout << str << " == close!!\n"		// ����(close!!)�̏o��
#endif
#define Mybfunc_gate(b)					if(b)								// ��:�^�̎� ���g��Ȃ�
#define Mybfunc_iif(b)					(b == true) ? true: false			// ����������^�U��Ԃ�
#define Mybfunc_iifEx(b ,t ,f)			(b == true) ? t: f					// ����������^�U��Ԃ�(�^�U����)
#define Mybfunc_WhenBiggerSet(o ,src)	if(o > src) {o = src;}				// s���o���傫���Ƃ��ݒ肷��
#define Mybfunc_WhenSmallerSet(o ,src)	if(o < src) {o = src;}				// s���o���������Ƃ��ݒ肷��
#define Mybfunc_swap(lhs,rhs,tmp)		do{tmp = rhs; rhs = lhs; lhs = tmp}while(false);	// ����
#define Mybfunc_bit_clear(lhs,rhs)		(lhs &= ~(1 << rhs))
#define Mybfunc_bit_set(lhs,rhs)		(lhs |= (1 << rhs))
#define Mybfunc_bit_comp(lhs,rhs)		(lhs & (1 << rhs))

#define MLB_CASE(t)     break;case (t):
#define MLB_DEFAULT     break;default

//-------------------------------------------------------------------------------------------------------------
// �񋓌^��`
//-------------------------------------------------------------------------------------------------------------
// ���_�_�̌��_(�΃L�[�p�b�h)
typedef enum
{
	ORIGINVERTEXTYPE_NONE = 0,			// �Ȃ�
	ORIGINVERTEXTYPE_LOWERLEFT,			// ����
	ORIGINVERTEXTYPE_LOWERCENTER,		// ������
	ORIGINVERTEXTYPE_LOWERRIGHT,		// �E��
	ORIGINVERTEXTYPE_CENTERLEFT,		// ������
	ORIGINVERTEXTYPE_CENTER,			// ����
	ORIGINVERTEXTYPE_CENTERRIGHT,		// �E����
	ORIGINVERTEXTYPE_UPPERLEFT,			// ����
	ORIGINVERTEXTYPE_UPPERCENTER,		// ������
	ORIGINVERTEXTYPE_UPPERRIGHT,		// �E��
	ORIGINVERTEXTYPE_MAX				// �ő吔
} ORIGINVERTEXTYPE;

// ���Z�qID
typedef enum
{
	OPERATOR_ID_NONE = -1,				// ����
	OPERATOR_ID_ADDITION,				// ���Z
	OPERATOR_ID_SUBTRACTION,			// ���Z
	OPERATOR_ID_MULTIPLICATION,			// ��Z
	OPERATOR_ID_DIVISION,				// ���Z
	OPERATOR_ID_MAX						// �ő吔
} OPERATOR_ID;

//-------------------------------------------------------------------------------------------------------------
// �^�A�\���̒�`
//-------------------------------------------------------------------------------------------------------------
typedef const char *       CONST_STRING;	// �ύX�s������
typedef char *             STRING;			// ������

typedef signed char        VSHORT;			// ��������1�o�C�g���̕ϐ�
typedef unsigned char      UVSHORT;			// �����Ȃ�1�o�C�g���̕ϐ�

typedef long long          VLONG;			// ��������8�o�C�g���̕ϐ�
typedef unsigned long long UVLONG;			// �����Ȃ�8�o�C�g���̕ϐ�

typedef const char *       FILE_NAME;		// �t�@�C����
typedef unsigned int       FILE_SIZE;		// �t�@�C���f�[�^�T�C�Y
typedef char *             FILE_DATA;		// �t�@�C���f�[�^
typedef const char *       OPEN_MODE;		// �t�@�C�����J�����[�h

typedef const INT          CINT;
typedef const UINT         CUINT;
typedef const FLOAT        CFLOAT;


// �r�b�g�t�B�[���h
typedef struct BITS_12
{
	unsigned char Bit1 : 1;
	unsigned char Bit2 : 1;
	unsigned char Bit3 : 1;
	unsigned char Bit4 : 1;
	unsigned char Bit5 : 1;
	unsigned char Bit6 : 1;
	unsigned char Bit7 : 1;
	unsigned char Bit8 : 1;
	unsigned char Bit9 : 1;
	unsigned char Bit10 : 1;
	unsigned char Bit11 : 1;
	unsigned char Bit12 : 1;
}BITS_12;

typedef union UBITS_12
{
public:
	UBITS_12(unsigned short rhs) :Value(rhs) {}
	UBITS_12() :Value(0) {}
	unsigned short Value;
	inline unsigned short operator = (unsigned short rhs)
	{
		Value = rhs;
		return Value;
	}
	inline unsigned char operator[] (int nIndex)
	{
		return (Value & (1 << nIndex));
	}
	inline bool comp(int nIndex)
	{
		return (Value & (1 << nIndex)) != 0;
	}
	inline void clear(int nIndex)
	{
		Value &= ~(1 << nIndex);
	}
	inline void set(int nIndex)
	{
		Value |= (1 << nIndex);
	}
private:
	BITS_12 Bits;
} UBITS_12;

// �r�b�g�t�B�[���h
typedef struct BITS_8
{
	unsigned char Bit1 : 1;
	unsigned char Bit2 : 1;
	unsigned char Bit3 : 1;
	unsigned char Bit4 : 1;
	unsigned char Bit5 : 1;
	unsigned char Bit6 : 1;
	unsigned char Bit7 : 1;
	unsigned char Bit8 : 1;
}BITS_8;

typedef union UBITS_8
{
public:
	UBITS_8(unsigned char rhs) : cValue(rhs) {}
	UBITS_8() : cValue(0) {}
	unsigned char cValue;
	inline unsigned char operator = (unsigned char rhs)
	{
		cValue = rhs;
		return cValue;
	}
	inline unsigned char operator[] (int nIndex)
	{
		return (cValue & (1 << nIndex));
	}
	inline bool comp(int nIndex)
	{
		return (cValue & (1 << nIndex)) != 0;
	}
	inline void clear(int nIndex)
	{
		cValue &= ~(1 << nIndex);
	}
	inline void set(int nIndex)
	{
		cValue |= (1 << nIndex);
	}
private:
	BITS_8 Bits;
} UBITS_8;

// �r�b�g�t�B�[���h
typedef struct BITS_4
{
	unsigned char _1 : 1;
	unsigned char _2 : 1;
	unsigned char _3 : 1;
	unsigned char _4 : 1;
}BITS_4;

typedef union UBITS_4
{
public:
	UBITS_4(unsigned char rhs) :cValue(rhs) {}
	UBITS_4() :cValue(0) {}
	unsigned char cValue;
	inline unsigned char operator = (unsigned char rhs)
	{
		cValue = rhs;
		return cValue;
	}
	inline unsigned char operator[] (int nIndex)
	{
		return (cValue & (1 << nIndex));
	}
	inline bool comp(int nIndex)
	{
		return (cValue & (1 << nIndex)) != 0;
	}
	inline void clear(int nIndex)
	{
		cValue &= ~(1 << nIndex);
	}
	inline void set(int nIndex)
	{
		cValue |= (1 << nIndex);
	}
private:
	BITS_4 Bits;
} UBITS_4;

// 3����float
typedef struct FLOAT3 : public D3DXVECTOR3
{
	FLOAT3() {}																												// �R���X�g���N�^
	FLOAT3(float x, float y, float z) : D3DXVECTOR3(x, y, z) {}																// �R���X�g���N�^
	FLOAT3(CONST FLOAT3& rhs) : D3DXVECTOR3(rhs) {}																			// �R���X�g���N�^
	FLOAT3(CONST D3DXVECTOR3& rhs) : D3DXVECTOR3(rhs) {}																	// �R���X�g���N�^
	~FLOAT3() {}																											// �f�X�g���N�^

	inline FLOAT3        operator +(const FLOAT3 &rhs) const;																// �l�����Z�q+
	inline FLOAT3        operator -(const FLOAT3 &rhs) const;																// �l�����Z�q-
	inline FLOAT3        operator -(void) const;																			// �l�����Z�q-
	inline FLOAT3        operator *(const FLOAT3 &rhs) const;																// �l�����Z�q*
	inline FLOAT3        operator /(const FLOAT3 &rhs) const;																// �l�����Z�q/
	inline FLOAT3        operator *(float rhs) const;																		// �l�����Z�q*
	inline FLOAT3        operator /(float rhs) const;																		// �l�����Z�q/
	inline friend FLOAT3 operator *(float lhs, const FLOAT3 &rhs) { return FLOAT3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs); }	// �l�����Z�q*�t�����h�֐�
	inline friend FLOAT3 operator /(float lhs, const FLOAT3 &rhs) { return FLOAT3(rhs.x / lhs, rhs.y / lhs, rhs.z / lhs); }	// �l�����Z�q/�t�����h�֐�

	inline float         Dot(const FLOAT3 &rhs) const;																		// ����
	inline FLOAT3        Cross(const FLOAT3 &rhs) const;																	// �O��
	inline float         Length(void) const;																				// ����
	inline float         LengthSq(void) const;																				// �ׂ��撷��
	inline void          Norm(void);																						// ���K��
	inline FLOAT3        GetNorm(void) const;																				// ���K�����擾
	inline static FLOAT3 Zero(void) { return FLOAT3(0.0f, 0.0f, 0.0f); }

}FLOAT3;

// �x�N�g��
typedef struct VEC3 : public FLOAT3
{
	VEC3() {}												// �R���X�g���N�^
	VEC3(float x, float y, float z) : FLOAT3(x, y, z) {}	// �R���X�g���N�^
	VEC3(const FLOAT3 &rhs) : FLOAT3(rhs) {}				// �R���X�g���N�^
	~VEC3() {}												// �f�X�g���N�^
	inline VEC3& operator =(const FLOAT3 &rhs);				// ������Z�q
	inline bool  IsVertical(const VEC3 &rhs) const;			// �����֌W�ɂ���H
	inline bool  IsParallel(const VEC3 &rhs) const;			// ���s�֌W�ɂ���H
	inline bool  IsSharpAngle(const VEC3 &rhs) const;		// �s�p�֌W�H
}VEC3;

// ����
typedef struct LINE
{
	FLOAT3 pos;															// �ʒu
	VEC3 vec;															// �����x�N�g��
	LINE() : pos(0.0f, 0.0f, 0.0f), vec(1.0f, 0.0f, 0.0f) {}			// �R���X�g���N�^
	LINE(const FLOAT3 &pos, const VEC3 &vec) : pos(pos), vec(vec) {}	// �R���X�g���N�^
	~LINE() {}															// �f�X�g���N�^
	inline FLOAT3 GetPoint(float fCoffi) const;							// �_��̍��W���擾
}LINE;

// ����
typedef struct SEGMENT : public LINE
{
	SEGMENT() {}														// �R���X�g���N�^
	SEGMENT(const FLOAT3 &p, const VEC3 &v) : LINE(p, v) {}				// �R���X�g���N�^
	SEGMENT(const FLOAT3 &p1, const FLOAT3 &p2) : LINE(p1, p2 - p1) {}	// �R���X�g���N�^
	~SEGMENT() {}														// �f�X�g���N�^
	inline FLOAT3 GetEndPoint(void) const;								// �I�_���擾
}SEGMENT;

// ��
typedef struct SPHERE
{
	FLOAT3 Point;														// ���S�_
	float fRadius;														// ���a
	SPHERE() : Point(0.0f, 0.0f, 0.0f), fRadius(0.5f) {}				// �R���X�g���N�^
	SPHERE(const FLOAT3 &p, float r) : Point(p), fRadius(r) {}			// �R���X�g���N�^
	~SPHERE() {}														// �f�X�g���N�^
}SPHERE;

// �J�v�Z��
typedef struct CAPSULE
{
	SEGMENT Segment;																		// ����
	float fRadius;																			// ���a
	CAPSULE() : fRadius(0.5f) {}															// �R���X�g���N�^
	CAPSULE(const SEGMENT &s, float r) : Segment(s), fRadius(r) {}							// �R���X�g���N�^
	CAPSULE(const FLOAT3 &p1, const FLOAT3 &p2, float r) : Segment(p1, p2), fRadius(r) {}	// �R���X�g���N�^
	~CAPSULE() {}																			// �f�X�g���N�^
}CAPSULE;

// AABB
typedef struct AABB
{
	FLOAT3 Point;		// ���S�_
	FLOAT3 HalLength;	// �e���̕ӂ̒����̔���
	AABB() {}																// �R���X�g���N�^
	AABB(const FLOAT3 &p, const FLOAT3 &hl) : Point(p), HalLength(hl) {}	// �R���X�g���N�^
	inline float LenX(void) const { return HalLength.x * 2.0f; };			// X���ӂ̒������擾
	inline float LenY(void) const { return HalLength.y * 2.0f; };			// Y���ӂ̒������擾
	inline float LenZ(void) const { return HalLength.z * 2.0f; };			// Z���ӂ̒������擾
	inline float Len(int i) { return *((&HalLength.x) + i) * 2.0f; }		// �ӂ̒������擾
}AABB;

/* * ���̓L�[�̃Z�� */
typedef struct _INPUTKEYCELL
{
	int             nKey;		// �L�[
	int             nData;		// �f�[�^
	_INPUTKEYCELL*  pNext;		// ���̃f�[�^�|�C���^
}INPUTKEYCELL;

/* *�^�C�}�[��� */
typedef struct _TIMER_INFO
{
	_TIMER_INFO() {};
	_TIMER_INFO(int nStart, int nEnd);

	int nStart;		// �J�n
	int nEnd;		// �I��
}TIMER_INFO;

/* *
* �e�N�X�`����UV���W�̐ݒ�p�̏��
* Previous version TEXTUREVARIABLES
*/
typedef struct _SETING_UV
{
	/* * �R���X�g���N�^ */
	_SETING_UV() {}
	_SETING_UV(int nCntU, int nNumU, int nCntV, int nNumV);
	int nCntU;	// ���̃J�E���g
	int nNumU;	// ���̌�
	int nCntV;	// �c�̃J�E���g
	int nNumV;	// �c�̌�
}SETING_UV;

/* *
* �e�N�X�`���A�j���[�V�������
* Previous version ANIMTEXVARIABLES
*/
typedef struct _TEXTUREANIMEINFO
{
	/* * �R���X�g���N�^ */
	_TEXTUREANIMEINFO() {}
	_TEXTUREANIMEINFO(int nFrame, int nFrameMax, int nIteration);

	int nFrame;		// �t���[��
	int nFrameMax;	// �ő�t���[����
	int nIteration;	// �؂�Ԃ�(1��-1)
}TEXTUREANIMEINFO;

typedef struct _INTEGER2SOURCE
{
	int nX;	// �ő�l
	int nY;	// �ŏ��l
}INTEGER2SOURCE;

/* * �͈� */
typedef struct _RANGE
{
	/* * �R���X�g���N�^ */
	_RANGE() {}
	_RANGE(const int nMax, const int nMin);
	_RANGE(CONST INTEGER2SOURCE& rhs);
	_RANGE(const int rhs);

	/* * �P�����Z�q + */
	inline _RANGE operator + (void) const;
	/* * �P�����Z�q - */
	inline _RANGE operator - (void) const;

	/* * �񍀉��Z�q + */
	inline _RANGE operator + (CONST _RANGE& rhs) const;
	inline _RANGE operator + (CONST INTEGER2SOURCE& rhs) const;
	inline _RANGE operator + (CONST int rhs) const;

	/* * �񍀉��Z�q - */
	inline _RANGE operator - (CONST _RANGE& rhs) const;
	inline _RANGE operator - (CONST INTEGER2SOURCE& rhs) const;
	inline _RANGE operator - (CONST int rhs) const;

	/* * �񍀉��Z�q * */
	inline _RANGE operator * (CONST _RANGE& rhs) const;
	inline _RANGE operator * (CONST INTEGER2SOURCE& rhs) const;
	inline _RANGE operator * (CONST int rhs) const;

	/* * �񍀉��Z�q / */
	inline _RANGE operator / (CONST _RANGE& rhs) const;
	inline _RANGE operator / (CONST INTEGER2SOURCE& rhs) const;
	inline _RANGE operator / (CONST int rhs) const;

	/* * ��r���Z�q == */
	inline bool operator == (CONST _RANGE& rhs) const;
	inline bool operator == (CONST INTEGER2SOURCE& rhs) const;
	inline bool operator == (CONST int rhs) const;

	/* * ��r���Z�q != */
	inline bool operator != (CONST _RANGE& rhs) const;
	inline bool operator != (CONST INTEGER2SOURCE& rhs) const;
	inline bool operator != (CONST int rhs) const;

	/* * ������Z�q += */
	inline _RANGE& operator += (CONST _RANGE& rhs);
	inline _RANGE& operator += (CONST INTEGER2SOURCE& rhs);
	inline _RANGE& operator += (CONST int rhs);

	//* * ������Z�q -= */
	inline _RANGE& operator -= (CONST _RANGE& rhs);
	inline _RANGE& operator -= (CONST INTEGER2SOURCE& rhs);
	inline _RANGE& operator -= (CONST int rhs);

	//* * ������Z�q *= */
	inline _RANGE& operator *= (CONST _RANGE& rhs);
	inline _RANGE& operator *= (CONST INTEGER2SOURCE& rhs);
	inline _RANGE& operator *= (CONST int rhs);

	//* * ������Z�q /= */
	inline _RANGE& operator /= (CONST _RANGE& rhs);
	inline _RANGE& operator /= (CONST INTEGER2SOURCE& rhs);
	inline _RANGE& operator /= (CONST int rhs);

	/* * �����o�A�N�Z�X���Z�q[] */
	inline int  operator[] (unsigned int nIdx) const;
	inline int& operator[] (unsigned int nIdx);

	/* * �����_���l�����߂� */
	inline int GetRand(void);

	/* * �擾�ł��邩�H*/
	inline bool IsItGet(void);
	int nMax;	// �ő�l
	int nMin;	// �ŏ��l
}RANGE;

/* * int�^2�� */
typedef struct INTEGER2 : public INTEGER2SOURCE
{
public:
	/* * �R���X�g���N�^ */
	INTEGER2() {}
	INTEGER2(const int nMax, const int nMin);
	INTEGER2(CONST _RANGE& rhs);
	INTEGER2(const int rhs);

	/* * �P�����Z�q + */
	inline INTEGER2 operator + (void) const;
	/* * �P�����Z�q - */
	inline INTEGER2 operator - (void) const;

	/* * �񍀉��Z�q + */
	inline INTEGER2 operator + (CONST INTEGER2& rhs) const;
	inline INTEGER2 operator + (CONST _RANGE& rhs) const;
	inline INTEGER2 operator + (CONST int rhs) const;

	/* * �񍀉��Z�q - */
	inline INTEGER2 operator - (CONST INTEGER2& rhs) const;
	inline INTEGER2 operator - (CONST _RANGE& rhs) const;
	inline INTEGER2 operator - (CONST int rhs) const;

	/* * �񍀉��Z�q * */
	inline INTEGER2 operator * (CONST INTEGER2& rhs) const;
	inline INTEGER2 operator * (CONST _RANGE& rhs) const;
	inline INTEGER2 operator * (CONST int rhs) const;

	/* * �񍀉��Z�q / */
	inline INTEGER2 operator / (CONST INTEGER2& rhs) const;
	inline INTEGER2 operator / (CONST _RANGE& rhs) const;
	inline INTEGER2 operator / (CONST int rhs) const;

	/* * ��r���Z�q == */
	inline bool operator == (CONST INTEGER2& rhs) const;
	inline bool operator == (CONST _RANGE& rhs) const;
	inline bool operator == (CONST int rhs) const;

	/* * ��r���Z�q != */
	inline bool operator != (CONST INTEGER2& rhs) const;
	inline bool operator != (CONST _RANGE& rhs) const;
	inline bool operator != (CONST int rhs) const;

	/* * ������Z�q += */
	inline INTEGER2& operator += (CONST INTEGER2& rhs);
	inline INTEGER2& operator += (CONST _RANGE& rhs);
	inline INTEGER2& operator += (CONST int rhs);

	//* * ������Z�q -= */
	inline INTEGER2& operator -= (CONST INTEGER2& rhs);
	inline INTEGER2& operator -= (CONST _RANGE& rhs);
	inline INTEGER2& operator -= (CONST int rhs);

	//* * ������Z�q *= */
	inline INTEGER2& operator *= (CONST INTEGER2& rhs);
	inline INTEGER2& operator *= (CONST _RANGE& rhs);
	inline INTEGER2& operator *= (CONST int rhs);

	//* * ������Z�q /= */
	inline INTEGER2& operator /= (CONST INTEGER2& rhs);
	inline INTEGER2& operator /= (CONST _RANGE& rhs);
	inline INTEGER2& operator /= (CONST int rhs);

	/* * �����o�A�N�Z�X���Z�q[] */
	inline int  operator[] (unsigned int nIdx) const;
	inline int& operator[] (unsigned int nIdx);

}INTEGER2, *PINTEGER2;

/* * int�^3�� */
typedef struct INTEGER3
{
public:
	/* * �R���X�g���N�^ */
	INTEGER3() {}
	INTEGER3(int nX, int nY, int nZ);
	INTEGER3(int nRhs);

	/* * �P�����Z�q + */
	inline INTEGER3 operator + (void) const;
	/* * �P�����Z�q - */
	inline INTEGER3 operator - (void) const;

	/* * �񍀉��Z�q + */
	inline INTEGER3 operator + (CONST INTEGER3& rhs) const;
	inline INTEGER3 operator + (CONST int rhs) const;

	/* * �񍀉��Z�q - */
	inline INTEGER3 operator - (CONST INTEGER3& rhs) const;
	inline INTEGER3 operator - (CONST int rhs) const;

	/* * �񍀉��Z�q * */
	inline INTEGER3 operator * (CONST INTEGER3& rhs) const;
	inline INTEGER3 operator * (CONST int rhs) const;

	/* * �񍀉��Z�q / */
	inline INTEGER3 operator / (CONST INTEGER3& rhs) const;
	inline INTEGER3 operator / (CONST int rhs) const;

	/* * ��r���Z�q == */
	inline bool operator == (CONST INTEGER3& rhs) const;
	inline bool operator == (CONST int rhs) const;

	/* * ��r���Z�q != */
	inline bool operator != (CONST INTEGER3& rhs) const;
	inline bool operator != (CONST int rhs) const;

	/* * ������Z�q += */
	inline INTEGER3& operator += (CONST INTEGER3& rhs);
	inline INTEGER3& operator += (CONST int rhs);

	//* * ������Z�q -= */
	inline INTEGER3& operator -= (CONST INTEGER3& rhs);
	inline INTEGER3& operator -= (CONST int rhs);

	//* * ������Z�q *= */
	inline INTEGER3& operator *= (CONST INTEGER3& rhs);
	inline INTEGER3& operator *= (CONST int rhs);

	//* * ������Z�q /= */
	inline INTEGER3& operator /= (CONST INTEGER3& rhs);
	inline INTEGER3& operator /= (CONST int rhs);

	/* * �����o�A�N�Z�X���Z�q[] */
	inline int  operator[] (unsigned int nIdx) const;
	inline int& operator[] (unsigned int nIdx);

	int x;		// X������
	int y;		// Y������
	int z;		// Z������
} INTEGER3, *PINTEGER3;

/* * int�^4�� */
typedef struct INTEGER4
{
public:
	/* * �R���X�g���N�^ */
	INTEGER4() {}
	INTEGER4(int nX, int nY, int nZ, int nW);
	INTEGER4(int nRhs);

	/* * �P�����Z�q + */
	inline INTEGER4 operator + (void) const;
	/* * �P�����Z�q - */
	inline INTEGER4 operator - (void) const;

	/* * �񍀉��Z�q + */
	inline INTEGER4 operator + (CONST INTEGER4& rhs) const;
	inline INTEGER4 operator + (CONST int rhs) const;

	/* * �񍀉��Z�q - */
	inline INTEGER4 operator - (CONST INTEGER4& rhs) const;
	inline INTEGER4 operator - (CONST int rhs) const;

	/* * �񍀉��Z�q * */
	inline INTEGER4 operator * (CONST INTEGER4& rhs) const;
	inline INTEGER4 operator * (CONST int rhs) const;

	/* * �񍀉��Z�q / */
	inline INTEGER4 operator / (CONST INTEGER4& rhs) const;
	inline INTEGER4 operator / (CONST int rhs) const;

	/* * ��r���Z�q == */
	inline bool operator == (CONST INTEGER4& rhs) const;
	inline bool operator == (CONST int rhs) const;

	/* * ��r���Z�q != */
	inline bool operator != (CONST INTEGER4& rhs) const;
	inline bool operator != (CONST int rhs) const;

	/* * ������Z�q += */
	inline INTEGER4& operator += (CONST INTEGER4& rhs);
	inline INTEGER4& operator += (CONST int rhs);

	//* * ������Z�q -= */
	inline INTEGER4& operator -= (CONST INTEGER4& rhs);
	inline INTEGER4& operator -= (CONST int rhs);

	//* * ������Z�q *= */
	inline INTEGER4& operator *= (CONST INTEGER4& rhs);
	inline INTEGER4& operator *= (CONST int rhs);

	//* * ������Z�q /= */
	inline INTEGER4& operator /= (CONST INTEGER4& rhs);
	inline INTEGER4& operator /= (CONST int rhs);

	/* * �����o�A�N�Z�X���Z�q[] */
	inline int  operator[] (unsigned int nIdx) const;
	inline int& operator[] (unsigned int nIdx);

	int x;		// X������
	int y;		// Y������
	int z;		// Z������
	int w;		// W������
} INTEGER4, *PINTEGER4;

// �g�����X�t�H�[�����
typedef struct TRANSFORM
{
	/* * �R���X�g���N�^ */
	TRANSFORM() : pos(MYLIB_3DVECTOR_ZERO), rot(MYLIB_3DVECTOR_ZERO), scal(MYLIB_SCALE_UNSET) {}														// �R���X�g���N�^
	TRANSFORM(D3DXVECTOR3 &pos, D3DXVECTOR3 &rot, D3DXVECTOR3 &scal, D3DXMATRIX &mtxWorld) : pos(pos), rot(rot), scal(scal), mtxWorld(mtxWorld) {}		// �R���X�g���N�^
	TRANSFORM(D3DXVECTOR3 &pos, D3DXVECTOR3 &rot, D3DXVECTOR3 &scal) : pos(pos), rot(rot), scal(scal) {}												// �R���X�g���N�^

	// inline void Move(CONST D3DXVECTOR3 &rhs);			// �ړ�
	// inline void Move(CONST D3DXVECTOR2 &rhs);			// �ړ�
	// inline void Move(const float &rhs);					// �ړ�

	// inline void FlatMove(CONST D3DXVECTOR3 &rhs);		// ���ʈړ�
	// inline void FlatMove(const float &rhs);				// ���ʈړ�

	inline void Identity(void);								// �}�g���b�N�X�̏�����

	D3DXVECTOR3 pos;		// �ʒu
	D3DXVECTOR3 rot;		// ��]
	D3DXVECTOR3 scal;		// �X�P�[��
	D3DXMATRIX mtxWorld;	// �}�g���b�N�X
} TRANSFORM, *PTRANSFORM;


/*-- ���[�V�����L�[ --*/
typedef struct
{
	int				nFlame;		// �t���[����
	D3DXVECTOR3		*pos;		// �ʒu
	D3DXVECTOR3		*rot;		// ��]��
} MOTION_KEY;

/*-- ���[�V���� --*/
typedef struct
{
	int			nLoop;			// ���[�v���邩�ǂ���
	int			nNumKey;		// �L�[��
	MOTION_KEY	*MotionKey;		// ���[�V�����L�[
}MOTION_INFO;


// �Q�[�W���
typedef struct GAGE_INFO
{
	GAGE_INFO() {}
	GAGE_INFO(RANGE SourceRange, int nSourceValue, float fSourceCoefficient);

	RANGE		range;			// �͈�
	int			nValue;			// ������l
	float		fCoefficient;	// �W��
} GAGE_INFO;


typedef struct
{
	UVSHORT b;	// ��
	UVSHORT g;	// ��
	UVSHORT r;	// ��
} BGR;

typedef struct
{
	UVSHORT b;	// ��
	UVSHORT g;	// ��
	UVSHORT r;	// ��
	UVSHORT a;	// �����x
} BGRA;

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
/* �v���N���X�i�����[�X���͓��삵�Ȃ��j */
class CMeasurement
{
public:
	// �R���X�g���N�^
	inline CMeasurement() {};
	// �f�X�g���N�^
	inline ~CMeasurement() {};

	// �v���J�n
	inline void Start(void);
	// �v���I��
	inline void End(void);
	// �`��
	inline void Draw(void);
	// �b���̎擾
	inline double GetTime(void);
private:
#ifdef MYLIB_MEASURE
	LARGE_INTEGER m_freq;		// �t���b�v
	LARGE_INTEGER m_start;		// �J�n���̎���
	LARGE_INTEGER m_end;		// �I�����̎���

#endif
};



/* �x�N�^�[�^ */
template<class T>
class MyVector
{
public:
	/* ����
	* T* = �C�e���[�^�[
	*/
	// �R���X�g���N�^
	inline MyVector();
	// �R���X�g���N�^
	inline MyVector(const MyVector<T>& source);
	// �f�X�g���N�^
	inline ~MyVector();
	// = �̃I�[�o�[���[�h
	inline MyVector<T>& operator=(const MyVector<T>& source);

	// �R���e�i���󂩂ǂ����𔻒肷��
	inline bool empty(void) const;
	// �T�C�Y�̎擾
	inline int &size(void);
	// ���e�ʂ̎擾
	inline int &capacity(void);
	// []�̃I�[�o�[���[�h
	inline T& operator[](int nArray);
	// []�̃I�[�o�[���[�h
	inline const T& operator[](int nArray) const;
	// �N���A
	inline void clear(void);

	// �擪�v�f���w���C�e���[�^���擾����B
	inline T* begin(void);
	// �擪�v�f���w���C�e���[�^���擾����B
	inline const T* begin(void) const;
	// �����̎����w���C�e���[�^���擾����
	inline T* end(void);
	// �����̎����w���C�e���[�^���擾����
	inline const T* end(void) const;
	// �擪�v�f�ւ̎Q�Ƃ��擾����B
	inline T& front(void);
	// �擪�v�f�ւ̎Q�Ƃ��擾����B
	inline const T& front(void) const;
	// �����v�f�ւ̎Q�Ƃ��擾����
	inline T& back(void);
	// �����v�f�ւ̎Q�Ƃ��擾����
	inline const T& back(void) const;

	// ����vector�I�u�W�F�N�g�ƃf�[�^�����ւ���B
	inline void swap(MyVector<T>& rhs);
	// �v�f����ύX����
	inline void resize(int nNewSize);
	// �v�f����ύX����
	inline void resize(int nNewSize, const T& tValue);
	// ���e�ʂ�ύX����
	inline void reserve(int nNewCapacity);
	// �V���ȗv�f�𖖔��ɒǉ�����
	inline void push_back(const T& tValue);
	// �V���ȗv�f�𖖔��ɒǉ�����
	inline void push_back(void);
	// �w�肵���v�f���폜����B
	inline T* erase(const T* pIt);
	// �w�肵���͈̗͂v�f���폜
	inline T* erase(const T* pIt, const T* pIt_last);
	// �C�ӂ̈ʒu�ɐV���ȗv�f��}������
	inline T* insert(const T* pIt, const T& tValue);
	// �C�ӂ̒l���v�f���Ɋ܂܂�Ă��邩
	inline bool contains(const T& tValue) const;
	// �w�肳�ꂽ�l����������
	inline T* find(const T& tValue);
	// �w�肳�ꂽ�l����������
	inline const T* find(const T& tValue) const;
	// �w�肳�ꂽ�l���������폜����
	inline bool find_erase(const T& tValue);
	// �C�e���[�^�[����C���f�b�N�X�ɂ���
	inline int index_from_ptr(const T* pIt) const;
	// �����v�f���폜����
	inline void pop_back(void);
private:

	// ���e�ʂ𑝂₷
	inline int AddCapacity(int nSize) const;

	int m_nSize;		// �T�C�Y
	int m_nCapacity;	// ���e��
	T*  m_pData;		// �f�[�^�|�C���^
};

// �L�[�C���v�b�g���^
class CInputkey
{
	/* * �R���X�g���N�^ */
	CInputkey() {}
	/* * �f�X�g���N�^ */
	~CInputkey() {}
	/* * ������ */
	void Init(void);
	/* * �L�[�f�[�^�̏����� */
	void KeyInit(void);
	/* * �L�[�f�[�^�̐��� */
	void KeyCreate(void);
	/* * �L�[�f�[�^���X�g�̊J�� */
	void KeyListRelease(void);
	/* * �L�[�f�[�^�̑}�� */
	void KeyInsert(int nData, int nKey);
	/* * �L�[�f�[�^�𔲂����@*/
	void KeyPullout(int nKey);
	/* * �L�[�f�[�^�̎擾 */
	int GetKeyData(int nKey);
	/* * �T�C�Y�̎擾 */
	int GetSize(void);
private:
	int           m_nSize;		// �T�C�Y�i�f�[�^��)
	INPUTKEYCELL* m_pKeyTop;	// �L�[�̐擪�|�C���^
};

// ������^
class CString
{
public:
	/* * �R���X�g���N�^ */
	CString();
	/* * �f�X�g���N�^ */
	~CString();
	/* * ������ */
	inline void Init(void);
	/* * �J������ */
	inline void release(void);
	/* * ������̐ݒ�(�ݒ肵�Ă����ꍇ�͍Đݒ肷��) */
	inline void Set(STRING string);
	inline void Set(CONST_STRING string);
	/* * ������̎擾 */
	inline STRING Get(void);
	/* * �T�C�Y�̎擾 */
	inline int & size(void);
private:
	STRING m_string;		// ������|�C���^
	int m_nStringLength;	// ������̒���
};

class CMylibrary
{
public:
	//----------------------------------------------------------------------------------------------------
	// 2D
	//----------------------------------------------------------------------------------------------------

	//* [contents] 2D�x�N�g���𐶐�����{ B - A }
	//* [in] 3DposA�A3DposB
	//* [out] ��������2D�x�N�g��
	static void CreateVector2(D3DXVECTOR2 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 2D�x�N�g���𐶐�����{ B - A }
	//* [in] 2DposA�A2DposB
	//* [out] ��������2D�x�N�g��
	static void CreateVector2(D3DXVECTOR2 *output, CONST D3DXVECTOR2 *posA, CONST D3DXVECTOR2 *posB);

	//* [contents] 2D�x�N�g���𐶐�����{ B - A }
	//* [in] 3DposA�A2DposB
	//* [out] ��������2D�x�N�g��
	static void CreateVector2(D3DXVECTOR2 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR2 *posB);

	//* [contents] 2D�x�N�g���𐶐�����{ B - A }
	//* [in] 2DposA�A3DposB
	//* [out] ��������2D�x�N�g��
	static void CreateVector2(D3DXVECTOR2 *output, CONST D3DXVECTOR2 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 2D�̊O�ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [return] ��������2D�O��
	static float Create2DCross(CONST D3DXVECTOR3 *vecA, CONST D3DXVECTOR3 *vecB);

	//* [contents] 2D�̊O�ς𐶐�����
	//* [in] 2DvecA�A2DvecB
	//* [return] ��������2D�O��
	static float Create2DCross(CONST D3DXVECTOR2 *vecA, CONST D3DXVECTOR2 *vecB);

	//* [contents] 2D�̓��ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [return] ��������2D�O��
	static float Create2DDot(CONST D3DXVECTOR3* vecA, CONST D3DXVECTOR3* vecB);

	//* [contents] 2D�̓��ς𐶐�����
	//* [in] 2DvecA�A2DvecB
	//* [return] ��������2D�O��
	static float Create2DDot(CONST D3DXVECTOR2* vecA, CONST D3DXVECTOR2* vecB);

	//* [contents] 2D�̃x�N�g���̒��������߂�
	//* [in] 2Dvec
	//* [return] �x�N�g���̒���
	static float Get2DVecLength(D3DXVECTOR2 *vec);

	//* [contents] 2D�̍����̋���
	//* [in] 3D����
	//* [return] �v�Z��������
	static float Get2DToPointDistance(D3DXVECTOR2 *diffPos);

	//* [contents] 2D�̒P�ʃx�N�g���𐶐�
	//* [in] 2Dvec
	//* [out] ���������P�ʃx�N�g��
	static void CreateUnitVec2D(D3DXVECTOR2 *Output, D3DXVECTOR2 *Vec);

	//* [contents] 2D�̍����̊p�x
	//* [in] 3DposA, 3DposB
	//* [out] �v�Z�����p�x
	static void Get2DToPointAngle(float *pOutput, D3DXVECTOR3 *posA, D3DXVECTOR3 *posB);

	//* [contents] 2D�̍����̊p�x
	//* [in] 3D����
	//* [out] �v�Z�����p�x
	static void Get2DToPointAngle(float *pOutput, D3DXVECTOR3 *diffPos);

	//* [contents] 2D���ς�p���Ē������m�̌�_�����߂�
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC, ���_�ʒuD
	//* [out] ��_
	//* [return] bool �itrue ������Ă���Afalse ������Ă��Ȃ��j
	static bool Get2DIntersectionOfStraightLines(D3DXVECTOR3 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB, CONST D3DXVECTOR3 *posC, CONST D3DXVECTOR3 *posD);

	//* [contents] 2D�O�ς�p���Đ������m�̌�_�����߂�
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC, ���_�ʒuD, �@��
	//* [out] ��_
	//* [return] bool �itrue ������Ă���Afalse ������Ă��Ȃ��j
	static bool Get2DIntersectionOfLineSegments(D3DXVECTOR3 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB, CONST D3DXVECTOR3 *posC, CONST D3DXVECTOR3 *posD);

	//* [contents] 2D�������m���������Ă��邩���߂�
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC, ���_�ʒuD
	//* [out] ��_
	//* [return] bool �itrue ������Ă���Afalse ������Ă��Ȃ��j
	static bool Get2DIntersectionOfStraightLineSegments(D3DXVECTOR3 * output, CONST D3DXVECTOR3 * posA, CONST D3DXVECTOR3 * posB, CONST D3DXVECTOR3 * posC, CONST D3DXVECTOR3 * posD);

	//* [contents] 2D�l�p�`�̓����蔻��
	//* [in] �ʒuA,�ʒuB, �傫��A, �傫��B
	//* [return] bool �itrue �ڐG���Ă���Afalse �ڐG���Ă��Ȃ��j
	static bool Test2DCollisionRect(D3DXVECTOR3 *posA, D3DXVECTOR3 *posB, D3DXVECTOR2 *sizeA = NULL, D3DXVECTOR2 *sizeB = NULL);

	//-------------------------------------------------------------------------------------------------------------
	// 3D
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] Y�����Ȃ�����3D�x�N�g���𐶐�����
	//* [in] 3DposA�A3DposB
	//* [out] ��������3D�x�N�g��
	static void CreateFlatVector3(D3DXVECTOR3 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 3D�x�N�g���𐶐�����
	//* [in] 3DposA�A3DposB
	//* [out] ��������3D�x�N�g��
	static void CreateVector3(D3DXVECTOR3 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 3D�x�N�g���𐶐�����
	//* [in] 2DposA�A2DposB
	//* [out] ��������3D�x�N�g��
	static void CreateVector3(D3DXVECTOR3 *output, CONST D3DXVECTOR2 *posA, CONST D3DXVECTOR2 *posB);

	//* [contents] 3D�x�N�g���𐶐�����
	//* [in] 2DposA�A3DposB
	//* [out] ��������3D�x�N�g��
	static void CreateVector3(D3DXVECTOR3 *output, CONST D3DXVECTOR2 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 3D�x�N�g���𐶐�����
	//* [in] 3DposA�A2DposB
	//* [out] ��������3D�x�N�g��
	static void CreateVector3(D3DXVECTOR3 *output, CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR2 *posB);

	//* [contents] 3D�̊O�ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [out] ��������3D�O��
	static void Create3DCross(D3DXVECTOR3 *resulut, D3DXVECTOR3 *vecA, D3DXVECTOR3 *vecB);

	//* [contents] 3D�̕��ʊO�ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [return] ������������3D�O��
	static float CreateflatCross(CONST D3DXVECTOR3 *vecA, CONST D3DXVECTOR3 *vecB);

	//* [contents] 3D�̓��ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [return] ��������3D����
	static float Create3DDot(D3DXVECTOR3 *vecA, D3DXVECTOR3 *vecB);

	//* [contents] 3D�̓��ς𐶐�����
	//* [in] �x�N�g��
	//* [return] ��������3D����
	static float Create3DDot(D3DXVECTOR3 *vec);

	//* [contents] 3D�̓��ς𐶐�����
	//* [in] 3DvecA�A3DvecB
	//* [out] ��������3D����
	static void Create3DDot(float *out, D3DXVECTOR3 *vecA, D3DXVECTOR3 *vecB);

	//* [contents] 3D��2D��̃x�N�g���̒��������߂�
	//* [in] 3DvecA�A3DvecB
	//* [out] ��������3D����
	static float GetFlatVecLength(D3DXVECTOR3 *vec);

	//* [contents] 3D��2D��̃x�N�g���̒��������߂�
	//* [in] 3Dvec
	//* [out] ���������x�N�g���̒���
	static float Get3DVecLength(D3DXVECTOR3 *vec);

	//* [contents] 3D��2�_�̃x�N�g���̒��������߂�
	//* [in] 3DvecA�A3DvecB
	//* [return] ���������x�N�g���̒���
	static float Get3DClossLength(D3DXVECTOR3 *vecA, D3DXVECTOR3 *vecB);

	//* [contents] 3D��2�_�̃x�N�g���̒��������߂�
	//* [in] 3Dvec
	//* [out] ���������x�N�g���̒���
	static void Get3DVecLength(float *out, D3DXVECTOR3 * vec);

	//* [contents] 3D��2�_�̊O�ς̒��������߂�
	//* [in] 3DposA�A3DposB
	//* [out] ���������x�N�g���̒���
	static void Get3DClossLength(float *out, D3DXVECTOR3 *posA, D3DXVECTOR3 *posB);

	//* [contents] 3D�̒P�ʃx�N�g���𐶐�
	//* [in] 3Dvec
	//* [out] ���������P�ʃx�N�g��
	static void CreateUnitVector(D3DXVECTOR3 *out, D3DXVECTOR3 *Vec);

	//* [contents] 3D�̒��_�Ԃ̋����̎擾
	//* [in] 3DposA�A3DposB
	//* [return] �v�Z��������
	static float Get3DToPointDistance(CONST D3DXVECTOR3 *posA, CONST D3DXVECTOR3 *posB);

	//* [contents] 3D�̍����̋���
	//* [in] 3D����
	//* [return] �v�Z��������
	static float Get3DToDiffDistance(D3DXVECTOR3 *diffPos);

	//* [contents] 3D�̍����̋���
	//* [in] 3D����
	//* [out] �v�Z��������
	static void Get3DToPointDistance(float *Length, D3DXVECTOR3 *diffPos);

	//* [contents] 3D���ʂ̍����̋���
	//* [in] 3D�ʒuA�A3D�ʒuB
	//* [out] �v�Z��������
	static float GetFlatToPointDistance(CONST D3DXVECTOR3 * pPosA, CONST D3DXVECTOR3 * pPosB);

	//* [contents] �|���S���̗��ɂ��邩�e�X�g
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC , �ʒuP(�_P)
	//* [return] bool �i�͈͓� == true �͈͊O == false�j
	static bool TestIfPolygonBack(CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posP, CONST D3DXVECTOR3 &nom);

	//* [contents] �|���S�����ɂ��邩�e�X�g����
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC , �ʒuP(�_P)
	//* [return] bool �i�͈͓� == true �͈͊O == false�j
	static bool PolygonInTest(CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, CONST D3DXVECTOR3 &posC, CONST D3DXVECTOR3 &posP);

	//* [contents] ���ʂ̃|���S���͈̔͂ɂ��邩�e�X�g
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC , �ʒuP(�_P)
	//* [return] bool �i�͈͓� == true �͈͊O == false�j
	static bool Test3DInsidePlanePolygon(CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, CONST D3DXVECTOR3 &posC, CONST D3DXVECTOR3 &posP);

	//* [contents] �|���S���͈̔͂ɂ��邩�e�X�g
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC , �ʒuP(�_P)
	//* [return] bool �i�͈͓� == true �͈͊O == false�j
	static bool Test3DInsidePolygon(CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, CONST D3DXVECTOR3 &posC, CONST D3DXVECTOR3 &posP);

	//* [contents] �|���S���͈̔͂ɂ��邩�e�X�g
	//* [in] ���_�ʒuA, ���_�ʒuB, ���_�ʒuC , �ʒuP(�_P), �|���S���̖@��
	//* [return] bool �i�͈͓� == true �͈͊O == false�j
	static bool Test3DInsidePolygon(CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, CONST D3DXVECTOR3 &posC, CONST D3DXVECTOR3 &posP, CONST D3DXVECTOR3 & nom);

	//* [contents] �������m�̋����ƍŒZ�_���W�̎擾
	//* [in] �ʒuA , �x�N�g��A, �ʒuB, �x�N�g��B
	//* [out] ����, �ŒZ�_���WA, �ŒZ�_���WB
	static bool Calc2LineNearestDistAndPos(D3DXVECTOR3* posA, D3DXVECTOR3* vecA, D3DXVECTOR3* posB, D3DXVECTOR3* vecB, float* fOutDist, D3DXVECTOR3* pOutPosA, D3DXVECTOR3* pOutPosB);

	//* [contents] �O�ςœ��O�ʒu�֌W�𒲂ׂ�
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [return] bool �i�� == true �O == false�j
	static bool CrossRelationship(D3DXVECTOR3 &posP, D3DXVECTOR3 &posA, D3DXVECTOR3 &posB);

	//* [contents] ���ςŕ\���ʒu�֌W�𒲂ׂ�
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [return] bool �i�\ == true �� == false�j
	static bool DotRelationship(CONST D3DXVECTOR3 &Dot, CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, float fTolerance = 0.0f);

	//* [contents] 2D��ӂ���ςňʒu�֌W�𒲂ׂ�
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [return] bool �i�\ == true �� == false�j
	static bool OneSideDotRelationship(CONST D3DXVECTOR3 &Dot, CONST D3DXVECTOR3 &posA, CONST D3DXVECTOR3 &posB, float fTolerance = 0.0f);

	//* [contents] 3D�_�ƒ����̋���
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [return] �v�Z��������
	static float Get3DLengthDotAndLine(CONST D3DXVECTOR3 *posP, CONST D3DXVECTOR3 *pPosA, CONST D3DXVECTOR3 *pPosB);

	//* [contents] 3D����̍ŋߓ_���Z�o
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [out] �ŋߓ_
	static void Get3DNearestPointOnline(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *posP, CONST D3DXVECTOR3 *pPosA, CONST D3DXVECTOR3 *pPosB);

	//* [contents] 3D���ʏ�̓_�ƒ����̂̋���
	//* [in] �ʒuP(�_P), ���_�ʒuA, ���_�ʒuB
	//* [return] �v�Z��������
	static float Get3DFlatLengthDotAndLine(CONST D3DXVECTOR3 *posP, CONST D3DXVECTOR3 *pPosA, CONST D3DXVECTOR3 *pPosB);

	//* [contents] ���ʂƂ̋���
	//* [in] ���ʏ�̈ʒu�A���ʂ̕����x�N�g���A�����̈ʒu�A�����̕����x�N�g��
	//* [return] �v�Z��������
	static float GetPlaneDistance(D3DXVECTOR3* pPosOnPlane, D3DXVECTOR3* pPlaneUnitVec, D3DXVECTOR3* pLinePos, D3DXVECTOR3* pLineUnitVec);

	//* [contents] ���ʂƒ����̌�_���Z�o
	//* [in] ���ʏ�̈ʒu�A���ʂ̖@���A������̈ʒu�A�����̕����x�N�g��
	//* [out] �v�Z������_
	static bool CalIntersectionPointToPlaneAndLine(D3DXVECTOR3 * pOut, D3DXVECTOR3 * pPlanePos, D3DXVECTOR3 * pPlaneNor, D3DXVECTOR3 * pStartPos, D3DXVECTOR3 * pVecDir);

	//* [contents] �r���{�[�h�̐ݒ�
	//* [in] �f�o�C�X�|�C���^
	//* [out] �}�g���b�N�X
	static void SetBillboard(LPDIRECT3DDEVICE9 pDevice, D3DXMATRIX *mtxOutput);

	//* [contents] �r���{�[�h���[��]�̑ł������̐ݒ�
	//* [in] �f�o�C�X�|�C���^
	//* [out] �}�g���b�N�X
	static void SetBillboardNotRoll(LPDIRECT3DDEVICE9 pDevice, D3DXMATRIX *mtxOutput);

	//* [contents] ������ɒ��_�����邩����
	//* [in] ���_�ʒu�A�����̎n�܂�A�����̏I���A�����̌���
	//* [return] bool �i���� == true ���Ȃ� == false�j
	static bool Test3DVertexOnLine(D3DXVECTOR3 * pPos, D3DXVECTOR3 *LineBegin, D3DXVECTOR3 *LineEnd, D3DXVECTOR3*pLineDir);

	//* [contents] �@���x�N�g������I�C���[�p�ɕϊ�
	//* [in] �@���x�N�g��
	//* [out]�@�ϊ������p�x
	static void ConvertEulerAngleFromNormal(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pNor);

	//-------------------------------------------------------------------------------------------------------------
	// 2,3D
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] �����^������
	//* [in] (����)�W��
	//* [out] 3DVec�ړ���
	static void SlowingMove(D3DXVECTOR3 *pMove, const float fCoefficient);

	//* [contents] �����^������
	//* [in] (����)�W��
	//* [out] �ړ���
	static void SlowingMove(float *pMove, const float fCoefficient);

	//* [contents] �Ǐ]�ړ�����
	//* [in] �ǂ��ʒu, �ǂ���ʒu, (�Ǐ])�W��
	//* [out] 3DVec�ړ���
	static void FollowingMove(D3DXVECTOR3 *move, const D3DXVECTOR3 *ChasPos, const D3DXVECTOR3 *ChasedPos, const float *SpeedFactor);

	//* [contents] �_�Ɠ_�̋������r����
	//* [in] ����, �\�[�X�i�����̏ꍇ�ǉ��\�[�X�Ȃ��j, �ǉ��\�[�X
	//* [return] bool �itrue �ݒ肵���������߂��Afalse �ݒ肵��������艓���j
	static bool TestToPointDistance(float fDistance, CONST D3DXVECTOR3 *Source, CONST D3DXVECTOR3 *AddSource = NULL);

	//* [contents] ��]�ʂ𒼂�
	//* [out] ����or��]��
	static void SetFixTheRotation(float *Rotation);

	//* [contents] ��]�ʂ𒼂�
	//* [out] Vec3����or��]��
	static void SetVec3FixTheRotation(D3DXVECTOR3 *Rotation);

	//-------------------------------------------------------------------------------------------------------------
	// Quaternion
	//-------------------------------------------------------------------------------------------------------------
	//* [contents] �����x�N�g������N�H�[�^�j�I�������߂�
	//* [in] �����x�N�g��(���K��)�A��]��
	//* [out] �Z�o�����N�H�[�^�j�I��
	static void CalQuaternionRotationAxis(D3DXQUATERNION * pOutput, CONST D3DXVECTOR3 &Norm,const float &fAngle);

	//* [contents] �N�H�[�^�j�I�����g���Ĉʒu���v�Z����
	//* [in] �����x�N�g��(���K��)�A���_����̋���
	//* [out] �Z�o�����ʒu
	static void UsingQuaternionCalculatePos(D3DXVECTOR3 *pOut, CONST D3DXVECTOR3& Nom, CONST D3DXVECTOR3& Vec, const float& fRadian);


	//-------------------------------------------------------------------------------------------------------------
	// COLLAR
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] COLORREF����D3DXCOLOR�ɕϊ�����(�A���t�@�l�Ȃ�)
	//* [in] �V�X�e���J���[
	//* [out] DirectX3D�J���[
	static void SetD3DXCOLORfromREF_WithoutAlpha(COLORREF *SystemColor, D3DXCOLOR *col);

	//* [contents]  COLORREF����D3DXCOLOR�ɕϊ�����
	//* [in] �V�X�e���J���[
	//* [out] DirectX3D�J���[
	static void SetD3DXCOLORfromREF(COLORREF *SystemColor, D3DXCOLOR *col);

	//-------------------------------------------------------------------------------------------------------------
	// Misc
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] �������擾����
	//* [in] �\�[�X�i�����j
	//* [out] ����
	static void GetDigits(int &out, int nSource);

	//* [contents] �������擾����
	//* [in] �\�[�X�i�����j
	//* [return] ����
	static int GetDigits(int nSource);

	//* [contents] �������擾����(��������)
	//* [in] �\�[�X, ����, ��i�i���j
	//* [out] ����
	static void GetDigitsEx(int &out, int nSource, int nRadix);

	//* [contents] �������擾����(��������)
	//* [in] �\�[�X, ����, ��i�i���j
	//* [return] ����
	static int GetDigitsEx(int nSource, int nRadix);

	//* [contents] �L�[ID�̎Q�Ƃ����L�[�����擾
	//* [in] �L�[ID
	//* [out] �L�[��
	static void GetKeyInputInfo(int nKeyID, STRING KeyName = NULL);

	//* [contents] �J��グ�������擾
	//* [in] �\�[�X, �
	//* [return] �J��グ����
	static int GetRoundedUp(int nSource, int nBase);

	//-------------------------------------------------------------------------------------------------------------
	// FILE
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] �e�L�X�g�t�@�C����������擾����
	//* [in] �t�@�C����, ���ږ�
	//* [return] ��
	static int GetNumberFromText(CONST_STRING TextFile, CONST_STRING SetItem);

	//* [contents] �e�L�X�g�t�@�C���ɃX�N���v�g�����݂��邩�`�F�b�N
	//* [in] �t�@�C���|�C���^
	//* [return] bool (true ���݂����Afalse ���݂��Ȃ�)
	static bool CheckforScript(FILE *pFile);

	//-------------------------------------------------------------------------------------------------------------
	// STRING
	//-------------------------------------------------------------------------------------------------------------

	//* [contents] ������̊m�ہA�ݒ�
	//* [in] �\�[�X(������)
	//* [return] ������|�C���^
	static STRING SetStringAlloc(CONST_STRING source);

	//* [contents] �����񂩂�int�^�ɕϊ�����(�����񂩂琔���𔲂����)�|���l�����Ȃ�
	//* [in] ������
	//* [return] �ϊ���������
	static int GetConvertStoI(STRING str);

	//* [contents] �����񂩂�int�^�ɕϊ�����(�����񂩂琔���𔲂����)�|���l�����Ȃ�
	//* [in] ������
	//* [return] �ϊ���������
	static int GetConvertStoI(CONST_STRING str);

	//* [contents] int�^���當����ɕϊ�����
	//* [in] �ϊ�����l�A��i�i���j
	//* [out] �ϊ�����������
	static void ConvertItoS(STRING pOut, int nVal, int nRadix);

	//* [contents] int�^���當����𐶐����A�ϊ�����
	//* [in] ��i�i���j
	//* [return] �ϊ�����������
	static STRING ConvertItoSAlloc(int nVal, int nRadix);

	//* [contents] int�^���當����𐶐����A�ϊ�����
	//* [in] �ϊ�����l�A��i�i���j
	//* [out] �ϊ�����������
	static void ConvertItoSAlloc(char **ppOut, int nVal, int nRadix);

	//* [contents] �p�X����菜��
	//* [in] ������
	//* [return] ��菜����������
	static STRING RemovePath(STRING src);

	//* [contents] �p�X����菜��
	//* [in] ������
	//* [out] ��菜����������
	static void RemovePath(CString& out, CString& src);


	//-------------------------------------------------------------------------------------------------------------
	// TEMPLATE
	//-------------------------------------------------------------------------------------------------------------
	/* MEMO
	* �G���[��������邽�߂�inline�֐��ɂ���
	*/

	// �Ⴄ�l�̎��ɐݒ�
	// input : (�ύX����f�[�^�A)
	template <class T>
	inline static bool Setdifferentvalue(T &tData, CONST T tSource)
	{
		if (tData != tSource)
		{
			tData = tSource;
			return true;
		}
		return false;
	}
};

// �C�����C���֐��p�t�@�C�����C���N���[�h
#include "mylibrary.inl"

#endif
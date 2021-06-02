//*************************************************************************************************************
//
// �}�C���C�u����[Mylibrary.inl]
// Contents : Mylibrary inline functions
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _CBMPFILE_INL
#define _CBMPFILE_INL

/*
// struct inline func
// �\���̂̃C�����C���֐�
*/
//----------------------------------------------------------------------------------------------------
// 3����float
//----------------------------------------------------------------------------------------------------
inline FLOAT3
FLOAT3::operator +(const FLOAT3 &rhs) const
{
	return FLOAT3(x + rhs.x, y + rhs.y, z + rhs.z);
}

inline FLOAT3
FLOAT3::operator -(const FLOAT3 &rhs) const
{
	return FLOAT3(x - rhs.x, y - rhs.y, z - rhs.z);
}

inline FLOAT3
FLOAT3::operator -(void) const
{
	return FLOAT3(x * -1.0f, y * -1.0f, z * -1.0f);
}

inline FLOAT3
FLOAT3::operator *(const FLOAT3 &rhs) const
{
	return FLOAT3(x * rhs.x, y * rhs.y, z * rhs.z);
}

inline FLOAT3
FLOAT3::operator /(const FLOAT3 &rhs) const
{
	return FLOAT3(x / rhs.x, y / rhs.y, z / rhs.z);
}

inline FLOAT3
FLOAT3::operator *(float rhs) const
{
	return FLOAT3(x * rhs, y * rhs, z * rhs);
}

inline FLOAT3
FLOAT3::operator /(float rhs) const
{
	return FLOAT3(x / rhs, y / rhs, z / rhs);
}

inline float
FLOAT3::Dot(const FLOAT3 &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

inline FLOAT3
FLOAT3::Cross(const FLOAT3 &rhs) const
{
	return FLOAT3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

inline float
FLOAT3::Length() const
{
	return sqrtf(LengthSq());
}

inline float
FLOAT3::LengthSq() const
{
	return x * x + y * y + z * z;
}

inline void
FLOAT3::Norm()
{
	const float fLength = Length();
	if (fLength > 0.0f)
	{
		x /= fLength;
		y /= fLength;
		z /= fLength;
	}
}

inline FLOAT3
FLOAT3::GetNorm() const
{
	const float fLength = Length();
	if (fLength > 0.0f) {
		return FLOAT3(x / fLength, y / fLength, z / fLength);
	}
	return FLOAT3(0.0f, 0.0f, 0.0f);
}

//----------------------------------------------------------------------------------------------------
// 3D�x�N�g��
//----------------------------------------------------------------------------------------------------
inline VEC3& VEC3::operator =(const FLOAT3 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

inline bool
VEC3::IsVertical(const VEC3 &rhs) const
{
	float DotValue = Dot(rhs);
	return (-MYLIB_OX_EPSILON < DotValue && DotValue < MYLIB_OX_EPSILON);	// �덷�͈͓��Ȃ琂���Ɣ���
}

inline bool
VEC3::IsParallel(const VEC3 &rhs) const
{
	float CrossValue = Cross(rhs).LengthSq();
	return (-MYLIB_OX_EPSILON < CrossValue && CrossValue < MYLIB_OX_EPSILON);	// �덷�͈͓��Ȃ畽�s�Ɣ���
}

inline bool
VEC3::IsSharpAngle(const VEC3 &rhs) const
{
	return (Dot(rhs) >= 0.0f);
}

//----------------------------------------------------------------------------------------------------
// ����
//----------------------------------------------------------------------------------------------------
inline FLOAT3
LINE::GetPoint(float fCoffi) const
{
	return pos + fCoffi * vec;
}

//----------------------------------------------------------------------------------------------------
// ����
//----------------------------------------------------------------------------------------------------
inline FLOAT3
SEGMENT::GetEndPoint() const
{
	return pos + vec;
}

//----------------------------------------------------------------------------------------------------
// �^�C�}�[���
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
inline _TIMER_INFO::_TIMER_INFO(int nStart, int nEnd)
{
	this->nStart = nStart;
	this->nEnd = nEnd;
}


//----------------------------------------------------------------------------------------------------
// �e�N�X�`����UV���W�̐ݒ�p�̏��
//----------------------------------------------------------------------------------------------------
inline _SETING_UV::_SETING_UV(int nCntU, int nNumU, int nCntV, int nNumV)
{
	this->nCntU = nCntU;
	this->nNumU = nNumU;
	this->nCntV = nCntV;
	this->nNumV = nNumV;
}

//----------------------------------------------------------------------------------------------------
// �e�N�X�`���A�j���[�V�������
//----------------------------------------------------------------------------------------------------
inline _TEXTUREANIMEINFO::_TEXTUREANIMEINFO(int nFrame, int nFrameMax, int nIteration)
{
	this->nFrame = nFrame;
	this->nFrameMax = nFrameMax;
	this->nIteration = nIteration;
}

//----------------------------------------------------------------------------------------------------
// �͈�
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
inline _RANGE::_RANGE(const int nMax, const int nMin)
{
	this->nMax = nMax;
	this->nMin = nMin;
}
inline _RANGE::_RANGE(CONST INTEGER2SOURCE& rhs)
{
	this->nMax = rhs.nX;
	this->nMin = rhs.nY;
}
inline _RANGE::_RANGE(const int rhs)
{
	this->nMax = rhs;
	this->nMin = rhs;
}
/* * �P�����Z�q + */
inline _RANGE
_RANGE::operator + (void) const
{
	return *this;
}
/* * �P�����Z�q - */
inline _RANGE
_RANGE::operator - (void) const
{
	return _RANGE(-this->nMax, -this->nMin);
}

/* * �񍀉��Z�q + */
inline _RANGE
_RANGE::operator + (CONST _RANGE& rhs) const
{
	return _RANGE(this->nMax + rhs.nMax, this->nMin + rhs.nMin);
}
inline _RANGE
_RANGE::operator + (CONST INTEGER2SOURCE& rhs) const
{
	return _RANGE(this->nMax + rhs.nX, this->nMin + rhs.nY);
}
inline _RANGE
_RANGE::operator + (CONST int rhs) const
{
	return _RANGE(this->nMax + rhs, this->nMin + rhs);
}

/* * �񍀉��Z�q - */
inline _RANGE
_RANGE::operator - (CONST _RANGE& rhs) const
{
	return _RANGE(this->nMax - rhs.nMax, this->nMin - rhs.nMin);
}
inline _RANGE
_RANGE::operator - (CONST INTEGER2SOURCE& rhs) const
{
	return _RANGE(this->nMax - rhs.nX, this->nMin - rhs.nY);
}
inline _RANGE
_RANGE::operator - (CONST int rhs) const
{
	return _RANGE(this->nMax - rhs, this->nMin - rhs);
}

/* * �񍀉��Z�q * */
inline _RANGE
_RANGE::operator * (CONST _RANGE& rhs) const
{
	_RANGE(this->nMax * rhs.nMax, this->nMin * rhs.nMin);
}
inline _RANGE
_RANGE::operator * (CONST INTEGER2SOURCE& rhs) const
{
	return _RANGE(this->nMax * rhs.nX, this->nMin * rhs.nY);
}
inline _RANGE
_RANGE::operator * (CONST int rhs) const
{
	return _RANGE(this->nMax * rhs, this->nMin * rhs);
}

/* * �񍀉��Z�q / */
inline _RANGE
_RANGE::operator / (CONST _RANGE& rhs) const
{
	return _RANGE(this->nMax / rhs.nMax, this->nMin / rhs.nMin);
}
inline _RANGE
_RANGE::operator / (CONST INTEGER2SOURCE& rhs) const
{
	return _RANGE(this->nMax / rhs.nX, this->nMin / rhs.nY);
}
inline _RANGE
_RANGE::operator / (CONST int rhs) const
{
	return _RANGE(this->nMax / rhs, this->nMin / rhs);
}

/* * ��r���Z�q == */
inline bool
_RANGE::operator == (CONST _RANGE& rhs) const
{
	return this->nMax == rhs.nMax && this->nMin == rhs.nMin;
}
inline bool
_RANGE::operator == (CONST INTEGER2SOURCE& rhs) const
{
	return this->nMax == rhs.nX && this->nMin == rhs.nY;
}
inline bool
_RANGE::operator == (CONST int rhs) const
{
	return this->nMax == rhs && this->nMin == rhs;
}

/* * ��r���Z�q != */
inline bool
_RANGE::operator != (CONST _RANGE& rhs) const
{
	return this->nMax != rhs.nMax || this->nMin != rhs.nMin;
}
inline bool
_RANGE::operator != (CONST INTEGER2SOURCE& rhs) const
{
	return this->nMax != rhs.nX || this->nMin != rhs.nY;
}
inline bool
_RANGE::operator != (CONST int rhs) const
{
	return this->nMax != rhs || this->nMin != rhs;
}
/* * ������Z�q += */
inline _RANGE&
_RANGE::operator += (CONST _RANGE& rhs)
{
	this->nMax += rhs.nMax;
	this->nMin += rhs.nMin;
	return *this;
}
inline _RANGE&
_RANGE::operator += (CONST INTEGER2SOURCE& rhs)
{
	this->nMax += rhs.nX;
	this->nMin += rhs.nY;
	return *this;
}
inline _RANGE&
_RANGE::operator += (CONST int rhs)
{
	this->nMax += rhs;
	this->nMin += rhs;
	return *this;
}

//* * ������Z�q -= */
inline _RANGE&
_RANGE::operator -= (CONST _RANGE& rhs)
{
	this->nMax -= rhs.nMax;
	this->nMin -= rhs.nMin;
	return *this;
}
inline _RANGE&
_RANGE::operator -= (CONST INTEGER2SOURCE& rhs)
{
	this->nMax -= rhs.nX;
	this->nMin -= rhs.nY;
	return *this;
}
inline _RANGE&
_RANGE::operator -= (CONST int rhs)
{
	this->nMax -= rhs;
	this->nMin -= rhs;
	return *this;
}

//* * ������Z�q *= */
inline _RANGE&
_RANGE::operator *= (CONST _RANGE& rhs)
{
	this->nMax *= rhs.nMax;
	this->nMin *= rhs.nMin;
	return *this;
}
inline _RANGE&
_RANGE::operator *= (CONST INTEGER2SOURCE& rhs)
{
	this->nMax *= rhs.nX;
	this->nMin *= rhs.nY;
	return *this;
}
inline _RANGE&
_RANGE::operator *= (CONST int rhs)
{
	this->nMax *= rhs;
	this->nMin *= rhs;
	return *this;
}

//* * ������Z�q /= */
inline _RANGE&
_RANGE::operator /= (CONST _RANGE& rhs)
{
	this->nMax /= rhs.nMax;
	this->nMin /= rhs.nMin;
	return *this;
}
inline _RANGE&
_RANGE::operator /= (CONST INTEGER2SOURCE& rhs)
{
	this->nMax /= rhs.nX;
	this->nMin /= rhs.nY;
	return *this;
}
inline _RANGE&
_RANGE::operator /= (CONST int rhs)
{
	this->nMax /= rhs;
	this->nMin /= rhs;
	return *this;
}

/* * �����o�A�N�Z�X���Z�q[] */
inline int
_RANGE::operator[] (unsigned int nIdx) const
{
	return (&this->nMax)[nIdx];
}
inline int&
_RANGE::operator[] (unsigned int nIdx)
{
	return (&this->nMax)[nIdx];
}

/* * �����_���l�����߂� */
inline int
_RANGE::GetRand(void)
{
	return (rand() % nMax) + nMin;
}

/* * �擾�ł��邩�H */
inline bool
_RANGE::IsItGet(void)
{
	return (nMax != 0);
}

//----------------------------------------------------------------------------------------------------
// INTEGER2
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
inline
INTEGER2::INTEGER2(const int nMax, const int nMin)
{
	this->nX = nMax;
	this->nY = nMin;
}
inline 
INTEGER2::INTEGER2(CONST _RANGE& rhs)
{
	this->nX = rhs.nMax;
	this->nY = rhs.nMin;
}
inline
INTEGER2::INTEGER2(const int rhs)
{
	this->nX = rhs;
	this->nY = rhs;
}

/* * �P�����Z�q + */
inline INTEGER2
INTEGER2::operator + (void) const
{
	return *this;
}
/* * �P�����Z�q - */
inline INTEGER2
INTEGER2::operator - (void) const
{
	return INTEGER2(-this->nX, -this->nY);
}

/* * �񍀉��Z�q + */
inline INTEGER2
INTEGER2::operator + (CONST INTEGER2& rhs) const
{
	return INTEGER2(this->nX + rhs.nX, this->nY+rhs.nY);
}
inline INTEGER2
INTEGER2::operator + (CONST _RANGE& rhs) const
{
	return INTEGER2(this->nX + rhs.nMax, this->nY + rhs.nMin);
}
inline INTEGER2
INTEGER2::operator + (CONST int rhs) const
{
	return INTEGER2(this->nX + rhs, this->nY + rhs);
}

/* * �񍀉��Z�q - */
inline INTEGER2
INTEGER2::operator - (CONST INTEGER2& rhs) const
{
	return INTEGER2(this->nX - rhs.nX, this->nY - rhs.nY);
}
inline INTEGER2
INTEGER2::operator - (CONST _RANGE& rhs) const
{
	return INTEGER2(this->nX - rhs.nMax, this->nY - rhs.nMin);
}
inline INTEGER2
INTEGER2::operator - (CONST int rhs) const
{
	return INTEGER2(this->nX - rhs, this->nY - rhs);
}

/* * �񍀉��Z�q * */
inline INTEGER2
INTEGER2::operator * (CONST INTEGER2& rhs) const
{
	return INTEGER2(this->nX * rhs.nX, this->nY * rhs.nY);
}
inline INTEGER2
INTEGER2::operator * (CONST _RANGE& rhs) const
{
	return INTEGER2(this->nX * rhs.nMax, this->nY * rhs.nMin);
}
inline INTEGER2
INTEGER2::operator * (CONST int rhs) const
{
	return INTEGER2(this->nX * rhs, this->nY * rhs);
}

/* * �񍀉��Z�q / */
inline INTEGER2
INTEGER2::operator / (CONST INTEGER2& rhs) const
{
	return INTEGER2(this->nX / rhs.nX, this->nY / rhs.nY);
}
inline INTEGER2
INTEGER2::operator / (CONST _RANGE& rhs) const
{
	return INTEGER2(this->nX / rhs.nMax, this->nY / rhs.nMin);
}
inline INTEGER2
INTEGER2::operator / (CONST int rhs) const
{
	return INTEGER2(this->nX / rhs, this->nY / rhs);
}

/* * ��r���Z�q == */
inline bool
INTEGER2::operator == (CONST INTEGER2& rhs) const
{
	return this->nX == rhs.nX && this->nY == rhs.nY;
}
inline bool
INTEGER2::operator == (CONST _RANGE& rhs) const
{
	return this->nX == rhs.nMax && this->nY == rhs.nMin;
}
inline bool
INTEGER2::operator == (CONST int rhs) const
{
	return this->nX == rhs && this->nY == rhs;
}

/* * ��r���Z�q != */
inline bool
INTEGER2::operator != (CONST INTEGER2& rhs) const
{
	return this->nX != rhs.nX || this->nY != rhs.nY;
}
inline bool
INTEGER2::operator != (CONST _RANGE& rhs) const
{
	return this->nX != rhs.nMax || this->nY != rhs.nMin;
}
inline bool
INTEGER2::operator != (CONST int rhs) const
{
	return this->nX != rhs || this->nY != rhs;
}

/* * ������Z�q += */
inline INTEGER2&
INTEGER2::operator += (CONST INTEGER2& rhs)
{
	this->nX += rhs.nX;
	this->nY += rhs.nY;
	return *this;
}
inline INTEGER2&
INTEGER2::operator += (CONST _RANGE& rhs)
{
	this->nX += rhs.nMax;
	this->nY += rhs.nMin;
	return *this;
}
inline INTEGER2&
INTEGER2::operator += (CONST int rhs)
{
	this->nX += rhs;
	this->nY += rhs;
	return *this;
}

//* * ������Z�q -= */
inline INTEGER2&
INTEGER2::operator -= (CONST INTEGER2& rhs)
{
	this->nX -= rhs.nX;
	this->nY -= rhs.nY;
	return *this;
}
inline INTEGER2&
INTEGER2::operator -= (CONST _RANGE& rhs)
{
	this->nX -= rhs.nMax;
	this->nY -= rhs.nMin;
	return *this;
}
inline INTEGER2&
INTEGER2::operator -= (CONST int rhs)
{
	this->nX -= rhs;
	this->nY -= rhs;
	return *this;
}

//* * ������Z�q *= */
inline INTEGER2&
INTEGER2::operator *= (CONST INTEGER2& rhs)
{
	this->nX *= rhs.nX;
	this->nY *= rhs.nY;
	return *this;
}
inline INTEGER2&
INTEGER2::operator *= (CONST _RANGE& rhs)
{
	this->nX *= rhs.nMax;
	this->nY *= rhs.nMin;
	return *this;
}
inline INTEGER2&
INTEGER2::operator *= (CONST int rhs)
{
	this->nX *= rhs;
	this->nY *= rhs;
	return *this;
}

//* * ������Z�q /= */
inline INTEGER2& 
INTEGER2::operator /= (CONST INTEGER2& rhs)
{
	this->nX /= rhs.nX;
	this->nY /= rhs.nY;
	return *this;
}
inline INTEGER2&
INTEGER2::operator /= (CONST _RANGE& rhs)
{
	this->nX /= rhs.nMax;
	this->nY /= rhs.nMin;
	return *this;
}
inline INTEGER2&
INTEGER2::operator /= (CONST int rhs)
{
	this->nX /= rhs;
	this->nY /= rhs;
	return *this;
}

/* * �����o�A�N�Z�X���Z�q[] */
inline int
INTEGER2::operator[] (unsigned int nIdx) const
{
	return (&this->nX)[nIdx];
}
inline int&
INTEGER2::operator[] (unsigned int nIdx)
{
	return (&this->nX)[nIdx];
}

//----------------------------------------------------------------------------------------------------
// INTEGER3
//----------------------------------------------------------------------------------------------------
inline
INTEGER3::INTEGER3(int nX, int nY, int nZ)
{
	this->x = nX;
	this->y = nY;
	this->z = nZ;
}
inline
INTEGER3::INTEGER3(int nRhs)
{
	this->x = nRhs;
	this->y = nRhs;
	this->z = nRhs;
}

/* * �P�����Z�q + */
inline INTEGER3
INTEGER3::operator + (void) const
{
	return *this;
}

/* * �P�����Z�q - */
inline INTEGER3
INTEGER3::operator - (void) const
{
	return INTEGER3(-this->x, -this->y, -this->z);
}

/* * �񍀉��Z�q + */
inline INTEGER3
INTEGER3::operator + (CONST INTEGER3& rhs) const
{
	return INTEGER3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}
inline INTEGER3
INTEGER3::operator + (CONST int rhs) const
{
	return INTEGER3(this->x + rhs, this->y + rhs, this->z + rhs);
}

/* * �񍀉��Z�q - */
inline INTEGER3
INTEGER3::operator - (CONST INTEGER3& rhs) const
{
	return INTEGER3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}
inline INTEGER3
INTEGER3::operator - (CONST int rhs) const
{
	return INTEGER3(this->x - rhs, this->y - rhs, this->z - rhs);
}

/* * �񍀉��Z�q * */
inline INTEGER3
INTEGER3::operator * (CONST INTEGER3& rhs) const
{
	return INTEGER3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
}
inline INTEGER3
INTEGER3::operator * (CONST int rhs) const
{
	return INTEGER3(this->x * rhs, this->y * rhs, this->z * rhs);
}

/* * �񍀉��Z�q / */
inline INTEGER3
INTEGER3::operator / (CONST INTEGER3& rhs) const
{
	return INTEGER3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
}
inline INTEGER3
INTEGER3::operator / (CONST int rhs) const
{
	return INTEGER3(this->x / rhs, this->y / rhs, this->z / rhs);
}

/* * ��r���Z�q == */
inline bool
INTEGER3::operator == (CONST INTEGER3& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
}
inline bool
INTEGER3::operator == (CONST int rhs) const
{
	return this->x == rhs && this->y == rhs && this->z == rhs;
}

/* * ��r���Z�q != */
inline bool
INTEGER3::operator != (CONST INTEGER3& rhs) const
{
	return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;
}
inline bool
INTEGER3::operator != (CONST int rhs) const
{
	return this->x != rhs || this->y != rhs || this->z != rhs;
}

/* * ������Z�q += */
inline INTEGER3&
INTEGER3::operator += (CONST INTEGER3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}
inline INTEGER3&
INTEGER3::operator += (CONST int rhs)
{
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;
	return *this;
}

/* * ������Z�q -= */
inline INTEGER3&
INTEGER3::operator -= (CONST INTEGER3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}
inline INTEGER3&
INTEGER3::operator -= (CONST int rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;
	return *this;
}

/* * ������Z�q *= */
inline INTEGER3&
INTEGER3::operator *= (CONST INTEGER3& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	return *this;
}
inline INTEGER3&
INTEGER3::operator *= (CONST int rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;
}

/* * ������Z�q /= */
inline INTEGER3&
INTEGER3::operator /= (CONST INTEGER3& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return *this;
}
inline INTEGER3&
INTEGER3::operator /= (CONST int rhs)
{
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	return *this;
}

/* * �����o�A�N�Z�X���Z�q[] */
inline int
INTEGER3::operator[] (unsigned int nIdx) const
{
	return (&this->x)[nIdx];
}
inline int&
INTEGER3::operator[] (unsigned int nIdx)
{
	return (&this->x)[nIdx];
}

//----------------------------------------------------------------------------------------------------
// INTEGER4
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
inline
INTEGER4::INTEGER4(int x, int y, int z, int w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
inline
INTEGER4::INTEGER4(int nRhs)
{
	this->x = nRhs;
	this->y = nRhs;
	this->z = nRhs;
	this->w = nRhs;
}

/* * �P�����Z�q + */
inline INTEGER4
INTEGER4::operator + (void) const
{
	return *this;
}

/* * �P�����Z�q - */
inline INTEGER4
INTEGER4::operator - (void) const
{
	return INTEGER4(-this->x, -this->y, -this->z,-this->w);
}

/* * �񍀉��Z�q + */
inline INTEGER4
INTEGER4::operator + (CONST INTEGER4& rhs) const
{
	return INTEGER4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}
inline INTEGER4
INTEGER4::operator + (CONST int rhs) const
{
	return INTEGER4(this->x + rhs, this->y + rhs, this->z + rhs,this->w + rhs);
}

/* * �񍀉��Z�q - */
inline INTEGER4
INTEGER4::operator - (CONST INTEGER4& rhs) const
{
	return INTEGER4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}
inline INTEGER4
INTEGER4::operator - (CONST int rhs) const
{
	return INTEGER4(this->x - rhs, this->y - rhs, this->z - rhs, this->w - rhs);
}

/* * �񍀉��Z�q * */
inline INTEGER4
INTEGER4::operator * (CONST INTEGER4& rhs) const
{
	return INTEGER4(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w * rhs.w);
}
inline INTEGER4
INTEGER4::operator * (CONST int rhs) const
{
	return INTEGER4(this->x * rhs, this->y * rhs, this->z * rhs, this->w * rhs);
}

/* * �񍀉��Z�q / */
inline INTEGER4
INTEGER4::operator / (CONST INTEGER4& rhs) const
{
	return INTEGER4(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z, this->w / rhs.w);
}
inline INTEGER4
INTEGER4::operator / (CONST int rhs) const
{
	return INTEGER4(this->x / rhs, this->y / rhs, this->z / rhs, this->w / rhs);
}

/* * ��r���Z�q == */
inline bool
INTEGER4::operator == (CONST INTEGER4& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
}
inline bool
INTEGER4::operator == (CONST int rhs) const
{
	return this->x == rhs && this->y == rhs && this->z == rhs && this->w == rhs;
}

/* * ��r���Z�q != */
inline bool
INTEGER4::operator != (CONST INTEGER4& rhs) const
{
	return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
}
inline bool
INTEGER4::operator != (CONST int rhs) const
{
	return this->x != rhs || this->y != rhs || this->z != rhs || this->w != rhs;
}

/* * ������Z�q += */
inline INTEGER4&
INTEGER4::operator += (CONST INTEGER4& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
	return *this;
}
inline INTEGER4&
INTEGER4::operator += (CONST int rhs)
{
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;
	this->w += rhs;
	return *this;
}

/* * ������Z�q -= */
inline INTEGER4&
INTEGER4::operator -= (CONST INTEGER4& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
	return *this;
}
inline INTEGER4&
INTEGER4::operator -= (CONST int rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;
	this->w -= rhs;
	return *this;
}

/* * ������Z�q *= */
inline INTEGER4&
INTEGER4::operator *= (CONST INTEGER4& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	this->w *= rhs.w;
	return *this;
}
inline INTEGER4&
INTEGER4::operator *= (CONST int rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;
	return *this;
}

/* * ������Z�q /= */
inline INTEGER4&
INTEGER4::operator /= (CONST INTEGER4& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	this->w /= rhs.w;
	return *this;
}
inline INTEGER4&
INTEGER4::operator /= (CONST int rhs)
{
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	this->w /= rhs;
	return *this;
}

/* * �����o�A�N�Z�X���Z�q[] */
inline int
INTEGER4::operator[] (unsigned int nIdx) const
{
	return (&this->x)[nIdx];
}
inline int&
INTEGER4::operator[] (unsigned int nIdx)
{
	return (&this->x)[nIdx];
}

//----------------------------------------------------------------------------------------------------
// �g�����X�t�H�[�����
//----------------------------------------------------------------------------------------------------
///* * �R���X�g���N�^ */
//inline
//TRANSFORM::TRANSFORM(D3DXVECTOR3 &pos, D3DXVECTOR3 &rot, D3DXVECTOR3 &scal, D3DXMATRIX &mtxWorld)
//{
//	this->pos = pos;
//	this->rot = rot;
//	this->scal = scal;
//	this->mtxWorld = mtxWorld;
//}
//inline
//TRANSFORM::TRANSFORM(D3DXVECTOR3 &pos, D3DXVECTOR3 &rot, D3DXVECTOR3 &scal)
//{
//	this->pos = pos;
//	this->rot = rot;
//	this->scal = scal;
//}

// �}�g���b�N�X�̏�����
inline void
TRANSFORM::Identity(void)
{
	D3DXMatrixIdentity(&mtxWorld);
}

//----------------------------------------------------------------------------------------------------
// �Q�[�W���
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
inline
GAGE_INFO::GAGE_INFO(RANGE SourceRange, int nSourceValue, float fSourceCoefficient)
{
	range = SourceRange;
	nValue = nSourceValue;
	fCoefficient = fSourceCoefficient;
}

/*
// class inline func
// �N���X�̃C�����C���֐�
*/

//----------------------------------------------------------------------------------------------------
// class CMeasurement�@�v���N���X
//----------------------------------------------------------------------------------------------------
/* * �v���J�n */
inline void
CMeasurement::Start(void)
{
#ifdef MYLIB_MEASURE
	// �J�n���̎��Ԃ̎擾
	QueryPerformanceFrequency(&m_freq);
	QueryPerformanceCounter(&m_start);
#endif
}

/* * �v���I�� */
inline void
CMeasurement::End(void)
{
#ifdef MYLIB_MEASURE
	// �I�����̎��Ԃ̎擾
	QueryPerformanceCounter(&m_end);
#endif
}

/* * �`�� */
inline void
CMeasurement::Draw(void)
{
#ifdef MYLIB_MEASURE
	std::cout << "�������x == " << (m_end.QuadPart - m_start.QuadPart) * 1000.0 / m_freq.QuadPart  << "[ms.]\n";
#endif
}

inline double
CMeasurement::GetTime(void)
{
#ifdef MYLIB_MEASURE
	return (m_end.QuadPart - m_start.QuadPart) * 1000.0 / m_freq.QuadPart;
#endif
}

//----------------------------------------------------------------------------------------------------
// template<class T>class MyVector �}�C�x�N�^�[�N���X
//----------------------------------------------------------------------------------------------------
/* * �R���X�g���N�^ */
template<class T>
inline MyVector<T>::MyVector()
{
	this->m_nSize = MYLIB_INT_UNSET;
	this->m_nCapacity = MYLIB_INT_UNSET;
	this->m_pData = NULL;
}

/* * �R���X�g���N�^ */
template<class T>
inline MyVector<T>::MyVector(const MyVector<T>& source)
{
	this->m_nSize = MYLIB_INT_UNSET;
	this->m_nCapacity = MYLIB_INT_UNSET;
	this->m_pData = NULL;
	operator=(source);
}

// �f�X�g���N�^
template<class T>
inline MyVector<T>::~MyVector()
{
	if (this->m_pData != NULL)
	{
		delete[]this->m_pData;
		this->m_pData = NULL;
	}
}

// = �̃I�[�o�[���[�h
template<class T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector<T>& source)
{
	this->clear();
	resize(source.this->m_nSize);
	memcpy(this->m_pData, source.m_pData, (size_t)this->m_nSize * sizeof(T));
	return *this;
}

// �R���e�i���󂩂ǂ����𔻒肷��
template<class T>
inline bool MyVector<T>::empty(void) const
{
	return this->m_nSize == 0;
}
// �T�C�Y�̎擾
template<class T>
inline int& MyVector<T>::size(void)
{
	return this->m_nSize;
}
// ���e�ʂ̎擾
template<class T>
inline int& MyVector<T>::capacity(void)
{
	return this->m_nCapacity;
}

// []�̃I�[�o�[���[�h
template<class T>
inline T & MyVector<T>::operator[](int nArray)
{
	return this->m_pData[nArray];
}
// []�̃I�[�o�[���[�h
template<class T>
inline const T & MyVector<T>::operator[](int nArray) const
{
	return this->m_pData[nArray];
}
// �N���A
template<class T>
inline void MyVector<T>::clear(void)
{
	if (this->m_pData != NULL)
	{
		this->m_nSize = 0;
		this->m_nCapacity = 0;
		delete[]this->m_pData;
		this->m_pData = NULL;
	}
}

// �擪�v�f���w���C�e���[�^���擾����B
template<class T>
inline T * MyVector<T>::begin(void)
{
	return this->m_pData;
}
// �擪�v�f���w���C�e���[�^���擾����B
template<class T>
inline const T * MyVector<T>::begin(void) const
{
	return this->m_pData;
}
// �����̎����w���C�e���[�^���擾����
template<class T>
inline T * MyVector<T>::end(void)
{
	return this->m_pData + this->m_nSize;
}
// �����̎����w���C�e���[�^���擾����
template<class T>
inline const T * MyVector<T>::end(void) const
{
	return this->m_pData + this->m_nSize;
}
// �擪�v�f�ւ̎Q�Ƃ��擾����B
template<class T>
inline T & MyVector<T>::front(void)
{
	return this->m_pData[0];
}
// �擪�v�f�ւ̎Q�Ƃ��擾����B
template<class T>
inline const T & MyVector<T>::front(void) const
{
	return this->m_pData[0];
}
// �����v�f�ւ̎Q�Ƃ��擾����
template<class T>
inline T & MyVector<T>::back(void)
{
	return this->m_pData[this->m_nSize - 1];
}
// �����v�f�ւ̎Q�Ƃ��擾����
template<class T>
inline const T & MyVector<T>::back(void) const
{
	return this->m_pData[this->m_nSize - 1];
}

// ����vector�I�u�W�F�N�g�ƃf�[�^�����ւ���B
template<class T>
inline void MyVector<T>::swap(MyVector<T>& rhs)
{
	// �ϐ��錾
	int       nRhs_size;		// �E�ӂ̃T�C�Y
	int       nRhs_cap;			// �E�ӂ̓��e��
	T*        pRhs_data;		// �E�ӂ̃f�[�^

	// �T�C�Y�̌���
	Mybfunc_swap(this->m_nSize, rhs.m_nSize, nRhs_size);
	// ���e�ʂ̌���
	Mybfunc_swap(this->m_nCapacity, rhs.m_nCapacity, nRhs_cap);
	// �f�[�^�̌���
	Mybfunc_swap(this->m_pData, rhs.m_pData, pRhs_data);
}

// �v�f����ύX����
template<class T>
inline void MyVector<T>::resize(int nNewSize)
{
	// �V�����T�C�Y���傫���Ƃ�
	if (nNewSize > this->m_nCapacity)
	{
		// �]�T�����
		reserve(AddCapacity(nNewSize));
		// �T�C�Y��ݒ�
		this->m_nSize = nNewSize;
	}
}
// �v�f����ύX����
template<class T>
inline void MyVector<T>::resize(int nNewSize, const T & tValue)
{
	// ���e�ʂ��V�����T�C�Y���傫���Ƃ�
	if (nNewSize > this->m_nCapacity)
	{	// �]�T�����
		reserve(AddCapacity(nNewSize));
	}
	// �T�C�Y���V�����T�C�Y���傫���Ƃ�
	if (nNewSize > this->m_nSize)
	{
		// �V���������R�s�[����
		for (int nCntData = this->m_nSize; nCntData < nNewSize; nCntData++)
		{
			memcpy(&Data[nCntData], &tValue, sizeof(tValue));
		}
	}
	// �T�C�Y��ݒ�
	this->m_nSize = nNewSize;
}
// ���e�ʂ�ύX����
template<class T>
inline void MyVector<T>::reserve(int nNewCapacity)
{
	// �V�����e�ʂ����̗e�ʈȉ��̎��������Ȃ�
	if (nNewCapacity <= this->m_nCapacity)
	{
		return;
	}
	// �ϐ��錾
	T* pNewData;	// �V�����f�[�^

	// �̈�̊m��
	pNewData = new T[nNewCapacity];
	// �f�[�^����������
	if (this->m_pData != NULL)
	{// ���������R�s�[
		memcpy(pNewData, this->m_pData, this->m_nSize * sizeof(T));
		// �f�[�^���J��
		delete[]this->m_pData;
	}
	// �f�[�^�ɐV�����f�[�^����
	this->m_pData = pNewData;
	// ���e�ʂ�ݒ�
	this->m_nCapacity = nNewCapacity;
}

// �V���ȗv�f�𖖔��ɒǉ�����
template<class T>
inline void MyVector<T>::push_back(const T & tValue)
{
	// �T�C�Y�Ɠ��e�ʂ������Ƃ�
	if (this->m_nSize == this->m_nCapacity)
	{
		// �]�T�����
		reserve(AddCapacity(this->m_nSize + 1));
	}
	// �l���R�s�[����
	memcpy(&this->m_pData[this->m_nSize], &tValue, sizeof(tValue));
	// �T�C�Y���C���N�������g
	this->m_nSize++;
}
// �V���ȗv�f�𖖔��ɒǉ�����
template<class T>
inline void MyVector<T>::push_back(void)
{
	// �T�C�Y�Ɠ��e�ʂ������Ƃ�
	if (this->m_nSize == this->m_nCapacity)
	{
		// �]�T�����
		reserve(AddCapacity(this->m_nSize + 1));
	}
	// �T�C�Y���C���N�������g
	this->m_nSize++;
}

// �w�肵���v�f���폜����B
template<class T>
inline T * MyVector<T>::erase(const T * pIt)
{
	// �ϐ��錾
	const int nOff; //  �폜����擪
	nOff = pIt - this->m_pData;
	// ���������ړ�����
	memmove(
		this->m_pData + nOff,
		this->m_pData + nOff + 1,
		((size_t)this->m_nSize - (size_t)nOff - 1) * sizeof(T)
	);
	// �T�C�Y���f�N�������g
	this->m_nSize--;
	// �폜�������̃C�e���[�^�[��Ԃ�
	return this->m_pData + nOff;
}
// �w�肵���͈̗͂v�f���폜
template<class T>
inline T * MyVector<T>::erase(const T * pIt, const T * pIt_last)
{
	// �ϐ��錾
	const int nCount = pIt_last - pIt;	// �폜����J�E���g
	const int nOff = pIt - Data;		// �폜����擪
	// ���������ړ�����
	memmove(
		this->m_pData + nOff,
		this->m_pData + nOff + nCount,
		((size_t)this->m_nSize - (size_t)nOff - nCount) * sizeof(T));
	// �T�C�Y�����炷
	this->m_nSize -= (int)nCount;
	// �폜�������̃|�C���^��n��
	return this->m_pData + nOff;
}

// �C�ӂ̈ʒu�ɐV���ȗv�f��}������
template<class T>
inline T * MyVector<T>::insert(const T * pIt, const T & tValue)
{
	// �ϐ��錾
	const int nOff = pIt - this->m_pData;	// �ύX����擪
	// �T�C�Y�Ɠ��e�ʂ������Ƃ�
	if (this->m_nSize == this->m_nCapacity)
	{// ���e�ʂ�ύX����
		reserve(AddCapacity(this->m_nSize + 1));
	}
	// �폜����擪���T�C�Y�̕����傫���Ƃ�
	if (nOff < (int)this->m_nSize)
	{// ���������ړ�����
		memmove(
			this->m_pData + nOff + 1,
			this->m_pData + nOff,
			((size_t)this->m_nSize - (size_t)nOff) * sizeof(T)
		);
	}
	// �ύX���郁�����ɃR�s�[
	memcpy(&this->m_pData[nOff], &tValue, sizeof(tValue));
	// �T�C�Y���C���N�������g
	this->m_nSize++;
	// �}�������|�C���^��Ԃ�
	return this->m_pData + nOff;
}

// �C�ӂ̒l���v�f���Ɋ܂܂�Ă��邩
template<class T>
inline bool MyVector<T>::contains(const T & tValue) const
{
	// �ϐ��錾
	const T* pData = this->m_pData;						// �f�[�^�|�C���^
	const T* pData_end = this->m_pData + this->m_nSize;	// �f�[�^�̏I���
	while (pData < pData_end)
	{
		if (*pData++ == tValue)
		{
			return true;
		}
	}
	return false;
}
// �w�肳�ꂽ�l����������
template<class T>
inline T * MyVector<T>::find(const T & tValue)
{
	// �ϐ��錾
	T* pData = this->m_pData;							// �f�[�^�|�C���^
	const T* pData_end = this->m_pData + this->m_nSize;	// �f�[�^�̏I���
	while (pData < pData_end)
	{
		if (*pData == tValue)
		{
			break;
		}
		else
		{
			++pData;
		}
	}
	return pData;
}
// �w�肳�ꂽ�l����������
template<class T>
inline const T * MyVector<T>::find(const T & tValue) const
{
	// �ϐ��錾
	const T* pData = this->m_pData;						// �f�[�^�|�C���^
	const T* pData_end = this->m_pData + this->m_nSize;	// �f�[�^�̏I���
	while (pData < pData_end)
	{
		if (*data == tValue)
		{
			break;
		}
		else
		{
			++pData;
		}
	}
	return pData;
}
// �w�肳�ꂽ�l���������폜����
template<class T>
inline bool MyVector<T>::find_erase(const T & tValue)
{
	// �ϐ��錾
	const T* pIt = find(tValue);
	if (pIt < this->m_pData + this->m_nSize)
	{
		erase(pIt);
		return true;
	}
	return false;
}
// �C�e���[�^�[����C���f�b�N�X�ɂ���
template<class T>
inline int MyVector<T>::index_from_ptr(const T * pIt) const
{
	// �ϐ��錾
	const int nOff = pIt - this->m_pData;
	return nOff;
}

// �����v�f���폜����
template<class T>
inline void MyVector<T>::pop_back(void)
{
	// �傫�����f�N�������g
	this->m_nSize--;
}

/* * ���e�ʂ𑝂₷ */
template<class T>
inline int MyVector<T>::AddCapacity(int nSize) const
{
	// �ϐ��錾
	int nNewCapacity;	// �V�����e��
	// �V�����e�ʂ�ݒ�
	nNewCapacity = Mybfunc_iifEx(
		(this->m_nCapacity != 0),
		(this->m_nCapacity + this->m_nCapacity / 2),
		8);
	// �傫���ق���Ԃ�
	return Mybfunc_iifEx(
		(nNewCapacity > this->m_nSize),
		nNewCapacity,
		this->m_nSize);
}

//----------------------------------------------------------------------------------------------------
// class CLoadInitSetingfromFile �t�@�C�����珉���ݒ��ǂ݂��ރN���X
//----------------------------------------------------------------------------------------------------

// * [contents] �t�@�C�������s���ǂ݂���
// * [input] �t�@�C���� �֐��̃A�h���X
// * [return] enum�^(����)
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::ReadLineByLineFromFile(FILE_NAME pFileName, void(*ReadLine)(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData))
{
	// �ϐ��錾
	LOADRESULT result;	// ����
	CLoadInitSetingfromFile Load;
	// �ǂݍ��݃t�@�C���̏����쐬
	if((result = Load.LoadFileIntoString(pFileName)) != LR_SUCCESS)
	{
		return result;
	}

	// �����񂩂珉���ݒ��ǂݍ���
	if ((result = Load.SetingfromString(ReadLine)) != LR_SUCCESS)
	{
		return result;
	}

	// �t�@�C���f�[�^�̔j��
	Load.DeleteFileData();

	return result;
}

// * [contents] �t�@�C�������s���ǂ݂���
// * [input] �t�@�C���� �֐��̃A�h���X
// * [return] enum�^(����)
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::ReadLineByLineFromFile(FILE_NAME pFileName, void(*ReadLine)(CONST_STRING cnpLine))
{
	// �ϐ��錾
	LOADRESULT result;	// ����
	CLoadInitSetingfromFile Load;

	// �ǂݍ��݃t�@�C���̏����쐬
	if ((result = Load.LoadFileIntoString(pFileName)) != LR_SUCCESS)
	{
		return result;
	}

	// �����񂩂珉���ݒ��ǂݍ���
	if ((result = Load.SetingfromString(ReadLine)) != LR_SUCCESS)
	{
		return result;
	}

	// �t�@�C���f�[�^�̔j��
	Load.DeleteFileData();

	return result;
}

// * [contents] �t�@�C�������s���ǂ݂���
// * [input] �t�@�C���� �֐��̃A�h���X
// * [return] enum�^(����)
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::ReadLineByLineFromFile(FILE_NAME pFileName, void(*ReadLine)(CONST_STRING cnpLine, void *pVoidPtr), void * pVoidPtr)
{
	// �ϐ��錾
	LOADRESULT result;	// ����
	CLoadInitSetingfromFile Load;

	// �ǂݍ��݃t�@�C���̏����쐬
	if ((result = Load.LoadFileIntoString(pFileName)) != LR_SUCCESS)
	{
		return result;
	}

	// �����񂩂珉���ݒ��ǂݍ���
	if ((result = Load.SetingfromString(ReadLine, pVoidPtr)) != LR_SUCCESS)
	{
		return result;
	}

	// �t�@�C���f�[�^�̔j��
	Load.DeleteFileData();

	return result;
}

// * [contents] �t�@�C�����̊J��
// * [output] �J������N���X�̃|�C���^
inline void 
CLoadInitSetingfromFile::Release(CLoadInitSetingfromFile * pClass)
{
	// �N���X�|�C���^��NULL�̎�
	if (pClass == NULL)
	{
		return;
	}

	// �t�@�C���f�[�^�̔j��
	pClass->DeleteFileData();

	// �N���X�|�C���^��j��
	delete pClass;
	pClass = NULL;
}

// * [contents] �t�@�C���f�[�^�̔j��
inline void
CLoadInitSetingfromFile::DeleteFileData(void)
{
	// �t�@�C���f�[�^��NULL����Ȃ���
	if (this->m_pFileData != NULL)
	{// �t�@�C�f�[�^��j��
		delete[] this->m_pFileData;
		this->m_pFileData = NULL;
	}
}

// * [contents] �t�@�C���T�C�Y�̎擾
// * [input] �t�@�C���̃|�C���^
// * [return] �T�C�Y
inline UVLONG
CLoadInitSetingfromFile::GetFileSize(FILE * pFile)
{
// �ϐ��錾
	long lTop;	// �擪�ʒu
	long lSize;	// �t�@�C���T�C�Y

	// ������
	lTop = MYLIB_INT_UNSET;
	lSize = MYLIB_INT_UNSET;

	// �擪�̃t�@�C���ʒu���擾
	lTop = ftell(pFile);

	// (�t�@�C���ʒu���擾���� && �t�@�C���ʒu������ɐݒ�ɐ���)�����s������
	if ((lTop != MYLIB_FAILURE &&
		fseek(pFile, 0, SEEK_END) == MYLIB_SUCCESS) != MYLIB_TRUE)
	{
		return MYLIB_FAILURE;
	}

	// �����̃t�@�C���ʒu�i�T�C�Y�j���擾
	lSize = ftell(pFile);

	// (�T�C�Y�̎擾���� && �t�@�C���ʒu��擪�ɐݒ�ɐ���)�����s������
	if ((lSize != MYLIB_FAILURE &&
		fseek(pFile, lTop, SEEK_SET) == MYLIB_SUCCESS) != MYLIB_TRUE)
	{
		return MYLIB_FAILURE;
	}

	return (UVLONG)lSize;
}

// * [contents]�@������փt�@�C�������[�h����
// * [input]�@�t�@�C����,�J�����[�h
// * [return]�@����
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::LoadFileIntoString(FILE_NAME pFileName, OPEN_MODE Mode)
{
	// �ϐ��錾
	FILE *pFile;		// �t�@�C���|�C���^
	// �t�@�C�����J��
	if ((pFile = fopen(pFileName, Mode)) == NULL)
	{// ���s������
		return M_OPEN_FAIL;
	}

	// �ϐ��錾
	UVLONG uvlSize = GetFileSize(pFile);	// �t�@�C���T�C�Y
	// �t�@�C���T�C�Y�̎擾���s������
	if (uvlSize == (UVLONG)MYLIB_FAILURE)
	{
		// �t�@�C�������
		fclose(pFile);

		return M_SIZE_FAIL;
	}

	// �ϐ��錾
	FILE_DATA pFileData = new char[(size_t)uvlSize];
	// �t�@�C���f�[�^�̊m�ێ��s������
	if (pFileData == NULL)
	{
		// �t�@�C�������
		fclose(pFile);

		return M_FILEDATA_FAIL;
	}

	// �t�@�C���ǂݍ��ݎ��s������
	if ((UVLONG)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize)
	{
		// �t�@�C�������
		fclose(pFile);
		// �t�@�C���f�[�^�̊J��
		delete[]pFileData;

		return M_READ_FAIL; 
	}

	// �t�@�C�������
	fclose(pFile);

	// �t�@�C���T�C�Y�̐ݒ�
	this->m_nuFileSize = (FILE_SIZE)uvlSize;
	// �t�@�C���f�[�^�̐ݒ�
	this->m_pFileData = pFileData;

	return LR_SUCCESS;
}

// * [contents]�@�����񂩂�ݒ��ǂݍ���
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::SetingfromString(void(*ReadLine)(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData))
{
	// �o�b�t�@�̗̈�m��
	STRING pBuffe = new char[this->m_nuFileSize + 1];
	// �m�ێ��s������
	if (pBuffe == NULL)
	{
		return B_FAIL;
	}
	// �o�b�t�@�̈�̍Ō�ɐݒ�
	STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
	// �̈���R�s�[����
	memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
	// �o�b�t�@�̍Ō��0�ɐݒ�
	pBuffe[this->m_nuFileSize] = MYLIB_CHAR_UNSET;

	STRING pEntryData = NULL;	// �o�^�p�f�[�^
	STRING pEntryType = NULL;	// �o�^�p�̃^�C�v
	STRING pLineEnd = NULL;		// 1�s�̔���
	STRING pLine = pBuffe;		// 1�s���̕�����

	// �o�b�t�@�̏I���n�_�܂Ń��[�v����
	for (pLine = pBuffe; pLine < pBuffeEnd; pLine = pLineEnd + 1)
	{
		// 1�s���̕�������擾
		// �s���̎��X�L�b�v
		while (*pLine == '\n' || *pLine == '\r')
		{
			pLine++;
		}
		// 1�s�̔����̏�����
		pLineEnd =pLine;
		// �s���܂ŃX�L�b�v
		while (pLineEnd < pBuffeEnd && *pLineEnd != '\n' && *pLineEnd != '\r')
		{
			pLineEnd++;
		}
		// �s�����珉����
		pLineEnd[0] = MYLIB_CHAR_UNSET;

		// 1�s�̍ŏ��� [ �Ōオ ] �̎�
		if (pLine[0] == '[' &&pLineEnd > pLine &&pLineEnd[-1] == ']')
		{
			// 1�s�̍Ō��������
			pLineEnd[-1] = MYLIB_CHAR_UNSET;

			/* --- 1�s����[][]�𔲂���� --- */
			// �ϐ��錾
			CONST_STRING pDataEnd;		// �o�^�p�̃f�[�^�̍Ō�
			CONST_STRING pTypeStart;	// �o�^�p�̃^�C�v�̍ŏ�
			STRING       pTypeEnd;		// �o�^�p�̃f�[�^�̍Ō�
			CONST_STRING pDataStart;	// �o�^�p�̃^�C�v�̍ŏ�

			// ������
			pDataEnd = pLineEnd - 1;	// �s�̍Ō��ݒ�
			pTypeStart = pLine + 1;		// �ŏ��� [ ���X�L�b�v
			pTypeEnd = (STRING)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// �ŏ��� ] �܂ŃX�L�b�v
			pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : NULL;	// 2�ڂ� [ �܂ŃX�L�b�v

			// �o�^�p�̃^�C�v�̍Ō�Ɠo�^�p�̃f�[�^�̍ŏ��̂ǂ��炩�����݂��Ă��Ȃ����ŏ�����
			if (pTypeEnd == MYLIB_CHAR_UNSET ||
				pDataStart == MYLIB_CHAR_UNSET)
			{
				continue;
			}
			// ��ڂ� ] ��������
			*pTypeEnd = MYLIB_CHAR_UNSET;
			// ��ڂ� [ ���΂�
			pDataStart++;

			/* --- ����������炻�ꂼ��ɑ�� --- */
			// �o�^�p�f�[�^�̐ݒ�
			pEntryType = (STRING)(void*)pTypeStart;
			// �o�^�p�̃^�C�v�̐ݒ�
			pEntryData = (STRING)(void*)pDataStart;
		}

		// �o�^�f�[�^�̎擾������
		if ((pEntryData != NULL && pEntryType != NULL))
		{
			ReadLine(pLine, pEntryType, pEntryData);
		}
	}

	if (pBuffe != NULL)
	{
		delete[] pBuffe;
		pBuffe = NULL;
	}

	return LR_SUCCESS;
}

// * [contents]�@�����񂩂�ݒ��ǂݍ���
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::SetingfromString(void(*ReadLine)(CONST_STRING cnpLine))
{
	// �o�b�t�@�̗̈�m��
	STRING pBuffe = new char[this->m_nuFileSize + 1];
	// �m�ێ��s������
	if (pBuffe == NULL)
	{
		return B_FAIL;
	}
	// �o�b�t�@�̈�̍Ō�ɐݒ�
	STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
	// �̈���R�s�[����
	memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
	// �o�b�t�@�̍Ō��0�ɐݒ�
	pBuffe[this->m_nuFileSize] = MYLIB_CHAR_UNSET;

	STRING pLineEnd = NULL;		// 1�s�̔���
	STRING pLine = pBuffe;		// 1�s���̕�����

	// �o�b�t�@�̏I���n�_�܂Ń��[�v����
	for (pLine = pBuffe; pLine < pBuffeEnd; pLine = pLineEnd + 1)
	{
		// 1�s���̕�������擾
		// �s���̎��X�L�b�v
		while (*pLine == '\n' || *pLine == '\r')
		{
			pLine++;
		}
		// 1�s�̔����̏�����
		pLineEnd = pLine;
		// �s���܂ŃX�L�b�v
		while (pLineEnd < pBuffeEnd && *pLineEnd != '\n' && *pLineEnd != '\r')
		{
			pLineEnd++;
		}
		// �s�����珉����
		pLineEnd[0] = MYLIB_CHAR_UNSET;

		// 1�s�ǂݍ���
		ReadLine(pLine);
	}

	if (pBuffe != NULL)
	{
		delete[] pBuffe;
		pBuffe = NULL;
	}

	return LR_SUCCESS;
}

// * [contents]�@�����񂩂�ݒ��ǂݍ���
inline CLoadInitSetingfromFile::LOADRESULT
CLoadInitSetingfromFile::SetingfromString(void(*ReadLine)(CONST_STRING cnpLine, void * pVoidPtr), void * pVoidPtr)
{
	// �o�b�t�@�̗̈�m��
	STRING pBuffe = new char[this->m_nuFileSize + 1];
	// �m�ێ��s������
	if (pBuffe == NULL)
	{
		return B_FAIL;
	}
	// �o�b�t�@�̈�̍Ō�ɐݒ�
	STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
	// �̈���R�s�[����
	memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
	// �o�b�t�@�̍Ō��0�ɐݒ�
	pBuffe[this->m_nuFileSize] = MYLIB_CHAR_UNSET;

	STRING pLineEnd = NULL;		// 1�s�̔���
	STRING pLine = pBuffe;		// 1�s���̕�����

	// �o�b�t�@�̏I���n�_�܂Ń��[�v����
	for (pLine = pBuffe; pLine < pBuffeEnd; pLine = pLineEnd + 1)
	{
		// 1�s���̕�������擾
		// �s���̎��X�L�b�v
		while (*pLine == '\n' || *pLine == '\r')
		{
			pLine++;
		}
		// 1�s�̔����̏�����
		pLineEnd = pLine;
		// �s���܂ŃX�L�b�v
		while (pLineEnd < pBuffeEnd && *pLineEnd != '\n' && *pLineEnd != '\r')
		{
			pLineEnd++;
		}
		// �s�����珉����
		pLineEnd[0] = MYLIB_CHAR_UNSET;

		// 1�s�ǂݍ���
		ReadLine(pLine, pVoidPtr);
	}

	if (pBuffe != NULL)
	{
		delete[] pBuffe;
		pBuffe = NULL;
	}

	return LR_SUCCESS;
}

// * [contents] �����񂩂�C�ӂ̕����ȍ~�͈̔͂��擾
// * [input] ������A������̏I���A�C�ӂ̕���
// * [return] �擾����������
inline CONST_STRING
CLoadInitSetingfromFile::GetRangeStrfromChar(CONST_STRING cnStr, CONST_STRING cnStrEnd, char marker)
{
	// �ϐ��錾
	CONST_STRING cnRetStr;	// �Ԃ�������|�C���^
	cnRetStr = (CONST_STRING)memchr(cnStr, (int)marker, cnStrEnd - cnStr);
	return cnRetStr;
}

//----------------------------------------------------------------------------------------------------
// class CInputkey ���̓L�[�N���X
//----------------------------------------------------------------------------------------------------

/* * ������ */
inline void
CInputkey::Init(void)
{
	this->m_nSize = 0;		// �T�C�Y
	this->m_pKeyTop = NULL;		// �L�[�̐擪�|�C���^
}

/* * �L�[�f�[�^�̎擾 */
inline void
CInputkey::KeyInit(void)
{
	this->m_pKeyTop->nData = 0;		// �f�[�^
	this->m_pKeyTop->nKey = 0;		// �L�[
	this->m_pKeyTop->pNext = NULL;	// �L�[�̐擪�|�C���^
}

/* * �L�[�f�[�^�̐��� */
inline void
CInputkey::KeyCreate(void)
{
	// ����
	this->m_pKeyTop = new INPUTKEYCELL;
	// �������s
	if (this->m_pKeyTop == NULL)
	{
		return;
	}
	// �L�[�̏�����
	this->KeyInit();
}

/* * �L�[�f�[�^���X�g�̊J�� */
inline void
CInputkey::KeyListRelease(void)
{
	// �ϐ��錾
	INPUTKEYCELL* pTemp;	// �ꎞ�ۑ��p
	INPUTKEYCELL* pSwap;	// �����p

							// �擪�|�C���^
	pTemp = this->m_pKeyTop;
	// ���݂��Ă��鎞
	if (pTemp != NULL)
	{
		// ���X�g�̊J��
		while (pTemp != NULL)
		{
			// �����p�ɐݒ�
			pSwap = pTemp->pNext;
			// �ۑ��p��j��
			delete pTemp;
			// �ۑ��p�ɐݒ�
			pTemp = pSwap;
		}
	}
	this->m_pKeyTop = NULL;
}

/* * �L�[�f�[�^�̑}�� */
inline void
CInputkey::KeyInsert(int nData, int nKey)
{
	// �ϐ��錾
	INPUTKEYCELL * pInsert;			// �}������|�C���^
									// ����
	pInsert = new INPUTKEYCELL;
	// �����Ɏ��s
	if (pInsert == NULL)
	{
		return;
	}
	// �f�[�^�̐ݒ�
	pInsert->nData = nData;
	// �L�[�̐ݒ�
	pInsert->nKey = nKey;
	// �}�����鎟�̃|�C���^�̐ݒ�
	pInsert->pNext = this->m_pKeyTop;
	// �擪�|�C���^�̐ݒ�
	this->m_pKeyTop = pInsert;
	// �T�C�Y���C���N�������g
	m_nSize++;
}

/* * �L�[�f�[�^�𔲂���� */
inline void
CInputkey::KeyPullout(int nKey)
{
	// �ϐ��錾
	INPUTKEYCELL *pTarget = NULL;	// �^�[�Q�b�g�p�|�C���^
	INPUTKEYCELL *pChain = NULL;	// �Ȃ��̃|�C���^

									// �^�[�Q�b�g�̐ݒ�
	pTarget = this->m_pKeyTop;
	// �^�[�Q�b�g�����Ȃ���
	if (pTarget == NULL)
	{
		return;
	}
	// �Ȃ��̃|�C���^�̐ݒ�
	pChain = pTarget->pNext;

	// �擪�𔲂����ꍇ
	if (pTarget->nKey == nKey)
	{
		// �T�C�Y���f�N�������g
		m_nSize--;
		// �Ȃ��̃|�C���^��擪�ɂ���
		this->m_pKeyTop = pChain;
		// �^�[�Q�b�g��j��
		delete pTarget;
		pTarget = NULL;
		return;
	}

	// �擪�ȊO�𔲂����ꍇ
	while (pTarget != NULL)
	{
		// �^�[�Q�b�g�̃L�[�ƔC�ӂ̃L�[�������Ƃ�
		if (pTarget->nKey == nKey)
		{
			// �T�C�Y���f�N�������g
			m_nSize--;
			// �Ȃ��̎��Ƀ^�[�Q�b�g�̎��̃|�C���^��ݒ�
			pChain->pNext = pTarget->pNext;
			// �^�[�Q�b�g�̔j��
			delete pTarget;
			pTarget = NULL;
			return;
		}
		// �Ȃ��Ƀ^�[�Q�b�g�|�C���^��ݒ�
		pChain = pTarget;
		// �^�[�Q�b�g�Ƀ^�[�Q�b�g�̎���ݒ�
		pTarget = pTarget->pNext;
	}
}

/* * �L�[�f�[�^�̎擾 */
inline int
CInputkey::GetKeyData(int nKey)
{
	// �ϐ��錾
	INPUTKEYCELL *pTarget = NULL;	// �^�[�Q�b�g�̃|�C���^
	INPUTKEYCELL *pChain = NULL;	// �Ȃ��̃|�C���^

									// �^�[�Q�b�g�̐ݒ�
	pTarget = this->m_pKeyTop;
	// �^�[�Q�b�g��NULL����Ȃ������[�v
	while (pTarget != NULL)
	{
		// �^�[�Q�b�g�̃L�[�ƔC�ӂ̃L�[�������Ƃ�
		if (pTarget->nKey == nKey)
		{// �f�[�^��Ԃ�
			return pTarget->nData;
		}
		// �^�[�Q�b�g���Ȃ��ɐݒ�
		pChain = pTarget;
		// �^�[�Q�b�g�Ƀ^�[�Q�b�g�Ɏ���ݒ�
		pTarget = pTarget->pNext;
	}
	return -1;
}

/* * �T�C�Y�̎擾 */
inline int
CInputkey::GetSize(void)
{
	return m_nSize;
}

//----------------------------------------------------------------------------------------------------
// class CString ������N���X
//----------------------------------------------------------------------------------------------------

/* * �R���X�g���N�^ */
inline
CString::CString()
{
	this->Init();
}

/* * �f�X�g���N�^ */
inline
CString::~CString()
{
	this->release();
}

/* * ������ */
inline void
CString::Init(void)
{
	this->m_string = nullptr;					// ������|�C���^
	this->m_nStringLength = MYLIB_INT_UNSET;	// ������̒���
}

/* * �J������ */
inline void
CString::release(void)
{
	// nullptr�J������Ă��Ȃ���
	if (this->m_string != nullptr)
	{
		// ������̔j��
		delete[this->m_nStringLength] this->m_string;
		// ������
		this->Init();
	}
}

/* * ������̐ݒ�i�ݒ肵�Ă����ꍇ�Đݒ肷��j */
inline void
CString::Set(STRING string)
{
	// �J������
	this->release();
	// ����
	if (this->m_string == nullptr)
	{
		this->m_nStringLength = strlen(string) + 1;
		this->m_string = new char[this->m_nStringLength];
		strcpy(this->m_string, string);
	}
}
inline void
CString::Set(CONST_STRING string)
{
	// �J������
	this->release();
	// ����
	if (this->m_string == nullptr)
	{
		this->m_nStringLength = strlen(string) + 1;
		this->m_string = new char[this->m_nStringLength];
		strcpy(this->m_string, string);
	}
}

/* * ������̎擾 */
inline STRING
CString::Get(void)
{
	return this->m_string;
}

/* * �T�C�Y�̎擾 */
inline int & CString::size(void)
{
	return this->m_nStringLength;
}

#endif
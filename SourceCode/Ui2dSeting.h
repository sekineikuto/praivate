//*************************************************************************************************************
//
// 2DUI�ݒ肷��\���̂̏���[UISetingTypes.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _UISETINGTYPES_H_
#define _UISETINGTYPES_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"


//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define UISETING_ABILITY_DEFAULT  "default"
#define UISETING_ABILITY_NUMBER   "number"
#define UISETING_ABILITY_FLASHING "flashing"
#define UISETING_ABILITY_FADE     "fade"

//-------------------------------------------------------------------------------------------------------------
// �O���錾
//-------------------------------------------------------------------------------------------------------------
class CHash;

//-------------------------------------------------------------------------------------------------------------
// ���O��Ԓ�`
//-------------------------------------------------------------------------------------------------------------
namespace ui2d
{
	/* �񋓌^��` */
	// �}�X�N�̐ݒ�l
	enum
	{
		MASK_NONE     = 0b00000000,
		MASK_NUMBER   = 0b00000001,
		MASK_FLASHING = 0b00000010,
		MASK_FADE     = 0b00000100,
		MASK_MAX      = 0b00000111,
	};
	// �t���O�̐ݒ�l
	enum
	{
		FLAG_NONE = -1,
		FLAG_NUMBER,
		FLAG_FLASHING,
		FLAG_FADE,
		FLAG_MAX
	};

	// 2DUI�̐ݒ�p�̍\����
	typedef struct SETING
	{
		SETING() {}
		SETING(int  nTextureID, bool bDisp, D3DXVECTOR3& pos, D3DXVECTOR2& size, float fRotation, int nOriginType, D3DXCOLOR& col) :
			nTextureID(nTextureID), bDisp(bDisp), pos(pos), size(size), fRotation(fRotation), nOriginType(nOriginType), col(col)
		{}
		// �R�s�[�R���X�g���N�^
		SETING(SETING &CopySource)
		{
			this->nTextureID  = CopySource.nOriginType;	// �e�N�X�`��ID
			this->bDisp       = CopySource.bDisp;		// �`��t���O
			this->pos         = CopySource.pos;			// �ʒu
			this->size        = CopySource.size;		// �T�C�Y
			this->fRotation   = CopySource.fRotation;	// ��]��
			this->nOriginType = CopySource.nOriginType;	// ���_�^�C�v
			this->col         = CopySource.col;			// �F
		}
		// �R�s�[
		SETING &operator = (SETING &CopySource)
		{
			this->nTextureID  = CopySource.nOriginType;	// �e�N�X�`��ID
			this->bDisp       = CopySource.bDisp;		// �`��t���O
			this->pos         = CopySource.pos;			// �ʒu
			this->size        = CopySource.size;		// �T�C�Y
			this->fRotation   = CopySource.fRotation;	// ��]��
			this->nOriginType = CopySource.nOriginType;	// ���_�^�C�v
			this->col         = CopySource.col;			// �F
		}

		/* �����o�ϐ� */
		int         nTextureID;		// �e�N�X�`��ID
		bool        bDisp;			// �`��t���O
		D3DXVECTOR3 pos;			// �ʒu
		D3DXVECTOR2 size;			// �T�C�Y
		float       fRotation;		// ��]��
		int         nOriginType;	// ���_�^�C�v
		D3DXCOLOR   col;			// �F
	} SETING;

	// �ݒ�������[�h����
	inline void LoadSetingInfo(const char *pFileName, std::vector<SETING> &output)
	{
		// �t�@�C���������Ƃ�
		if (pFileName == nullptr)
			return;

		// �t�@�C�����J��
		FILE *pFile = fopen(pFileName, "rb");

		// �t�@�C�����J���Ȃ�
		if (pFile == nullptr)
			return;


		// �t�@�C�������
		fclose(pFile);
		pFile = nullptr;

	}
}
#endif
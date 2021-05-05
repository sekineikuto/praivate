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
	typedef struct SETING2DUI
	{
		SETING2DUI() {}
		SETING2DUI(int  nTextureID, bool bDisp, D3DXVECTOR3 pos, D3DXCOLOR col, D3DXVECTOR2 size, float fRotation, int nValue, int nOriginType)
		{
			this->nTextureID = nTextureID;
			this->bDisp = bDisp;
			this->pos = pos;
			this->col = col;
			this->size = size;
			this->fRotation = fRotation;
			this->nValue = nValue;
			this->nOriginType = nOriginType;
		}
		int         nTextureID;		// �e�N�X�`��ID
		bool        bDisp;			// �`��t���O
		D3DXVECTOR3 pos;			// �ʒu
		D3DXCOLOR   col;			// �F
		D3DXVECTOR2 size;			// �T�C�Y
		float       fRotation;		// ��]��
		int         nValue;			// �l
		int         nOriginType;	// ���_�^�C�v
	} SETING2DUI;

	/* �N���X��` */
	// �֐��Q
	class CFunctions
	{
	public:
		// �֐��Q���g�����߂̐錾
		static void DeclarationToUse(void);
		// �֐��Q�̏I���錾
		static void DeclarationToEnd(void);

		// �����񂩂�}�X�N�l�̎擾
		static inline int GetMaskToString(STRING str);

	private:
		/* �����o�֐� */
		// �}�X�N�̃n�b�V���̍쐬
		static void MakeMaskHash(void);

		/* �����o�ϐ� */
		static CHash * m_pMaskHash;
	};



}
#endif
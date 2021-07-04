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
#include "TextfileController.h"
#include <unordered_map>

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define UISETING_ABILITY_DEFAULT  "default"
#define UISETING_ABILITY_NUMBER   "number"
#define UISETING_ABILITY_FLASHING "flashing"
#define UISETING_ABILITY_FADE     "fade"

//-------------------------------------------------------------------------------------------------------------
// ���O��Ԓ�`
//-------------------------------------------------------------------------------------------------------------
namespace ui2d
{
	//-------------------------------------------------------------------------------------------------------------
	// �G�C���A�X�錾
	//-------------------------------------------------------------------------------------------------------------
	using Map_for_load = std::unordered_map<std::string, int>;

	//-------------------------------------------------------------------------------------------------------------
	// �񋓌^��`
	//-------------------------------------------------------------------------------------------------------------
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

	//-------------------------------------------------------------------------------------------------------------
	// �\���̒�`
	//-------------------------------------------------------------------------------------------------------------
	// 2DUI�̐ݒ�p�̍\����
	typedef struct SETING
	{
		/* �����o�֐� */
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

	//-------------------------------------------------------------------------------------------------------------
	// �N���X��`
	//-------------------------------------------------------------------------------------------------------------
	class CLoadinfo
	{
	public:
		/* �����o�֐� */

		// �ݒ�������[�h����
		inline static void LoadSetingInfo(const char *pFileName, std::vector<SETING> *output)
		{
		}

		// �}�b�v�̐ݒ�
		static void SetMap(void);

		// �}�b�v�̍폜
		static void UnsetMap(void);

	private:
		/* �����o�֐� */

		// ��s�������ǂݎ��
		inline static void ReadFromLine(const char * info, CLoadinfo* load)
		{
		}

		// �ǂݎ�����s����p�����[�^��ݒ肷��
		inline static void ReadFromLineSetParam(const char * line, CLoadinfo* load)
		{
			// �ϐ��錾
			char aData[MYLIB_STRINGSIZE] = {};
			int nData = 0;
			D3DXCOLOR float4 = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

			// �I���|�C���^��������
			// UI�^�C�v
			if (sscanf(line, "UI_TYPE = %s", aData) == 1)
			{

			}
			// ���_ID
			else if (sscanf(line, "ORIGINTYPEID = %d", &nData) == 1)
			{
			}
			// �ʒu
			else if (sscanf(line, "POS = %f %f %f", &float4.r, &float4.g, &float4.b) == 3)
			{
			}
			// �T�C�Y
			else if (sscanf(line, "SIZE = %f %f", &float4.r, &float4.g) == 2)
			{
			}
			// ��]
			else if (sscanf(line, "ROTATION = %f", &float4.r) == 1)
			{
			}
			// �F
			else if (sscanf(line, "COL = %f %f %f %f", &float4.r, &float4.g, &float4.b, &float4.a) == 4)
			{
			}
			// �e�N�X�`���^�C�v�̐ݒ�
			else if (sscanf(line, "TEXTURETYPE = %d", &nData) == 1)
			{
			}
			// �X�N���v�g�t�@�C��
			else if (sscanf(line, "SCRIPTFILE = %s", aData) == 1)
			{

			}
		}

		/* �����o�ϐ� */
		static Map_for_load *m_pMap; // ���[�h�p�̃}�b�v
	};



}
#endif
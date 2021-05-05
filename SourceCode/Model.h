//*************************************************************************************************************
//
// ���f������[Model.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _MODEL_H_
#define _MODEL_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CModel
{
public:
	enum
	{
		CHARMODEL_NONE = -1,		// ����
		CHARMODEL_WAIST,			// ��
		CHARMODEL_BODY,				// ��
		CHARMODEL_RIGHTUPPERARM,	// �E��r
		CHARMODEL_RIGHTFOREARM,		// �E�O�r
		CHARMODEL_RIGHTHAND,		// �E��
		CHARMODEL_RIGHTTHIGH,		// �E��
		CHARMODEL_RIGHTLEG,			// �E�r
		CHARMODEL_LEFTUPPERARM,		// ����r
		CHARMODEL_LEFTFOREARM,		// ���O�r
		CHARMODEL_LEFTHAND,			// ����
		CHARMODEL_LEFTTHIGH,		// ����
		CHARMODEL_LEFTLEG,			// ���r
		CHARMODEL_WEAPON,			// ����
		CHARMODEL_MAX				// �ő吔
	};
	enum
	{
		WEAPON_NONE = -1,		// ����
		WEAPON_SWORD,			// ��
		WEAPON_SPEAR,			// ��
		WEAPON_AXE,				// ��
		WEAPON_MAX				// �ő吔
	};
	enum
	{
		MODELBOT_NONE = -1,			// ����
		MODELBOT_BODY,				// ��
		MODELBOT_MAX				// �ő�
	};
	enum
	{
		MODEL3DOBJECT_NONE = -1,	// ����
		MODEL3DOBJECT_ROCK000,		// �⒆���炢
		MODEL3DOBJECT_ROCK001,		// �⏬����
		MODEL3DOBJECT_ROCK002,		// ��傫��
		MODEL3DOBJECT_Wood000,		// ��(�����Ă�)
		MODEL3DOBJECT_Wood001,		// ��(����ł�)
		MODEL3DOBJECT_SCREEN,		// �X�N���[��
		MODEL3DOBJECT_MALL,			// ���[��
		MODEL3DOBJECT_ARROWSIGN,	// ���
		MODEL3DOBJECT_MAX			// �ő吔
	};
	enum
	{
		ATTACBULLET_NONE = -1,	// ����
		ATTACBULLET_SWORD,		// ��
		ATTACBULLET_SPEAR,		// ��
		ATTACBULLET_AXE,		// ��
		ATTACBULLET_BOT,		// �{�b�g
		ATTACBULLET_MAX			// �ő吔
	};
	enum
	{
		DEADLY_NONE = -1,	// ����
		DEADLY_SWORD000,	// ��(���g)
		DEADLY_SWORD001,	// ��(�g��)
		DEADLY_SPEAR000,	// ��(��)
		DEADLY_AXE000,		// ��(�g��1)
		DEADLY_AXE001,		// ��(�g��2)
		DEADLY_MAX			// �ő吔
	};
	enum
	{
		TOP_NONE        = -1,									// ����
		TOP_PLAYER      = 0,									// �v���C���[
		TOP_ENEMY       = CHARMODEL_MAX - 1,					// �G�l�~�[
		TOP_WEAPON      = TOP_ENEMY + CHARMODEL_MAX - 1,		// ����
		TOP_BOT         = TOP_WEAPON + WEAPON_MAX,				// �{�b�g
		TOP_3DOBJECT    = TOP_BOT + MODELBOT_MAX,				// 3D�I�u�W�F�N�g
		TOP_ATTACBULLET = TOP_3DOBJECT + MODEL3DOBJECT_MAX,		// �U���p�̋�
		TOP_DEADLY      = TOP_ATTACBULLET + ATTACBULLET_MAX,	// �K�E
		TOP_MAX         = TOP_DEADLY + DEADLY_MAX,				// �ő吔
	};

	typedef struct MODEL
	{
		void release(void);				// �J������
		LPD3DXMESH		pMesh;			// ���b�V�����̃|�C���^
		LPD3DXBUFFER	pBuffMat;		// �}�e���A�����̃|�C���^
		DWORD			nNumMat;		// �}�e���A���̐�
		D3DXVECTOR3		vtxMax;			// �ő咸�_
		D3DXVECTOR3		vtxMin;			// �ŏ����_
		int				*pTextureID;	// �e�N�X�`��ID
	} MODEL;

	typedef struct
	{
		TRANSFORM Trans;		// �ʒu,��]�Ȃǂ̏��
		int       nIdentifier;	// ID�A���ʔԍ�
		bool      bDisp;		// �`��t���O
		CModel*   pParent;		// �e���f���̃|�C���^
	} SETINGINITMODEL;

	typedef SETINGINITMODEL MODELPARAM;

	CModel();																												// �R���X�g���N�^
	~CModel() {}																											// �f�X�g���N�^
	static void                Load(void);																					// ���f���̓ǂݍ���
	static void                Unload(void);																				// ���f���̊J��
	static CModel*             Create(int nID, TRANSFORM &Trans);															// ����
	static CModel*             Create(SETINGINITMODEL &pInitInfo);															// ����

	void                       Init(SETINGINITMODEL &pInitInfo);															// ������
	void                       Init(int nModelID);																			// ������
	void                       Uninit(void);																				// �I��
	void                       Update(void);																				// �X�V
	void                       Draw(void);																					// �`��

	/* �C�����C���֐� */
	inline static CONST MODEL& GetModelInfo(int nID)            { return m_AllModelInfo[nID]; }								// �S�Ẵ��f����񂩂�̎擾
	inline static CONST_STRING GetFileName(int nID)             { return m_FileName[nID].Get(); }							// �t�@�C�����̎擾
	inline static const int&   GetNumAllModel(void)             { return m_nNumAllModel; }									// �S���f�����̎擾
	inline void                SetTrans(CONST TRANSFORM &Trans) { m_Param.Trans = Trans; }										// �g�����X���̐ݒ�
	inline TRANSFORM&          GetTrans(void)                   { return m_Param.Trans; }											// �g�����X���̎擾
	inline void                SetTrans(CONST MODEL &Model)     { m_Model = Model; }										// ���f�����̐ݒ�
	inline MODEL&              GetModel(void)                   { return m_Model; }											// ���f�����̎擾
	inline void                SetParent(CONST CModel* pParent) { m_Param.pParent = (CModel*)pParent; }							// �e���f���̃|�C���^�̐ݒ�
	inline CModel&	           GetParent(void)                  { return *m_Param.pParent; }										// �e���f���̃|�C���^�̎擾
	inline void                SetID(const int &nID)            { m_Param.nIdentifier = nID; }									// ID�A���ʔԍ��̐ݒ�
	inline int&                GetID(void)                      { return m_Param.nIdentifier; }									// ID�A���ʔԍ��̎擾
	inline void                SetDisp(CONST bool &bDisp)       { m_Param.bDisp = bDisp; }										// �`��t���O�̐ݒ�
	inline bool&               GetDisp(void)                    { return m_Param.bDisp; }											// �`��t���O�̎擾
	inline void                ChangeDisp(void)                 { m_Param.bDisp ^= 1; }											// �`��t���O�̕ύX
private:
	/* -- �����o�֐� -- */
	static void                LoadModelFromX(void);																		// ���f����X�t�@�C������ǂݍ���
	static void                GetResource(void);																			// �����̒��B
	static void                GetMaxMinVertices(MODEL& Model);																// �ő�ŏ��̒��_�ʒu�̎擾
	static void                GetTextureIDfrom_Xfile(MODEL& Model, CONST_STRING sFileName);								// X�t�@�C������擾�����e�N�X�`������ID�̎擾����
	static void                SetTextureID(int& nTextureID, CONST_STRING sFileName);
	static void                ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);	// 1�s�������ǂݎ��
	static void                NumLoad(CONST_STRING cnpLine);																// ���̓ǂݍ���
	static void                FileNameLoad(CONST_STRING cnpLine);															// �t�@�C�����̓ǂݍ���

	/* -- �����o�ϐ� -- */
	static MyVector<MODEL>   m_AllModelInfo;	// �S�Ẵ��f�����
	static MyVector<CString> m_FileName;		// �t�@�C�����̃|�C���^
	static int               m_nNumAllModel;	// �S���f����
	LPDIRECT3DTEXTURE9       m_pTexture;		// �e�N�X�`���̃|�C���^
	MODEL                    m_Model;			// ���f���̏��|�C���^
	MODELPARAM               m_Param;			// ���f���̃p�����[�^
};

#endif
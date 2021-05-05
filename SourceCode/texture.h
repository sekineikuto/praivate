//*************************************************************************************************************
//
// �e�N�X�`������[texture.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CTexture
{
public:
	enum
	{
		NAME_NONE = -1,					// ����
		// �ėp�e�N�X�`��
		NAME_NUMBER,					// ����							number000.png
		NAME_LOCK_ON,					// ���b�N�I��					Lock-on000.png
		// �Q�[���p�e�N�X�`��
		NAME_TIMER,						// �^�C�}�[�@					TIMER000.png
		NAME_GAGE,						// �Q�[�W						Gage000.png
		NAME_FRAME,						// �g							Frame000.png
		NAME_READY,						// READY?						ready000.png
		NAME_START,						// START!						start000.png
		NAME_FINISH,					// FINISH!						finish000.png
		// �^�C�g���p�e�N�X�`��
		NAME_TITLENAME,					// �l�R�^���{�b�g���			TitleName000.png
		NAME_PLEASEENTER,				// �X�^�[�gEnter�������Ă�������Pleasestartbuttonorenter000.png
		// �`���[�g���A���p�e�N�X�`��
		NAME_GAMEPADKEYBOARD,			// �Q�[���p�b�h / �L�[�{�[�h	amepadAndKeyboard000.png
		NAME_MOVEOPERATION,				// �ړ�����						MovementOperationExplanation000.png
		NAME_CAMERAMOVEOPERATION,		// �J�����ړ�����				ExplanationOfCameraMovementOperation000.png
		NAME_JUMPOPERATION,				// �W�����v�������				JumpOperationExplanation000.png
		NAME_BOOSTOPERATION,			// �u�[�X�g�������				BoostOperatingInstructions000.png
		NAME_ATTACKPERATION,			// �U���������					AttackOperationExplanation000.png
		NAME_SPATTACKERATION,			// ����U���������				SpecialAttackOperationExplanation000.png
		NAME_CHARGEOPERATION,			// �`���[�W�������				OperationExplanationOfCharge000.png
		NAME_CAMERAREPAIROPERATION,		// �J���������������			OperatingInstructionsForCameraRepair000.png
		NAME_DEATHBLOWOPERATION,		// �K�E�Z�������				OperationalInstructionsForTheSpecialMove000.png
		NAME_LOCK_ONOPERATION,			// ���b�N�I���I�t�������		Lock - onOperationDescription000.png
		NAME_LOCK_ONSWITCHOPERATION,	// ���b�N�I���؂�ւ��������	Lock - onSwitchingOperationDescription000.png
		NAME_MAGMAFLOOROPERATION,		// �}�O�}�̏�����				DescriptionOfMagmaFloor1000.png
		// ���U���g�p�e�N�X�`��
		NAME_BATTLERESULT,				// �擪����						battleresult000.png
		NAME_RESULTITEM,				// ���ʍ���						resultItem000.png
		NAME_VERSUS,					// ��							versus.png
		NAME_CONNECTOR,					// ��							Connector.png
		NAME_WINS,						// ������						Wins000.png
		NAME_CAT,						// �l�R							cat000.png
		NAME_MOUSE,						// �l�Y�~						mouse000.png
		NAME_DRAW,						// ��������						draw000.png
		// �I����ʗp�e�N�X�`��
		NAME_SCREEN_VOLCANO,			// �ΎR�X�N���[���p				Volcano.jpg
		NAME_WINDOW,					// �E�B���h�EUI					window000.png
		NAME_ITEMWINDOW0,				// ���ڗp�E�B���h�EUI(��)		itemwindow000.png
		NAME_ITEMWINDOW1,				// ���ڗp�E�B���h�EUI(�D)		itemwindow001.png
		NAME_PLAYER,					// �v���C�C���[UI(����)			PLAYER000.png
		NAME_ENEMY,						// �G�l�~�[UI(����)				ENEMY000.png
		NAME_WEAPON,					// ����UI(����)					WEAPON000.png
		NAME_SWORD,						// ��UI(����)					sword000.png
		NAME_SPEAR,						// ��UI(����)					spear000.png
		NAME_AXE,						// ��UI(����)					axe000.png
		NAME_MAP,						// �}�b�vUI(����)				MAP000.png
		NAME_VOLCANO000,				// VOLCANOUI(����)				VOLCANO000.png
		NAME_WHERE_TO_START,			// WHERE_TO_START(����)			WHERE_TO_START000.png
		NAME_TUTORIAL,					// TUTORIAL(����)				TUTORIAL000.png
		NAME_BATTLE,					// BATTLE(����)					BATTLE000.png
		NAME_1_ENEMY,					// �G�̑̐�(1�l)				1_Enemy000.png
		NAME_2_ENEMY,					// �G�̑̐�(2�l)				2_Enemy000.png
		NAME_3_ENEMY,					// �G�̑̐�(3�l)				3_Enemy000.png
		NAME_RIGHT_ARROWSIGN,			// �E���						Right_Arrowsign000.png
		NAME_LEFT_ARROWSIGN,			// �����						Left_Arrowsign000.png
		NAME_OPERATION_KEY000,			// �L�[�{�[�h�ł̑I�𑀍����	Keyoperation000.png
		NAME_OPERATION_KEY001,			// �L�[�{�[�h�ł̑I�𑀍����	Keyoperation001.png
		NAME_OPERATION_PAD000,			// �Q�[���p�b�h�ł̑I�𑀍����	Padoperation000.png
		NAME_OPERATION_PAD001,			// �Q�[���p�b�h�ł̑I�𑀍����	Padoperation001.png
		// ���b�V���p�e�N�X�`��
		NAME_MAGUMA0,					// �}�O�}(�M)					maguma.jpg
		NAME_MAGUMA1,					// �}�O�}(��)					maguma002.jpg
		NAME_TILE,						// �΂̃^�C��					tile000.jpg
		NAME_SKY,						// ��(�܂���)					sky002.jpg
		// �G�t�F�N�g�p�e�N�X�`��
		NAME_EFFECT0,					// ���q							Effect000.jpg
		NAME_EFFECT1,					// �g							Effect001.jpg
		NAME_EFFECT2,					// �g(��d)						Effect002.jpg
		NAME_EFFECT3,					// ������						Effect003.jpg
		// �O�՗p�e�N�X�`��
		NAME_ORBIT0,					// �O��(��)						orbit000.jpg
		NAME_ORBIT1,					// �O��(��)						orbit001.jpg
		NAME_ORBIT2,					// �O��(��)						orbit002.jpg
		NAME_ORBIT3,					// �O��(�^����)					orbit003.pos
		// �Ǘp�e�N�X�`��
		NAME_WALLSKIN,					// �{�[�_�[						wallsukin.png
		NAME_MAX						// �ő吔
	};
	enum
	{
		TEXTURE_TOPID_NONE     = -1,						// ����
		TEXTURE_TOPID_UI       = NAME_NUMBER,				// UI�̐擪
		TEXTURE_TOPID_GAME     = NAME_TIMER,				// �Q�[��UI�̐擪
		TEXTURE_TOPID_TITLE    = NAME_TITLENAME,			// �^�C�g��UI�̐擪
		TEXTURE_TOPID_TUTORIAL = NAME_GAMEPADKEYBOARD,		// �`���[�g���A���̐擪
		TEXTURE_TOPID_RESULT   = NAME_BATTLERESULT,			// ���U���g�̐擪
		TEXTURE_TOPID_SELECT   = NAME_SCREEN_VOLCANO,		// �I���̐擪
		TEXTURE_TOPID_MESH     = NAME_MAGUMA0,				// ���b�V���̐擪
		TEXTURE_TOPID_EFFECT   = NAME_EFFECT0,				// �G�t�F�N�g�̐擪
		TEXTURE_TOPID_ORBIT    = NAME_ORBIT0,				// �O��
		TEXTURE_TOPID_MAX      = NAME_MAX,					// �ő吔
	};
	CTexture();																												// �R���X�g���N�^
	~CTexture();																											// �f�X�g���N�^
	static void               Load(void);																					// �ǂݍ���
	static void               Unload(void);																					// �J��
	static void               CreateTexture(void);																			// �e�N�X�`���̐���
	static LPDIRECT3DTEXTURE9 GetTextureInfo(int nIndex);																	// �e�N�X�`���̎擾
	static int                GetNumTextureMax(void);																		// �e�N�X�`�����̍ő�
	static void               GetFileName(const int nIndex, STRING output);													// �t�@�C�����̎擾
	static CONST_STRING       GetFileName(const int nIndex);																// �t�@�C�����̎擾
private:
	/* �����o�֐� */
	static void               GetResource(void);																			// �����̒��B
	static void               ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);		// 1�s�������ǂݎ��
	static void               NumLoad(CONST_STRING cnpLine);																// ���̓ǂݍ���
	static void               FileNameLoad(CONST_STRING cnpLine);															// �t�@�C�����̓ǂݍ���
	/* �����o�ϐ� */
	static MyVector<LPDIRECT3DTEXTURE9> m_pTexture;																			// �e�N�X�`�����̃|�C���^
	static MyVector<CString>            m_pFileName;																		// �t�@�C�����̃|�C���^
	static int                          m_nNumTextureMax;																	// �ő�e�N�X�`����
};
#endif

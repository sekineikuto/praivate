//*************************************************************************************************************
//
// �}�l�[�W������[manager.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _MANAGER_H_
#define _MANAGER_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "sound.h"
#include "DebugProc.h"
#include "keyboard.h"
#include "mouse.h"
#include "gamepad.h"
#include "camera.h"
#include "Light.h"
#include "Mylibrary.h"
#include <unordered_map>

//-------------------------------------------------------------------------------------------------------------
// �G�C���A�X�錾
//-------------------------------------------------------------------------------------------------------------
using hash_map = std::unordered_map<std::string, int>;

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CSound;
class CMouse;
class Ckeyboard;
class CDebugProc;
class CRenderer;
class CCamera;
class CLight;
class CGamepad;
class CHash;
class CMode;
class CTextureManager;
class CManager
{
public:
	typedef enum
	{
		FILE_NONE = -1,		// ����
		FILE_SOUND,			// �T�E���h
		FILE_CHARACTERINFO,	// �L�����N�^�[���
		FILE_CHARAMOTION,	// �L�����N�^�[���[�V����
		FILE_BOTINFO,		// �{�b�g�̏��
		FILE_MESHFIELD,		// ���b�V���t�B�[���h
		FILE_MODEL,			// ���f��
		FILE_COLLIDER,		// �Փ˔���
		FILE_MAP,			// �}�b�v
		FILE_TITLEUI,		// �^�C�g��UI
		FILE_SELECTUI,		// �I�����[�hUI
		FILE_TUTORIALUI,	// �`���[�g���A��UI
		FILE_GAMEUI,		// �Q�[��UI
		FILE_RESULTUI,		// ���U���gUI
		FILE_PARTICLE,		// �p�[�e�B�N��
		FILE_TEXTURE,		// �e�N�X�`��
		FILE_MAX			// �ő吔
	} FILE_NAME;

	typedef enum
	{
		MODE_NONE = 0,		// ����
		MODE_TITLE,			// �^�C�g��
		MODE_SELECT,		// �I��
		MODE_TUTORIAL,		// �`���[�g���A��
		MODE_GAME,			// �Q�[��
		MODE_RESULT,		// ���U���g
		MODE_MAX			// �ő�
	} MODE;

	/* -- �����o�֐� -- */
	CManager();																								// �R���X�g���N�^
	~CManager();																							// �f�X�g���N�^
	HRESULT Init(HINSTANCE hInstance ,HWND hWnd, BOOL bWindow);										// ������
	void Uninit(void);																				// �I��
	void Update(void);																				// �X�V
	void Draw(void);																					// �`��
	static void SetHash(void);																				// �n�b�V����ݒ�
	static void UnsetHash(void);																				// �n�b�V���̏�����
	static void LoadInitFile(void);																			// �������t�@�C���̓ǂݍ���
	static void ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);	// 1�s�������ǂݎ��
	static STRING GetFIleName(CManager::FILE_NAME FileIndex);												// �t�@�C�����̎擾
	static void SceneAllReleaseAndSoundStop(void);															// �V�[���̊J�������ƃT�E���h�̒�~
	static void SetMode(MODE mode);																			// ���[�h�̐ݒ�

	/*�@�C�����C���֐� */
	static MODE       GetMode(void)               { return m_mode; }			// ���[�h�̎擾
	static MODE&      GetModeRef(void)            { return m_mode; }			// ���[�h�Q�Ƃ̎擾
	static MODE*      GetModePtr(void)            { return &m_mode; }			// ���[�|�C���^�̎擾

	static CRenderer& GetRenderer(void)           { return m_Renderer; }		// �����_���[�Q�Ƃ̎擾
	static CRenderer& GetRendererRef(void)        { return m_Renderer; }		// �����_���[�Q�Ƃ̎擾
	static CRenderer* GetRendererPtr(void)        { return &m_Renderer; }		// �����_���[�|�C���^�̎擾

	static Ckeyboard& GetKeyboard(void)           { return m_Keyboard; }		// �L�[�{�[�h�Q�Ƃ̎擾
	static Ckeyboard& GetKeyboardRef(void)        { return m_Keyboard; }		// �L�[�{�[�h�Q�Ƃ̎擾
	static Ckeyboard* GetKeyboardPtr(void)        { return &m_Keyboard; }		// �L�[�{�[�h�|�C���^�̎擾

	static CGamepad&  GetGamepad(void)            { return m_Gamepad; }			// �Q�[���p�b�h�̎擾
	static CGamepad&  GetGamepadRef(void)         { return m_Gamepad; }			// �Q�[���p�b�h�̎擾
	static CGamepad*  GetGamepadPtr(void)         { return &m_Gamepad; }			// �Q�[���p�b�h�̎擾

	static CMouse&    GetMouse(void)              { return m_Mouse; }			// �}�E�X�̎擾
	static CMouse&    GetMouseRef(void)           { return m_Mouse; }			// �}�E�X�̎擾
	static CMouse*    GetMousePtr(void)           { return &m_Mouse; }			// �}�E�X�̎擾

	static CCamera&   GetCamera(void)             { return m_Camera; }			// �J�����̎擾
	static CCamera&   GetCameraRef(void)          { return m_Camera; }			// �J�����̎擾
	static CCamera*   GetCameraPtr(void)          { return &m_Camera; }			// �J�����̎擾

	static CLight&    GetLight(void)              { return m_Light; }			// ���C�g�̎擾
	static CLight&    GetLightRef(void)           { return m_Light; }			// ���C�g�̎擾
	static CLight*    GetLightPtr(void)           { return &m_Light; }			// ���C�g�̎擾

	static CSound&    GetSound(void)              { return m_Sound; }			// �T�E���h�̎擾
	static CSound&    GetSoundRef(void)           { return m_Sound; }			// �T�E���h�̎擾
	static CSound*    GetSoundPtr(void)           { return &m_Sound; }			// �T�E���h�̎擾

	static CMode&     GetModeClass(void)          { return *m_pModeClass; }		// ���[�h�N���X�̎擾
	static CMode*     GetModeClassPtr(void)       { return m_pModeClass; }		// ���[�h�N���X�̎擾

	static void       SetTotalScore(const int nMyScore) { m_nMyScore = nMyScore; }	// �g�[�^���X�R�A�̐ݒ�
	static int        GetTotalScore(void)         { return m_nMyScore; }		// �g�[�^���X�R�A�̎擾
	static int&       GetTotalScoreRef(void)      { return m_nMyScore; }		// �g�[�^���X�R�A�̎擾
	static int*       GetTotalScorePtr(void)      { return &m_nMyScore; }		// �g�[�^���X�R�A�̎擾

	static CTextureManager* GetTextureManager(void) { return m_pTextureManager; }

#ifdef _DEBUG
	void SetFPS(int nFps);												// FPS�̐ݒ�
#endif
private:
	/* -- �����o�ϐ� -- */
	static CRenderer	m_Renderer;						// �����_���[�|�C���^
	static Ckeyboard	m_Keyboard;						// �L�[�{�[�h�̃|�C���^
	static CMouse		m_Mouse;							// �}�E�X�̃|�C���^
	static CGamepad		m_Gamepad;						// �Q�[���p�b�h�̃|�C���^
	static CSound		m_Sound;							// �T�E���h�̃|�C���^
	static CDebugProc	m_DebugProc;						// �f�o�b�O�����̃|�C���^
	static CCamera		m_Camera;							// �J�����̃|�C���^
	static CLight		m_Light;							// ���C�g�̃|�C���^
	static STRING		m_aFIleName[FILE_NAME::FILE_MAX];	// �t�@�C����(.ini����ǂ݂��񂾃t�@�C��)
	static MODE			m_mode;								// ���[�h
	static int			m_nMyScore;							// �X�R�A�ۑ�
	static CHash		m_Hash;							// �n�b�V���|�C���^
	static CMode*		m_pModeClass;					// ���[�h�N���X�̃|�C���^
	static CTextureManager * m_pTextureManager;			// �e�N�X�`���}�l�[�W���[
	static hash_map*	m_pSeting_map;	// �ݒ�p�̃n�b�V���}�b�v
protected:
};

#endif
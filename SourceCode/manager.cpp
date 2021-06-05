//*************************************************************************************************************
//
// �}�l�[�W������[manager.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"
#include "Scene.h"
#include "myhash.h"
#include "renderer.h"
#include "Model.h"
#include "mode.h"
#include "title.h"
#include "TextureManager.h"
#include "TextfileController.h"
#include <unordered_map>
#include "mystd\hash_map.h"

//-------------------------------------------------------------------------------------------------------------
// �ÓI�����o�ϐ��̏�����
//-------------------------------------------------------------------------------------------------------------
CRenderer		CManager::m_Renderer                       = MYLIB_INITSTRUCT_WITHCONST;	// �����_���[�|�C���^
Ckeyboard		CManager::m_Keyboard                       = MYLIB_INITSTRUCT_WITHCONST;	// �L�[�{�[�h�̃|�C���^
CMouse			CManager::m_Mouse                          = MYLIB_INITSTRUCT_WITHCONST;	// �}�E�X�̃|�C���^
CGamepad		CManager::m_Gamepad                        = MYLIB_INITSTRUCT_WITHCONST;	// �Q�[���p�b�h�̃|�C���^
CSound			CManager::m_Sound                          = MYLIB_INITSTRUCT_WITHCONST;	// �T�E���h�̃|�C���^
CDebugProc		CManager::m_DebugProc                      = MYLIB_INITSTRUCT_WITHCONST;	// �f�o�b�O�����̃|�C���^
CCamera			CManager::m_Camera                         = MYLIB_INITSTRUCT_WITHCONST;	// �J�����̃|�C���^
CLight			CManager::m_Light                          = MYLIB_INITSTRUCT_WITHCONST;	// ���C�g�̃|�C���^
STRING			CManager::m_aFIleName[FILE_NAME::FILE_MAX] = MYLIB_INITSTRUCT_WITHCONST;	// �t�@�C����(.ini����ǂ݂��񂾃t�@�C��)
CManager::MODE	CManager::m_mode                           = CManager::MODE_NONE;			// ���[�h
int				CManager::m_nMyScore                       = MYLIB_INT_UNSET;				// �X�R�A�ۑ�
CHash			CManager::m_Hash                           = MYLIB_INITSTRUCT_WITHCONST;	// �n�b�V���|�C���^
CMode*			CManager::m_pModeClass                     = nullptr;						// ���[�h�N���X�̃|�C���^
CTextureManager* CManager::m_pTextureManager = nullptr;

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CManager::CManager()
{

}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CManager::~CManager()
{

}

//-------------------------------------------------------------------------------------------------------------
// ����������
//-------------------------------------------------------------------------------------------------------------
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// �����������i�E�B���h�E�̐�����ɍs���j
	if (FAILED(m_Renderer.Init(hWnd, bWindow)))
	{
		return -1;
	}
	// �n�b�V���e�[�u���̍쐬
	m_Hash.MakeHashtable();
	// �n�b�V���̐ݒ�
	SetHash();

	// �������t�@�C���̓ǂݍ���
	LoadInitFile();

	// �L�[�{�[�h�̏�����������
	m_Keyboard.Init(hInstance, hWnd);
	// �}�E�X�̏�����
	m_Mouse.Init(hInstance, hWnd);

	// �Q�[���p�b�h�̏�����
	m_Gamepad.Init(hInstance, hWnd);

	// �T�E���h�̏�����
	m_Sound.InitSound(hWnd,m_aFIleName[FILE_NAME::FILE_SOUND]);
	// �J�����̏�����
	m_Camera.Init();
	// ���C�g�̐���
	m_Light.Init();

#ifdef _DEBUG
	// �f�o�b�O�̐���
	m_DebugProc.Init();
#endif // _DEBUG

	// �e�N�X�`���}�l�[�W���[����
	m_pTextureManager = CTextureManager::Create();
	// ���f���̓ǂݍ���
	//CModel::Load();
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �I������
//------------------------------------------------------------------------------------------------------------
void CManager::Uninit(void)
{
	// �V�[���̊J�������ƃT�E���h�̒�~
	SceneAllReleaseAndSoundStop();
	// ���f���̊J��
	//CModel::Unload();
	// �e�N�X�`���}�l�[�W���[�̊J��
	CTextureManager::Release(m_pTextureManager);
#ifdef _DEBUG
	// �f�o�b�O�̏I������
	m_DebugProc.Uninit();
#endif // _DEBUG

	// ���C�g�̏I������
	m_Light.Uninit();
	// �J�����̏I������
	m_Camera.Uninit();
	// �T�E���h�̏I������
	m_Sound.UninitSound();
	// �Q�[���p�b�h�̏I������
	m_Gamepad.Uninit();
	// �}�E�X�̏I������
	m_Mouse.Uninit();
	// �L�[�{�[�h�̏I������
	m_Keyboard.Uninit();
	// �t�@�C���̊J��
	for (int nCntFiileName = 0; nCntFiileName < CManager::FILE_NAME::FILE_MAX; nCntFiileName++)
	{// �t�@�C���̏I������
		delete[] m_aFIleName[nCntFiileName];
		m_aFIleName[nCntFiileName] = nullptr;
	}
	// �n�b�V���e�[�u���̊J��
	m_Hash.ReleaseHashtable();
	// �����_���[�̏I������
	m_Renderer.Uninit();
}

//-------------------------------------------------------------------------------------------------------------
// �X�V����
//-------------------------------------------------------------------------------------------------------------
void CManager::Update(void)
{
	// �L�[�{�[�h�̍X�V����
	m_Keyboard.Update();
	// �}�E�X�̍X�V����
	m_Mouse.Update();
	// �Q�[���p�b�h�̍X�V����
	m_Gamepad.Update();
	// �J�����̍X�V����
	m_Camera.Update();
	// ���C�g�̍X�V����
	m_Light.Update();

	if (m_mode != MODE_NONE)
	{
		// ���[�h�N���X�̍X�V
		m_pModeClass->Update();
	}

	// �����_���[�̍X�V����
	m_Renderer.UpDate();
}

//-------------------------------------------------------------------------------------------------------------
// �`�揈��
//-------------------------------------------------------------------------------------------------------------
void CManager::Draw(void)
{
	// ���[�h�N���X�̍X�V
	m_pModeClass->Draw();
	// �����_���[�̕`�揈��
	m_Renderer.Draw();
}

//-------------------------------------------------------------------------------------------------------------
// ���[�h�̐؂�ւ�
//-------------------------------------------------------------------------------------------------------------
void CManager::SetMode(MODE mode)
{
	// �J�����̏�����
	m_Camera.Init();
	// ���C�g�̕�����ݒ�
	m_Light.SetDirection();

	if (m_pModeClass != nullptr)
	{
		m_pModeClass->Uninit();
		delete m_pModeClass;
		m_pModeClass = nullptr;
	}
	m_mode = mode;
	switch (m_mode)
	{
	case MODE_TITLE:
		m_pModeClass = CTitle::Create();
		break;
	case MODE_SELECT:
		break;
	case MODE_TUTORIAL:
		break;
	case MODE_GAME:
		break;
	case MODE_RESULT:
		break;
	}
}

#ifdef _DEBUG
//-------------------------------------------------------------------------------------------------------------
// FPS�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CManager::SetFPS(int fps)
{
	m_Renderer.SetFPS(fps);
}
#endif


//-------------------------------------------------------------------------------------------------------------
// �n�b�V���̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CManager::SetHash(void)
{
	// �ݒ�p�L�[
	char SetingKey[FILE_MAX][16] = 
	{
		{ "SOUND		" },
		{ "CHARACTER	" },
		{ "CHARAMOTION	" },
		{ "BOTINFO		" },
		{ "MESHFIELD	" },
		{ "MODEL		" },
		{ "COLLIDERL	" },
		{ "MAP			" },
		{ "TITLEUI		" },
		{ "SELECT		" },
		{ "TUTORIALUI	" },
		{ "GAMEUI		" },
		{ "RESULTUI		" },
		{ "PARTICLE		" },
		{ "TEXTURE		" },
	};
	// �ݒ�p�f�[�^
	char SetingData[FILE_MAX][4] =
	{
		{ "0" },
		{ "1" },
		{ "2" },
		{ "3" },
		{ "4" },
		{ "5" },
		{ "6" },
		{ "7" },
		{ "8" },
		{ "9" },
		{ "10" },
		{ "11" },
		{ "12" },
		{ "13" },
		{ "14" },
	};
	// �t�@�C���ő吔�����[�v
	for (int nCntHash = 0; nCntHash < FILE_MAX; nCntHash++)
	{// �n�b�V���ɓo�^����
		m_Hash.Insert(SetingKey[nCntHash], SetingData[nCntHash]);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �������t�@�C���̓ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CManager::LoadInitFile(void)
{
	mystd::hash_map<int> seting_test =
	{ 
		{ "SOUND"      , 0 },
	};







	std::unordered_map<std::string, int> seting_map =
	{
		{ "SOUND"      , 0 },
		{ "CHARACTER"  , 1 },
		{ "CHARAMOTION", 2 },
		{ "BOTINFO"    , 3 },
		{ "MESHFIELD"  , 4 },
		{ "MODEL"      , 5 },
		{ "COLLIDERL"  , 6 },
		{ "MAP"        , 7 },
		{ "TITLEUI"    , 8 },
		{ "SELECT"     , 9 },
		{ "TUTORIALUI" , 10 },
		{ "GAMEUI"     , 11 },
		{ "RESULTUI"   , 12 },
		{ "PARTICLE"   , 13 },
		{ "TEXTURE"    , 14},
	};

	CLoadInitFile::LoadFile("DATA/TEXT/GameManager.ini",
		[&seting_map]
		(CLoadInitFile::READINFO& info)
	{
		// �ϐ��錾
		char SetingFileName[MYLIB_STRINGSIZE];	// �ݒ�p�t�@�C����
		SetingFileName[0] = MYLIB_CHAR_UNSET;

		if (sscanf(info.line, "FILENAME = %s", &SetingFileName[0]) == 1)
		{
			// �z��ԍ��̎擾
			int nIndex = seting_map.at(info.entrydata);
			// ������̊m�ۂƐݒ�
			m_aFIleName[nIndex] = CMylibrary::SetStringAlloc(SetingFileName);
		}
	});
}

//-------------------------------------------------------------------------------------------------------------
// 1�s�������ǂݎ��
//-------------------------------------------------------------------------------------------------------------
void CManager::ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData)
{
	// �ϐ��錾
	char SetingFileName[MYLIB_STRINGSIZE];	// �ݒ�p�t�@�C����
	SetingFileName[0] = MYLIB_CHAR_UNSET;

	if (sscanf(cnpLine, "FILENAME = %s", &SetingFileName[0]) == 1)
	{
		// �z��ԍ��̎擾
		int nIndex = CMylibrary::GetConvertStoI(m_Hash.Search((char*)cnpEntryData));
		// ������̊m�ۂƐݒ�
		m_aFIleName[nIndex] = CMylibrary::SetStringAlloc(SetingFileName);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �t�@�C����
//-------------------------------------------------------------------------------------------------------------
STRING CManager::GetFIleName(CManager::FILE_NAME FileIndex)
{
	return m_aFIleName[FileIndex];
}

//-------------------------------------------------------------------------------------------------------------
// �V�[���̊J�������ƃT�E���h�̒�~
//-------------------------------------------------------------------------------------------------------------
void CManager::SceneAllReleaseAndSoundStop(void)
{
	if (m_pModeClass != nullptr)
	{
		m_pModeClass->Uninit();
		delete m_pModeClass;
		m_pModeClass = nullptr;
	}
	// �T�E���h���~
	m_Sound.StopSound();
	// �S�Ă̊J������
	CScene::ReleaseAll();
}

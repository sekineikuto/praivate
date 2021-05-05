//*************************************************************************************************************
//
// �T�E���h���� [sound.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _SOUND_H_
#define _SOUND_H_

#include "manager.h"
//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CSound
{
public:
	// �T�E���h���x��
	typedef enum
	{
		SOUND_LABEL_NONE = -1,				// ����
		/* ----- BGM ----- */
		SOUND_LABEL_BGM_TITLE = 0,			// �^�C�g��
		SOUND_LABEL_BGM_SELECT,				// �I��
		SOUND_LABEL_BGM_TUTORIAL,			// �`���[�g���A��
		SOUND_LABEL_BGM_GAME,				// �Q�[��
		SOUND_LABEL_BGM_RESULT,				// ���U���g
		/* ----- SE ----- */
		SOUND_LABEL_SE_NEXT,				// ����
		SOUND_LABEL_SE_SELECT,				// �I��
		SOUND_LABEL_SE_DECISION,			// ����
		SOUND_LABEL_SE_ATTACKHIT,			// �U�������������Ƃ�
		SOUND_LABEL_SE_DEADLYATTACKHIT,		// �K�E�Z�����������Ƃ�
		SOUND_LABEL_SE_FIRE,				// ����
		SOUND_LABEL_SE_CHARGE,				// �`���[�W
		/* ----- �ő吔 ----- */
		SOUND_LABEL_MAX,
	} SOUND_LABEL;// �T�E���h���x��

	// �T�E���h�p�����[�^
	typedef struct
	{
		char *pFilename;	// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g BGM = -1 ; SE = 1
	} SOUNDPARAM;

	CSound();																								// �R���X�g���N�^
	~CSound();																								// �f�X�g���N�^
	HRESULT     InitSound(HWND hWnd);																		// ������
	void        UninitSound(void);																			// �I��
	HRESULT     PlaySound(SOUND_LABEL label);																// �Z�O�����g�Đ�(�Đ����Ȃ��~)
	HRESULT     DoNotOverlapPlaySound(SOUND_LABEL label);													// �Z�O�����g�Đ�(����SE���d�Ȃ�Ȃ��悤�ɂ���)
	void        StopSound(SOUND_LABEL label);																// �Z�O�����g��~(���x���w��)
	void        StopSound(void);																			// �Z�O�����g��~(�S��)
	static      CSound *Create(HWND hWnd);																	// ����
private:
	/* �����o�֐� */
	HRESULT     CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);		// �`�����N�̃`�F�b�N
	HRESULT     ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);		// �`�����N�f�[�^�̓ǂݍ���
	void        UnLoadFileName(void);																		// �T�E���h�t�@�C�����̊J��
	static void GetSoundInfo(void);																			// �T�E���h�����擾����
	static void ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);	// 1�s�������ǂݎ��
	/* �����o�ϐ� */
	static IXAudio2*               m_pXAudio2;																// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	static IXAudio2MasteringVoice* m_pMasteringVoice;														// �}�X�^�[�{�C�X
	static IXAudio2SourceVoice*    m_apSourceVoice[SOUND_LABEL_MAX];										// �\�[�X�{�C�X
	static BYTE*                   m_apDataAudio[SOUND_LABEL_MAX];											// �I�[�f�B�I�f�[�^
	static DWORD                   m_aSizeAudio[SOUND_LABEL_MAX];											// �I�[�f�B�I�f�[�^�T�C�Y
	static SOUNDPARAM              m_aParam[SOUND_LABEL_MAX];												// �e���f�ނ̃p�����[�^
	static int                     m_nNumParam;																// �p�����[�^��
};

#endif

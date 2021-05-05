//*************************************************************************************************************
//
// �Q�[���p�b�h���� [gamepad.h]
// Author : KOKI NISHIYAMA
//
//*************************************************************************************************************
#ifndef _GAMEPAD_H_
#define _GAMEPAD_H_

#define _CRT_SECURE_NO_WARNINGS
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "input.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define MAX_GAMEPAD (1)			// �Q�[���p�b�h�̍ő吔

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CGamepad : public CInput
{
public:
	/* �\���̔ԍ�(enum) */
	typedef enum
	{
		KEY_X = 0,
		KEY_Y,
		KEY_A,
		KEY_B,
		KEY_LEFT_1,
		KEY_RIGHT_1,
		KEY_LEFT_2,
		KEY_RIGHT_2,
		KEY_LEFT_STICK,
		KEY_RIGHT_STICK,
		KEY_BACK,
		KEY_START,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_UP,
		KEY_DOWN,
		KEY_MAX,
	}KEY;

	/* �֐� */
	CGamepad();										// �R���X�g���N�^
	~CGamepad();									// �f�X�g���N�^
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);	// ������
	void Uninit(void);								// �I��
	void Update(void);								// �X�V
	// �����Ă����Ԃ̎擾
	bool GetPress(int nJoy, KEY key);
	// ���������̏�Ԃ̎擾
	bool GetTrigger(int nJoy, KEY key);
	// ���������̏�Ԃ̎擾
	bool GetRelease(int nJoy, KEY key);
	// ���s�[�g��Ԃ̎擾
	bool GetRepeat(int nJoy, KEY key);
	// ���������̍��̎擾
	int GetTriggerLeft(int nJoy, KEY key);
	// ���������̉E�̎擾
	int GetTriggerRight(int nJoy, KEY key);
	// ���X�e�B�b�N�̎擾
	void GetStickLeft(int nJoy, int *pValueH, int *pValueV);
	// �E�X�e�B�b�N�̎擾
	void GetStickRight(int nJoy, int *pValueH, int *pValueV);

protected:
private:
	/* �����o�֐� */
	static BOOL CALLBACK EnumCallback(const DIDEVICEINSTANCE *pdidInstance, VOID *pContext);	// �\�͎擾
	void SetState(int nJoy);																	// �{�^���ݒ�
	/* �����o�ϐ� */
	static LPDIRECTINPUTDEVICE8 m_pJoyDevice[MAX_GAMEPAD];	// ���̓f�o�C�X�ւ̃|�C���^
	DIJOYSTATE2 m_aState[MAX_GAMEPAD];						// �Q�[���p�b�h��Ԃ��󂯎�郏�[�N
	D3DXVECTOR3 m_aStateAxis[MAX_GAMEPAD];					// �X�e�B�b�N�̈ʒu���
	int m_nCntWaitRepeat;									// �J�E���g�}�b�N�X
	int m_nIntervalRepeat;									// �����̊�
	static int m_nCntpad;									// �J�E���g
	int m_aStateRepeatCnt[MAX_GAMEPAD][KEY_MAX];			// ���s�[�g��
	bool m_abState[MAX_GAMEPAD][KEY_MAX];					// �Q�[���p�b�h��Ԃ̕ۑ��ꏊ
	bool m_abStateTrigger[MAX_GAMEPAD][KEY_MAX];			// �Q�[���p�b�h��Ԃ̃I���E�I�t
	bool m_abStateRelease[MAX_GAMEPAD][KEY_MAX];			// �Q�[���p�b�h��Ԃ̕Ԃ�
	bool m_abStateRepeat[MAX_GAMEPAD][KEY_MAX];				// �Q�[���p�b�h��Ԃ��J��Ԃ�

};
#endif

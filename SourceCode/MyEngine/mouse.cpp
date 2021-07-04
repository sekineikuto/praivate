//*************************************************************************************************************
//
// �}�E�X���͏��� [mouse.cpp]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mouse.h"

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CMouse::CMouse()
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CMouse::~CMouse()
{
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
HRESULT CMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);
	m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL);

	m_pDevice->SetDataFormat(&c_dfDIMouse2); // �}�E�X�p�̃f�[�^�E�t�H�[�}�b�g��ݒ�

	m_pDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	// �f�o�C�X�̐ݒ�
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL; // ���Βl���[�h�Őݒ�i��Βl��DIPROPAXISMODE_ABS�j
	m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph);

	// ���͐���J�n
	m_pDevice->Acquire();

	// ���
	m_hWnd = hWnd;

	// �J�[�\����\��
	ShowCursor(TRUE);

	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// �X�V����
//-------------------------------------------------------------------------------------------------------------
void CMouse::Update(void)
{
	// �{�^���̏�����
	m_mouse.mouseState.rgbButtons[0] = 0;

	// �}�E�X�̍��W���擾
	GetCursorPos(&m_mouse.point);
	ScreenToClient(m_hWnd, &m_mouse.point);

	// �l�̍X�V 
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &m_mouse.mouseState)))
	{
		for (int nCntButton = 0; nCntButton < NUM_BUTTON_MAX; nCntButton++)
		{
			// �r���I�_���a���ǂ������f
			m_aButtonStateTrigger[nCntButton] = (m_aButtonState[nCntButton] ^ m_mouse.mouseState.rgbButtons[nCntButton]) & m_mouse.mouseState.rgbButtons[nCntButton];
			m_aButtonStateRelease[nCntButton] = (m_aButtonState[nCntButton] ^ m_mouse.mouseState.rgbButtons[nCntButton]) & m_aButtonState[nCntButton];
			// �L�[�v���X���ۑ�
			m_aButtonState[nCntButton] = m_mouse.mouseState.rgbButtons[nCntButton];
		}
	}
	else
	{
 		m_pDevice->Acquire();
	}
}

//-------------------------------------------------------------------------------------------------------------
// �I������
//-------------------------------------------------------------------------------------------------------------
void CMouse::Uninit(void)
{
	CInput::Uninit();
}

//*************************************************************************************************************
//
// �}�E�X���� [mouse.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MOUSE_H_
#define _MOUSE_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "input.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define	NUM_BUTTON_MAX			(8)		// �{�^��(�}�E�X)�̍ő吔

//-------------------------------------------------------------------------------------------------------------
// �N���X�̒�`
//-------------------------------------------------------------------------------------------------------------
class CMouse :public CInput
{
public:
	typedef struct
	{
		DIMOUSESTATE2	mouseState;	// ���
		POINT			point;		// �ʒu
	} MOUSE;

	/* --- �����o�֐� --- */
	CMouse();
	~CMouse();
	HRESULT      Init(HINSTANCE hInstance, HWND hWnd);														// ������
	void         Update(void);																				// �X�V
	void         Uninit(void);																				// �I��
	/* �C�����C���֐� */
	inline bool  GetPress(int nButton)   { return (m_aButtonState[nButton] & 0x80) ? true : false; }		// �����Ă���Ƃ�
	inline bool  GetTrigger(int nButton) { return (m_aButtonStateTrigger[nButton] & 0x80) ? true : false; }	// ��������
	inline bool  GetRelease(int nButton) { return (m_aButtonStateRelease[nButton] & 0x80) ? true : false; }	// ��������
	inline LONG  GetMouseX(void)         { return m_mouse.point.x; }										// �}�E�XX��
	inline LONG  GetMouseY(void)         { return m_mouse.point.y; }										// �}�E�XY��
	inline POINT GetMousePoint(void)     { return m_mouse.point; }											// �}�E�X�̈ʒu
private:
	MOUSE	m_mouse;									// �}�E�X�̏��
	BYTE	m_aButtonState[NUM_BUTTON_MAX];				// �}�E�X�̓��͏�񃏁[�N
	BYTE	m_aButtonStateTrigger[NUM_BUTTON_MAX];		// �}�E�X�̃g���K�[
	BYTE	m_aButtonStateRelease[NUM_BUTTON_MAX];		// ��������
	HWND	m_hWnd;										// �E�B���h�E�n���h��
};

#endif

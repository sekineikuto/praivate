//*************************************************************************************************************
//
// ���[�h���� [mode.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MODE_H_
#define _MODE_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CMode
{
public:
	typedef enum
	{
		STATE_NONE = 0,		// ����
		STATE_IN,			// ����
		STATE_NORMAL,		// �ʏ�
		STATE_OUT,			// ������
		STATE_MAX			// �ő�
	}STATE;

	CMode() {};															// �R���X�g���N�^
	~CMode() {};														// �f�X�g���N�^

	virtual void Init(void) = 0;										// ������
	virtual void Uninit(void) = 0;										// �I��
	virtual void Update(void) = 0;										// �X�V
	virtual void Draw(void) = 0;										// �`��

	void          Init(STATE State,int nMaxCnt);						// ������

	inline void   SetState(STATE rhs)      { m_State = rhs; }			// ��Ԃ̐ݒ�
	inline STATE& GetState(void)           { return m_State; }			// ��Ԃ̎擾
	inline void   SetMaxCntState(UINT rhs) { m_nMaxCntState = rhs; }	// �؂�ւ��J�E���g�̍ő吔�̐ݒ�
	inline UINT&  GetMaxCntState(void)     { return m_nMaxCntState; }	// �؂�ւ��J�E���g�̍ő吔�̎擾
	inline void   SetCntState(UINT rhs)    { m_nCntState = rhs; }		// �؂�ւ��J�E���g�̐ݒ�
	inline UINT&  GetCntState(void)        { return m_nCntState; }		// �؂�ւ��J�E���g�̎擾

	bool          ChangeState(STATE State);			// ��Ԃ̐؂�ւ�

protected:
	STATE m_State;								// ���
	UINT  m_nMaxCntState;						// �؂�ւ��J�E���g�̍ő吔
	UINT  m_nCntState;							// �؂�ւ��J�E���g
};

#endif
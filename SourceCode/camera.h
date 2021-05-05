//*************************************************************************************************************
//
// �J�������� [camera.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _CAMERA_H_
#define _CAMERA_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define CAMERA_FOLLOW_ROTCOEFFICIENT	(0.2f)									// �Ǐ]�W��(��])
#define CAMERA_FOLLOW_COEFFICIENT		(0.3f)									// �Ǐ]�W��
#define CAMERA_MAGNIFICAT_MIN			(5.0f)									// �ő�g�嗦
#define CAMERA_MAGNIFICAT_MAX			(0.25f)									// �ŏ��g�嗦
#define CAMERA_MAGNIFICAT_ADDVALUE		(0.01f)									// �g�嗦�̉��Z�l
#define CAMERA_MAGNIFICAT_UNSET			(1.7f)									// �g�嗦�̏����l(�ݒ�Ȃ�)
#define CAMERA_MAGNIFICAT_SETTITLE		(4.5f)									// �g�嗦�̏����l(�^�C�g�����[�h)
#define CAMERA_MAGNIFICAT_SETRESULT		(4.5f)									// �g�嗦�̏����l(���U���g���[�h)
#define CAMERA_MAGNIFICAT_SETSELECT		(1.36f)									// �g�嗦�̏����l(�I�����[�h)
#define CAMERA_ROTATION_SPEED			(0.05f)									// ��]���x
#define CAMERA_ROT_UNSET				(D3DXVECTOR3(0.35f, 0.0f, 0.0f))		// ��]�̏����l(�ݒ�Ȃ�)
#define CAMERA_ROT_SETSELECT			(D3DXVECTOR3(0.25f, 0.0f, 0.0f))		// ��]�̏����l(�I�����[�h)

#define CAMERA_ROTSPEED_RESULT_TITLE	(0.001f)								// ���U���g�ƃ^�C�g���̉�]���x

#define CAMERA_HEADPOS_UNSET			(MYLIB_3DVECTOR_ZERO)					// �������ʒu�̏����l(�ݒ�Ȃ�)
#define CAMERA_HEADPOS_SETSELECT		(D3DXVECTOR3(-100.0f, 100.0f, 0.0f))	// �������ʒu�̏����l(�I�����[�h)
#define CAMARA_INITPOS_TITLE			(D3DXVECTOR3(0.0f,0.0f,0.0f))			// �^�C�g���̏������ʒu

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CCamera
{
public:

	CCamera();																						// �R���X�g���N�^
	~CCamera();																						// �f�X�g���N�^
	static CCamera* Create(void);																	// ����
	void            Init(void);																		// ������
	void            Uninit(void);																	// �I��
	void            Update(void);																	// �X�V
	void            Set(void);																		// �ݒ�
	void            Operation(void);																// ����
	D3DXVECTOR3*    GetDirecVector(void);															// �J�����������Ă�������̎擾
	D3DXVECTOR3     GetFlatDirecVector(void);														// �J�����������Ă�������̎擾(Y���Ȃ�)
	void            SetCameraPosAndMagni(D3DXVECTOR3 HeadPos, D3DXVECTOR3 rot,float fMagnificat);	// �J�����̈ʒu�ƌ����Ƌ����̊g�嗦�̐ݒ�
	void            SetRotation(D3DXVECTOR3 *rotation);												// �J�����̉�]�̐ݒ�
	void            SetYawRotation(float fYawrot);													// �J�����̉�]�̐ݒ�(Y��)
	void            SetRollRotation(float fRollrot);												// �J�����̉�]�̐ݒ�(X��)
	void            SetRollRotationsave(float fRollrotsave);										// �J�����̉�]�̕ۑ��p�ݒ�(X��)
	D3DXVECTOR3*    GetRotation(void);																// �J�����̉�]�̎擾
	float           GetYawRotation(void);															// �J�����̉�]�̎擾(Y��)
	float           GetRollRotation(void);															// �J�����̉�]�̎擾(X��)
	float           GetRollRotationsave(void);														// �J�����̉�]�̕ۑ��p�擾(X��)
private:

	/* �����o�ϐ� */
	D3DXVECTOR3 m_posR;				// �����_
	D3DXVECTOR3 m_PosRDest;			// �����_�̍s����
	D3DXVECTOR3 m_posV;				// ���_
	D3DXVECTOR3 m_PosVDest;			// ���_�̍s����
	D3DXVECTOR3 m_vecU;				// �x�N�g��
	D3DXVECTOR3 m_rot;				// ���_�̉�]
	D3DXVECTOR3 m_move;				// �ړ���
	D3DXMATRIX  m_mtxProjection;	// �v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX  m_mtxView;			// �r���[�}�g���b�N�X
	float       m_fLength;			// ����
	float       m_fMagnificat;		// �����̕ω���
	D3DXVECTOR3 m_DirecVector;		// �����Ă�x�N�g��
	D3DXVECTOR3 m_HeadPos;			// �������ʒu
	float       m_fRollRotationsave;// X����]�ۑ��p
};


#endif

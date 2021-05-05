//*************************************************************************************************************
//
// ���͏���[keyboard.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "camera.h"
#include "keyboard.h"
#include "DebugProc.h"
#include "gamepad.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define CAMERA_V_POS_X					(100.0f)							// ���_�̃|�W�V����X
#define CAMERA_V_POS_Y					(100.0f)							// ���_�̃|�W�V����Y
#define CAMERA_V_POS_Z					(100.0f)							// ���_�̃|�W�V����Z

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CCamera::CCamera()
{
}

//-------------------------------------------------------------------------------------------------------------
// �f�X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CCamera::~CCamera()
{
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CCamera * CCamera::Create(void)
{
	CCamera *pCamera = new CCamera;
	pCamera->Init();
	return pCamera;
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CCamera::Init(void)
{
	// �\���̂̏�����
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_move = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	// �I�����[�h�̎�
	if (CManager::GetMode() == CManager::MODE_SELECT)
	{
		m_rot = CAMERA_ROT_SETSELECT;
		m_HeadPos = CAMERA_HEADPOS_SETSELECT;
		m_fMagnificat = CAMERA_MAGNIFICAT_SETSELECT;
	}
	// �^�C�g�����[�h�̎�
	else if (CManager::GetMode() == CManager::MODE_TITLE)
	{
		m_rot = CAMERA_ROT_UNSET;
		m_HeadPos = CAMARA_INITPOS_TITLE;
		m_fMagnificat = CAMERA_MAGNIFICAT_SETTITLE;
	}
	// ���U���g���[�h�̎�
	else if (CManager::GetMode() == CManager::MODE_RESULT)
	{
		m_rot = CAMERA_ROT_UNSET;
		m_HeadPos = CAMARA_INITPOS_TITLE;
		m_fMagnificat = CAMERA_MAGNIFICAT_SETRESULT;
	}
	else
	{// ���̑��̎�
		m_rot = CAMERA_ROT_UNSET;
		m_HeadPos = CAMERA_HEADPOS_UNSET;
		m_fMagnificat = CAMERA_MAGNIFICAT_UNSET;
	}
	// ����
	m_fLength = sqrtf(CAMERA_V_POS_X*CAMERA_V_POS_Y*CAMERA_V_POS_Z) / 3;	// / xyz��
	// X����]�ۑ��p
	m_fRollRotationsave = m_rot.x;
	// ���_�̍s����
	m_PosVDest.x = m_HeadPos.x - cosf(m_rot.x)*sinf(m_rot.y)*m_fLength*m_fMagnificat;
	m_PosVDest.y = m_HeadPos.y + sinf(m_rot.x)*m_fLength*m_fMagnificat;
	m_PosVDest.z = m_HeadPos.z - cosf(m_rot.x)*cosf(m_rot.y)*m_fLength*m_fMagnificat;
	// ���_�̍X�V
	m_posV.x += (m_PosVDest.x - m_posV.x);
	m_posV.y += (m_PosVDest.y - m_posV.y);
	m_posV.z += (m_PosVDest.z - m_posV.z);

	// �����_�̍s����
	m_PosRDest.x = m_HeadPos.x;
	m_PosRDest.y = m_HeadPos.y;
	m_PosRDest.z = m_HeadPos.z;
	// �����_�̍X�V
	m_posR.x += (m_PosRDest.x - m_posR.x);
	m_posR.y += (m_PosRDest.y - m_posR.y);
	m_posR.z += (m_PosRDest.z - m_posR.z);
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CCamera::Uninit(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CCamera::Update(void)
{
	/*---------------------------------------------
	//	���_�̍X�V
	---------------------------------------------*/
	// ���_�̍s����̍X�V
	m_PosVDest.x = m_HeadPos.x - cosf(m_rot.x)*sinf(m_rot.y)*m_fLength*m_fMagnificat;
	m_PosVDest.y = m_HeadPos.y + sinf(m_rot.x)*m_fLength*m_fMagnificat;
	m_PosVDest.z = m_HeadPos.z - cosf(m_rot.x)*cosf(m_rot.y)*m_fLength*m_fMagnificat;
	// ���_�̍X�V
	m_posV += (m_PosVDest - m_posV)*CAMERA_FOLLOW_COEFFICIENT;

	/*---------------------------------------------
	//	�����_�̍X�V
	---------------------------------------------*/
	// �����_�̍s����̍X�V
	m_PosRDest.x = m_HeadPos.x;
	m_PosRDest.y = m_HeadPos.y;
	m_PosRDest.z = m_HeadPos.z;
	// �����_�̍X�V
	m_posR += (m_PosRDest - m_posR)*CAMERA_FOLLOW_COEFFICIENT;

	// �����Ă���������Z�o
	m_DirecVector = m_posR - m_posV;
	// �P�ʃx�N�g���̐���
	CMylibrary::CreateUnitVector(&m_DirecVector, &m_DirecVector);
}

//-------------------------------------------------------------------------------------------------------------
// �ݒ�
//-------------------------------------------------------------------------------------------------------------
void CCamera::Set(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();	// �f�o�C�X�̎擾

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	// �v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(
		&m_mtxProjection,
		D3DXToRadian(45.0f),							// ����p
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,		// �A�X�y�N�g��
		10.0f,											// NearZ�l
		10000.0f);										// FearZ�l

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION,
		&m_mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	// �r���[�}�g���b�N�X���쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);

	// �r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
void CCamera::Operation(void)
{
	// �L�[�{�[�h�̎擾
	Ckeyboard *pKeyboard = &CManager::GetKeyboard();
	CGamepad *pGamepad = &CManager::GetGamepad();
	// �J�����̌��]
	if (pKeyboard->GetPress(DIK_RIGHTARROW))
	{
		m_rot.y += CAMERA_ROTATION_SPEED;
	}
	else if (pKeyboard->GetPress(DIK_LEFTARROW))
	{
		m_rot.y -= CAMERA_ROTATION_SPEED;
	}
	if (pKeyboard->GetPress(DIK_UPARROW))
	{
		m_rot.x += CAMERA_ROTATION_SPEED*0.3f;
		m_fRollRotationsave += CAMERA_ROTATION_SPEED*0.3f;
	}
	else if (pKeyboard->GetPress(DIK_DOWNARROW))
	{
		m_rot.x -= CAMERA_ROTATION_SPEED*0.3f;
		m_fRollRotationsave -= CAMERA_ROTATION_SPEED*0.3f;
	}

	// �ϐ��錾
	int nValueH = 0;//�X�e�B�b�N�̉�
	int nValueV = 0;//�X�e�B�b�N�̏c
	//�W���C�p�b�h�ł̏���
	pGamepad->GetStickRight(0, &nValueH, &nValueV);
	// ���͏�񂪑��݂���Ƃ�
	if (nValueH != 0)
	{
		m_rot.y += (nValueH / 1024) * CAMERA_ROTATION_SPEED;
	}
	if ( nValueV != 0)
	{
		m_rot.x -= (nValueV / 1024) * CAMERA_ROTATION_SPEED*0.3f;
		m_fRollRotationsave -= (nValueV / 1024) * CAMERA_ROTATION_SPEED*0.3f;
	}
	// �����̔{���ύX
	if (pKeyboard->GetPress(DIK_4))
	{
		m_fMagnificat += 0.01f;
	}
	else if (pKeyboard->GetPress(DIK_5))
	{
		m_fMagnificat -= 0.01f;
	}
	else if (pKeyboard->GetPress(DIK_1))
	{
		m_fMagnificat = 1.0f;
	}
	else if (pKeyboard->GetPress(DIK_2))
	{
		m_fMagnificat = CAMERA_MAGNIFICAT_MAX;
	}
	else if (pKeyboard->GetPress(DIK_3))
	{
		m_fMagnificat = CAMERA_MAGNIFICAT_MIN;
	}

	// �g�嗦�̐���
	if (m_fMagnificat >= CAMERA_MAGNIFICAT_MIN)
	{
		m_fMagnificat = CAMERA_MAGNIFICAT_MIN;
	}
	else if (m_fMagnificat <= CAMERA_MAGNIFICAT_MAX)
	{
		m_fMagnificat = CAMERA_MAGNIFICAT_MAX;
	}

	// �J�����̉�]��90�x�����ɗ}����
	if (m_rot.x >= D3DX_PI*0.49f)
	{
		m_rot.x = D3DX_PI*0.49f;
	}
	else if (m_rot.x <= -D3DX_PI*0.49f)
	{
		m_rot.x = -D3DX_PI*0.49f;
	}
	// ��]�ʂ�360�x�Ȃ��ɒ���
	CMylibrary::SetFixTheRotation(&m_rot.y);
}

//-------------------------------------------------------------------------------------------------------------
// �J�����������Ă���������擾����
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 * CCamera::GetDirecVector(void)
{
	return &m_DirecVector;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����������Ă��镽�ʂł̕������擾����
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 CCamera::GetFlatDirecVector(void)
{
	return D3DXVECTOR3(m_DirecVector.x, 0.0f, m_DirecVector.z);
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̈ʒu�ƌ����Ƌ����̊g�嗦�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CCamera::SetCameraPosAndMagni(D3DXVECTOR3 HeadPos, D3DXVECTOR3 rot, float fMagnificat)
{
	m_HeadPos		= HeadPos;		// �������ʒu
	m_rot			= rot;			// ����
	m_fMagnificat	= fMagnificat;	// �g�嗦
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CCamera::SetRotation(D3DXVECTOR3 * rotation)
{
	m_rot = *rotation;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̐ݒ�(Y��)
//-------------------------------------------------------------------------------------------------------------
void CCamera::SetYawRotation(float fYawrot)
{
	m_rot.y = fYawrot;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̐ݒ�(X��)
//-------------------------------------------------------------------------------------------------------------
void CCamera::SetRollRotation(float fRollrot)
{
	m_rot.x = fRollrot;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̕ۑ��p�ݒ�(X��)
//-------------------------------------------------------------------------------------------------------------
void CCamera::SetRollRotationsave(float fRollrotsave)
{
	m_fRollRotationsave = fRollrotsave;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̎擾
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 * CCamera::GetRotation(void)
{
	return &m_rot;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̎擾(Y��)
//-------------------------------------------------------------------------------------------------------------
float CCamera::GetYawRotation(void)
{
	return m_rot.y;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̎擾(X��)
//-------------------------------------------------------------------------------------------------------------
float CCamera::GetRollRotation(void)
{
	return m_rot.x;
}

//-------------------------------------------------------------------------------------------------------------
// �J�����̉�]�̕ۑ��p�擾(X��)
//-------------------------------------------------------------------------------------------------------------
float CCamera::GetRollRotationsave(void)
{
	return m_fRollRotationsave;
}
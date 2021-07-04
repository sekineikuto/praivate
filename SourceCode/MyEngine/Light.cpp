//*************************************************************************************************************
//
// ���͏���[keyboard.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Light.h"
#include "manager.h"
#include "DebugProc.h"
#include "keyboard.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define LIGHT_0_SELECT_DIRECTION	(D3DXVECTOR3(0.0f,-0.6f,0.8f))			// �I�����[�h���̃��C�g0�̌���
#define LIGHT_1_SELECT_DIRECTION	(D3DXVECTOR3(0.96f,-0.0f,0.5f))			// �I�����[�h���̃��C�g1�̌���
#define LIGHT_2_SELECT_DIRECTION	(D3DXVECTOR3(-0.53f,-0.4f,0.74f))		// �I�����[�h���̃��C�g2�̌���

#define LIGHT_0_UNSET_DIRECTION		(D3DXVECTOR3(0.22f, -0.87f, 0.44f))		// ���ɐݒ�Ȃ��̃��C�g0�̌���
#define LIGHT_1_UNSET_DIRECTION		(D3DXVECTOR3(-0.18f, 0.88f, -0.44f))	// ���ɐݒ�Ȃ��̃��C�g1�̌���
#define LIGHT_2_UNSET_DIRECTION		(D3DXVECTOR3(0.89f, -0.11f, 0.44f))		// ���ɐݒ�Ȃ��̃��C�g2�̌���


#define LIGHT_0_UNSET_COLOR			(D3DXCOLOR( 1.0f,1.0f,1.0f,1.0f))		// ���ɐݒ�Ȃ��̃��C�g0�̐F
#define LIGHT_1_UNSET_COLOR			(D3DXCOLOR(0.65f,0.65f,0.65f,0.65f))	// ���ɐݒ�Ȃ��̃��C�g1�̐F
#define LIGHT_2_UNSET_COLOR			(D3DXCOLOR(0.15f,0.15f,0.15f,0.15f))	// ���ɐݒ�Ȃ��̃��C�g2�̐F

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CLight::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();	// �f�o�C�X�̎擾
	// �����̐ݒ�
	D3DXVECTOR3 vecDir[LIGHT_MAX] = {
		{ LIGHT_0_UNSET_DIRECTION },
		{ LIGHT_1_UNSET_DIRECTION },
		{ LIGHT_2_UNSET_DIRECTION },
	};
	// �F�̐ݒ�
	D3DXCOLOR col[LIGHT_MAX] = {
		{ LIGHT_0_UNSET_COLOR },
		{ LIGHT_1_UNSET_COLOR },
		{ LIGHT_2_UNSET_COLOR },
	};

	for (int nCount = 0; nCount < LIGHT_MAX; nCount++)
	{
		// ���C�g���N���A����
		ZeroMemory(&m_aLight[nCount], sizeof(D3DLIGHT9));

		// ���C�g�̎�ނ�ݒ�		(_DIRECTIONAL | _SPOT | _POINT)
		m_aLight[nCount].Type = D3DLIGHT_DIRECTIONAL;

		// ���C�g�̊g�U����ݒ�
		m_aLight[nCount].Diffuse = col[nCount];
		// ���K��
		D3DXVec3Normalize(&vecDir[nCount], &vecDir[nCount]);
		// ��������
		m_aLight[nCount].Direction = vecDir[nCount];
		// ���C�g��ݒ肷��
		pDevice->SetLight(nCount, &m_aLight[nCount]);

		// ���C�g��L���ɂ���
		pDevice->LightEnable(nCount, TRUE);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CLight::Uninit(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CLight::Update(void)
{

}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CLight * CLight::Create(void)
{
	// ���C�g�̐���
	CLight *pLight = new CLight;
	// ���C�g�̏�����
	pLight->Init();
	return pLight;
}

//-------------------------------------------------------------------------------------------------------------
// ���C�g�̕����̐ݒ�
//-------------------------------------------------------------------------------------------------------------
void CLight::SetDirection(void)
{
	// �ϐ��錾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();	// �f�o�C�X�̎擾

	// �����x�N�g��
	D3DXVECTOR3 vecDir[LIGHT_MAX] = {};
	// �Z���N�g���[�h�̎�
	if (CManager::GetMode() == CManager::MODE_SELECT)
	{
		vecDir[0] = LIGHT_0_SELECT_DIRECTION;
		vecDir[1] = LIGHT_1_SELECT_DIRECTION;
		vecDir[2] = LIGHT_2_SELECT_DIRECTION;
	}
	else
	{// ���̑�
		vecDir[0] = LIGHT_0_UNSET_DIRECTION;
		vecDir[1] = LIGHT_1_UNSET_DIRECTION;
		vecDir[2] = LIGHT_2_UNSET_DIRECTION;
	}
	// ���C�g�̍ő吔�����[�v
	for (int nCount = 0; nCount < LIGHT_MAX; nCount++)
	{// ���K��
		D3DXVec3Normalize(&vecDir[nCount], &vecDir[nCount]);
		// ��������
		m_aLight[nCount].Direction = vecDir[nCount];
		// ���C�g��ݒ肷��
		pDevice->SetLight(nCount, &m_aLight[nCount]);
	}
}

//-------------------------------------------------------------------------------------------------------------
// ���C�g���̎擾
//-------------------------------------------------------------------------------------------------------------
D3DLIGHT9 * CLight::GetLight(int nNumLight)
{
	return &m_aLight[nNumLight];
}

//*************************************************************************************************************
//
// �����_���[����[renderer.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _RENDERER_H_
#define _RENDERER_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "../main.h"
#include "../mystd/types.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CFade;
class CRenderer
{
public:
	using VERTEX_2D = mystd::VERTEX_2D;
	using VERTEX_3D = mystd::VERTEX_3D;


	/* -- �����o�֐� -- */
	CRenderer();
	~CRenderer();
	HRESULT Init(HWND hWnd, BOOL bWindow);		// ����������
	void Uninit(void);							// �I������
	void UpDate(void);							// �X�V����
	void Draw(void);							// �`�揈��

	inline LPDIRECT3DDEVICE9 GetDevice(void) { return m_pD3DDevice; }			// �f�o�C�X�̎擾
	inline CFade *GetFade(void) { return m_pFade; }								// �t�F�[�h�̎擾

	static void SetStencilMaskRenderState(LPDIRECT3DDEVICE9 pDevice, unsigned char ref, D3DCMPFUNC cmp_func);	// �X�e���V���}�X�N�p�����_���[�X�e�[�g�̃Z�b�g�A�b�v
	static void SetStencilRenderState(LPDIRECT3DDEVICE9 pDevice, unsigned char ref, D3DCMPFUNC cmp_func);		// �X�e���V���p�����_���[�X�e�[�g�̃Z�b�g�A�b�v
	static void UnsetStencilRenderState(LPDIRECT3DDEVICE9 pDevice);												// �X�e���V���p�����_���[�X�e�[�g�̐ݒ���O��
#ifdef _DEBUG
	inline void SetFPS(int fps) { m_nCountFPS = fps; }
#endif

private:
	/* -- �����o�֐� -- */

	/* -- �����o�ϐ� -- */
	LPDIRECT3D9			m_pD3D = NULL;				// Direct3D�I�u�W�F�N�g�̃|�C���^
	LPDIRECT3DDEVICE9	m_pD3DDevice = NULL;		// DirectX3D�f�o�C�X�̃|�C���^
	static CFade		*m_pFade;					// �t�F�[�h
#ifdef _DEBUG
	int			m_nCountFPS = 0;	// FPS�J�E���^
#endif

protected:
};

#endif
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
#include "main.h"

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
	typedef struct
	{
		D3DXVECTOR3 pos;						// ���_�̍��W
		float		rhw;						// 1.0�ŌŒ蓯�����W
		D3DCOLOR	col;						// ���_�J���[
		D3DXVECTOR2	tex;						// �e�N�X�`�����W
	} VERTEX_2D;

	// �R�c�|���S�����_�t�H�[�}�b�g�ɍ��킹���\���̂��`
	typedef struct
	{
		D3DXVECTOR3 pos;	// ���_���W
		D3DXVECTOR3 nor;	// �@���x�N�g��
		D3DCOLOR	col;	// ���_�J���[
		D3DXVECTOR2 tex;	// �e�N�X�`�����W
	} VERTEX_3D;


	/* -- �����o�֐� -- */
	CRenderer();
	~CRenderer();
	HRESULT Init(HWND hWnd, BOOL bWindow);		// ����������
	void Uninit(void);							// �I������
	void UpDate(void);							// �X�V����
	void Draw(void);							// �`�揈��

	inline LPDIRECT3DDEVICE9 GetDevice(void) { return m_pD3DDevice; }			// �f�o�C�X�̎擾
	inline CFade *GetFade(void) { return m_pFade; }								// �t�F�[�h�̎擾
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
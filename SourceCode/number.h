//*************************************************************************************************************
//
// �����̏���[number.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _NUMBER_H_
#define _NUMBER_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "main.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define SCORE_NUMBER_SIZE_X (35.0f)
#define SCORE_NUMBER_SIZE_Y (55.0f)

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CNumber
{
public:
	CNumber(int nNumOrder);																							// �R���X�g���N�^
	CNumber();																										// �R���X�g���N�^
	~CNumber();																										// �f�X�g���N�^
	static HRESULT Load(void);																						// �ǂݍ���
	static void Unload(void);																						// �J��
	static CNumber *Create(float fSizeX, float fSizeY, D3DXVECTOR3 pos, float fRot, int nNumber, D3DXCOLOR col);	// ����
	HRESULT Init(float fSizeX, float fSizeY, int nNumber, float fRot, D3DXVECTOR3 pos, D3DXCOLOR col);				// ������
	void Unint(void);																								// �I��
	void Update(void);																								// �X�V
	void Draw(void);																								// �`��
	void SetNumber(int nNumber);																					// �����̐ݒ�
	void SetVaetex(int *nNumber = NULL, D3DXVECTOR3 *pos = NULL, D3DXCOLOR *col = NULL);							// ���_�̍X�V
	void SetVeatexColor(void);																						// ���_�J���[�ݒ�
	void SetSize(D3DXVECTOR2 *size);																				// �傫���̐ݒ�
	void SetRotation(float fRot);																					// ��]�ʂ̐ݒ�
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);																	// �e�N�X�`�����̐ݒ�

	inline D3DXCOLOR *GetColor(void) { return &m_col; }
	inline D3DXVECTOR2 *GetSize(void) { return &m_size; }
	inline D3DXVECTOR3 *GetPos(void) { return &m_pos; }
	inline float *GetRot(void) { return &m_fRot; }
	inline int *GetNumber(void) { return&m_nNumber; }

private:
	LPDIRECT3DTEXTURE9			m_pTexture;		// �e�N�X�`�����̃|�C���^
	LPDIRECT3DVERTEXBUFFER9		m_pVtxBuff;		// �o�b�t�@���̃|�C���^
	int							m_nNumber;		// ����
	float						m_fRot;			// ��]��
	D3DXVECTOR2					m_size;			// �傫��
	D3DXVECTOR3					m_pos;			// �ʒu
	D3DXCOLOR					m_col;			// �F
};

#endif

//*************************************************************************************************************
//
// ���������񏈗�[NumericString.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _NUMERICSTRING_H_
#define _NUMERICSTRING_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "MyEngine\Scene.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CNumber;
class CMultiNumbers : public CScene
{
public:
	CMultiNumbers(CScene::PRIORITY pri):CScene(pri) {}
	CMultiNumbers();				// �R���X�g���N�^
	~CMultiNumbers();				// �f�X�g���N�^

	static CMultiNumbers *Create(D3DXVECTOR3 pos, D3DXCOLOR col, D3DXVECTOR2 size, float fRotation, int nValue);

	void Init(D3DXVECTOR3 &pos, D3DXCOLOR &col, D3DXVECTOR2 &size, float &fRotation, int &nValue);
	void Init(void) {}
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void AddValue(void);

	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);				// �e�N�X�`�����֘A�t����

	int GetDigit(void) { return m_nDigits; }		// �����̎擾

	int							m_nValue;			// �l
	int							m_nDigits;			// ����(�`�搔)
	int							m_nNumNumber;		// �g����
	int							m_nAddSign;			// ���Z���镄��
	CNumber						*m_pNumber;			// �������
	D3DXCOLOR					m_col;				// �F
	D3DXVECTOR3					m_pos;				// �ʒu
	D3DXVECTOR2					m_size;				// �傫��
	float						m_fRotation;		// ��]��
	int							m_nNumDiff;			// ����
};

#endif
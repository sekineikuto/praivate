//*************************************************************************************************************
//
// 2DUI����[2DUI.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _2DUI_H_
#define _2DUI_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Scene2D.h"
#include "Ui2dSeting.h"
#include "mystd\CompoBehaviour.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CUi2d : public CScene, public mystd::CCompoBehaviour
{
public:
	CUi2d() : CScene(PRIORITY_2DUI) {}
	CUi2d(PRIORITY pri) : CScene(pri) {}												// �R���X�g���N�^
	~CUi2d() {}																			// �f�X�g���N�^

	static CUi2d * Create(ui2d::SETING &seting, PRIORITY pri = PRIORITY_2DUI);		// ����

	void Init(ui2d::SETING &seting, PRIORITY pri);									// ������
	void Init(void);																	// ������
	void Uninit(void);																	// �I��
	void Update(void);																	// �X�V
	void Draw(void);																	// �`��

private:

protected:
};


#endif
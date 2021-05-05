//*************************************************************************************************************
//
// �^�C�g��UI���� [TitleUI.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _TITLEUI_H_
#define _TITLEUI_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"

#include "2DUI.h"
#include "TextfileController.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CTitleUI
{
public:
	/* �񋓌^��` */
	enum
	{
		TYPE_NONE = -1,																	// ����
		TYPE_TITLENAME,																	// �^�C�g����
		TITLEUI_PLEASEKEY,																// �L�[�������Ă�������
		TYPE_MAX																		// �ő吔
	};

	/* �����o�֐� */
	inline           CTitleUI() {};														// �R���X�g���N�^
	inline           ~CTitleUI() {};													// �f�X�g���N�^

	static CTitleUI* Create(void);														// ����
	void             Init(void);														// ������
	void             Uninit(void);														// �I��
	void             Update(void);														// �X�V
	void             Draw(void);														// �`��

	// �擾�֐�
	C2DUi*          Get2dui(int nIndex = TYPE_TITLENAME);								// 2DUi�̎擾
private:
	/* �����o�֐� */
	static void     ReadFromLine(CLoadInitFile::READINFO& info, std::vector<C2DUi*> *p2dui);						// 1�s���ǂݍ���
	static void     ReadFromLineSetParam(CONST_STRING line, std::vector<C2DUi*> *p2dui);	// �p�����[�^�ɐݒ�
	/* �����o�ϐ� */
	static ui2d::SETING2DUI m_Seting;													// �ݒ�
	static bool             m_bSetingUI;												// UI�ݒ�t���O
	std::vector<C2DUi*>     m_2dui;															// �QDUI�|�C���^

};

#endif
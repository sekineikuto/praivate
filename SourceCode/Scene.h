//*************************************************************************************************************
//
// �V�[������[scene.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _SCENE_H_
#define _SCENE_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "renderer.h"
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define NUM_SCENE2D			(100)						// Scene2D�̌�

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CScene
{
public:
	typedef enum
	{
		TYPE_BG = 0,		// �w�i
		TYPE_FIELD,			// �t�B�[���h
		TYPE_BLOCK,			// �u���b�N
		TYPE_CHARACTER,		// �L�����N�^�[
		TYPE_3DOBJECT,		// 3D�I�u�W�F�N�g
		TYPE_WALL,			// ��
		TYPE_BULLET,		// �e
		TYPE_DEADLY,		// �K�E�G�t�F�N�g
		TYPE_BOSS,			// �{�X
		TYPE_ENEMY,			// �G�l�~�[
		TYPE_PLAYER,		// �v���C���[
		TYPE_EFFECT,		// �G�t�F�N�g
		TYPE_PARTICLE,		// �p�[�e�B�N��
		TYPE_HP,			// HP
		TYPE_SCORE,			// �X�R�A
		TYPE_BUTTON,		// �{�^��
		TYPE_COLLIDER,		// �R���C�_�[
		TYPE_UI,			// UI
		TYPE_MAX			// �ő吔
	} TYPE;
	typedef enum
	{
		PRIORITY_NONE = -1,		// ����
		PRIORITY_3DMODEL,		// 3D���f��
		PRIORITY_FIELD,			// �t�B�[���h
		PRIORITY_SHADOW,		// �e
		PRIORITY_3DUI,			// 3DUI
		PRIORITY_3DCOLLIDER,	// 3D�R���C�_�[
		PRIORITY_3DEFFECT,		// 3D�G�t�F�N�g
		PRIORITY_BG,			// 2D�w�i
		PRIORITY_2DUI,			// 2DUI
		PRIORITY_2DEFFECT,		// 2D�G�t�F�N�g
		PRIORITY_MAX,			// �ő吔
	}PRIORITY;

	CScene(PRIORITY priority);				// �R���X�g���N�^
	virtual ~CScene();						// �f�X�g���N�^
	/* -- �������z�֐� -- */
	virtual void   Init(void) = 0;			// ����������
	virtual void   Uninit(void) = 0;		// �I������
	virtual void   Update(void) = 0;		// �X�V����
	virtual void   Draw(void) = 0;			// �`�揈��
	/* -- �����o�֐� -- */
	static void    UpdataAll(void);			// �S�Ă̍X�V����
	static void    DrawAll(void);			// �S�Ă̕`�揈��
	static void    ReleaseAll(void);		// �S�Ă̊J������
	void           Release(void);			// �J������
	void           ListRelease(void);		// ���X�g����̊J������
	static CScene* GetPlayerScene(void);	// �v���C���[�V�[���̎擾
	static CScene* GetScene(TYPE type);		// �V�[���̎擾
	static CScene* GetTop(int nPriority);	// �擪�̃|�C���^�̎擾
	CScene*        GetNext(void);			// ���̃|�C���^
	/* -- �C�����C���֐� -- */
	inline void SetObjectTyoe(TYPE type)    { m_type = type; }			// ��ނ̐ݒ�
	inline TYPE GetObjectTyoe(void)         { return m_type; }			// ��ނ̎擾
	inline int GetID(void)                  { return m_nID; }			// ID�̎擾
	inline static int GetNumAll(void)       { return m_nNumAll; }		// �S�Ă̐������ꂽ��
	inline void SetOrder(PRIORITY priority) { m_priority = priority; }	// �V�[���̕`��D�揇�̐ݒ�
	inline PRIORITY GetOrder(void)          { return m_priority; }		// �V�[���̕`��D�揇�̎擾

private:
	/* -- �����o�ϐ� -- */
	static int     m_nNumAll;					// �S�ẴV�[����
	int            m_nID;						// ID
	PRIORITY       m_priority;					// �D�揇
	TYPE           m_type;						// �I�u�W�F�N�g�̎��
	static CScene* m_pTop[PRIORITY_MAX];		// �擪�ւ̃I�u�W�F�N�g�|�C���^
	static CScene* m_pCur[PRIORITY_MAX];		// ����(�Ō��)�I�u�W�F�N�g�ւ̃|�C���^
	CScene*        m_pPrev;						// �O�̃I�u�W�F�N�g�ւ̃|�C���^
	CScene*        m_pNext;						// ���̃I�u�W�F�N�g�ւ̃|�C���^
	bool           m_bDie;						// ���S�t���O
	int            m_nPriority;					// �`�揇
protected:
};

#endif
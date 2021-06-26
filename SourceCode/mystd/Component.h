//*************************************************************************************************************
//
// �R���|�[�l���g����[Component.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mystd.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// �O�|�錾
//-------------------------------------------------------------------------------------------------------------
class CCompoBehaviour;

//-------------------------------------------------------------------------------------------------------------
// �C���^�[�t�F�C�X�N���X��`
//-------------------------------------------------------------------------------------------------------------

// ���R���|�[�l���g
class IComponent
{
public:
	IComponent() {}
	virtual ~IComponent() {}

	virtual void Start(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	CCompoBehaviour *parent;	// �e���
	bool             enabled;	// �A�N�e�B�u��ݒ�
private:
protected:

};

// �r�W���A���R���|�[�l���g
class IVisualComponent : public IComponent
{
public:
	IVisualComponent() {}
	virtual ~IVisualComponent() {}

	virtual void Start(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

private:
protected:

};

// �C���e���[�V�����R���|�[�l���g
class IInteractionComponent : public IComponent
{
public:
	IInteractionComponent() {}
	virtual ~IInteractionComponent() {}

	virtual void Start(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) {}

private:
protected:
};


_END_MYSTD

#endif
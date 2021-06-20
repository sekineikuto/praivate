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
// �C���^�[�t�F�C�X�N���X��`
//-------------------------------------------------------------------------------------------------------------
class IComponent
{
public:
	IComponent() {}
	virtual ~IComponent() {}

	virtual void Start(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

private:
protected:
	// �A�N�e�B�u��ݒ�
	bool enabled = true;
};

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
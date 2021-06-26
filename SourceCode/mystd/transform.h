//*************************************************************************************************************
//
// トランスフォーム処理[transform.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#pragma once
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Component.h"
#include "types.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
// トランスフォーム2D
class Transform2D : public IComponent
{
public:
	/* メンバ関数 */
	// コンストラクタ
	Transform2D() {}
	// コンストラクタ
	Transform2D(float fPosX, float fPosY, float fPosZ, float fSizeX, float fSizeY, PIVOTTYPE inPivot, float fRotation, float fScaleX, float fScaleY)
		: Position(fPosX, fPosY, fPosZ), Size(fSizeX, fSizeY), Pivot(inPivot), Rotation(fRotation), Scale(fScaleX, fScaleY) {}
	// コンストラクタ
	Transform2D(D3DXVECTOR3 inPos, RECTSIZE niSize, PIVOTTYPE inPivot, float inRotation, D3DXVECTOR2 inScale)
		:Position(inPos), Size(niSize), Pivot(inPivot), Rotation(inRotation), Scale(inScale) {}

	// デストラクタ
	~Transform2D() {}

	void Start(void) {}
	void Update(void) {}
	void Draw(void) {}

	/* メンバ変数 */
	D3DXVECTOR3 Position;	// 位置
	RECTSIZE    Size;		// サイズ
	PIVOTTYPE   Pivot;		// ピボット種類
	float       Rotation;	// 回転
	D3DXVECTOR2 Scale;		// スケール
};

_END_MYSTD

#endif

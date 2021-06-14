//*************************************************************************************************************
//
// 自作の標準ライブラリのユーティリティ処理 [mystd_utility.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MYSTD_TYPES_H_
#define _MYSTD_TYPES_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "mystd.h"
#include "d3dx9.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// 列挙型定義
//-------------------------------------------------------------------------------------------------------------
// 頂点点の原点(対キーパッド)
typedef enum
{
	PIVOTTYPE_NONE = 0,			// なし
	PIVOTTYPE_LOWERLEFT,			// 左下
	PIVOTTYPE_LOWERCENTER,		// 中央下
	PIVOTTYPE_LOWERRIGHT,		// 右下
	PIVOTTYPE_CENTERLEFT,		// 左中央
	PIVOTTYPE_CENTER,			// 中央
	PIVOTTYPE_CENTERRIGHT,		// 右中央
	PIVOTTYPE_UPPERLEFT,			// 左上
	PIVOTTYPE_UPPERCENTER,		// 中央上
	PIVOTTYPE_UPPERRIGHT,		// 右上
	PIVOTTYPE_MAX				// 最大数
} PIVOTTYPE;

//-------------------------------------------------------------------------------------------------------------
// 変数定義
//-------------------------------------------------------------------------------------------------------------
typedef const char * CSTRING;
typedef char *       STRING;

//-------------------------------------------------------------------------------------------------------------
// 構造体定義
//-------------------------------------------------------------------------------------------------------------
typedef struct _RECTSIZE
{
	_RECTSIZE() {}
	_RECTSIZE(const float fWidth, const float fHeight) : Width(fWidth), Height(fHeight) {}
	_RECTSIZE(_RECTSIZE &src) : Width(src.Width), Height(src.Height) {}
	_RECTSIZE(D3DXVECTOR2 &src) : Width(src.x), Height(src.y) {}

	float Width, Height;
}RECTSIZE;

//-------------------------------------------------------------------------------------------------------------
// 構造体定義
//-------------------------------------------------------------------------------------------------------------
typedef struct Transform2D
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

	/* メンバ変数 */
	D3DXVECTOR3 Position;	// 位置
	RECTSIZE    Size;		// サイズ
	PIVOTTYPE   Pivot;		// ピボット種類
	float       Rotation;	// 回転
	D3DXVECTOR2 Scale;		// スケール
}Transform2D;

_END_MYSTD

#endif

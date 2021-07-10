//*************************************************************************************************************
//
// 画像2D処理[Image2d.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#pragma once
#ifndef _IMAGE2D_H_
#define _IMAGE2D_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "..\MyEngine\Component.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class Transform2D;
class Image2D : public IVisualComponent
{
public:
	/* メンバ関数 */
	// コンストラクタ
	Image2D();

	// デストラクタ
	~Image2D();

	// 処理の開始
	void Start(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// コンポーネントを取り付ける
	void AttachComponent(IComponent * pComp);

private:
	// 頂点情報の作成
	HRESULT MakeVertex(void);

	// 頂点位置の設定
	void SetVertexPosition(VERTEX_2D *pVtx);

	// 頂点カラーの設定
	void SetVertexColor(VERTEX_2D *pVtx);

public:
	/* メンバ変数 */
	LPDIRECT3DVERTEXBUFFER9 pVtxBuff;	// 頂点バッファへのポインタ
	LPDIRECT3DTEXTURE9      pTexture;	// テクスチャへのポインタ
	D3DXCOLOR               color;		// カラー
	Transform2D *           pTransform;	// トランスフォームポインタ
	VERTEX_2D*              pVtx;		// 頂点ポインタ
};
_END_MYSTD



#endif
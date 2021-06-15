//*************************************************************************************************************
//
// 画像2D処理[Image2d.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _IMAGE2D_H_
#define _IMAGE2D_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Component.h"
#include "types.h"

_BEGIN_MYSTD

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class Image2D : public IVisualComponent
{
public:
	/* メンバ関数 */

	// コンストラクタ
	Image2D()
	{

	}

	// デストラクタ
	~Image2D()
	{

	}

	// 開始処理
	void Start(void)
	{

	}

	// 更新
	void Update(void)
	{

	}

	// 描画
	void Draw(void)
	{

	}


	/* メンバ変数 */
	LPDIRECT3DVERTEXBUFFER9 pVtxBuff;	// 頂点バッファへのポインタ
	LPDIRECT3DTEXTURE9      pTexture;	// テクスチャへのポインタ
	D3DXCOLOR               color;		// カラー
private:
	Transform2D *pTransform;
};




_END_MYSTD



#endif
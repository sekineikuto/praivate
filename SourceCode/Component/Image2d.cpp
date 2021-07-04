//*************************************************************************************************************
//
// 画像2D処理[Image2d.cpp]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "../manager.h"
#include "../renderer.h"
#include "Image2d.h"
#include "CompoBehaviour.h"
#include "transform.h"
#include "../mystd/utility.h"

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
mystd::Image2D::Image2D()
{
	// トランスコンポーネントポインタの取得
	pTransform = parent->GetComponent<Transform2D>();
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
mystd::Image2D::~Image2D()
{
}

//-------------------------------------------------------------------------------------------------------------
// 処理の開始
//------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Start(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 頂点情報の作成
//-------------------------------------------------------------------------------------------------------------
HRESULT mystd::Image2D::MakeVertex(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,									// 頂点フォーマット
		D3DPOOL_MANAGED,
		&pVtxBuff,
		NULL);

	// 頂点情報へのポインタ
	VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点位置の設定
	SetVertexPosition(pVtx);

	// Z軸は使う必要ないので0.0f
	pVtx[0].pos.z =
		pVtx[1].pos.z =
		pVtx[2].pos.z =
		pVtx[3].pos.z = 0.0f;

	// 同次座標の設定
	pVtx[0].rhw =
		pVtx[1].rhw =
		pVtx[2].rhw =
		pVtx[3].rhw = 1.0f;

	// 頂点カラーの設定
	SetVertexColor(pVtx);

	// テクスチャ座標
	SetTexturePosition(pVtx);

	// 頂点データをアンロック
	pVtxBuff->Unlock();

	return E_NOTIMPL;
}

//-------------------------------------------------------------------------------------------------------------
// 頂点位置の設定
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetVertexPosition(VERTEX_2D *pVtx)
{
	// 変数宣言
	D3DXVECTOR2 halfsize = D3DXVECTOR2(pTransform->Size.Width * mystd::fHalfSize, pTransform->Size.Height * mystd::fHalfSize);	// 半分の大きさ
	float		fInvRot = -pTransform->Rotation;																	// 逆の回転
	float		fSin_size_x = sinf(mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;					// sin方向のxX軸の大きさの計算結果
	float		fCos_size_x = cosf(mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;					// cos方向のxX軸の大きさの計算結果

	// 原点タイプに応じて頂点[0]の位置を設定する
	switch (pTransform->Pivot)
	{
	case PIVOTTYPE_LOWERLEFT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height;
		break;
	case PIVOTTYPE_LOWERCENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_LOWERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*pTransform->Size.Height + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*pTransform->Size.Height + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	case PIVOTTYPE_CENTERLEFT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y;
		break;
	case PIVOTTYPE_CENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_CENTERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(fPi - pTransform->Rotation)*halfsize.y + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(fPi - pTransform->Rotation)*halfsize.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	case PIVOTTYPE_UPPERLEFT:
		pVtx[0].pos.x = pTransform->Position.x;
		pVtx[0].pos.y = pTransform->Position.y;
		break;
	case PIVOTTYPE_UPPERCENTER:
		pVtx[0].pos.x = pTransform->Position.x + sinf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		pVtx[0].pos.y = pTransform->Position.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*halfsize.x;
		break;
	case PIVOTTYPE_UPPERRIGHT:
		pVtx[0].pos.x = pTransform->Position.x + sinf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		pVtx[0].pos.y = pTransform->Position.y + cosf(-mystd::fHalf_PI - pTransform->Rotation)*pTransform->Size.Width;
		break;
	}

	// 頂点[2]の設定
	pVtx[2].pos.x = pVtx[0].pos.x + sinf(fInvRot)*pTransform->Size.Height;
	pVtx[2].pos.y = pVtx[0].pos.y + cosf(fInvRot)*pTransform->Size.Height;

	// 頂点[1]の設定
	pVtx[1].pos.x = pVtx[0].pos.x + fSin_size_x;
	pVtx[1].pos.y = pVtx[0].pos.y + fCos_size_x;

	// 頂点[3]の設定
	pVtx[3].pos.x = pVtx[2].pos.x + fSin_size_x;
	pVtx[3].pos.y = pVtx[2].pos.y + fCos_size_x;
}

//-------------------------------------------------------------------------------------------------------------
// 頂点カラーの設定
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetVertexColor(VERTEX_2D *pVtx)
{
	pVtx[0].col = pVtx[1].col = pVtx[2].col = pVtx[3].col = color;
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャ位置の設定
//-------------------------------------------------------------------------------------------------------------
void mystd::Image2D::SetTexturePosition(VERTEX_2D *pVtx)
{
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}

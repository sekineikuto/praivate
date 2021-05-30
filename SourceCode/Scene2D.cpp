﻿//*************************************************************************************************************
//
// シーン2D処理[Scene2D.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Scene2D.h"
#include "manager.h"
#include "keyboard.h"
#include "DebugProc.h"
#include "mystd_utility.h"

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CScene2D::CScene2D(CScene::PRIORITY priority) : CScene(priority)
{
	m_bDisp = true;
	m_UpdateFlags.data = 0;
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
CScene2D::~CScene2D()
{
}

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CScene2D * CScene2D::Create(CScene::PRIORITY priority, D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXCOLOR col, float fRotation, ORIGINVERTEXTYPE OriginType, SETING_UV TexUVInfo)
{
	CScene2D *ptr = new CScene2D(priority);
	ptr->SetColor(col);
	ptr->SetOriginType(OriginType);
	ptr->SetPosition(pos);
	ptr->SetRotation(fRotation);
	ptr->SetSize(size);
	ptr->Init();
	return ptr;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CScene2D::Init(void)
{
	// 変数宣言
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();

	m_bDisp = true;

	// 頂点の作成
	this->MakeVatex(pDevice);
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CScene2D::Uninit(void)
{
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void CScene2D::Update(void)
{
	if (m_UpdateFlags.data != 0) {
		UpdateVertex(m_UpdateFlags.pos, m_UpdateFlags.col, m_UpdateFlags.tex);
		m_UpdateFlags.data = 0;
	}
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CScene2D::Draw(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();;

	// 頂点バッファをストリームにバインド
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(CRenderer::VERTEX_2D));

	// 頂点フォーマット設定
	pDevice->SetTexture(0, nullptr);

	// テクスチャの設定
	pDevice->SetFVF(FVF_VERTEX_2D);
	if (m_bDisp)
	{
		// Fill Mode の設定
		pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		// ポリゴン描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
		// Fill Mode の設定
		pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}
}

//-------------------------------------------------------------------------------------------------------------
// 頂点情報の更新
//-------------------------------------------------------------------------------------------------------------
void CScene2D::UpdateVertex(bool bUpdatePos, bool bUpdateCol, bool bUpdateUVTex)
{
	// 頂点情報へのポインタ
	CRenderer::VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (bUpdatePos)
	{
		this->SetVatexPosition(pVtx);
	}
	if (bUpdateCol)
	{
		this->SetVatexColor(pVtx);
	}
	if (bUpdateUVTex)
	{
		this->SetVatexTexture(pVtx);
	}
	// 頂点データをアンロック
	m_pVtxBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// 頂点の原点の変更
//-------------------------------------------------------------------------------------------------------------
void CScene2D::ChangeVertexOrigin(CONST ORIGINVERTEXTYPE OriginType)
{
	// 同じタイプだった時処理を抜ける
	if (m_OriginType == OriginType)return;

	// 頂点情報へのポインタ
	CRenderer::VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_OriginType = OriginType;
	this->SetVatexPosition(pVtx);

	// 頂点データをアンロック
	m_pVtxBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// バッファの取得
//-------------------------------------------------------------------------------------------------------------
LPDIRECT3DVERTEXBUFFER9 CScene2D::GetpVtxBuff(void) const { return m_pVtxBuff; }

//-------------------------------------------------------------------------------------------------------------
// バインドテクスチャ
//-------------------------------------------------------------------------------------------------------------
void CScene2D::BindTexture(LPDIRECT3DTEXTURE9 pTexture) { m_pTexture = pTexture; }

//-------------------------------------------------------------------------------------------------------------
// 原点タイプの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetOriginType(CONST ORIGINVERTEXTYPE OriginType) { m_OriginType = OriginType; }

//-------------------------------------------------------------------------------------------------------------
// 原点タイプの取得
//-------------------------------------------------------------------------------------------------------------
ORIGINVERTEXTYPE CScene2D::GetOriginType(void) const { return m_OriginType; }

//-------------------------------------------------------------------------------------------------------------
// 原点タイプ参照の取得
//-------------------------------------------------------------------------------------------------------------
ORIGINVERTEXTYPE &CScene2D::GetOriginTypeRef(void) { return m_OriginType; }

//-------------------------------------------------------------------------------------------------------------
// 原点タイプポインタの取得
//-------------------------------------------------------------------------------------------------------------
ORIGINVERTEXTYPE *CScene2D::GetOriginTypePtr(void) { return &m_OriginType; }

//-------------------------------------------------------------------------------------------------------------
// 位置の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPosition(CONST D3DXVECTOR3& pos) { m_pos = pos; }

//-------------------------------------------------------------------------------------------------------------
// 位置の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPosition(const float x, const float y, const float z) { m_pos.x = x; m_pos.y = y; m_pos.z = z; }

//-------------------------------------------------------------------------------------------------------------
// 位置Xの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPositionX(const float x) { m_pos.x = x; }

//-------------------------------------------------------------------------------------------------------------
// 位置Yの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPositionY(const float y) { m_pos.y = y; }

//-------------------------------------------------------------------------------------------------------------
// 位置Zの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPositionZ(const float z) { m_pos.z = z; }

//-------------------------------------------------------------------------------------------------------------
// 位置の取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 CScene2D::GetPosition(void) const { return m_pos; }

//-------------------------------------------------------------------------------------------------------------
// 位置参照の取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 & CScene2D::GetPositionRef(void) { return m_pos; }

//-------------------------------------------------------------------------------------------------------------
// 位置ポインタの取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 * CScene2D::GetPositionPtr(void) { return &m_pos; }

//-------------------------------------------------------------------------------------------------------------
// 色の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColor(CONST D3DXCOLOR& col) { m_col = col; }

//-------------------------------------------------------------------------------------------------------------
// 色の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColor(const float r, const float g, const float b, const float a) { m_col.r = r; m_col.g = g; m_col.b = b; m_col.a = a; }

//-------------------------------------------------------------------------------------------------------------
// 色Rの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColorR(const float r) { m_col.r = r; }

//-------------------------------------------------------------------------------------------------------------
// 色Gの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColorG(const float g) { m_col.g = g; }

//-------------------------------------------------------------------------------------------------------------
// 色Bの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColorB(const float b) { m_col.b = b; }

//-------------------------------------------------------------------------------------------------------------
// 色Aの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColorA(const float a) { m_col.a = a; }

//-------------------------------------------------------------------------------------------------------------
// 色の取得
//-------------------------------------------------------------------------------------------------------------
D3DXCOLOR CScene2D::GetColor(void) const { return m_col; }

//-------------------------------------------------------------------------------------------------------------
// 色参照の取得
//-------------------------------------------------------------------------------------------------------------
D3DXCOLOR & CScene2D::GetColorRef(void) { return m_col; }

//-------------------------------------------------------------------------------------------------------------
// 色ポインタの取得
//-------------------------------------------------------------------------------------------------------------
D3DXCOLOR * CScene2D::GetColorPtr(void) { return &m_col; }

//-------------------------------------------------------------------------------------------------------------
// 大きさの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSize(CONST D3DXVECTOR2& size) { m_size = size; }

//-------------------------------------------------------------------------------------------------------------
// 大きさの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSize(const float x, const float y) { m_size.x = x; m_size.y = y; }

//-------------------------------------------------------------------------------------------------------------
// 大きさXの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSizeX(const float x) { m_size.x = x; }

//-------------------------------------------------------------------------------------------------------------
// 大きさYの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSizeY(const float y) { m_size.y = y; }

//-------------------------------------------------------------------------------------------------------------
// 大きさの取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR2 *CScene2D::GetSize(void) { return &m_size; }

//-------------------------------------------------------------------------------------------------------------
// 回転量の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetRotation(float fRotation) { m_fRotation = fRotation; }

//-------------------------------------------------------------------------------------------------------------
// 回転量の取得
//-------------------------------------------------------------------------------------------------------------
float CScene2D::GetRotation(void) { return m_fRotation; }

//-------------------------------------------------------------------------------------------------------------
// 回転量参照の取得
//-------------------------------------------------------------------------------------------------------------
float & CScene2D::GetRotationRef(void) { return m_fRotation; }

//-------------------------------------------------------------------------------------------------------------
// 回転量ポインタの取得
//-------------------------------------------------------------------------------------------------------------
float * CScene2D::GetRotationPtr(void) { return &m_fRotation; }

//-------------------------------------------------------------------------------------------------------------
// 描画フラグの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetDisp(const bool bDisp) { m_bDisp = bDisp; }

//-------------------------------------------------------------------------------------------------------------
// 描画フラグの取得
//-------------------------------------------------------------------------------------------------------------
bool CScene2D::GetDisp(void) { return m_bDisp; }

//-------------------------------------------------------------------------------------------------------------
// 描画フラグ参照の取得
//-------------------------------------------------------------------------------------------------------------
bool & CScene2D::GetDispRef(void) { return m_bDisp; }

//-------------------------------------------------------------------------------------------------------------
// 描画フラグポインタの取得
//-------------------------------------------------------------------------------------------------------------
bool * CScene2D::GetDispPtr(void) { return &m_bDisp; }

//-------------------------------------------------------------------------------------------------------------
// 頂点の作成
//-------------------------------------------------------------------------------------------------------------
HRESULT CScene2D::MakeVatex(LPDIRECT3DDEVICE9 pDevice)
{
	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(CRenderer::VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,									// 頂点フォーマット
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	// 頂点情報へのポインタ
	CRenderer::VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点位置の設定
	SetVatexPosition(pVtx);

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
	SetVatexColor(pVtx);

	// テクスチャ座標
	SetVatexTexture(pVtx);

	// 頂点データをアンロック
	m_pVtxBuff->Unlock();

	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// 頂点位置の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetVatexPosition(CRenderer::VERTEX_2D * pVtx)
{
	// 変数宣言
	D3DXVECTOR2 halfsize;														// 半分の大きさ
	float		fInvRot = -m_fRotation;										// 逆の回転
	float		fSin_size_x = sinf(mystd::fHalf_PI - m_fRotation)*m_size.x;		// sin方向のxX軸の大きさの計算結果
	float		fCos_size_x = cosf(mystd::fHalf_PI - m_fRotation)*m_size.x;		// cos方向のxX軸の大きさの計算結果

	// halfsizeに半分の大きさを格納
	mystd::Convert_to_half_size(halfsize, m_size);

	// 原点タイプに応じて頂点[0]の位置を設定する
	switch (m_OriginType)
	{
	case ORIGINVERTEXTYPE_LOWERLEFT:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*m_size.y;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*m_size.y;
		break;
	case ORIGINVERTEXTYPE_LOWERCENTER:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*m_size.y + sinf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*m_size.y + cosf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		break;
	case ORIGINVERTEXTYPE_LOWERRIGHT:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*m_size.y + sinf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*m_size.y + cosf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		break;
	case ORIGINVERTEXTYPE_CENTERLEFT:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*halfsize.y;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*halfsize.y;
		break;
	case ORIGINVERTEXTYPE_CENTER:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*halfsize.y + sinf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*halfsize.y + cosf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		break;
	case ORIGINVERTEXTYPE_CENTERRIGHT:
		pVtx[0].pos.x = m_pos.x + sinf(D3DX_PI - m_fRotation)*halfsize.y + sinf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		pVtx[0].pos.y = m_pos.y + cosf(D3DX_PI - m_fRotation)*halfsize.y + cosf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		break;
	case ORIGINVERTEXTYPE_UPPERLEFT:
		pVtx[0].pos.x = m_pos.x;
		pVtx[0].pos.y = m_pos.y;
		break;
	case ORIGINVERTEXTYPE_UPPERCENTER:
		pVtx[0].pos.x = m_pos.x + sinf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		pVtx[0].pos.y = m_pos.y + cosf(-mystd::fHalf_PI - m_fRotation)*halfsize.x;
		break;
	case ORIGINVERTEXTYPE_UPPERRIGHT:
		pVtx[0].pos.x = m_pos.x + sinf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		pVtx[0].pos.y = m_pos.y + cosf(-mystd::fHalf_PI - m_fRotation)*m_size.x;
		break;
	}


	// 頂点[2]の設定
	pVtx[2].pos.x = pVtx[0].pos.x + sinf(fInvRot)*m_size.y;
	pVtx[2].pos.y = pVtx[0].pos.y + cosf(fInvRot)*m_size.y;

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
void CScene2D::SetVatexColor(CRenderer::VERTEX_2D * pVtx)
{
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = m_col;
}

//-------------------------------------------------------------------------------------------------------------
// 頂点テクスチャ座標の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetVatexTexture(CRenderer::VERTEX_2D * pVtx)
{
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}

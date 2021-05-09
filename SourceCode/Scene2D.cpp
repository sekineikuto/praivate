//*************************************************************************************************************
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
	m_OriginType = ORIGINVERTEXTYPE_CENTER;
	m_pos = { 0.0f,0.0f,0.0f };
	m_col = { 1.0f,1.0f,1.0f,1.0f };
	m_size = { 0.0f,0.0f };
	m_fRotation = { 0.0f };
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
// 細かい作成
//-------------------------------------------------------------------------------------------------------------
CScene2D * CScene2D::Create(CScene::PRIORITY priority, D3DXVECTOR3 pos, D3DXCOLOR col, ORIGINVERTEXTYPE OriginType, D3DXVECTOR2 size, float fRadius, float m_fRotation, SETING_UV nTexVari)
{
	CScene2D *pScene2D = new CScene2D(priority);
	pScene2D->SetColor(col);
	pScene2D->SetOriginType(OriginType);
	pScene2D->SetPosition(pos);
	pScene2D->SetRotation(m_fRotation);
	pScene2D->SetSize(size);
	pScene2D->Init();
	return pScene2D;
}

//-------------------------------------------------------------------------------------------------------------
// 作成
//-------------------------------------------------------------------------------------------------------------
CScene2D * CScene2D::Create(CScene::PRIORITY priority, D3DXVECTOR3 pos, ORIGINVERTEXTYPE OriginType, D3DXVECTOR2 size, float fRadius)
{
	CScene2D *pScene2D = new CScene2D(priority);
	pScene2D->SetOriginType(OriginType);
	pScene2D->SetPosition(pos);
	pScene2D->SetSize(size);
	pScene2D->Init();
	return pScene2D;
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
void CScene2D::UpdateVertex(D3DXVECTOR3 * pos, D3DXVECTOR2 * size, float * fRadius, D3DXCOLOR * col, SETING_UV * TexVari)
{
	// 頂点情報へのポインタ
	CRenderer::VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (pos != NULL) {
		m_pos = *pos;
	}
	if (size != NULL) {
		m_size = *size;
	}
	if (pos != NULL || size != NULL || fRadius != NULL)
	{
		this->SetVatexPosition(pVtx);
	}

	if (col != NULL)
	{
		m_col = *col;
		this->SetVatexColor(pVtx);
	}

	if (TexVari != NULL)
	{
		this->SetVatexTexture(pVtx);
	}

	// 頂点データをアンロック
	m_pVtxBuff->Unlock();
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
void CScene2D::ChangeVertexOrigin(ORIGINVERTEXTYPE OriginType)
{
	// 頂点情報へのポインタ
	CRenderer::VERTEX_2D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (m_OriginType != OriginType)
	{
		m_OriginType = OriginType;
		this->SetVatexPosition(pVtx);
	}

	// 頂点データをアンロック
	m_pVtxBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// バインドテクスチャ
//-------------------------------------------------------------------------------------------------------------
void CScene2D::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

//-------------------------------------------------------------------------------------------------------------
// バッファの取得
//-------------------------------------------------------------------------------------------------------------
LPDIRECT3DVERTEXBUFFER9 CScene2D::GetpVtxBuff(void)
{
	return m_pVtxBuff;
}

//-------------------------------------------------------------------------------------------------------------
// 原点種類の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetOriginType(ORIGINVERTEXTYPE OriginType)
{
	m_OriginType = OriginType;
}

//-------------------------------------------------------------------------------------------------------------
// 原点種類の取得
//-------------------------------------------------------------------------------------------------------------
ORIGINVERTEXTYPE *CScene2D::GetOriginType(void)
{
	return &m_OriginType;
}

//-------------------------------------------------------------------------------------------------------------
// 位置の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetPosition(D3DXVECTOR3& pos)
{
	m_pos = pos;
}

//-------------------------------------------------------------------------------------------------------------
// 位置の取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR3 *CScene2D::GetPosition(void)
{
	return &m_pos;
}

//-------------------------------------------------------------------------------------------------------------
// 色の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetColor(D3DXCOLOR& col)
{
	m_col = col;
}

//-------------------------------------------------------------------------------------------------------------
// 色の取得
//-------------------------------------------------------------------------------------------------------------
D3DXCOLOR *CScene2D::GetColor(void)
{
	return &m_col;
}

//-------------------------------------------------------------------------------------------------------------
// 大きさの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSize(D3DXVECTOR2& size)
{
	m_size = size;
}

//-------------------------------------------------------------------------------------------------------------
// 大きさXの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSizeX(float size)
{
	m_size.x = size;
}

//-------------------------------------------------------------------------------------------------------------
// 大きさYの設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetSizeY(float size)
{
	m_size.y = size;
}

//-------------------------------------------------------------------------------------------------------------
// 大きさの取得
//-------------------------------------------------------------------------------------------------------------
D3DXVECTOR2 *CScene2D::GetSize(void)
{
	return &m_size;
}

//-------------------------------------------------------------------------------------------------------------
// 回転量の設定
//-------------------------------------------------------------------------------------------------------------
void CScene2D::SetRotation(float fRotation)
{
	m_fRotation = fRotation;
}

//-------------------------------------------------------------------------------------------------------------
// 回転量の取得
//-------------------------------------------------------------------------------------------------------------
float CScene2D::GetRotation(void)
{
	return m_fRotation;
}

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

	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.z = 0.0f;


	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
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
	// 半分のサイズ
	D3DXVECTOR2 halfsize = mystd::half(m_size);
	float fInvRot = -m_fRotation;
	float fSin_size_x = sinf(mystd::fHalf_PI - m_fRotation)*m_size.x;
	float fCos_size_x = cosf(mystd::fHalf_PI - m_fRotation)*m_size.x;

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

	pVtx[2].pos.x = pVtx[0].pos.x + sinf(fInvRot)*m_size.y;
	pVtx[2].pos.y = pVtx[0].pos.y + cosf(fInvRot)*m_size.y;

	pVtx[1].pos.x = pVtx[0].pos.x + fSin_size_x;
	pVtx[1].pos.y = pVtx[0].pos.y + fCos_size_x;
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

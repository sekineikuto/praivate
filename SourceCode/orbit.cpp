//*************************************************************************************************************
//
// 軌道処理 [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "orbit.h"
#include "DebugProc.h"
#include "manager.h"
#include "TextureManager.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define ORBIT_NUM_HEIGHT			(1)		// 高さの個数

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
COrbit::COrbit(CScene::PRIORITY priority) : CScene(priority)
{
}

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
COrbit::COrbit() :CScene(CScene::PRIORITY_3DEFFECT)
{
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
COrbit::~COrbit()
{
}

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
COrbit * COrbit::Create(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size, int nTextureID, D3DXCOLOR &col)
{
	// クラスの生成
	COrbit *pOrbit = new COrbit;
	// テクスチャマネージャーの取得
	CTextureManager*pTexManager = CManager::GetTextureManager();
	// テクスチャの設定
	pOrbit->BindTexture(pTexManager->GetTextureInfo(nTextureID));
	// 情報の設定
	pOrbit->SetInfo(pMtxParent, nNumWidht, size, col);
	// 初期化
	pOrbit->Init();
	return pOrbit;
}

//-------------------------------------------------------------------------------------------------------------
// 情報の設定
//-------------------------------------------------------------------------------------------------------------
void COrbit::SetInfo(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size, D3DXCOLOR &col)
{
	m_nNumWidht		= nNumWidht;		// 横の個数
	m_size			= size;				// 大きさ
	m_pMtxParent	= pMtxParent;		// 親のマトリックス情報
	m_posOriggin = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);	// 原点
	m_posEdge = D3DXVECTOR3(0.0f, m_size.y, 0.0f);											// 端の位置
	m_col = col;						// 色
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void COrbit::Init(void)
{
	m_nNumVertex	= (m_nNumWidht + 1)*(ORBIT_NUM_HEIGHT + 1);									// 総頂点数
	m_nNumIndex		= ((m_nNumWidht + 1) * 2) * ORBIT_NUM_HEIGHT + 2 * (ORBIT_NUM_HEIGHT - 1);	// 総インデックス数
	m_nNumPolygon	= ((m_nNumWidht * ORBIT_NUM_HEIGHT * 2) + 4 * (ORBIT_NUM_HEIGHT - 1));		// 総ポリゴン数
	m_bDisp			= false;																	// 描画フラグ

	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();
	// 頂点情報の作成
	MakeVatex(pDevice);
	// インデックス情報の作成
	MakeIndex(pDevice);

	m_pPosOld     = new D3DXVECTOR3[m_nNumWidht];		// 前回の位置
	m_pPosEdgeOld = new D3DXVECTOR3[m_nNumWidht];	// 切っ先の前回の位置
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void COrbit::Uninit(void)
{
	if (m_pPosOld != NULL)
	{// 前回の位置の開放
		delete[]m_pPosOld;
		m_pPosOld = NULL;
	}
	if (m_pPosEdgeOld != NULL)
	{// 切っ先の前回の位置の開放
		delete[]m_pPosEdgeOld;
		m_pPosEdgeOld = NULL;
	}
	if (m_pVtexBuff != NULL)
	{// 頂点バッファの開放
		m_pVtexBuff->Release();
		m_pVtexBuff = NULL;
	}
	if (m_pIdxBuff != NULL)
	{// インデックスバッファの開放
		m_pIdxBuff->Release();
		m_pIdxBuff = NULL;
	}
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void COrbit::Update(void)
{
	// 頂点情報のポインタ
	CRenderer::VERTEX_3D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点情報の変更
	pVtx[0].pos = m_posOriggin;
	// 親のマトリックス情報を設定
	pVtx[m_nNumWidht + 1].pos = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

	// 前回の位置と入れ替ええていく
	for (int nCntOrbit = 0; nCntOrbit < m_nNumWidht; nCntOrbit++)
	{
		pVtx[nCntOrbit + 1].pos = m_pPosEdgeOld[nCntOrbit];
		pVtx[nCntOrbit + m_nNumWidht + 2].pos  = m_pPosOld[nCntOrbit];
	}

	for (int nCntOld = m_nNumWidht - 1; nCntOld > 0; nCntOld--)
	{
		m_pPosEdgeOld[nCntOld] = m_pPosEdgeOld[nCntOld - 1];
		m_pPosOld[nCntOld] = m_pPosOld[nCntOld - 1];
	}
	m_pPosEdgeOld[0] = m_posOriggin;
	m_pPosOld[0] = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

	// 頂点データをアンロック
	m_pVtexBuff->Unlock();
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void COrbit::Draw(void)
{
	// 変数宣言
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer().GetDevice();
	D3DXMATRIX			mtxRot, mtxTrans , mtxWork;		// 計算用マトリックス

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// 裏面(左回り)をカリングする
	// レンダーステート(加算合成処理)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);				// αブレンドを行う
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// αディスティネーションカラーの指定

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);
	D3DXMatrixIdentity(&mtxWork);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld
		, &m_mtxWorld
		, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld
		, &m_mtxWorld
		, &mtxTrans);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans,
		m_posEdge.x,
		m_posEdge.y,
		m_posEdge.z);

	D3DXMatrixMultiply(&mtxWork
		, &mtxWork
		, &mtxTrans);

	// 親のマトリックス情報と掛ける
	D3DXMatrixMultiply(&mtxWork
		, &mtxWork
		, m_pMtxParent);

	m_posOriggin = D3DXVECTOR3(mtxWork._41, mtxWork._42, mtxWork._43);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtexBuff, 0, sizeof(CRenderer::VERTEX_3D));

	// インデックスバッファをデータストリームを設定
	pDevice->SetIndices(m_pIdxBuff);

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	if (m_bDisp == true)
	{// 描画フラグがオンの時
		// テクスチャの設定
		pDevice->SetTexture(0, m_pTexture);
		// ポリゴンの描画
		pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, m_nNumVertex, 0, m_nNumPolygon);
	}
	// レンダーステート(通常ブレンド処理)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);				// αブレンドを行う
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// 裏面(左回り)をカリングする
}

//-------------------------------------------------------------------------------------------------------------
// 描画開始
//-------------------------------------------------------------------------------------------------------------
void COrbit::DrawStart(void)
{
	// 描画フラグオンじゃない時
	if (m_bDisp != true)
	{// 描画フラグオン
		m_bDisp = true;

		// 頂点情報のポインタ
		CRenderer::VERTEX_3D *pVtx;

		// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
		m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

		// 頂点情報の変更
		pVtx[0].pos = m_posOriggin;

		// 親のマトリックス情報を設定
		pVtx[m_nNumWidht + 1].pos = D3DXVECTOR3(m_pMtxParent->_41, m_pMtxParent->_42, m_pMtxParent->_43);

		// 頂点情報を初期化
		for (int nCntOrbit = 0; nCntOrbit < m_nNumWidht; nCntOrbit++)
		{
			pVtx[nCntOrbit + 1].pos = m_posOriggin;
			pVtx[nCntOrbit + m_nNumWidht + 2].pos = pVtx[m_nNumWidht + 1].pos;
		}

		// 頂点データをアンロック
		m_pVtexBuff->Unlock();
	}
}

//-------------------------------------------------------------------------------------------------------------
// 描画終了
//-------------------------------------------------------------------------------------------------------------
void COrbit::DrawEnd(void)
{
	// 描画フラグオフじゃない時
	if (m_bDisp != false)
	{// 描画フラグオフ
		m_bDisp = false;
	}
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャ情報の拘束
//-------------------------------------------------------------------------------------------------------------
void COrbit::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

//-------------------------------------------------------------------------------------------------------------
// 頂点情報の作成
//-------------------------------------------------------------------------------------------------------------
HRESULT COrbit::MakeVatex(LPDIRECT3DDEVICE9 pDevice)
{

	// 頂点バッファを生成
	if ((FAILED(pDevice->CreateVertexBuffer(
		sizeof(CRenderer::VERTEX_3D) * m_nNumVertex,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,									// 頂点フォーマット
		D3DPOOL_MANAGED,
		&m_pVtexBuff,
		NULL))))
	{
		std::cout << "COrbit == 頂点情報の作成に失敗しました\n";
		return E_FAIL;
	}

	// 頂点情報のポインタ
	CRenderer::VERTEX_3D *pVtx;

	// 頂点データの範囲ロックし、頂点バッファへのポインタ取得
	m_pVtexBuff->Lock(0, 0, (void**)&pVtx, 0);

	float fTexWidth = 1.0f / m_nNumWidht;
	for (int nCntHeight = 0; nCntHeight < ORBIT_NUM_HEIGHT + 1; nCntHeight++)
	{
		for (int nCntWidth = 0; nCntWidth < m_nNumWidht + 1; nCntWidth++)
		{
			pVtx[0].pos = MYLIB_3DVECTOR_ZERO;
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[0].col = m_col;
			pVtx[0].tex = D3DXVECTOR2(fTexWidth*nCntWidth, (float)nCntHeight);
			pVtx++;
		}
	}
	// 頂点データをアンロック
	m_pVtexBuff->Unlock();
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// インデックス情報の作成
//-------------------------------------------------------------------------------------------------------------
HRESULT COrbit::MakeIndex(LPDIRECT3DDEVICE9 pDevice)
{
	// インデックスバッファの生成
	if ((FAILED(pDevice->CreateIndexBuffer(
		sizeof(WORD) * m_nNumIndex,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&m_pIdxBuff,
		NULL))))
	{
		std::cout << "COrbit == インデックス情報の作成に失敗しました\n";
		return E_FAIL;
	}

	// インデックスデータへのポインタ
	WORD *pIdx;

	// インデックスバッファをロックし、インデックスバッファのポインタ取得
	m_pIdxBuff->Lock(0, 0, (void**)&pIdx, 0);

	// インデックスの設定
	// 奥行の個数
	for (int nCntVertical = 0; nCntVertical < ORBIT_NUM_HEIGHT; nCntVertical++)
	{
		// 最初だけはいらないようにするため
		if (nCntVertical > 0)
		{
			// 縮退ポリゴン分
			pIdx[0] = (nCntVertical*(m_nNumWidht + 1) + m_nNumWidht + 1);
			pIdx++;
		}
		// 横の個数
		for (int nCntInd = 0; nCntInd < m_nNumWidht + 1; nCntInd++)
		{
			// 縮退ポリゴンを除いた分
			pIdx[0] = nCntVertical*(m_nNumWidht + 1) + nCntInd + m_nNumWidht + 1;
			pIdx[1] = nCntVertical*(m_nNumWidht + 1) + nCntInd;
			pIdx += 2;
		}
		// 最後だけ入らないようにする
		if (nCntVertical <ORBIT_NUM_HEIGHT - 1)
		{
			// 縮退ポリゴン分
			pIdx[0] = (nCntVertical*(m_nNumWidht + 1) + m_nNumWidht);
			pIdx++;
		}
	}

	// インデックスバッファをアンロック
	m_pIdxBuff->Unlock();
	return S_OK;
}

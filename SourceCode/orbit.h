//*************************************************************************************************************
//
// 軌道処理 [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _ORBIT_H_
#define _ORBIT_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class COrbit :public CScene
{
public:
	COrbit(CScene::PRIORITY priority);	// コンストラクタ
	COrbit();						// コンストラクタ
	~COrbit();						// デストラクタ
	// 生成
	static COrbit *Create(D3DXMATRIX *pMtxParent,int nNumWidht,D3DXVECTOR2 size ,int nTextureID, D3DXCOLOR &col);
	// 情報の設定
	void SetInfo(D3DXMATRIX *pMtxParent, int nNumWidht, D3DXVECTOR2 size , D3DXCOLOR &col);
	void Init(void);		// 初期化
	void Uninit(void);		// 終了
	void Update(void);		// 更新
	void Draw(void);		// 描画
	// 描画開始
	void DrawStart(void);
	// 描画終了
	void DrawEnd(void);
	// テクスチャ情報の拘束
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
private:
	/* -- メンバ関数 -- */
	HRESULT MakeVatex(LPDIRECT3DDEVICE9 pDevice);		// 頂点情報の作成
	HRESULT MakeIndex(LPDIRECT3DDEVICE9 pDevice);		// インデックス情報の作成

	/* -- メンバ変数 -- */
	LPDIRECT3DTEXTURE9		m_pTexture = NULL;	// テクスチャのポインタ
	LPDIRECT3DVERTEXBUFFER9	m_pVtexBuff = NULL;	// 頂点バッファのポインタ
	LPDIRECT3DINDEXBUFFER9	m_pIdxBuff = NULL;	// インデックスのバッファのポインタ
	D3DXVECTOR3				m_pos;				// 位置
	D3DXVECTOR3				m_rot;				// 向き(回転)
	D3DXVECTOR2				m_size;
	bool					m_bDisp;			// 描画フラグ

	D3DXMATRIX				m_mtxWorld;			// ワールドマトリックス
	D3DXVECTOR3				*m_pPosOld;			// 前回の位置
	D3DXVECTOR3				*m_pPosEdgeOld;		// 切っ先の前回の位置
	D3DXMATRIX				*m_pMtxParent;		// 親のマトリックス情報

	D3DXVECTOR3				m_posEdge;			// 端の位置

	D3DXVECTOR3				m_posOriggin;		// 原点
	int						m_nNumWidht;		// 横の個数
	int						m_nNumVertex;		// 総頂点数
	int						m_nNumIndex;		// 総インデックス数
	int						m_nNumPolygon;		// 総ポリゴン数

	D3DXCOLOR				m_col;				// 色の設定
};

#endif
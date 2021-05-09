//*************************************************************************************************************
//
// シーン2D処理[scene2D.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Scene.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CScene2D :public CScene
{
public:
	// 構造体定義
	typedef struct UPDATEFLAG
	{
		union {
			struct {
				bool pos : 1;
				bool col : 1;
				bool tex : 1;
			};
			UINT data;
		};
	} UPDATEFLAG;

	CScene2D(CScene::PRIORITY priority);											// コンストラクタ
	~CScene2D();																	// デストラクタ

	static CScene2D *Create(														// 生成
		CScene::PRIORITY priority,													// 描画優先順位
		D3DXVECTOR3      pos,														// 位置
		D3DXCOLOR        col,														// 色
		ORIGINVERTEXTYPE OriginType,												// 原点タイプ
		D3DXVECTOR2      size,														// 大きさ
		float            fRadius = 0.0f,											// 半径
		float            fRotation = 0.0f,											// 回転量
		SETING_UV        TexUVInfo = SETING_UV(0, 1, 0, 1));						// テクスチャUV設定

	static CScene2D *Create(														// 生成
		CScene::PRIORITY priority,													// 描画優先順位
		D3DXVECTOR3      pos,														// 位置
		ORIGINVERTEXTYPE OriginType,												// 色
		D3DXVECTOR2      size,														// サイズ
		float            fRadius = 0.0f);											// 半径

	void Init(void);																// 初期化
	void Uninit(void);																// 終了
	void Update(void);																// 更新
	void Draw(void);																// 描画

	void UpdateVertex(																// 頂点の更新
		D3DXVECTOR3 *pPos = NULL,													// 位置のポインタ
		D3DXVECTOR2 *pSize = NULL,													// 大きさのポインタ
		float       *pRadius = NULL,												// 半径のポインタ
		D3DXCOLOR   *pCol = NULL,													// 色のポインタ
		SETING_UV   *pTexVari = NULL);												// UV座標設定のポインタ

	void UpdateVertex(																// 頂点の更新
		bool bUpdatePos = false,													// 位置更新フラグ
		bool bUpdateCol = false,													// 色更新フラグ
		bool bUpdateUVTex = false);													// UV座標更新フラグ

	void                    ChangeVertexOrigin(ORIGINVERTEXTYPE OriginType);		// 原点の変更
	void                    BindTexture(LPDIRECT3DTEXTURE9 pTexture);				// テクスチャを関連付ける
	LPDIRECT3DVERTEXBUFFER9 GetpVtxBuff(void);										// 頂点バッファの取得
	void                    SetOriginType(ORIGINVERTEXTYPE OriginType);				// 原点タイプの設定
	ORIGINVERTEXTYPE*       GetOriginType(void);									// 原点タイプの取得
	void                    SetPosition(D3DXVECTOR3& pos);							// 位置の設定
	D3DXVECTOR3*            GetPosition(void);										// 位置の取得
	void                    SetColor(D3DXCOLOR& col);								// 色の設定
	D3DXCOLOR*              GetColor(void);											// 色の取得
	void                    SetSize(D3DXVECTOR2& size);								// 大きさの設定
	void                    SetSizeX(float fSize);									// 大きさXの設定
	void                    SetSizeY(float fSize);									// 大きさYの設定
	D3DXVECTOR2*            GetSize(void);											// 大きさの取得
	void                    SetRotation(float fRotation);							// 回転量の設定
	float                   GetRotation(void);										// 回転量の取得
	inline void             SetDisp(const bool bDisp) { m_bDisp = bDisp; }
	inline bool &           GetDisp(void) { return m_bDisp; }
protected:
	/* -- メンバ関数 -- */
	HRESULT                 MakeVatex(LPDIRECT3DDEVICE9 pDevice);					// 頂点の作成
	void                    SetVatexPosition(CRenderer::VERTEX_2D *pVtx);			// 頂点位置の設定
	void                    SetVatexColor(CRenderer::VERTEX_2D *pVtx);				// 頂点カラーの設定
	void                    SetVatexTexture(CRenderer::VERTEX_2D *pVtx);			// 頂点テクスチャの設定

	/* -- メンバ変数 -- */
	LPDIRECT3DTEXTURE9      m_pTexture;												// テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;												// 頂点バッファへのポインタ
	UPDATEFLAG              m_UpdateFlags;											// 更新フラグ
	ORIGINVERTEXTYPE        m_OriginType;											// 原点の種類
	D3DXVECTOR3             m_pos;													// 位置
	D3DXCOLOR               m_col;													// 色
	D3DXVECTOR2             m_size;													// 大きさ
	float                   m_fRotation;											// 回転量
	bool                    m_bDisp;												// 描画フラグ
};

#endif
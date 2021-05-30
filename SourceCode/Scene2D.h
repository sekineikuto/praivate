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

	CScene2D(CScene::PRIORITY priority);															// コンストラクタ
	~CScene2D();																					// デストラクタ

	static CScene2D *Create(																		// 生成
		CScene::PRIORITY priority,																	// 描画優先順位
		D3DXVECTOR3      pos,																		// 位置
		D3DXVECTOR2      size,																		// 大きさ
		D3DXCOLOR        col,																		// 色
		float            fRotation = 0.0f,															// 回転量
		ORIGINVERTEXTYPE OriginType = ORIGINVERTEXTYPE_CENTER,										// 原点タイプ
		SETING_UV        TexUVInfo = SETING_UV(0, 1, 0, 1));										// テクスチャUV設定

	void Init(void);																				// 初期化
	void Uninit(void);																				// 終了
	void Update(void);																				// 更新
	void Draw(void);																				// 描画

	void UpdateVertex(																				// 頂点の更新
		bool bUpdatePos = false,																	// 位置更新フラグ
		bool bUpdateCol = false,																	// 色更新フラグ
		bool bUpdateUVTex = false);																	// UV座標更新フラグ

	void                    ChangeVertexOrigin(CONST ORIGINVERTEXTYPE OriginType);					// 原点の変更

	LPDIRECT3DVERTEXBUFFER9 GetpVtxBuff(void) const;												// 頂点バッファの取得
	void                    BindTexture(LPDIRECT3DTEXTURE9 pTexture);								// テクスチャを関連付ける

	void                    SetOriginType(CONST ORIGINVERTEXTYPE OriginType);						// 原点タイプの設定
	ORIGINVERTEXTYPE        GetOriginType(void) const;												// 原点タイプの取得
	ORIGINVERTEXTYPE&       GetOriginTypeRef(void);													// 原点タイプ参照の取得
	ORIGINVERTEXTYPE*       GetOriginTypePtr(void);													// 原点タイプポインタの取得

	void                    SetPosition(CONST D3DXVECTOR3& pos);									// 位置の設定
	void                    SetPosition(const float x, const float y, const float z);				// 位置の設定
	void                    SetPositionX(const float x);											// 位置Xの設定
	void                    SetPositionY(const float y);											// 位置Yの設定
	void                    SetPositionZ(const float z);											// 位置Zの設定
	D3DXVECTOR3             GetPosition(void) const;												// 位置の取得
	D3DXVECTOR3&            GetPositionRef(void);													// 位置参照の取得
	D3DXVECTOR3*            GetPositionPtr(void);													// 位置ポインタの取得

	void                    SetColor(CONST D3DXCOLOR& col);											// 色の設定
	void                    SetColor(const float r, const float g, const float b, const float a);	// 色の設定
	void                    SetColorR(const float r);												// 色Rの設定
	void                    SetColorG(const float g);												// 色Gの設定
	void                    SetColorB(const float b);												// 色Bの設定
	void                    SetColorA(const float a);												// 色Aの設定
	D3DXCOLOR               GetColor(void) const;													// 色の取得
	D3DXCOLOR&              GetColorRef(void);														// 色参照の取得
	D3DXCOLOR*              GetColorPtr(void);														// 色ポインタの取得

	void                    SetSize(CONST D3DXVECTOR2& size);										// 大きさの設定
	void                    SetSize(const float x, const float y);									// 大きさの設定
	void                    SetSizeX(const float x);												// 大きさXの設定
	void                    SetSizeY(const float y);												// 大きさYの設定
	D3DXVECTOR2*            GetSize(void);															// 大きさの取得

	void                    SetRotation(float fRotation);											// 回転量の設定
	float                   GetRotation(void);														// 回転量の取得
	float&                  GetRotationRef(void);													// 回転量参照の取得
	float*                  GetRotationPtr(void);													// 回転量ポインタの取得

	void                    SetDisp(const bool bDisp);												// 描画フラグの設定
	bool                    GetDisp(void);															// 描画フラグの取得
	bool&                   GetDispRef(void);														// 描画フラグ参照の取得
	bool*                   GetDispPtr(void);														// 描画フラグポインタの取得

protected:
	/* -- メンバ関数 -- */
	HRESULT                 MakeVatex(LPDIRECT3DDEVICE9 pDevice);									// 頂点の作成
	void                    SetVatexPosition(CRenderer::VERTEX_2D *pVtx);							// 頂点位置の設定
	void                    SetVatexColor(CRenderer::VERTEX_2D *pVtx);								// 頂点カラーの設定
	void                    SetVatexTexture(CRenderer::VERTEX_2D *pVtx);							// 頂点テクスチャの設定

	/* -- メンバ変数 -- */
	LPDIRECT3DTEXTURE9      m_pTexture;																// テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;																// 頂点バッファへのポインタ
	UPDATEFLAG              m_UpdateFlags;															// 更新フラグ
	ORIGINVERTEXTYPE        m_OriginType;															// 原点の種類
	D3DXVECTOR3             m_pos;																	// 位置
	D3DXCOLOR               m_col;																	// 色
	D3DXVECTOR2             m_size;																	// 大きさ
	float                   m_fRotation;															// 回転量
	bool                    m_bDisp;																// 描画フラグ
};

#endif
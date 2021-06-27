//*************************************************************************************************************
//
// シーン処理[scene.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _SCENE_H_
#define _SCENE_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "renderer.h"
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define NUM_SCENE2D			(100)						// Scene2Dの個数

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CScene
{
public:
	typedef enum
	{
		TYPE_BG = 0,		// 背景
		TYPE_FIELD,			// フィールド
		TYPE_BLOCK,			// ブロック
		TYPE_CHARACTER,		// キャラクター
		TYPE_3DOBJECT,		// 3Dオブジェクト
		TYPE_WALL,			// 壁
		TYPE_BULLET,		// 弾
		TYPE_DEADLY,		// 必殺エフェクト
		TYPE_BOSS,			// ボス
		TYPE_ENEMY,			// エネミー
		TYPE_PLAYER,		// プレイヤー
		TYPE_EFFECT,		// エフェクト
		TYPE_PARTICLE,		// パーティクル
		TYPE_HP,			// HP
		TYPE_SCORE,			// スコア
		TYPE_BUTTON,		// ボタン
		TYPE_COLLIDER,		// コライダー
		TYPE_UI,			// UI
		TYPE_MAX			// 最大数
	} TYPE;
	typedef enum
	{
		PRIORITY_NONE = -1,		// 無し
		PRIORITY_3DMODEL,		// 3Dモデル
		PRIORITY_FIELD,			// フィールド
		PRIORITY_SHADOW,		// 影
		PRIORITY_3DUI,			// 3DUI
		PRIORITY_3DCOLLIDER,	// 3Dコライダー
		PRIORITY_3DEFFECT,		// 3Dエフェクト
		PRIORITY_BG,			// 2D背景
		PRIORITY_2DUI,			// 2DUI
		PRIORITY_2DEFFECT,		// 2Dエフェクト
		PRIORITY_MAX,			// 最大数
	}PRIORITY;

	CScene(PRIORITY priority);				// コンストラクタ
	virtual ~CScene();						// デストラクタ

	virtual void   Init(void) = 0;			// 初期化処理
	virtual void   Uninit(void) = 0;		// 終了処理
	virtual void   Update(void) = 0;		// 更新処理
	virtual void   Draw(void) = 0;			// 描画処理

	static void    UpdataAll(void);			// 全ての更新処理
	static void    DrawAll(void);			// 全ての描画処理
	static void    ReleaseAll(void);		// 全ての開放処理

	void           Release(void);			// 開放処理
	void           ListRelease(void);		// リストからの開放処理

	inline void SetObjectType(TYPE type)    { m_type = type; }			// 種類の設定
	inline TYPE GetObjectType(void)         { return m_type; }			// 種類の取得
	inline static int GetNumAll(void)       { return m_nNumAll; }		// 全ての生成された数
	inline PRIORITY GetPriority(void)       { return m_priority; }		// シーンの描画優先順の取得

private:
protected:
	static int     m_nNumAll;					// 総シーン数
	static CScene* m_pTop[PRIORITY_MAX];		// 先頭へのオブジェクトポインタ
	static CScene* m_pCur[PRIORITY_MAX];		// 最後尾オブジェクトへのポインタ
	PRIORITY       m_priority;					// 描画優先順
	TYPE           m_type;						// オブジェクトの種類
	CScene*        m_pPrev;						// 前のオブジェクトへのポインタ
	CScene*        m_pNext;						// 次のオブジェクトへのポインタ
	bool           m_bDie;						// 死亡フラグ
};

#endif
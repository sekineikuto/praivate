//*************************************************************************************************************
//
// モデル処理[Model.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _MODEL_H_
#define _MODEL_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CModel
{
public:
	enum
	{
		CHARMODEL_NONE = -1,		// 無し
		CHARMODEL_WAIST,			// 腰
		CHARMODEL_BODY,				// 体
		CHARMODEL_RIGHTUPPERARM,	// 右上腕
		CHARMODEL_RIGHTFOREARM,		// 右前腕
		CHARMODEL_RIGHTHAND,		// 右手
		CHARMODEL_RIGHTTHIGH,		// 右腿
		CHARMODEL_RIGHTLEG,			// 右脚
		CHARMODEL_LEFTUPPERARM,		// 左上腕
		CHARMODEL_LEFTFOREARM,		// 左前腕
		CHARMODEL_LEFTHAND,			// 左手
		CHARMODEL_LEFTTHIGH,		// 左腿
		CHARMODEL_LEFTLEG,			// 左脚
		CHARMODEL_WEAPON,			// 武器
		CHARMODEL_MAX				// 最大数
	};
	enum
	{
		WEAPON_NONE = -1,		// 無し
		WEAPON_SWORD,			// 剣
		WEAPON_SPEAR,			// 槍
		WEAPON_AXE,				// 斧
		WEAPON_MAX				// 最大数
	};
	enum
	{
		MODELBOT_NONE = -1,			// 無し
		MODELBOT_BODY,				// 体
		MODELBOT_MAX				// 最大
	};
	enum
	{
		MODEL3DOBJECT_NONE = -1,	// 無し
		MODEL3DOBJECT_ROCK000,		// 岩中ぐらい
		MODEL3DOBJECT_ROCK001,		// 岩小さい
		MODEL3DOBJECT_ROCK002,		// 岩大きい
		MODEL3DOBJECT_Wood000,		// 木(生きてる)
		MODEL3DOBJECT_Wood001,		// 木(死んでる)
		MODEL3DOBJECT_SCREEN,		// スクリーン
		MODEL3DOBJECT_MALL,			// モール
		MODEL3DOBJECT_ARROWSIGN,	// 矢印
		MODEL3DOBJECT_MAX			// 最大数
	};
	enum
	{
		ATTACBULLET_NONE = -1,	// 無し
		ATTACBULLET_SWORD,		// 剣
		ATTACBULLET_SPEAR,		// 槍
		ATTACBULLET_AXE,		// 斧
		ATTACBULLET_BOT,		// ボット
		ATTACBULLET_MAX			// 最大数
	};
	enum
	{
		DEADLY_NONE = -1,	// 無し
		DEADLY_SWORD000,	// 剣(刀身)
		DEADLY_SWORD001,	// 剣(波動)
		DEADLY_SPEAR000,	// 槍(槍)
		DEADLY_AXE000,		// 斧(波動1)
		DEADLY_AXE001,		// 斧(波動2)
		DEADLY_MAX			// 最大数
	};
	enum
	{
		TOP_NONE        = -1,									// 無し
		TOP_PLAYER      = 0,									// プレイヤー
		TOP_ENEMY       = CHARMODEL_MAX - 1,					// エネミー
		TOP_WEAPON      = TOP_ENEMY + CHARMODEL_MAX - 1,		// 武器
		TOP_BOT         = TOP_WEAPON + WEAPON_MAX,				// ボット
		TOP_3DOBJECT    = TOP_BOT + MODELBOT_MAX,				// 3Dオブジェクト
		TOP_ATTACBULLET = TOP_3DOBJECT + MODEL3DOBJECT_MAX,		// 攻撃用の球
		TOP_DEADLY      = TOP_ATTACBULLET + ATTACBULLET_MAX,	// 必殺
		TOP_MAX         = TOP_DEADLY + DEADLY_MAX,				// 最大数
	};

	typedef struct MODEL
	{
		void release(void);				// 開放処理
		LPD3DXMESH		pMesh;			// メッシュ情報のポインタ
		LPD3DXBUFFER	pBuffMat;		// マテリアル情報のポインタ
		DWORD			nNumMat;		// マテリアルの数
		D3DXVECTOR3		vtxMax;			// 最大頂点
		D3DXVECTOR3		vtxMin;			// 最小頂点
		int				*pTextureID;	// テクスチャID
	} MODEL;

	typedef struct
	{
		TRANSFORM Trans;		// 位置,回転などの情報
		int       nIdentifier;	// ID、識別番号
		bool      bDisp;		// 描画フラグ
		CModel*   pParent;		// 親モデルのポインタ
	} SETINGINITMODEL;

	typedef SETINGINITMODEL MODELPARAM;

	CModel();																												// コンストラクタ
	~CModel() {}																											// デストラクタ
	static void                Load(void);																					// モデルの読み込み
	static void                Unload(void);																				// モデルの開放
	static CModel*             Create(int nID, TRANSFORM &Trans);															// 生成
	static CModel*             Create(SETINGINITMODEL &pInitInfo);															// 生成

	void                       Init(SETINGINITMODEL &pInitInfo);															// 初期化
	void                       Init(int nModelID);																			// 初期化
	void                       Uninit(void);																				// 終了
	void                       Update(void);																				// 更新
	void                       Draw(void);																					// 描画

	/* インライン関数 */
	inline static CONST MODEL& GetModelInfo(int nID)            { return m_AllModelInfo[nID]; }								// 全てのモデル情報からの取得
	inline static CONST_STRING GetFileName(int nID)             { return m_FileName[nID].Get(); }							// ファイル名の取得
	inline static const int&   GetNumAllModel(void)             { return m_nNumAllModel; }									// 全モデル個数の取得
	inline void                SetTrans(CONST TRANSFORM &Trans) { m_Param.Trans = Trans; }										// トランス情報の設定
	inline TRANSFORM&          GetTrans(void)                   { return m_Param.Trans; }											// トランス情報の取得
	inline void                SetTrans(CONST MODEL &Model)     { m_Model = Model; }										// モデル情報の設定
	inline MODEL&              GetModel(void)                   { return m_Model; }											// モデル情報の取得
	inline void                SetParent(CONST CModel* pParent) { m_Param.pParent = (CModel*)pParent; }							// 親モデルのポインタの設定
	inline CModel&	           GetParent(void)                  { return *m_Param.pParent; }										// 親モデルのポインタの取得
	inline void                SetID(const int &nID)            { m_Param.nIdentifier = nID; }									// ID、識別番号の設定
	inline int&                GetID(void)                      { return m_Param.nIdentifier; }									// ID、識別番号の取得
	inline void                SetDisp(CONST bool &bDisp)       { m_Param.bDisp = bDisp; }										// 描画フラグの設定
	inline bool&               GetDisp(void)                    { return m_Param.bDisp; }											// 描画フラグの取得
	inline void                ChangeDisp(void)                 { m_Param.bDisp ^= 1; }											// 描画フラグの変更
private:
	/* -- メンバ関数 -- */
	static void                LoadModelFromX(void);																		// モデルをXファイルから読み込む
	static void                GetResource(void);																			// 資源の調達
	static void                GetMaxMinVertices(MODEL& Model);																// 最大最小の頂点位置の取得
	static void                GetTextureIDfrom_Xfile(MODEL& Model, CONST_STRING sFileName);								// Xファイルから取得したテクスチャからIDの取得する
	static void                SetTextureID(int& nTextureID, CONST_STRING sFileName);
	static void                ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);	// 1行から情報を読み取る
	static void                NumLoad(CONST_STRING cnpLine);																// 個数の読み込み
	static void                FileNameLoad(CONST_STRING cnpLine);															// ファイル名の読み込み

	/* -- メンバ変数 -- */
	static MyVector<MODEL>   m_AllModelInfo;	// 全てのモデル情報
	static MyVector<CString> m_FileName;		// ファイル名のポインタ
	static int               m_nNumAllModel;	// 全モデル個数
	LPDIRECT3DTEXTURE9       m_pTexture;		// テクスチャのポインタ
	MODEL                    m_Model;			// モデルの情報ポインタ
	MODELPARAM               m_Param;			// モデルのパラメータ
};

#endif
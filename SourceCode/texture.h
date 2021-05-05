//*************************************************************************************************************
//
// テクスチャ処理[texture.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CTexture
{
public:
	enum
	{
		NAME_NONE = -1,					// 無し
		// 汎用テクスチャ
		NAME_NUMBER,					// 数字							number000.png
		NAME_LOCK_ON,					// ロックオン					Lock-on000.png
		// ゲーム用テクスチャ
		NAME_TIMER,						// タイマー　					TIMER000.png
		NAME_GAGE,						// ゲージ						Gage000.png
		NAME_FRAME,						// 枠							Frame000.png
		NAME_READY,						// READY?						ready000.png
		NAME_START,						// START!						start000.png
		NAME_FINISH,					// FINISH!						finish000.png
		// タイトル用テクスチャ
		NAME_TITLENAME,					// ネコ型ロボット大戦			TitleName000.png
		NAME_PLEASEENTER,				// スタートEnterを押してくださいPleasestartbuttonorenter000.png
		// チュートリアル用テクスチャ
		NAME_GAMEPADKEYBOARD,			// ゲームパッド / キーボード	amepadAndKeyboard000.png
		NAME_MOVEOPERATION,				// 移動説明						MovementOperationExplanation000.png
		NAME_CAMERAMOVEOPERATION,		// カメラ移動説明				ExplanationOfCameraMovementOperation000.png
		NAME_JUMPOPERATION,				// ジャンプ操作説明				JumpOperationExplanation000.png
		NAME_BOOSTOPERATION,			// ブースト操作説明				BoostOperatingInstructions000.png
		NAME_ATTACKPERATION,			// 攻撃操作説明					AttackOperationExplanation000.png
		NAME_SPATTACKERATION,			// 特殊攻撃操作説明				SpecialAttackOperationExplanation000.png
		NAME_CHARGEOPERATION,			// チャージ操作説明				OperationExplanationOfCharge000.png
		NAME_CAMERAREPAIROPERATION,		// カメラ直し操作説明			OperatingInstructionsForCameraRepair000.png
		NAME_DEATHBLOWOPERATION,		// 必殺技操作説明				OperationalInstructionsForTheSpecialMove000.png
		NAME_LOCK_ONOPERATION,			// ロックオンオフ操作説明		Lock - onOperationDescription000.png
		NAME_LOCK_ONSWITCHOPERATION,	// ロックオン切り替え操作説明	Lock - onSwitchingOperationDescription000.png
		NAME_MAGMAFLOOROPERATION,		// マグマの床説明				DescriptionOfMagmaFloor1000.png
		// リザルト用テクスチャ
		NAME_BATTLERESULT,				// 先頭結果						battleresult000.png
		NAME_RESULTITEM,				// 結果項目						resultItem000.png
		NAME_VERSUS,					// 対							versus.png
		NAME_CONNECTOR,					// で							Connector.png
		NAME_WINS,						// が勝つ						Wins000.png
		NAME_CAT,						// ネコ							cat000.png
		NAME_MOUSE,						// ネズミ						mouse000.png
		NAME_DRAW,						// 引き分け						draw000.png
		// 選択画面用テクスチャ
		NAME_SCREEN_VOLCANO,			// 火山スクリーン用				Volcano.jpg
		NAME_WINDOW,					// ウィンドウUI					window000.png
		NAME_ITEMWINDOW0,				// 項目用ウィンドウUI(白)		itemwindow000.png
		NAME_ITEMWINDOW1,				// 項目用ウィンドウUI(灰)		itemwindow001.png
		NAME_PLAYER,					// プレイイヤーUI(文字)			PLAYER000.png
		NAME_ENEMY,						// エネミーUI(文字)				ENEMY000.png
		NAME_WEAPON,					// 武器UI(文字)					WEAPON000.png
		NAME_SWORD,						// 剣UI(文字)					sword000.png
		NAME_SPEAR,						// 槍UI(文字)					spear000.png
		NAME_AXE,						// 斧UI(文字)					axe000.png
		NAME_MAP,						// マップUI(文字)				MAP000.png
		NAME_VOLCANO000,				// VOLCANOUI(文字)				VOLCANO000.png
		NAME_WHERE_TO_START,			// WHERE_TO_START(文字)			WHERE_TO_START000.png
		NAME_TUTORIAL,					// TUTORIAL(文字)				TUTORIAL000.png
		NAME_BATTLE,					// BATTLE(文字)					BATTLE000.png
		NAME_1_ENEMY,					// 敵の体数(1人)				1_Enemy000.png
		NAME_2_ENEMY,					// 敵の体数(2人)				2_Enemy000.png
		NAME_3_ENEMY,					// 敵の体数(3人)				3_Enemy000.png
		NAME_RIGHT_ARROWSIGN,			// 右矢印						Right_Arrowsign000.png
		NAME_LEFT_ARROWSIGN,			// 左矢印						Left_Arrowsign000.png
		NAME_OPERATION_KEY000,			// キーボードでの選択操作説明	Keyoperation000.png
		NAME_OPERATION_KEY001,			// キーボードでの選択操作説明	Keyoperation001.png
		NAME_OPERATION_PAD000,			// ゲームパッドでの選択操作説明	Padoperation000.png
		NAME_OPERATION_PAD001,			// ゲームパッドでの選択操作説明	Padoperation001.png
		// メッシュ用テクスチャ
		NAME_MAGUMA0,					// マグマ(熱)					maguma.jpg
		NAME_MAGUMA1,					// マグマ(冷)					maguma002.jpg
		NAME_TILE,						// 石のタイル					tile000.jpg
		NAME_SKY,						// 空(曇った)					sky002.jpg
		// エフェクト用テクスチャ
		NAME_EFFECT0,					// 粒子							Effect000.jpg
		NAME_EFFECT1,					// 波							Effect001.jpg
		NAME_EFFECT2,					// 波(二重)						Effect002.jpg
		NAME_EFFECT3,					// 発光体						Effect003.jpg
		// 軌跡用テクスチャ
		NAME_ORBIT0,					// 軌跡(剣)						orbit000.jpg
		NAME_ORBIT1,					// 軌跡(槍)						orbit001.jpg
		NAME_ORBIT2,					// 軌跡(斧)						orbit002.jpg
		NAME_ORBIT3,					// 軌跡(真っ白)					orbit003.pos
		// 壁用テクスチャ
		NAME_WALLSKIN,					// ボーダー						wallsukin.png
		NAME_MAX						// 最大数
	};
	enum
	{
		TEXTURE_TOPID_NONE     = -1,						// 無し
		TEXTURE_TOPID_UI       = NAME_NUMBER,				// UIの先頭
		TEXTURE_TOPID_GAME     = NAME_TIMER,				// ゲームUIの先頭
		TEXTURE_TOPID_TITLE    = NAME_TITLENAME,			// タイトルUIの先頭
		TEXTURE_TOPID_TUTORIAL = NAME_GAMEPADKEYBOARD,		// チュートリアルの先頭
		TEXTURE_TOPID_RESULT   = NAME_BATTLERESULT,			// リザルトの先頭
		TEXTURE_TOPID_SELECT   = NAME_SCREEN_VOLCANO,		// 選択の先頭
		TEXTURE_TOPID_MESH     = NAME_MAGUMA0,				// メッシュの先頭
		TEXTURE_TOPID_EFFECT   = NAME_EFFECT0,				// エフェクトの先頭
		TEXTURE_TOPID_ORBIT    = NAME_ORBIT0,				// 軌跡
		TEXTURE_TOPID_MAX      = NAME_MAX,					// 最大数
	};
	CTexture();																												// コンストラクタ
	~CTexture();																											// デストラクタ
	static void               Load(void);																					// 読み込み
	static void               Unload(void);																					// 開放
	static void               CreateTexture(void);																			// テクスチャの生成
	static LPDIRECT3DTEXTURE9 GetTextureInfo(int nIndex);																	// テクスチャの取得
	static int                GetNumTextureMax(void);																		// テクスチャ数の最大
	static void               GetFileName(const int nIndex, STRING output);													// ファイル名の取得
	static CONST_STRING       GetFileName(const int nIndex);																// ファイル名の取得
private:
	/* メンバ関数 */
	static void               GetResource(void);																			// 資源の調達
	static void               ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);		// 1行から情報を読み取る
	static void               NumLoad(CONST_STRING cnpLine);																// 個数の読み込み
	static void               FileNameLoad(CONST_STRING cnpLine);															// ファイル名の読み込み
	/* メンバ変数 */
	static MyVector<LPDIRECT3DTEXTURE9> m_pTexture;																			// テクスチャ情報のポインタ
	static MyVector<CString>            m_pFileName;																		// ファイル名のポインタ
	static int                          m_nNumTextureMax;																	// 最大テクスチャ数
};
#endif

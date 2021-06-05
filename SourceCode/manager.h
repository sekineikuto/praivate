//*************************************************************************************************************
//
// マネージャ処理[manager.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _MANAGER_H_
#define _MANAGER_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "sound.h"
#include "DebugProc.h"
#include "keyboard.h"
#include "mouse.h"
#include "gamepad.h"
#include "camera.h"
#include "Light.h"
#include "Mylibrary.h"
#include <unordered_map>

//-------------------------------------------------------------------------------------------------------------
// エイリアス宣言
//-------------------------------------------------------------------------------------------------------------
using hash_map = std::unordered_map<std::string, int>;

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CSound;
class CMouse;
class Ckeyboard;
class CDebugProc;
class CRenderer;
class CCamera;
class CLight;
class CGamepad;
class CHash;
class CMode;
class CTextureManager;
class CManager
{
public:
	typedef enum
	{
		FILE_NONE = -1,		// 無し
		FILE_SOUND,			// サウンド
		FILE_CHARACTERINFO,	// キャラクター情報
		FILE_CHARAMOTION,	// キャラクターモーション
		FILE_BOTINFO,		// ボットの情報
		FILE_MESHFIELD,		// メッシュフィールド
		FILE_MODEL,			// モデル
		FILE_COLLIDER,		// 衝突判定
		FILE_MAP,			// マップ
		FILE_TITLEUI,		// タイトルUI
		FILE_SELECTUI,		// 選択モードUI
		FILE_TUTORIALUI,	// チュートリアルUI
		FILE_GAMEUI,		// ゲームUI
		FILE_RESULTUI,		// リザルトUI
		FILE_PARTICLE,		// パーティクル
		FILE_TEXTURE,		// テクスチャ
		FILE_MAX			// 最大数
	} FILE_NAME;

	typedef enum
	{
		MODE_NONE = 0,		// 無し
		MODE_TITLE,			// タイトル
		MODE_SELECT,		// 選択
		MODE_TUTORIAL,		// チュートリアル
		MODE_GAME,			// ゲーム
		MODE_RESULT,		// リザルト
		MODE_MAX			// 最大
	} MODE;

	/* -- メンバ関数 -- */
	CManager();																								// コンストラクタ
	~CManager();																							// デストラクタ
	HRESULT Init(HINSTANCE hInstance ,HWND hWnd, BOOL bWindow);										// 初期化
	void Uninit(void);																				// 終了
	void Update(void);																				// 更新
	void Draw(void);																					// 描画
	static void SetHash(void);																				// ハッシュを設定
	static void UnsetHash(void);																				// ハッシュの初期化
	static void LoadInitFile(void);																			// 初期化ファイルの読み込み
	static void ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData);	// 1行から情報を読み取る
	static STRING GetFIleName(CManager::FILE_NAME FileIndex);												// ファイル名の取得
	static void SceneAllReleaseAndSoundStop(void);															// シーンの開放処理とサウンドの停止
	static void SetMode(MODE mode);																			// モードの設定

	/*　インライン関数 */
	static MODE       GetMode(void)               { return m_mode; }			// モードの取得
	static MODE&      GetModeRef(void)            { return m_mode; }			// モード参照の取得
	static MODE*      GetModePtr(void)            { return &m_mode; }			// モーポインタの取得

	static CRenderer& GetRenderer(void)           { return m_Renderer; }		// レンダラー参照の取得
	static CRenderer& GetRendererRef(void)        { return m_Renderer; }		// レンダラー参照の取得
	static CRenderer* GetRendererPtr(void)        { return &m_Renderer; }		// レンダラーポインタの取得

	static Ckeyboard& GetKeyboard(void)           { return m_Keyboard; }		// キーボード参照の取得
	static Ckeyboard& GetKeyboardRef(void)        { return m_Keyboard; }		// キーボード参照の取得
	static Ckeyboard* GetKeyboardPtr(void)        { return &m_Keyboard; }		// キーボードポインタの取得

	static CGamepad&  GetGamepad(void)            { return m_Gamepad; }			// ゲームパッドの取得
	static CGamepad&  GetGamepadRef(void)         { return m_Gamepad; }			// ゲームパッドの取得
	static CGamepad*  GetGamepadPtr(void)         { return &m_Gamepad; }			// ゲームパッドの取得

	static CMouse&    GetMouse(void)              { return m_Mouse; }			// マウスの取得
	static CMouse&    GetMouseRef(void)           { return m_Mouse; }			// マウスの取得
	static CMouse*    GetMousePtr(void)           { return &m_Mouse; }			// マウスの取得

	static CCamera&   GetCamera(void)             { return m_Camera; }			// カメラの取得
	static CCamera&   GetCameraRef(void)          { return m_Camera; }			// カメラの取得
	static CCamera*   GetCameraPtr(void)          { return &m_Camera; }			// カメラの取得

	static CLight&    GetLight(void)              { return m_Light; }			// ライトの取得
	static CLight&    GetLightRef(void)           { return m_Light; }			// ライトの取得
	static CLight*    GetLightPtr(void)           { return &m_Light; }			// ライトの取得

	static CSound&    GetSound(void)              { return m_Sound; }			// サウンドの取得
	static CSound&    GetSoundRef(void)           { return m_Sound; }			// サウンドの取得
	static CSound*    GetSoundPtr(void)           { return &m_Sound; }			// サウンドの取得

	static CMode&     GetModeClass(void)          { return *m_pModeClass; }		// モードクラスの取得
	static CMode*     GetModeClassPtr(void)       { return m_pModeClass; }		// モードクラスの取得

	static void       SetTotalScore(const int nMyScore) { m_nMyScore = nMyScore; }	// トータルスコアの設定
	static int        GetTotalScore(void)         { return m_nMyScore; }		// トータルスコアの取得
	static int&       GetTotalScoreRef(void)      { return m_nMyScore; }		// トータルスコアの取得
	static int*       GetTotalScorePtr(void)      { return &m_nMyScore; }		// トータルスコアの取得

	static CTextureManager* GetTextureManager(void) { return m_pTextureManager; }

#ifdef _DEBUG
	void SetFPS(int nFps);												// FPSの設定
#endif
private:
	/* -- メンバ変数 -- */
	static CRenderer	m_Renderer;						// レンダラーポインタ
	static Ckeyboard	m_Keyboard;						// キーボードのポインタ
	static CMouse		m_Mouse;							// マウスのポインタ
	static CGamepad		m_Gamepad;						// ゲームパッドのポインタ
	static CSound		m_Sound;							// サウンドのポインタ
	static CDebugProc	m_DebugProc;						// デバッグ処理のポインタ
	static CCamera		m_Camera;							// カメラのポインタ
	static CLight		m_Light;							// ライトのポインタ
	static STRING		m_aFIleName[FILE_NAME::FILE_MAX];	// ファイル名(.iniから読みこんだファイル)
	static MODE			m_mode;								// モード
	static int			m_nMyScore;							// スコア保存
	static CHash		m_Hash;							// ハッシュポインタ
	static CMode*		m_pModeClass;					// モードクラスのポインタ
	static CTextureManager * m_pTextureManager;			// テクスチャマネージャー
	static hash_map*	m_pSeting_map;	// 設定用のハッシュマップ
protected:
};

#endif
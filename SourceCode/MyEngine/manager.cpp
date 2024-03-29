//*************************************************************************************************************
//
// マネージャ処理[manager.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "manager.h"
#include "Scene.h"
#include "..\myhash.h"
#include "renderer.h"
#include "..\Model.h"
#include "mode.h"
#include "..\title.h"
#include "..\TextureManager.h"
#include "..\TextfileController.h"

//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
CRenderer			CManager::m_Renderer                          = MYLIB_INITSTRUCT_WITHCONST;	// レンダラーポインタ
Ckeyboard			CManager::m_Keyboard                          = MYLIB_INITSTRUCT_WITHCONST;	// キーボードのポインタ
CMouse				CManager::m_Mouse                             = MYLIB_INITSTRUCT_WITHCONST;	// マウスのポインタ
CGamepad			CManager::m_Gamepad                           = MYLIB_INITSTRUCT_WITHCONST;	// ゲームパッドのポインタ
CSound				CManager::m_Sound                             = MYLIB_INITSTRUCT_WITHCONST;	// サウンドのポインタ
CDebugProc			CManager::m_DebugProc                         = MYLIB_INITSTRUCT_WITHCONST;	// デバッグ処理のポインタ
CCamera				CManager::m_Camera                            = MYLIB_INITSTRUCT_WITHCONST;	// カメラのポインタ
CLight				CManager::m_Light                             = MYLIB_INITSTRUCT_WITHCONST;	// ライトのポインタ
STRING				CManager::m_aFIleName[FILE_NAME::FILE_MAX]    = MYLIB_INITSTRUCT_WITHCONST;	// ファイル名(.iniから読みこんだファイル)
CManager::MODE		CManager::m_mode                              = CManager::MODE_NONE;		// モード
int					CManager::m_nMyScore                          = MYLIB_INT_UNSET;			// スコア保存
CHash				CManager::m_Hash                              = MYLIB_INITSTRUCT_WITHCONST;	// ハッシュポインタ
CMode*				CManager::m_pModeClass                        = nullptr;					// モードクラスのポインタ
CTextureManager*	CManager::m_pTextureManager                   = nullptr;					// テクスチャマネージャーのポインタ
hash_map*			CManager::m_pSeting_map                       = nullptr;					// 設定用ハッシュマップ

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CManager::CManager()
{

}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
CManager::~CManager()
{

}

//-------------------------------------------------------------------------------------------------------------
// 初期化処理
//-------------------------------------------------------------------------------------------------------------
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	// 初期化処理（ウィンドウの生成後に行う）
	if (FAILED(m_Renderer.Init(hWnd, bWindow)))
	{
		return -1;
	}
	// ハッシュテーブルの作成
	m_Hash.MakeHashtable();
	// ハッシュの設定
	SetHash();

	// 初期化ファイルの読み込み
	LoadInitFile();

	// キーボードの初期化初期化
	m_Keyboard.Init(hInstance, hWnd);
	// マウスの初期化
	m_Mouse.Init(hInstance, hWnd);

	// ゲームパッドの初期化
	m_Gamepad.Init(hInstance, hWnd);

	// サウンドの初期化
	m_Sound.InitSound(hWnd,m_aFIleName[FILE_NAME::FILE_SOUND]);
	// カメラの初期化
	m_Camera.Init();
	// ライトの生成
	m_Light.Init();

#ifdef _DEBUG
	// デバッグの生成
	m_DebugProc.Init();
#endif // _DEBUG

	// テクスチャマネージャー生成
	m_pTextureManager = CTextureManager::Create();
	// モデルの読み込み
	//CModel::Load();
	return S_OK;
}

//-------------------------------------------------------------------------------------------------------------
// 終了処理
//------------------------------------------------------------------------------------------------------------
void CManager::Uninit(void)
{
	// シーンの開放処理とサウンドの停止
	SceneAllReleaseAndSoundStop();
	// モデルの開放
	//CModel::Unload();
	// テクスチャマネージャーの開放
	CTextureManager::Release(m_pTextureManager);
#ifdef _DEBUG
	// デバッグの終了処理
	m_DebugProc.Uninit();
#endif // _DEBUG

	// ライトの終了処理
	m_Light.Uninit();
	// カメラの終了処理
	m_Camera.Uninit();
	// サウンドの終了処理
	m_Sound.UninitSound();
	// ゲームパッドの終了処理
	m_Gamepad.Uninit();
	// マウスの終了処理
	m_Mouse.Uninit();
	// キーボードの終了処理
	m_Keyboard.Uninit();
	// ファイルの開放
	for (int nCntFiileName = 0; nCntFiileName < CManager::FILE_NAME::FILE_MAX; nCntFiileName++)
	{// ファイルの終了処理
		delete[] m_aFIleName[nCntFiileName];
		m_aFIleName[nCntFiileName] = nullptr;
	}
	// ハッシュの初期化
	UnsetHash();
	// ハッシュテーブルの開放
	m_Hash.ReleaseHashtable();
	// レンダラーの終了処理
	m_Renderer.Uninit();
}

//-------------------------------------------------------------------------------------------------------------
// 更新処理
//-------------------------------------------------------------------------------------------------------------
void CManager::Update(void)
{
	// キーボードの更新処理
	m_Keyboard.Update();
	// マウスの更新処理
	m_Mouse.Update();
	// ゲームパッドの更新処理
	m_Gamepad.Update();
	// カメラの更新処理
	m_Camera.Update();
	// ライトの更新処理
	m_Light.Update();

	if (m_mode != MODE_NONE)
	{
		// モードクラスの更新
		m_pModeClass->Update();
	}

	// レンダラーの更新処理
	m_Renderer.UpDate();
}

//-------------------------------------------------------------------------------------------------------------
// 描画処理
//-------------------------------------------------------------------------------------------------------------
void CManager::Draw(void)
{
	// モードクラスの更新
	m_pModeClass->Draw();
	// レンダラーの描画処理
	m_Renderer.Draw();
}

//-------------------------------------------------------------------------------------------------------------
// モードの切り替え
//-------------------------------------------------------------------------------------------------------------
void CManager::SetMode(MODE mode)
{
	// カメラの初期化
	m_Camera.Init();
	// ライトの方向を設定
	m_Light.SetDirection();

	// nullcheck
	if (m_pModeClass != nullptr)
	{// 終了処理
		m_pModeClass->Uninit();
		// 破棄
		delete m_pModeClass;
		m_pModeClass = nullptr;
	}

	// モードを設定
	m_mode = mode;
	switch (m_mode)
	{
	case MODE_TITLE:
		m_pModeClass = CTitle::Create();
		break;
	case MODE_SELECT:
		break;
	case MODE_TUTORIAL:
		break;
	case MODE_GAME:
		break;
	case MODE_RESULT:
		break;
	}
}

#ifdef _DEBUG
//-------------------------------------------------------------------------------------------------------------
// FPSの設定
//-------------------------------------------------------------------------------------------------------------
void CManager::SetFPS(int fps)
{
	m_Renderer.SetFPS(fps);
}
#endif


//-------------------------------------------------------------------------------------------------------------
// ハッシュの設定
//-------------------------------------------------------------------------------------------------------------
void CManager::SetHash(void)
{
	// 設定用ハッシュマップの作成
	m_pSeting_map = new std::unordered_map<std::string, int>
	{
		{ "SOUND"      , 0 },
		{ "CHARACTER"  , 1 },
		{ "CHARAMOTION", 2 },
		{ "BOTINFO"    , 3 },
		{ "MESHFIELD"  , 4 },
		{ "MODEL"      , 5 },
		{ "COLLIDERL"  , 6 },
		{ "MAP"        , 7 },
		{ "TITLEUI"    , 8 },
		{ "SELECT"     , 9 },
		{ "TUTORIALUI" , 10 },
		{ "GAMEUI"     , 11 },
		{ "RESULTUI"   , 12 },
		{ "PARTICLE"   , 13 },
		{ "TEXTURE"    , 14 },
	};
}

//-------------------------------------------------------------------------------------------------------------
// ハッシュの初期化
//-------------------------------------------------------------------------------------------------------------
void CManager::UnsetHash(void)
{
	// 設定用ハッシュマップのクリア
	m_pSeting_map->clear();
	// 破棄
	delete m_pSeting_map;
	m_pSeting_map = nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化ファイルの読み込み
//-------------------------------------------------------------------------------------------------------------
void CManager::LoadInitFile(void)
{
	std::unordered_map<std::string, int> & seting_map = *m_pSeting_map;

	mystd::CLoadInitFile::LoadFile("DATA/TEXT/GameManager.ini",
		[&seting_map]
		(mystd::CLoadInitFile::READINFO& info)
	{
		// 変数宣言
		char SetingFileName[MYLIB_STRINGSIZE];	// 設定用ファイル名
		SetingFileName[0] = MYLIB_CHAR_UNSET;

		if (sscanf(info.line, "FILENAME = %s", &SetingFileName[0]) == 1)
		{
			// 配列番号の取得
			int nIndex = seting_map.at(info.entrydata);
			// 文字列の確保と設定
			m_aFIleName[nIndex] = CMylibrary::SetStringAlloc(SetingFileName);
		}
	});
}

//-------------------------------------------------------------------------------------------------------------
// 1行から情報を読み取る
//-------------------------------------------------------------------------------------------------------------
void CManager::ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData)
{
	// 変数宣言
	char SetingFileName[MYLIB_STRINGSIZE];	// 設定用ファイル名
	SetingFileName[0] = MYLIB_CHAR_UNSET;

	if (sscanf(cnpLine, "FILENAME = %s", &SetingFileName[0]) == 1)
	{
		// 配列番号の取得
		int nIndex = CMylibrary::GetConvertStoI(m_Hash.Search((char*)cnpEntryData));
		// 文字列の確保と設定
		m_aFIleName[nIndex] = CMylibrary::SetStringAlloc(SetingFileName);
	}
}

//-------------------------------------------------------------------------------------------------------------
// ファイル名
//-------------------------------------------------------------------------------------------------------------
STRING CManager::GetFIleName(CManager::FILE_NAME FileIndex)
{
	return m_aFIleName[FileIndex];
}

//-------------------------------------------------------------------------------------------------------------
// シーンの開放処理とサウンドの停止
//-------------------------------------------------------------------------------------------------------------
void CManager::SceneAllReleaseAndSoundStop(void)
{
	if (m_pModeClass != nullptr)
	{
		m_pModeClass->Uninit();
		delete m_pModeClass;
		m_pModeClass = nullptr;
	}
	// サウンドを停止
	m_Sound.StopSound();
	// 全ての開放処理
	CScene::ReleaseAll();
}

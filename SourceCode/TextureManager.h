//*************************************************************************************************************
//
// テクスチャマネージャー処理[TextureManager.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "mystd\types.h"
#include "TextfileController.h"
#include <vector>
#include <iostream>
#include "d3dx9.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CTextureManager
{
public:
	/* メンバ関数 */
	CTextureManager();													// コンストラクタ
	~CTextureManager();													// デストラクタ

	static CTextureManager* Create(void);								// 作成
	static void Release(CTextureManager * src);							// 開放

	void               Load(void);										// 読み込み
	void               Unload(void);									// 開放
	LPDIRECT3DTEXTURE9 GetTextureInfo(int nIndex);						// テクスチャの取得
	int                GetNumTextureMax(void);							// テクスチャ数の最大
	CSTRING            GetFileName(const int nIndex);					// ファイル名の取得
private:
	/* メンバ関数 */
	static void ReadFromLine(CLoadInitFile::READINFO& info, std::vector<std::string> *filename);	// 1行ずつ読み込む

	/* メンバ変数 */
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;							// テクスチャ情報のポインタ
	std::vector<std::string>        m_pFileName;						// ファイル名のポインタ
	int                             m_nNumTextureMax;					// 最大テクスチャ数
};
#endif
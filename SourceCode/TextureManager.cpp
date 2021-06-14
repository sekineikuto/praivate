//*************************************************************************************************************
//
// テクスチャマネージャー処理[TextureManager.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "TextureManager.h"
#include "manager.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CTextureManager::CTextureManager()
{
}

//-------------------------------------------------------------------------------------------------------------
// デストラクタ
//-------------------------------------------------------------------------------------------------------------
CTextureManager::~CTextureManager()
{
	Unload();
}

//-------------------------------------------------------------------------------------------------------------
// 作成
//-------------------------------------------------------------------------------------------------------------
CTextureManager * CTextureManager::Create(void)
{
	CTextureManager * ptr = new CTextureManager;
	ptr->Load();
	return ptr;
}

//-------------------------------------------------------------------------------------------------------------
// 開放
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Release(CTextureManager * src)
{
	if (src == nullptr)
		return;
	delete src;
	src = nullptr;
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャ情報のロード
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Load(void)
{
	// 変数宣言
	LPDIRECT3DDEVICE9 pDevice;						// デバイスのポインタ
	pDevice = CManager::GetRenderer().GetDevice();		// デバイスの取得

	// テクスチャ名を取得
	mystd::CLoadInitFile::LoadFile(CManager::GetFIleName(CManager::FILE_TEXTURE), &m_pFileName, ReadFromLine);

	// テクスチャ名の数要素を増やす
	m_pTexture.reserve(m_pFileName.size());

	// テクスチャを作成
	for (std::string str : m_pFileName)
	{
		LPDIRECT3DTEXTURE9 SetingTexture;
		// テクスチャの読み込み
		if (D3DXCreateTextureFromFile(pDevice, str.data(), &SetingTexture) != D3D_OK)
		{

		}
		// 要素の挿入
		m_pTexture.push_back(SetingTexture);
	}

	m_nNumTextureMax = m_pTexture.size();
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャ情報をアンロード
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::Unload(void)
{
	// ファイル名を削除
	for (auto & str : m_pFileName)
	{
		str.clear();
		str.shrink_to_fit();
	}
	m_pFileName.clear();
	m_pFileName.shrink_to_fit();

	// テクスチャ情報の開放
	for (auto& texture : m_pTexture)
	{
		if (texture != nullptr)
		{
			texture->Release();
			texture = nullptr;
		}
	}

	m_pTexture.clear();
	m_pTexture.shrink_to_fit();
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャ情報の取得
//-------------------------------------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 CTextureManager::GetTextureInfo(int nIndex)
{
	return m_pTexture[nIndex];
}

//-------------------------------------------------------------------------------------------------------------
// 最大テクスチャ数の取得
//-------------------------------------------------------------------------------------------------------------
int CTextureManager::GetNumTextureMax(void)
{
	return m_nNumTextureMax;
}

//-------------------------------------------------------------------------------------------------------------
// ファイル名の取得
//-------------------------------------------------------------------------------------------------------------
_MYSTD CSTRING CTextureManager::GetFileName(const int nIndex)
{
	return m_pFileName[nIndex].data();
}

//-------------------------------------------------------------------------------------------------------------
// 一行から読み取る
//-------------------------------------------------------------------------------------------------------------
void CTextureManager::ReadFromLine(mystd::CLoadInitFile::READINFO & info, std::vector<std::string>* filename)
{
	char aData[128] = { '\0' };
	int nNumber = 0;

	if (info.entrydata == nullptr ||
		info.entrydata == nullptr)
	{
		return;
	}

	if (sscanf(info.line, "FILENAME = %s", &aData[0]) == 1)
	{
		filename->push_back(std::string(aData));
	}
	else if (sscanf(info.line, "NUMBER = %d", &nNumber) == 1)
	{
		// 内容量を変更する
		filename->reserve(nNumber);
	}
}

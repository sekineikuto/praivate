//*************************************************************************************************************
//
// モデル処理[Model.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Model.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define MODEL_INITVTXMAX	D3DXVECTOR3(-10000.0f, -10000.0f, -10000.0f)	// ほぼ確実に代入されるものを設定する
#define MODEL_INITVTXMIN	D3DXVECTOR3(10000.0f, 10000.0f, 10000.0f)		// ほぼ確実に代入されるものを設定する

//-------------------------------------------------------------------------------------------------------------
// 静的メンバ変数の初期化
//-------------------------------------------------------------------------------------------------------------
MyVector<CModel::MODEL> CModel::m_AllModelInfo = {};
MyVector<CString>       CModel::m_FileName = {};
int                     CModel::m_nNumAllModel = MYLIB_INT_UNSET;	// 全モデル個数

//-------------------------------------------------------------------------------------------------------------
// コンストラクタ
//-------------------------------------------------------------------------------------------------------------
CModel::CModel()
{
}

//-------------------------------------------------------------------------------------------------------------
// 読み込み
//-------------------------------------------------------------------------------------------------------------
void CModel::Load(void)
{
	// モデルをXファイルから読み込む
	LoadModelFromX();
}

//-------------------------------------------------------------------------------------------------------------
// 開放
//-------------------------------------------------------------------------------------------------------------
void CModel::Unload(void)
{
	// モデル情報分ループ
	for (int nCntModel = 0; nCntModel < m_nNumAllModel; nCntModel++)
	{
		// メッシュポインタがnullじゃない時
		if (m_AllModelInfo[nCntModel].pMesh != nullptr)
		{// メッシュ情報の開放
			m_AllModelInfo[nCntModel].pMesh->Release();
			m_AllModelInfo[nCntModel].pMesh = nullptr;
		}
		// マテリアルポインタがnullじゃない時
		if (m_AllModelInfo[nCntModel].pBuffMat != nullptr)
		{// マテリアル情報の開放
			m_AllModelInfo[nCntModel].pBuffMat->Release();
			m_AllModelInfo[nCntModel].pBuffMat = nullptr;
		}
		// テクスチャIDポインタがnullptrじゃない時
		if (m_AllModelInfo[nCntModel].pTextureID != nullptr)
		{// テクスチャIDの破棄
			delete[] m_AllModelInfo[nCntModel].pTextureID;
			m_AllModelInfo[nCntModel].pTextureID = nullptr;
		}
	}
	// 情報のクリア
	m_AllModelInfo.clear();

	// ファイル名のクリア
	m_FileName.clear();
}

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CModel * CModel::Create(int nID, TRANSFORM &Trans)
{
	// オブジェクトの生成
	CModel* pModel = new CModel;
	// 初期化
	pModel->Init(nID);
	// トランス情報の設定
	pModel->SetTrans(Trans);
	return pModel;
}

//-------------------------------------------------------------------------------------------------------------
// 生成
//-------------------------------------------------------------------------------------------------------------
CModel * CModel::Create(SETINGINITMODEL & pInitInfo)
{
	// オブジェクトの生成
	CModel* pModel = new CModel;
	// 初期化
	pModel->Init(pInitInfo);
	return pModel;
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CModel::Init(SETINGINITMODEL & pInitInfo)
{
}

//-------------------------------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------------------------------
void CModel::Init(int nModelID)
{
	// モデル情報を代入
	m_Model = m_AllModelInfo[nModelID];
	// モデルIDを設定
	m_Param.nIdentifier = nModelID;
	// 親のポインタの初期化
	m_Param.pParent = nullptr;
	// 描画フラグの初期化
	m_Param.bDisp = true;
}

//-------------------------------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------------------------------
void CModel::Uninit(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------------------------------
void CModel::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 描画
//-------------------------------------------------------------------------------------------------------------
void CModel::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// モデルをXファイルから読み込む
//-------------------------------------------------------------------------------------------------------------
void CModel::LoadModelFromX(void)
{
	// 変数宣言
	LPDIRECT3DDEVICE9	pDevice;						// デバイスのポインタ
	pDevice = CManager::GetRenderer().GetDevice();		// デバイスの取得

	// 資源の調達
	GetResource();

	// モデル個数分ループ
	for (int nCntModelName = 0; nCntModelName < m_nNumAllModel; nCntModelName++)
	{
		// 設定用モデル情報
		MODEL SetingModel;
		SetingModel.pTextureID = NULL;
		// Xファイルの読み込み
		if (FAILED(D3DXLoadMeshFromX(m_FileName[nCntModelName].Get(),
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&SetingModel.pBuffMat,
			NULL,
			&SetingModel.nNumMat,
			&SetingModel.pMesh)))
		{
			MessageBox(NULL, "モデルの生成に失敗しました", "警告！", MB_ICONWARNING);
			std::cout << "Model.cpp == " << nCntModelName + 1 << "つ目のモデル失敗しました\n";
			std::cout << "Model.cpp == " << nCntModelName << " < " << m_nNumAllModel << "\n";
		}
		// 最大最小の頂点のサイズを取得する
		GetMaxMinVertices(SetingModel);
		// Xファイルから取得したテクスチャからIDの取得する
		GetTextureIDfrom_Xfile(SetingModel, m_FileName[nCntModelName].Get());
		// モデルの情報に追加する
		m_AllModelInfo.insert(m_AllModelInfo.end(), SetingModel);
	}

}

//-------------------------------------------------------------------------------------------------------------
// 資源の調達
//-------------------------------------------------------------------------------------------------------------
void CModel::GetResource(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// 最大最小の頂点位置の取得
//-------------------------------------------------------------------------------------------------------------
void CModel::GetMaxMinVertices(MODEL& Model)
{
	// 変数宣言
	int	  nNumVertices;		// 頂点数
	DWORD sizeFVF;			// 頂点フォーマットサイズ
	BYTE* pVertexBuffer;	// 頂点バッファのポインタ

	Model.vtxMax = MODEL_INITVTXMAX;
	Model.vtxMin = MODEL_INITVTXMIN;

	// 頂点情報取得
	nNumVertices = Model.pMesh->GetNumVertices();
	// 頂点フォーマットのサイズの取得
	sizeFVF = D3DXGetFVFVertexSize(Model.pMesh->GetFVF());

	// 頂点バッファをロック
	Model.pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertexBuffer);

	for (int nCntModel = 0; nCntModel < nNumVertices; nCntModel++)
	{// 頂点情報の取得
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVertexBuffer;
		// 全ての最小値、最大値を抜き取る
		// 最小
		if (Model.vtxMin.x > vtx.x)Model.vtxMin.x = vtx.x;
		if (Model.vtxMin.y > vtx.y)Model.vtxMin.y = vtx.y;
		if (Model.vtxMin.z > vtx.z)Model.vtxMin.z = vtx.z;
		// 最大
		if (Model.vtxMax.x < vtx.x)Model.vtxMax.x = vtx.x;
		if (Model.vtxMax.y < vtx.y)Model.vtxMax.y = vtx.y;
		if (Model.vtxMax.z < vtx.z)Model.vtxMax.z = vtx.z;

		pVertexBuffer += sizeFVF;		// サイズ分ポインタを進める
	}

	// 頂点データをアンロックする
	Model.pMesh->UnlockVertexBuffer();
}

//-------------------------------------------------------------------------------------------------------------
// Xファイルから取得したテクスチャからIDの取得する
//-------------------------------------------------------------------------------------------------------------
void CModel::GetTextureIDfrom_Xfile(MODEL & Model, CONST_STRING sFileName)
{
	// バッファの先頭ポインタをD3DXMATERIALにキャストして取得
	D3DXMATERIAL* materials = (D3DXMATERIAL*)Model.pBuffMat->GetBufferPointer();

	// 設定用ファイル名
	MyVector<CString> SetingFileName;

	// カウントマテリアル
	for (int nCntMat = 0; nCntMat < (int)Model.nNumMat; nCntMat++)
	{
		// ファイル名が存在している時
		if (materials[nCntMat].pTextureFilename == nullptr)
		{
			continue;
		}
		SetingFileName.push_back();
		CString *pBack = &SetingFileName.back();
		pBack->Set(strstr(materials[nCntMat].pTextureFilename, "TEXTURE"));
	}

	// 設定するサイズ
	int nSetingSize = SetingFileName.size();

	// テクスチャIDの生成
	Model.pTextureID = new int[nSetingSize];

	// テクスチャIDの設定
	for (int nCntSet = 0; nCntSet < nSetingSize; nCntSet++)
	{
		SetTextureID(Model.pTextureID[nCntSet], SetingFileName[nCntSet].Get());
	}

	// 設定用ファイル名の開放
	for (int nCntSet = 0; nCntSet < nSetingSize; nCntSet++)
	{
		SetingFileName[nCntSet].release();
	}
	
	// 設定用のファイル名のクリア
	SetingFileName.clear();
}

//-------------------------------------------------------------------------------------------------------------
// テクスチャIDの設定
//-------------------------------------------------------------------------------------------------------------
void CModel::SetTextureID(int& nTextureID, CONST_STRING sFileName)
{
	//for (int nCntTexture = 0; nCntTexture < CTexture::TEXTURE_TOPID_MAX; nCntTexture++)
	//{
	//	if (strcmp(sFileName, CTexture::GetFileName(nCntTexture)) == 0)
	//	{
	//		nTextureID = nCntTexture;
	//	}
	//}
}

//-------------------------------------------------------------------------------------------------------------
// 1行から情報を読み取る
//-------------------------------------------------------------------------------------------------------------
void CModel::ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData)
{
	if (strcmp("NUMBER", cnpEntryData) != 0)
	{// ファイル名の読み込み
		FileNameLoad(cnpLine);
	}
	else
	{// 個数の読み込み
		NumLoad(cnpLine);
	}
}

//-------------------------------------------------------------------------------------------------------------
// 個数の読み込み
//-------------------------------------------------------------------------------------------------------------
void CModel::NumLoad(CONST_STRING cnpLine)
{
	// 変数宣言
	int nSetingNumber = 0;	// 設定用個数

	if (sscanf(cnpLine, "NUMBER = %d", &nSetingNumber) == 1)
	{
		// テクスチャ
		m_nNumAllModel = nSetingNumber;
		// 内容量を増やす
		m_FileName.reserve(m_nNumAllModel);
		m_AllModelInfo.reserve(m_nNumAllModel);
	}
}

//-------------------------------------------------------------------------------------------------------------
// ファイル名の読み込み
//-------------------------------------------------------------------------------------------------------------
void CModel::FileNameLoad(CONST_STRING cnpLine)
{
	// 変数宣言
	char aSetingFileName[MYLIB_STRINGSIZE];			// 設定用ファイル名
	aSetingFileName[0] = MYLIB_CHAR_UNSET;
	if (sscanf(cnpLine, "FILENAME = %s", aSetingFileName) == 1)
	{
		// 要素を尾末に挿入
		m_FileName.push_back();
		// 尾末ポインタの取得
		CString *pBack = &m_FileName.back();
		// 尾末要素に文字列の設定
		pBack->Set(aSetingFileName);
	}
}

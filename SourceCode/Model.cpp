//*************************************************************************************************************
//
// ���f������[Model.cpp]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "Model.h"
#include "renderer.h"

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define MODEL_INITVTXMAX	D3DXVECTOR3(-10000.0f, -10000.0f, -10000.0f)	// �قڊm���ɑ���������̂�ݒ肷��
#define MODEL_INITVTXMIN	D3DXVECTOR3(10000.0f, 10000.0f, 10000.0f)		// �قڊm���ɑ���������̂�ݒ肷��

//-------------------------------------------------------------------------------------------------------------
// �ÓI�����o�ϐ��̏�����
//-------------------------------------------------------------------------------------------------------------
MyVector<CModel::MODEL> CModel::m_AllModelInfo = {};
MyVector<CString>       CModel::m_FileName = {};
int                     CModel::m_nNumAllModel = MYLIB_INT_UNSET;	// �S���f����

//-------------------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------------------------------------------------
CModel::CModel()
{
}

//-------------------------------------------------------------------------------------------------------------
// �ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CModel::Load(void)
{
	// ���f����X�t�@�C������ǂݍ���
	LoadModelFromX();
}

//-------------------------------------------------------------------------------------------------------------
// �J��
//-------------------------------------------------------------------------------------------------------------
void CModel::Unload(void)
{
	// ���f����񕪃��[�v
	for (int nCntModel = 0; nCntModel < m_nNumAllModel; nCntModel++)
	{
		// ���b�V���|�C���^��null����Ȃ���
		if (m_AllModelInfo[nCntModel].pMesh != nullptr)
		{// ���b�V�����̊J��
			m_AllModelInfo[nCntModel].pMesh->Release();
			m_AllModelInfo[nCntModel].pMesh = nullptr;
		}
		// �}�e���A���|�C���^��null����Ȃ���
		if (m_AllModelInfo[nCntModel].pBuffMat != nullptr)
		{// �}�e���A�����̊J��
			m_AllModelInfo[nCntModel].pBuffMat->Release();
			m_AllModelInfo[nCntModel].pBuffMat = nullptr;
		}
		// �e�N�X�`��ID�|�C���^��nullptr����Ȃ���
		if (m_AllModelInfo[nCntModel].pTextureID != nullptr)
		{// �e�N�X�`��ID�̔j��
			delete[] m_AllModelInfo[nCntModel].pTextureID;
			m_AllModelInfo[nCntModel].pTextureID = nullptr;
		}
	}
	// ���̃N���A
	m_AllModelInfo.clear();

	// �t�@�C�����̃N���A
	m_FileName.clear();
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CModel * CModel::Create(int nID, TRANSFORM &Trans)
{
	// �I�u�W�F�N�g�̐���
	CModel* pModel = new CModel;
	// ������
	pModel->Init(nID);
	// �g�����X���̐ݒ�
	pModel->SetTrans(Trans);
	return pModel;
}

//-------------------------------------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------------------------------------
CModel * CModel::Create(SETINGINITMODEL & pInitInfo)
{
	// �I�u�W�F�N�g�̐���
	CModel* pModel = new CModel;
	// ������
	pModel->Init(pInitInfo);
	return pModel;
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CModel::Init(SETINGINITMODEL & pInitInfo)
{
}

//-------------------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------------------
void CModel::Init(int nModelID)
{
	// ���f��������
	m_Model = m_AllModelInfo[nModelID];
	// ���f��ID��ݒ�
	m_Param.nIdentifier = nModelID;
	// �e�̃|�C���^�̏�����
	m_Param.pParent = nullptr;
	// �`��t���O�̏�����
	m_Param.bDisp = true;
}

//-------------------------------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------------------------------
void CModel::Uninit(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �X�V
//-------------------------------------------------------------------------------------------------------------
void CModel::Update(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �`��
//-------------------------------------------------------------------------------------------------------------
void CModel::Draw(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// ���f����X�t�@�C������ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CModel::LoadModelFromX(void)
{
	// �ϐ��錾
	LPDIRECT3DDEVICE9	pDevice;						// �f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer().GetDevice();		// �f�o�C�X�̎擾

	// �����̒��B
	GetResource();

	// ���f���������[�v
	for (int nCntModelName = 0; nCntModelName < m_nNumAllModel; nCntModelName++)
	{
		// �ݒ�p���f�����
		MODEL SetingModel;
		SetingModel.pTextureID = NULL;
		// X�t�@�C���̓ǂݍ���
		if (FAILED(D3DXLoadMeshFromX(m_FileName[nCntModelName].Get(),
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&SetingModel.pBuffMat,
			NULL,
			&SetingModel.nNumMat,
			&SetingModel.pMesh)))
		{
			MessageBox(NULL, "���f���̐����Ɏ��s���܂���", "�x���I", MB_ICONWARNING);
			std::cout << "Model.cpp == " << nCntModelName + 1 << "�ڂ̃��f�����s���܂���\n";
			std::cout << "Model.cpp == " << nCntModelName << " < " << m_nNumAllModel << "\n";
		}
		// �ő�ŏ��̒��_�̃T�C�Y���擾����
		GetMaxMinVertices(SetingModel);
		// X�t�@�C������擾�����e�N�X�`������ID�̎擾����
		GetTextureIDfrom_Xfile(SetingModel, m_FileName[nCntModelName].Get());
		// ���f���̏��ɒǉ�����
		m_AllModelInfo.insert(m_AllModelInfo.end(), SetingModel);
	}

}

//-------------------------------------------------------------------------------------------------------------
// �����̒��B
//-------------------------------------------------------------------------------------------------------------
void CModel::GetResource(void)
{
}

//-------------------------------------------------------------------------------------------------------------
// �ő�ŏ��̒��_�ʒu�̎擾
//-------------------------------------------------------------------------------------------------------------
void CModel::GetMaxMinVertices(MODEL& Model)
{
	// �ϐ��錾
	int	  nNumVertices;		// ���_��
	DWORD sizeFVF;			// ���_�t�H�[�}�b�g�T�C�Y
	BYTE* pVertexBuffer;	// ���_�o�b�t�@�̃|�C���^

	Model.vtxMax = MODEL_INITVTXMAX;
	Model.vtxMin = MODEL_INITVTXMIN;

	// ���_���擾
	nNumVertices = Model.pMesh->GetNumVertices();
	// ���_�t�H�[�}�b�g�̃T�C�Y�̎擾
	sizeFVF = D3DXGetFVFVertexSize(Model.pMesh->GetFVF());

	// ���_�o�b�t�@�����b�N
	Model.pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertexBuffer);

	for (int nCntModel = 0; nCntModel < nNumVertices; nCntModel++)
	{// ���_���̎擾
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVertexBuffer;
		// �S�Ă̍ŏ��l�A�ő�l�𔲂����
		// �ŏ�
		if (Model.vtxMin.x > vtx.x)Model.vtxMin.x = vtx.x;
		if (Model.vtxMin.y > vtx.y)Model.vtxMin.y = vtx.y;
		if (Model.vtxMin.z > vtx.z)Model.vtxMin.z = vtx.z;
		// �ő�
		if (Model.vtxMax.x < vtx.x)Model.vtxMax.x = vtx.x;
		if (Model.vtxMax.y < vtx.y)Model.vtxMax.y = vtx.y;
		if (Model.vtxMax.z < vtx.z)Model.vtxMax.z = vtx.z;

		pVertexBuffer += sizeFVF;		// �T�C�Y���|�C���^��i�߂�
	}

	// ���_�f�[�^���A�����b�N����
	Model.pMesh->UnlockVertexBuffer();
}

//-------------------------------------------------------------------------------------------------------------
// X�t�@�C������擾�����e�N�X�`������ID�̎擾����
//-------------------------------------------------------------------------------------------------------------
void CModel::GetTextureIDfrom_Xfile(MODEL & Model, CONST_STRING sFileName)
{
	// �o�b�t�@�̐擪�|�C���^��D3DXMATERIAL�ɃL���X�g���Ď擾
	D3DXMATERIAL* materials = (D3DXMATERIAL*)Model.pBuffMat->GetBufferPointer();

	// �ݒ�p�t�@�C����
	MyVector<CString> SetingFileName;

	// �J�E���g�}�e���A��
	for (int nCntMat = 0; nCntMat < (int)Model.nNumMat; nCntMat++)
	{
		// �t�@�C���������݂��Ă��鎞
		if (materials[nCntMat].pTextureFilename == nullptr)
		{
			continue;
		}
		SetingFileName.push_back();
		CString *pBack = &SetingFileName.back();
		pBack->Set(strstr(materials[nCntMat].pTextureFilename, "TEXTURE"));
	}

	// �ݒ肷��T�C�Y
	int nSetingSize = SetingFileName.size();

	// �e�N�X�`��ID�̐���
	Model.pTextureID = new int[nSetingSize];

	// �e�N�X�`��ID�̐ݒ�
	for (int nCntSet = 0; nCntSet < nSetingSize; nCntSet++)
	{
		SetTextureID(Model.pTextureID[nCntSet], SetingFileName[nCntSet].Get());
	}

	// �ݒ�p�t�@�C�����̊J��
	for (int nCntSet = 0; nCntSet < nSetingSize; nCntSet++)
	{
		SetingFileName[nCntSet].release();
	}
	
	// �ݒ�p�̃t�@�C�����̃N���A
	SetingFileName.clear();
}

//-------------------------------------------------------------------------------------------------------------
// �e�N�X�`��ID�̐ݒ�
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
// 1�s�������ǂݎ��
//-------------------------------------------------------------------------------------------------------------
void CModel::ReadFromLine(CONST_STRING cnpLine, CONST_STRING cnpEntryType, CONST_STRING cnpEntryData)
{
	if (strcmp("NUMBER", cnpEntryData) != 0)
	{// �t�@�C�����̓ǂݍ���
		FileNameLoad(cnpLine);
	}
	else
	{// ���̓ǂݍ���
		NumLoad(cnpLine);
	}
}

//-------------------------------------------------------------------------------------------------------------
// ���̓ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CModel::NumLoad(CONST_STRING cnpLine)
{
	// �ϐ��錾
	int nSetingNumber = 0;	// �ݒ�p��

	if (sscanf(cnpLine, "NUMBER = %d", &nSetingNumber) == 1)
	{
		// �e�N�X�`��
		m_nNumAllModel = nSetingNumber;
		// ���e�ʂ𑝂₷
		m_FileName.reserve(m_nNumAllModel);
		m_AllModelInfo.reserve(m_nNumAllModel);
	}
}

//-------------------------------------------------------------------------------------------------------------
// �t�@�C�����̓ǂݍ���
//-------------------------------------------------------------------------------------------------------------
void CModel::FileNameLoad(CONST_STRING cnpLine)
{
	// �ϐ��錾
	char aSetingFileName[MYLIB_STRINGSIZE];			// �ݒ�p�t�@�C����
	aSetingFileName[0] = MYLIB_CHAR_UNSET;
	if (sscanf(cnpLine, "FILENAME = %s", aSetingFileName) == 1)
	{
		// �v�f������ɑ}��
		m_FileName.push_back();
		// �����|�C���^�̎擾
		CString *pBack = &m_FileName.back();
		// �����v�f�ɕ�����̐ݒ�
		pBack->Set(aSetingFileName);
	}
}

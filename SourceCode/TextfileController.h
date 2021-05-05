//*************************************************************************************************************
//
// �����̃��C�u�����̏���[Mylibrary.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _TEXTFILECONTROLLER_H_
#define _TEXTFILECONTROLLER_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>

typedef const char *       CONST_STRING;	// �ύX�s������
typedef char *             STRING;			// ������

typedef signed char        VSHORT;			// ��������1�o�C�g���̕ϐ�
typedef unsigned char      UVSHORT;			// �����Ȃ�1�o�C�g���̕ϐ�

typedef long long          VLONG;			// ��������8�o�C�g���̕ϐ�
typedef unsigned long long UVLONG;			// �����Ȃ�8�o�C�g���̕ϐ�

typedef const char *       FILE_NAME;		// �t�@�C����
typedef unsigned int       FILE_SIZE;		// �t�@�C���f�[�^�T�C�Y
typedef char *             FILE_DATA;		// �t�@�C���f�[�^
typedef const char *       OPEN_MODE;		// �t�@�C�����J�����[�h

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CLoadInitFile
{
public:
	// * [contents] �񋓌^��`
	// * [memo] 
	//   LOADRESULT -> LR
	//   MAKE -> M
	//   BUFFER -> B
	enum LOADRESULT
	{
		LR_FAILURE = -1,		// ���s(�G���[)
		LR_SUCCESS,				// ����

		M_CREATE_FAIL,			// �쐬�Ɏ��s����
		M_OPEN_FAIL,			// �t�@�C�����J���Ȃ�����
		M_SIZE_FAIL,			// �T�C�Y�̎擾���s
		M_FILEDATA_FAIL,		// �t�@�C���f�[�^�̃G���[
		M_READ_FAIL,			// �ǂݍ��ݎ��s

		B_FAIL,					// �o�b�t�@�̈�擾�G���[
	};

	// �\���̒�`
	typedef struct READINFO
	{
	public:
		READINFO() {}
		READINFO(STRING in)
		{
			entrytype = entrydata = nullptr;
			line = in;
		}
		STRING entrytype;
		STRING entrydata;
		STRING line;
	} READINFO;

	// �R���X�g���N�^
	inline CLoadInitFile() {};
	// �f�X�g���N�^
	inline ~CLoadInitFile() {};

	// �t�@�C���̃��[�h
	template<class T, class F>
	inline static LOADRESULT LoadFile(FILE_NAME filename,T value, F func)
	{
		LOADRESULT result;
		CLoadInitFile Load;

		// �t�@�V�����𕶎���ɓǂݍ���
		if ((result = Load.LoadFileIntoString(filename)) != LR_SUCCESS)
			return result;

		// �����񂩂�ݒ肷��
		if ((result = Load.SetingfromString(value, func)) != LR_SUCCESS)
			return result;

		// �t�@�C���f�[�^�̔j��
		Load.DeleteFileData();

		return result;
	}

private:
	// �J��
	inline static void Release(CLoadInitFile *pClass)
	{
		if (pClass == nullptr)
			return;

		pClass->DeleteFileData();

		delete pClass;
		pClass = nullptr;
	}

	// �t�@�C���f�[�^�̍폜
	inline void DeleteFileData(void)
	{
		if (this->m_pFileData == nullptr)
			return;

		delete[] this->m_pFileData;
		this->m_pFileData = nullptr;
	}

	// �t�@�C����傫�����擾����
	inline UVLONG GetFileSize(FILE * pFile)
	{
		long lTop = 0;
		long lSize = 0;

		// �擪�̃t�@�C���ʒu���擾
		lTop = ftell(pFile);

		// (�t�@�C���ʒu���擾���� && �t�@�C���ʒu������ɐݒ�ɐ���)�����s������
		if ((lTop != -1 &&
			fseek(pFile, 0, SEEK_END) == 0) != 1)
		{
			return -1;
		}

		// �����̃t�@�C���ʒu�i�T�C�Y�j���擾
		lSize = ftell(pFile);

		// (�T�C�Y�̎擾���� && �t�@�C���ʒu��擪�ɐݒ�ɐ���)�����s������
		if ((lSize != -1 &&
			fseek(pFile, lTop, SEEK_SET) == 0) != 1)
		{
			return -1;
		}

		return (UVLONG)lSize;
	}

	// �t�@�C�����𕶎���ɓǂݍ���
	inline LOADRESULT LoadFileIntoString(FILE_NAME pFileName, OPEN_MODE Mode = "rb")
	{
		// �t�@�C�����J��
		FILE *pFile;
		if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

		// �t�@�C���T�C�Y�̎擾
		UVLONG uvlSize = GetFileSize(pFile);
		if (uvlSize == (UVLONG)-1) {
			fclose(pFile);
			return M_SIZE_FAIL;
		}

		// �t�@�C���f�[�^�̐���
		FILE_DATA pFileData = new char[(size_t)uvlSize];
		if (pFileData == nullptr) {
			fclose(pFile);
			return M_FILEDATA_FAIL;
		}

		// �t�@�C������ǂݍ���
		if ((UVLONG)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
			fclose(pFile);
			delete[]pFileData;
			return M_READ_FAIL;
		}

		// �t�@�C�������
		fclose(pFile);

		this->m_nuFileSize = (FILE_SIZE)uvlSize;
		this->m_pFileData = pFileData;

		return LR_SUCCESS;
	}

	// �����񂩂�ݒ�
	template<class T, class F>
	inline LOADRESULT SetingfromString(T value, F funk)
	{
		// �o�b�t�@�̗̈�m��
		STRING pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// �ǂݍ��񂾏��
		READINFO info = READINFO(pBuffe);
		STRING lineEnd = nullptr;

		// �o�b�t�@�̏I���n�_�܂Ń��[�v����
		for (info.line = pBuffe; info.line < pBuffeEnd; info.line = lineEnd + 1)
		{
			while (*info.line == '\n' || *info.line == '\r' || *info.line == '\t')++info.line;

			lineEnd = info.line;

			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')++lineEnd;

			lineEnd[0] = '\0';

			// 1�s�̍ŏ��� [ �Ōオ ] �̎�
			if (info.line[0] == '[' &&lineEnd > info.line &&lineEnd[-1] == ']')
			{
				lineEnd[-1] = '\0';

				CONST_STRING pDataEnd;		// �o�^�p�̃f�[�^�̍Ō�
				CONST_STRING pTypeStart;	// �o�^�p�̃^�C�v�̍ŏ�
				STRING       pTypeEnd;		// �o�^�p�̃^�C�v�̍Ō�
				CONST_STRING pDataStart;	// �o�^�p�̃f�[�^�̍ŏ�

				pDataEnd   = lineEnd - 1;															// �s�̍Ō��ݒ�
				pTypeStart = info.line + 1;															// �ŏ��� [ ���X�L�b�v
				pTypeEnd   = (STRING)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// �ŏ��� ] �܂ŃX�L�b�v
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2�ڂ� [ �܂ŃX�L�b�v

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// ��ڂ� ] ��������
				++pDataStart;		// ��ڂ� [ ���΂�

				info.entrytype = (STRING)(void*)pTypeStart;
				info.entrydata = (STRING)(void*)pDataStart;
			}

			// �o�^�f�[�^�̎擾������
			funk(info, value);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		return LR_SUCCESS;
	}

	// �C�ӂ̕����ȍ~�̕�������擾
	inline static CONST_STRING GetRangeStrfromChar(CONST_STRING cnStr, CONST_STRING cnStrEnd, char marker)
	{
		CONST_STRING cnRetStr = (CONST_STRING)memchr(cnStr, (int)marker, cnStrEnd - cnStr);
		return cnRetStr;
	}


	FILE_SIZE m_nuFileSize;	// �t�@�C���T�C�Y
	FILE_DATA m_pFileData;	// �t�@�C���f�[�^
};

#endif
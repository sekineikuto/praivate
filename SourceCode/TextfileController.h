//*************************************************************************************************************
//
// �����̃��C�u�����̏���[Mylibrary.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _TEXTFILECONTROLLER_H_
#define _TEXTFILECONTROLLER_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>
#include <vector>
#include "mystd\mystd.h"
#include "mystd\types.h"
#include <fstream>

//-------------------------------------------------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------------------------------------------------
#define TxtCtrlSkipCondition(chr) chr == '\n' || chr == '\r' || chr == '\t' || chr == ' ' || chr == '�@'

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// �^�錾
//-------------------------------------------------------------------------------------------------------------
typedef charptr_t    string_t;
typedef const char * const_string_t;

typedef const_string_t file_name_t;
typedef mystd::u32_t   file_size_t;
typedef string_t	   file_data_t;
typedef const_string_t open_mode_t;

//-------------------------------------------------------------------------------------------------------------
// �񋓌^��`
//-------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------
// �w���p�[�֐��Q
//-------------------------------------------------------------------------------------------------------------

// �t�@�C����傫�����擾����
inline u64_t GetFileSize(FILE * pFile)
{
	long lTop = 0;
	long lSize = 0;

	// �擪�̃t�@�C���ʒu���擾
	lTop = std::ftell(pFile);

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

	return (u64_t)lSize;
}

// �t�@�C�����𕶎���ɓǂݍ���
inline LOADRESULT LoadFileIntoString(file_name_t pFileName, file_size_t* outSize, file_data_t *outData, open_mode_t Mode = "rb")
{
	// �t�@�C�����J��
	FILE *pFile;
	if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

	// �t�@�C���T�C�Y�̎擾
	u64_t uvlSize = GetFileSize(pFile);
	if (uvlSize == (u64_t)-1) {
		fclose(pFile);
		return M_SIZE_FAIL;
	}

	// �t�@�C���f�[�^�̐���
	file_data_t pFileData = new char[(size_t)uvlSize];
	if (pFileData == nullptr) {
		fclose(pFile);
		return M_FILEDATA_FAIL;
	}

	// �t�@�C������ǂݍ���
	if ((u64_t)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
		fclose(pFile);
		delete[]pFileData;
		return M_READ_FAIL;
	}

	// �t�@�C�������
	fclose(pFile);

	*outSize = (file_size_t)uvlSize;
	*outData = pFileData;

	return LR_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
// �t�@�C�������擾����
//-------------------------------------------------------------------------------------------------------------
class CLoadFile
{
public:
	// �R���X�g���N�^
	CLoadFile() {}
	// �f�X�g���N�^
	~CLoadFile() {}

	// �t�@�C���𕪊����Ď擾����
	inline static LOADRESULT GetSplit(file_name_t filename, std::vector<std::string>& fileInfo)
	{
		// �ϐ��錾
		file_size_t nFileSize;	// �t�@�C���T�C�Y
		file_data_t pFileData = nullptr;			// �t�@�C���f�[�^
		LOADRESULT result;

		// �t�@�C�����𕶎���ɓǂݍ���
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// �o�b�t�@�̗̈�m��
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		string_t pBuffeEnd = pBuffe + nFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// �ǂݍ��񂾏��
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// �o�b�t�@�̏I���n�_�܂Ń��[�v����
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// �擪��end�ɐݒ�
			lineEnd = line;
			
			// end���s���܂ŃX�L�b�v
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// ���ɒǉ�
			fileInfo.push_back(line);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		if (pFileData != nullptr){
			delete[]pFileData;
			pFileData = nullptr;
		}

		return LR_SUCCESS;
	}

	// �P�s���擾���� 
	//$ function -> function(line, T value) { }
	template<class T, class F>
	inline static LOADRESULT GetLine(file_name_t filename, T value, F function)
	{
		// �ϐ��錾
		file_size_t nFileSize;			// �t�@�C���T�C�Y
		file_data_t pFileData = nullptr;	// �t�@�C���f�[�^
		LOADRESULT result;

		// �t�@�C�����𕶎���ɓǂݍ���
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// �o�b�t�@�̗̈�m��
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		string_t pBuffeEnd = pBuffe + nFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// �ǂݍ��񂾏��
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// �o�b�t�@�̏I���n�_�܂Ń��[�v����
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// �擪��end�ɐݒ�
			lineEnd = line;

			// end���s���܂ŃX�L�b�v
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// ���ɒǉ�
			function(line, value);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		if (pFileData != nullptr) {
			delete[]pFileData;
			pFileData = nullptr;
		}

		return LR_SUCCESS;
	}

	// �P�s���擾���� 
	//$ Lambda style -> function(line) { }
	template<class F>
	inline static LOADRESULT GetLine(file_name_t filename,F function)
	{
		// �ϐ��錾
		file_size_t nFileSize;	// �t�@�C���T�C�Y
		file_data_t pFileData = nullptr;			// �t�@�C���f�[�^
		LOADRESULT result;

		// �t�@�C�����𕶎���ɓǂݍ���
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// �o�b�t�@�̗̈�m��
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		string_t pBuffeEnd = pBuffe + nFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// �ǂݍ��񂾏��
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// �o�b�t�@�̏I���n�_�܂Ń��[�v����
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// �擪��end�ɐݒ�
			lineEnd = line;

			// end���s���܂ŃX�L�b�v
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// ���ɒǉ�
			function(line);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		if (pFileData != nullptr) {
			delete[]pFileData;
			pFileData = nullptr;
		}

		return LR_SUCCESS;
	}
};

//-------------------------------------------------------------------------------------------------------------
// �������t�@�C���̓ǂݍ���
//-------------------------------------------------------------------------------------------------------------
class CLoadInitFile
{
public:
	// �\���̒�`
	typedef struct READINFO
	{
	public:
		READINFO() {}
		READINFO(string_t in)
		{
			entrytype = entrydata = nullptr;
			line = in;
		}
		string_t entrytype;
		string_t entrydata;
		string_t line;
	} READINFO;

	// �R���X�g���N�^
	inline CLoadInitFile() {};
	// �f�X�g���N�^
	inline ~CLoadInitFile() {};

	// �t�@�C���̃��[�h
	template<class T, class F>
	inline static LOADRESULT LoadFile(file_name_t filename,T value, F func)
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

	template<class F>
	inline static LOADRESULT LoadFile(file_name_t filename, F func)
	{
		LOADRESULT result;
		CLoadInitFile Load;

		// �t�@�V�����𕶎���ɓǂݍ���
		if ((result = Load.LoadFileIntoString(filename)) != LR_SUCCESS)
			return result;

		// �����񂩂�ݒ肷��
		if ((result = Load.SetingfromString(func)) != LR_SUCCESS)
			return result;

		// �t�@�C���f�[�^�̔j��
		Load.DeleteFileData();

		return result;
	}

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

	// �t�@�C�����𕶎���ɓǂݍ���
	inline LOADRESULT LoadFileIntoString(file_name_t pFileName, open_mode_t Mode = "rb")
	{
		// �t�@�C�����J��
		FILE *pFile;
		if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

		// �t�@�C���T�C�Y�̎擾
		u64_t uvlSize = GetFileSize(pFile);
		if (uvlSize == (u64_t)-1) {
			fclose(pFile);
			return M_SIZE_FAIL;
		}

		// �t�@�C���f�[�^�̐���
		file_data_t pFileData = new char[(size_t)uvlSize];
		if (pFileData == nullptr) {
			fclose(pFile);
			return M_FILEDATA_FAIL;
		}

		// �t�@�C������ǂݍ���
		if ((u64_t)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
			fclose(pFile);
			delete[]pFileData;
			return M_READ_FAIL;
		}

		// �t�@�C�������
		fclose(pFile);

		this->m_nuFileSize = (file_size_t)uvlSize;
		this->m_pFileData = pFileData;

		return LR_SUCCESS;
	}

	// �����񂩂�ݒ�
	template<class T, class F>
	inline LOADRESULT SetingfromString(T value, F funk)
	{
		// �o�b�t�@�̗̈�m��
		string_t pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		string_t pBuffeEnd = pBuffe + this->m_nuFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// �ǂݍ��񂾏��
		READINFO info = READINFO(pBuffe);
		string_t lineEnd = nullptr;

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

				const_string_t pDataEnd;		// �o�^�p�̃f�[�^�̍Ō�
				const_string_t pTypeStart;	// �o�^�p�̃^�C�v�̍ŏ�
				string_t       pTypeEnd;		// �o�^�p�̃^�C�v�̍Ō�
				const_string_t pDataStart;	// �o�^�p�̃f�[�^�̍ŏ�

				pDataEnd = lineEnd - 1;															// �s�̍Ō��ݒ�
				pTypeStart = info.line + 1;															// �ŏ��� [ ���X�L�b�v
				pTypeEnd = (string_t)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// �ŏ��� ] �܂ŃX�L�b�v
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2�ڂ� [ �܂ŃX�L�b�v

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// ��ڂ� ] ��������
				++pDataStart;		// ��ڂ� [ ���΂�

				info.entrytype = (string_t)(void*)pTypeStart;
				info.entrydata = (string_t)(void*)pDataStart;
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

	// �����񂩂�ݒ�
	template<class F>
	inline LOADRESULT SetingfromString(F funk)
	{
		// �o�b�t�@�̗̈�m��
		string_t pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// �o�b�t�@�̈�̍ŏI�n�_
		string_t pBuffeEnd = pBuffe + this->m_nuFileSize;
		// �̈���R�s�[����
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// �ǂݍ��񂾏��
		READINFO info = READINFO(pBuffe);
		string_t lineEnd = nullptr;

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

				const_string_t pDataEnd;		// �o�^�p�̃f�[�^�̍Ō�
				const_string_t pTypeStart;	// �o�^�p�̃^�C�v�̍ŏ�
				string_t       pTypeEnd;		// �o�^�p�̃^�C�v�̍Ō�
				const_string_t pDataStart;	// �o�^�p�̃f�[�^�̍ŏ�

				pDataEnd = lineEnd - 1;															// �s�̍Ō��ݒ�
				pTypeStart = info.line + 1;															// �ŏ��� [ ���X�L�b�v
				pTypeEnd = (string_t)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// �ŏ��� ] �܂ŃX�L�b�v
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2�ڂ� [ �܂ŃX�L�b�v

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// ��ڂ� ] ��������
				++pDataStart;		// ��ڂ� [ ���΂�

				info.entrytype = (string_t)(void*)pTypeStart;
				info.entrydata = (string_t)(void*)pDataStart;
			}


			// �o�^�f�[�^�̎擾������
			funk(info);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		return LR_SUCCESS;
	}

private:
	// �C�ӂ̕����ȍ~�̕�������擾
	inline static const_string_t GetRangeStrfromChar(const_string_t cnStr, const_string_t cnStrEnd, char marker)
	{
		const_string_t cnRetStr = (const_string_t)memchr(cnStr, (int)marker, cnStrEnd - cnStr);
		return cnRetStr;
	}
	file_size_t m_nuFileSize;	// �t�@�C���T�C�Y
	file_data_t m_pFileData;	// �t�@�C���f�[�^
};

_END_MYSTD
#endif
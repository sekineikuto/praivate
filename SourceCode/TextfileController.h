//*************************************************************************************************************
//
// 自分のライブラリの処理[Mylibrary.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _TEXTFILECONTROLLER_H_
#define _TEXTFILECONTROLLER_H_

#define _CRT_SECURE_NO_WARNINGS

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <windows.h>
#include <vector>
#include "mystd\mystd.h"
#include "mystd\types.h"
#include <fstream>

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define TxtCtrlSkipCondition(chr) chr == '\n' || chr == '\r' || chr == '\t' || chr == ' ' || chr == '　'

_BEGIN_MYSTD
//-------------------------------------------------------------------------------------------------------------
// 型宣言
//-------------------------------------------------------------------------------------------------------------
typedef charptr_t    string_t;
typedef const char * const_string_t;

typedef const_string_t file_name_t;
typedef mystd::u32_t   file_size_t;
typedef string_t	   file_data_t;
typedef const_string_t open_mode_t;

//-------------------------------------------------------------------------------------------------------------
// 列挙型定義
//-------------------------------------------------------------------------------------------------------------

// * [contents] 列挙型定義
// * [memo] 
//   LOADRESULT -> LR
//   MAKE -> M
//   BUFFER -> B
enum LOADRESULT
{
	LR_FAILURE = -1,		// 失敗(エラー)
	LR_SUCCESS,				// 成功

	M_CREATE_FAIL,			// 作成に失敗した
	M_OPEN_FAIL,			// ファイルを開けなかった
	M_SIZE_FAIL,			// サイズの取得失敗
	M_FILEDATA_FAIL,		// ファイルデータのエラー
	M_READ_FAIL,			// 読み込み失敗

	B_FAIL,					// バッファ領域取得エラー
};

//-------------------------------------------------------------------------------------------------------------
// ヘルパー関数群
//-------------------------------------------------------------------------------------------------------------

// ファイルを大きさを取得する
inline u64_t GetFileSize(FILE * pFile)
{
	long lTop = 0;
	long lSize = 0;

	// 先頭のファイル位置を取得
	lTop = std::ftell(pFile);

	// (ファイル位置を取得成功 && ファイル位置を尾末に設定に成功)が失敗した時
	if ((lTop != -1 &&
		fseek(pFile, 0, SEEK_END) == 0) != 1)
	{
		return -1;
	}

	// 尾末のファイル位置（サイズ）を取得
	lSize = ftell(pFile);

	// (サイズの取得成功 && ファイル位置を先頭に設定に成功)が失敗した時
	if ((lSize != -1 &&
		fseek(pFile, lTop, SEEK_SET) == 0) != 1)
	{
		return -1;
	}

	return (u64_t)lSize;
}

// ファイル情報を文字列に読み込む
inline LOADRESULT LoadFileIntoString(file_name_t pFileName, file_size_t* outSize, file_data_t *outData, open_mode_t Mode = "rb")
{
	// ファイルを開く
	FILE *pFile;
	if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

	// ファイルサイズの取得
	u64_t uvlSize = GetFileSize(pFile);
	if (uvlSize == (u64_t)-1) {
		fclose(pFile);
		return M_SIZE_FAIL;
	}

	// ファイルデータの生成
	file_data_t pFileData = new char[(size_t)uvlSize];
	if (pFileData == nullptr) {
		fclose(pFile);
		return M_FILEDATA_FAIL;
	}

	// ファイル情報を読み込む
	if ((u64_t)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
		fclose(pFile);
		delete[]pFileData;
		return M_READ_FAIL;
	}

	// ファイルを閉じる
	fclose(pFile);

	*outSize = (file_size_t)uvlSize;
	*outData = pFileData;

	return LR_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------
// ファイル情報を取得する
//-------------------------------------------------------------------------------------------------------------
class CLoadFile
{
public:
	// コンストラクタ
	CLoadFile() {}
	// デストラクタ
	~CLoadFile() {}

	// ファイルを分割して取得する
	inline static LOADRESULT GetSplit(file_name_t filename, std::vector<std::string>& fileInfo)
	{
		// 変数宣言
		file_size_t nFileSize;	// ファイルサイズ
		file_data_t pFileData = nullptr;			// ファイルデータ
		LOADRESULT result;

		// ファイル情報を文字列に読み込む
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// バッファの領域確保
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		string_t pBuffeEnd = pBuffe + nFileSize;
		// 領域をコピーする
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// 読み込んだ情報
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// バッファの終了地点までループする
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// 先頭をendに設定
			lineEnd = line;
			
			// endを行末までスキップ
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// 後ろに追加
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

	// １行ずつ取得する 
	//$ function -> function(line, T value) { }
	template<class T, class F>
	inline static LOADRESULT GetLine(file_name_t filename, T value, F function)
	{
		// 変数宣言
		file_size_t nFileSize;			// ファイルサイズ
		file_data_t pFileData = nullptr;	// ファイルデータ
		LOADRESULT result;

		// ファイル情報を文字列に読み込む
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// バッファの領域確保
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		string_t pBuffeEnd = pBuffe + nFileSize;
		// 領域をコピーする
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// 読み込んだ情報
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// バッファの終了地点までループする
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// 先頭をendに設定
			lineEnd = line;

			// endを行末までスキップ
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// 後ろに追加
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

	// １行ずつ取得する 
	//$ Lambda style -> function(line) { }
	template<class F>
	inline static LOADRESULT GetLine(file_name_t filename,F function)
	{
		// 変数宣言
		file_size_t nFileSize;	// ファイルサイズ
		file_data_t pFileData = nullptr;			// ファイルデータ
		LOADRESULT result;

		// ファイル情報を文字列に読み込む
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// バッファの領域確保
		string_t pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		string_t pBuffeEnd = pBuffe + nFileSize;
		// 領域をコピーする
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// 読み込んだ情報
		string_t line = pBuffe;
		string_t lineEnd = nullptr;

		// バッファの終了地点までループする
		for (line = pBuffe; line < pBuffeEnd; line = lineEnd + 1)
		{
			while (TxtCtrlSkipCondition(*line))
				++line;

			// 先頭をendに設定
			lineEnd = line;

			// endを行末までスキップ
			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')
				++lineEnd;
			lineEnd[0] = '\0';

			// 後ろに追加
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
// 初期化ファイルの読み込み
//-------------------------------------------------------------------------------------------------------------
class CLoadInitFile
{
public:
	// 構造体定義
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

	// コンストラクタ
	inline CLoadInitFile() {};
	// デストラクタ
	inline ~CLoadInitFile() {};

	// ファイルのロード
	template<class T, class F>
	inline static LOADRESULT LoadFile(file_name_t filename,T value, F func)
	{
		LOADRESULT result;
		CLoadInitFile Load;

		// ファシル情報を文字列に読み込む
		if ((result = Load.LoadFileIntoString(filename)) != LR_SUCCESS)
			return result;

		// 文字列から設定する
		if ((result = Load.SetingfromString(value, func)) != LR_SUCCESS)
			return result;

		// ファイルデータの破棄
		Load.DeleteFileData();

		return result;
	}

	template<class F>
	inline static LOADRESULT LoadFile(file_name_t filename, F func)
	{
		LOADRESULT result;
		CLoadInitFile Load;

		// ファシル情報を文字列に読み込む
		if ((result = Load.LoadFileIntoString(filename)) != LR_SUCCESS)
			return result;

		// 文字列から設定する
		if ((result = Load.SetingfromString(func)) != LR_SUCCESS)
			return result;

		// ファイルデータの破棄
		Load.DeleteFileData();

		return result;
	}

		// 開放
	inline static void Release(CLoadInitFile *pClass)
	{
		if (pClass == nullptr)
			return;

		pClass->DeleteFileData();

		delete pClass;
		pClass = nullptr;
	}

	// ファイルデータの削除
	inline void DeleteFileData(void)
	{
		if (this->m_pFileData == nullptr)
			return;

		delete[] this->m_pFileData;
		this->m_pFileData = nullptr;
	}

	// ファイル情報を文字列に読み込む
	inline LOADRESULT LoadFileIntoString(file_name_t pFileName, open_mode_t Mode = "rb")
	{
		// ファイルを開く
		FILE *pFile;
		if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

		// ファイルサイズの取得
		u64_t uvlSize = GetFileSize(pFile);
		if (uvlSize == (u64_t)-1) {
			fclose(pFile);
			return M_SIZE_FAIL;
		}

		// ファイルデータの生成
		file_data_t pFileData = new char[(size_t)uvlSize];
		if (pFileData == nullptr) {
			fclose(pFile);
			return M_FILEDATA_FAIL;
		}

		// ファイル情報を読み込む
		if ((u64_t)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
			fclose(pFile);
			delete[]pFileData;
			return M_READ_FAIL;
		}

		// ファイルを閉じる
		fclose(pFile);

		this->m_nuFileSize = (file_size_t)uvlSize;
		this->m_pFileData = pFileData;

		return LR_SUCCESS;
	}

	// 文字列から設定
	template<class T, class F>
	inline LOADRESULT SetingfromString(T value, F funk)
	{
		// バッファの領域確保
		string_t pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		string_t pBuffeEnd = pBuffe + this->m_nuFileSize;
		// 領域をコピーする
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// 読み込んだ情報
		READINFO info = READINFO(pBuffe);
		string_t lineEnd = nullptr;

		// バッファの終了地点までループする
		for (info.line = pBuffe; info.line < pBuffeEnd; info.line = lineEnd + 1)
		{
			while (*info.line == '\n' || *info.line == '\r' || *info.line == '\t')++info.line;

			lineEnd = info.line;

			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')++lineEnd;

			lineEnd[0] = '\0';

			// 1行の最初が [ 最後が ] の時
			if (info.line[0] == '[' &&lineEnd > info.line &&lineEnd[-1] == ']')
			{
				lineEnd[-1] = '\0';

				const_string_t pDataEnd;		// 登録用のデータの最後
				const_string_t pTypeStart;	// 登録用のタイプの最初
				string_t       pTypeEnd;		// 登録用のタイプの最後
				const_string_t pDataStart;	// 登録用のデータの最初

				pDataEnd = lineEnd - 1;															// 行の最後を設定
				pTypeStart = info.line + 1;															// 最初の [ をスキップ
				pTypeEnd = (string_t)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// 最初の ] までスキップ
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2つ目の [ までスキップ

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// 一つ目の ] を初期化
				++pDataStart;		// 二つ目の [ を飛ばす

				info.entrytype = (string_t)(void*)pTypeStart;
				info.entrydata = (string_t)(void*)pDataStart;
			}


			// 登録データの取得条件式
			funk(info, value);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		return LR_SUCCESS;
	}

	// 文字列から設定
	template<class F>
	inline LOADRESULT SetingfromString(F funk)
	{
		// バッファの領域確保
		string_t pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		string_t pBuffeEnd = pBuffe + this->m_nuFileSize;
		// 領域をコピーする
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// 読み込んだ情報
		READINFO info = READINFO(pBuffe);
		string_t lineEnd = nullptr;

		// バッファの終了地点までループする
		for (info.line = pBuffe; info.line < pBuffeEnd; info.line = lineEnd + 1)
		{
			while (*info.line == '\n' || *info.line == '\r' || *info.line == '\t')++info.line;

			lineEnd = info.line;

			while (lineEnd < pBuffeEnd && *lineEnd != '\n' && *lineEnd != '\r')++lineEnd;

			lineEnd[0] = '\0';

			// 1行の最初が [ 最後が ] の時
			if (info.line[0] == '[' &&lineEnd > info.line &&lineEnd[-1] == ']')
			{
				lineEnd[-1] = '\0';

				const_string_t pDataEnd;		// 登録用のデータの最後
				const_string_t pTypeStart;	// 登録用のタイプの最初
				string_t       pTypeEnd;		// 登録用のタイプの最後
				const_string_t pDataStart;	// 登録用のデータの最初

				pDataEnd = lineEnd - 1;															// 行の最後を設定
				pTypeStart = info.line + 1;															// 最初の [ をスキップ
				pTypeEnd = (string_t)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// 最初の ] までスキップ
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2つ目の [ までスキップ

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// 一つ目の ] を初期化
				++pDataStart;		// 二つ目の [ を飛ばす

				info.entrytype = (string_t)(void*)pTypeStart;
				info.entrydata = (string_t)(void*)pDataStart;
			}


			// 登録データの取得条件式
			funk(info);
		}

		if (pBuffe != nullptr) {
			delete[] pBuffe;
			pBuffe = nullptr;
		}

		return LR_SUCCESS;
	}

private:
	// 任意の文字以降の文字列を取得
	inline static const_string_t GetRangeStrfromChar(const_string_t cnStr, const_string_t cnStrEnd, char marker)
	{
		const_string_t cnRetStr = (const_string_t)memchr(cnStr, (int)marker, cnStrEnd - cnStr);
		return cnRetStr;
	}
	file_size_t m_nuFileSize;	// ファイルサイズ
	file_data_t m_pFileData;	// ファイルデータ
};

_END_MYSTD
#endif
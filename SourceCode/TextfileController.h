//*************************************************************************************************************
//
// 自分のライブラリの処理[Mylibrary.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
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

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define TxtCtrlSkipCondition(chr) chr == '\n' || chr == '\r' || chr == '\t' || chr == ' ' || chr == '　'

//-------------------------------------------------------------------------------------------------------------
// 変数を宣言
//-------------------------------------------------------------------------------------------------------------
typedef const char *       CONST_STRING;	// 変更不可文字列
typedef char *             STRING;			// 文字列

typedef signed char        VSHORT;			// 符号あり1バイト分の変数
typedef unsigned char      UVSHORT;			// 符号なし1バイト分の変数

typedef long long          VLONG;			// 符号あり8バイト分の変数
typedef unsigned long long UVLONG;			// 符号なし8バイト分の変数

typedef const char *       FILE_NAME;		// ファイル名
typedef unsigned int       FILE_SIZE;		// ファイルデータサイズ
typedef char *             FILE_DATA;		// ファイルデータ
typedef const char *       OPEN_MODE;		// ファイルを開くモード

_BEGIN_MYSTD
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
inline UVLONG GetFileSize(FILE * pFile)
{
	long lTop = 0;
	long lSize = 0;

	// 先頭のファイル位置を取得
	lTop = ftell(pFile);

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

	return (UVLONG)lSize;
}

// ファイル情報を文字列に読み込む
inline LOADRESULT LoadFileIntoString(FILE_NAME pFileName, FILE_SIZE* outSize, FILE_DATA *outData, OPEN_MODE Mode = "rb")
{
	// ファイルを開く
	FILE *pFile;
	if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

	// ファイルサイズの取得
	UVLONG uvlSize = GetFileSize(pFile);
	if (uvlSize == (UVLONG)-1) {
		fclose(pFile);
		return M_SIZE_FAIL;
	}

	// ファイルデータの生成
	FILE_DATA pFileData = new char[(size_t)uvlSize];
	if (pFileData == nullptr) {
		fclose(pFile);
		return M_FILEDATA_FAIL;
	}

	// ファイル情報を読み込む
	if ((UVLONG)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
		fclose(pFile);
		delete[]pFileData;
		return M_READ_FAIL;
	}

	// ファイルを閉じる
	fclose(pFile);

	*outSize = (FILE_SIZE)uvlSize;
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
	inline static LOADRESULT GetSplit(FILE_NAME filename, std::vector<std::string>& fileInfo)
	{
		// 変数宣言
		FILE_SIZE nFileSize;	// ファイルサイズ
		FILE_DATA pFileData = nullptr;			// ファイルデータ
		LOADRESULT result;

		// ファイル情報を文字列に読み込む
		result = LoadFileIntoString(filename, &nFileSize, &pFileData);

		if (result != LR_SUCCESS) return result;

		// バッファの領域確保
		STRING pBuffe = new char[nFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		STRING pBuffeEnd = pBuffe + nFileSize;
		// 領域をコピーする
		memcpy(pBuffe, pFileData, nFileSize);
		pBuffe[nFileSize] = '\0';

		// 読み込んだ情報
		STRING line = pBuffe;
		STRING lineEnd = nullptr;

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
};

// 初期化ファイルの読み込み
class CLoadInitFile
{
public:
	// 構造体定義
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

	// コンストラクタ
	inline CLoadInitFile() {};
	// デストラクタ
	inline ~CLoadInitFile() {};

	// ファイルのロード
	template<class T, class F>
	inline static LOADRESULT LoadFile(FILE_NAME filename,T value, F func)
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
	inline static LOADRESULT LoadFile(FILE_NAME filename, F func)
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
	inline LOADRESULT LoadFileIntoString(FILE_NAME pFileName, OPEN_MODE Mode = "rb")
	{
		// ファイルを開く
		FILE *pFile;
		if ((pFile = fopen(pFileName, Mode)) == nullptr)return M_OPEN_FAIL;

		// ファイルサイズの取得
		UVLONG uvlSize = GetFileSize(pFile);
		if (uvlSize == (UVLONG)-1) {
			fclose(pFile);
			return M_SIZE_FAIL;
		}

		// ファイルデータの生成
		FILE_DATA pFileData = new char[(size_t)uvlSize];
		if (pFileData == nullptr) {
			fclose(pFile);
			return M_FILEDATA_FAIL;
		}

		// ファイル情報を読み込む
		if ((UVLONG)fread(pFileData, 1, (size_t)uvlSize, pFile) != uvlSize) {
			fclose(pFile);
			delete[]pFileData;
			return M_READ_FAIL;
		}

		// ファイルを閉じる
		fclose(pFile);

		this->m_nuFileSize = (FILE_SIZE)uvlSize;
		this->m_pFileData = pFileData;

		return LR_SUCCESS;
	}

	// 文字列から設定
	template<class T, class F>
	inline LOADRESULT SetingfromString(T value, F funk)
	{
		// バッファの領域確保
		STRING pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
		// 領域をコピーする
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// 読み込んだ情報
		READINFO info = READINFO(pBuffe);
		STRING lineEnd = nullptr;

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

				CONST_STRING pDataEnd;		// 登録用のデータの最後
				CONST_STRING pTypeStart;	// 登録用のタイプの最初
				STRING       pTypeEnd;		// 登録用のタイプの最後
				CONST_STRING pDataStart;	// 登録用のデータの最初

				pDataEnd = lineEnd - 1;															// 行の最後を設定
				pTypeStart = info.line + 1;															// 最初の [ をスキップ
				pTypeEnd = (STRING)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// 最初の ] までスキップ
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2つ目の [ までスキップ

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// 一つ目の ] を初期化
				++pDataStart;		// 二つ目の [ を飛ばす

				info.entrytype = (STRING)(void*)pTypeStart;
				info.entrydata = (STRING)(void*)pDataStart;
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
		STRING pBuffe = new char[this->m_nuFileSize + 1];
		if (pBuffe == nullptr)return B_FAIL;

		// バッファ領域の最終地点
		STRING pBuffeEnd = pBuffe + this->m_nuFileSize;
		// 領域をコピーする
		memcpy(pBuffe, this->m_pFileData, this->m_nuFileSize);
		pBuffe[this->m_nuFileSize] = '\0';

		// 読み込んだ情報
		READINFO info = READINFO(pBuffe);
		STRING lineEnd = nullptr;

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

				CONST_STRING pDataEnd;		// 登録用のデータの最後
				CONST_STRING pTypeStart;	// 登録用のタイプの最初
				STRING       pTypeEnd;		// 登録用のタイプの最後
				CONST_STRING pDataStart;	// 登録用のデータの最初

				pDataEnd = lineEnd - 1;															// 行の最後を設定
				pTypeStart = info.line + 1;															// 最初の [ をスキップ
				pTypeEnd = (STRING)(void*)GetRangeStrfromChar(pTypeStart, pDataEnd, ']');			// 最初の ] までスキップ
				pDataStart = pTypeEnd ? GetRangeStrfromChar(pTypeEnd + 1, pDataEnd, '[') : nullptr;	// 2つ目の [ までスキップ

				if (pTypeEnd == '\0' || pDataStart == '\0')continue;

				*pTypeEnd = '\0';	// 一つ目の ] を初期化
				++pDataStart;		// 二つ目の [ を飛ばす

				info.entrytype = (STRING)(void*)pTypeStart;
				info.entrydata = (STRING)(void*)pDataStart;
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
	inline static CONST_STRING GetRangeStrfromChar(CONST_STRING cnStr, CONST_STRING cnStrEnd, char marker)
	{
		CONST_STRING cnRetStr = (CONST_STRING)memchr(cnStr, (int)marker, cnStrEnd - cnStr);
		return cnRetStr;
	}
	FILE_SIZE m_nuFileSize;	// ファイルサイズ
	FILE_DATA m_pFileData;	// ファイルデータ
};

_END_MYSTD
#endif
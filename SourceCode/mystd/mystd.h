//*************************************************************************************************************
//
// 軌道処理 [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#pragma once
#ifndef _MYSTD_H_
#define _MYSTD_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define _BEGIN_MYSTD namespace mystd {
#define _END_MYSTD }
#define _MYSTD ::mystd::

//-------------------------------------------------------------------------------------------------------------
// マクロ関数
//-------------------------------------------------------------------------------------------------------------]

// Stream logs to console window * No line breaks needed at the end
#define AllConsoleLog(s) std::cout << s << std::endl();

// Display a error message window
#define ErrorMessage(title, str) MessageBox(NULL, str, title, MB_ABORTRETRYIGNORE | MB_ICONERROR)

// Display a question message window
#define QuestionMessage(title, str) MessageBox(NULL, str, title, MB_YESNOCANCEL | MB_ICONQUESTION)

// Display a warning message window
#define WarningMessage(title, str) MessageBox(NULL, str, title, MB_ABORTRETRYIGNORE | MB_ICONWARNING)

// Display a infornation message window
#define InfornationMessage(title, str) MessageBox(NULL, str, title, MB_OKCANCEL | MB_ICONINFORMATION)


#endif // _MYSTD_H_
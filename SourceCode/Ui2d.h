//*************************************************************************************************************
//
// 2DUI処理[2DUI.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#ifndef _2DUI_H_
#define _2DUI_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Scene2D.h"
#include "Ui2dSeting.h"
#include "mystd\CompoBehaviour.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CUi2d : public CScene, public mystd::CCompoBehaviour
{
public:
	CUi2d() : CScene(PRIORITY_2DUI) {}
	CUi2d(PRIORITY pri) : CScene(pri) {}												// コンストラクタ
	~CUi2d() {}																			// デストラクタ

	static CUi2d * Create(ui2d::SETING &seting, PRIORITY pri = PRIORITY_2DUI);		// 生成

	void Init(ui2d::SETING &seting, PRIORITY pri);									// 初期化
	void Init(void);																	// 初期化
	void Uninit(void);																	// 終了
	void Update(void);																	// 更新
	void Draw(void);																	// 描画

private:

protected:
};


#endif
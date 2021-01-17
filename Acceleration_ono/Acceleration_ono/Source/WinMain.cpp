

#include <stdio.h>
#include "DxLib.h"
#include "../Source/Scene/InGameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(1800, 1000, 32);
	SetBackgroundColor(180, 180, 180);
	SetMainWindowText("ほーみんぐみさいる");
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// 初期化処理
	InGameScene* pInGameScene = new InGameScene();

	// メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ＤＸライブラリを使う上で、１フレーム分の処理を始めるためのお約束
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// 処理
		pInGameScene->Exec();

		// 描画
		pInGameScene->Draw();

		ScreenFlip();
	}
	delete pInGameScene;
	pInGameScene = nullptr;

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}

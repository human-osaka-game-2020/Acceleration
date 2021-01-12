#include "common.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(Widht, Height, 16);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("Acceleration");


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	GameScene gameScene;

	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 ||
			CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;        // エラーが起きたらループを抜ける
		}
		else
		{
			//フレームごとにキーの状態更新
			UpdateKeyStatus();

			ClearDrawScreen();
			clsDx();

			//シーン処理
			gameScene.Exec();

			//シーン描画
			gameScene.Draw();

			ScreenFlip();
		}
	}


	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}

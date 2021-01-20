#include"DxLib.h"
#include"Ball.h"
#include"WinMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(Height, Width,32);
	SetBackgroundColor(200, 200, 200);
	SetMainWindowText("加速度");
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	Ball ball;
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		clsDx();
		
		ball.Exec();

		ball.Draw();
		

		ScreenFlip();
	}
	
	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
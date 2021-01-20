#include"DxLib.h"
#include"Ball.h"
#include"WinMain.h"

Ball::Ball()
{
	PosX = 350.0f;
	PosY = 50.0f;
	Speed = 10.0f;
	Gravity = 9.8f;
	Time = 0;
	Timer = 0;
	InitTexture();
}

Ball::~Ball()
{
	ReleseTexture();
}

void Ball::Exec()
{
	if (CheckHitKey(KEY_INPUT_UP) == true)
	{
		PosY -= Speed - Gravity * Time;
		Time += 0.1;
		if (PosY > Height)
		{
			PosY = 50.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == true)
	{
		PosY += Speed + Gravity * Time;
		Time += 0.1;
		if (PosY > Height)
		{
			PosY = 50.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == true)
	{
		Time = 0.0;
		PosY = 50.0f;
	}
}

void Ball::Draw()
{
	DrawExtendGraph(PosX, PosY, PosX + 100, PosY + 100, Texture, TRUE);
	DrawFormatString(100, 200, GetColor(255, 0, 255), "X:%f,Y:%f",PosX, PosY);
}

void Ball::InitTexture()
{
	Texture = LoadGraph("Res/maru.png");
}

void Ball::ReleseTexture()
{
	DeleteGraph(Texture);
}

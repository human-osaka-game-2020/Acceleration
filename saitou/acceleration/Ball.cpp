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
		IsPushUpArrow = true;
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == true)
	{
		IsPushDownArrow = true;
	}

	if(IsPushUpArrow == true)
	{
		PosY -= Speed - Gravity * Time;
		Time += 0.1;
		if (PosY > Height)
		{
			PosY = 50.0f;
			Time = 0.0f;
			IsPushUpArrow = false;
		}
	}
	
	if(IsPushDownArrow==true)
	{
		PosY += Speed + Gravity * Time;
		Time += 0.1;
		if (PosY > Height)
		{
			PosY = 50.0f;
			Time = 0.0f;
			IsPushDownArrow = false;
		}
	}
}

void Ball::Draw()
{
	DrawExtendGraph(PosX, PosY, PosX + 100, PosY + 100, Texture, TRUE);
	DrawFormatString(100, 200, GetColor(0, 0, 0), "X:%f,Y:%f",PosX, PosY);
}

void Ball::InitTexture()
{
	Texture = LoadGraph("Res/maru.png");
}

void Ball::ReleseTexture()
{
	DeleteGraph(Texture);
}

#include "Common.h"

Hanabi hanabi[number][sustaining][density];

GameScene::GameScene()
{
	for (int k = 0; k < number; k++)
	{
		finishedAnimation[k] = true;

		for (int j = 0; j < sustaining; j++)
		{
			for (int i = 0; i < density; i++)
			{
				hanabi[k][j][i].SetTheta(360.0f / density * i);
				hanabi[k][j][i].SetPosX(0.0f);
				hanabi[k][j][i].SetPosY(0.0f);
			}
		}
	}
}

GameScene::~GameScene()
{

}

void GameScene::Exec()
{
	if (IsKeyPushed(KEY_INPUT_RETURN))
	{
		for (int k = 0; k < number; k++)
		{
			if (!finishedAnimation[k])
			{
				continue;
			}

			finishedAnimation[k] = false;

			randPos_x = 100 + GetRand(Widht - 100);
			randPos_y = 100 + GetRand(Height - 100);

			for (int j = 0; j < sustaining; j++)
			{
				for (int i = 0; i < density; i++)
				{
					hanabi[k][j][i].SetPosX(randPos_x);
					hanabi[k][j][i].SetPosY(randPos_y);
					hanabi[k][j][i].SetTimer(j * -2);
				}
			}

			break;
		}
	}

	for (int k = 0; k < number; k++)
	{
		if (finishedAnimation[k])
		{
			continue;
		}

		for (int j = 0; j < sustaining; j++)
		{
			for (int i = 0; i < density; i++)
			{
				hanabi[k][j][i].Fall();
			}
		}

		if (hanabi[k][sustaining - 1][int((density - 1) / 4)].GetPosY() > Height + 50.0f)
		{
			finishedAnimation[k] = true;
		}
	}
}

void GameScene::Draw()
{
	for (int k = 0; k < number; k++)
	{
		if (finishedAnimation[k])
		{
			continue;
		}

		for (int j = 0; j < sustaining; j++)
		{
			for (int i = 0; i < density; i++)
			{
				switch (k % 3)
				{
				case 0:
					DrawCircle(hanabi[k][j][i].GetPosX(), hanabi[k][j][i].GetPosY(), 5.0f, GetColor(j * 5, 255, 0), TRUE);
					break;
				case 1:
					DrawCircle(hanabi[k][j][i].GetPosX(), hanabi[k][j][i].GetPosY(), 5.0f, GetColor(255, j * 5, 0), TRUE);
					break;
				case 2:
					DrawCircle(hanabi[k][j][i].GetPosX(), hanabi[k][j][i].GetPosY(), 5.0f, GetColor(0, j * 5, 255), TRUE);
					break;
				}
			}
		}
	}
}


#include "InGameScene.h"
#include "../Object/Player.h"
#include "../Difinition.h"
#include "../Function/Input.h"
#include "DxLib.h"

Player g_player;

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	g_player.Update();
}

void InGameScene::Draw()
{
	g_player.Draw();
}

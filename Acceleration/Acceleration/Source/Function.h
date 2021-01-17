
#ifndef FUNCTION_H
#define FUNCTION_H

#include "DxLib.h"

// キーボードの入力状態
enum class InputState {
	NotPressed,		// 押されていない
	Pressed,		// 押された瞬間
	Pressing,		// 押している
	Released,		// 離した瞬間
	Invalid			// 無効
};

/// @brief すべてのキーで現在押されているかを調べる
/// @param stateArray 情報保存用のbool配列
void CheckKeyPushed( bool* pStateArray );

/// @brief キーの入力状態を更新する
/// @return 0以外はエラー
int UpdateKeyState();

/// @brief キーの入力状態を取得する
/// @param keyCode 入力状態を取得したいキーのキーコード
/// @return InputStateで返す
InputState GetKeyStatus( int keyCode );

#endif // !FUNCTION_H

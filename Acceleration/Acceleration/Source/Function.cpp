
#include "Function.h"

// キーが何フレーム入力されているか保存する
InputState keyState[256];

void CheckKeyPushed( bool* pStateArray ){
	char temp[256];

	GetHitKeyStateAll( temp );

	for( int i = 0; i < 256; i++ ){
		pStateArray[i] = ( temp[i] == 1 ) ? true : false;
	}
}

/// @brief キー/マウスの入力状態を更新する
/// @param isPressed 現在キーが押されているか
/// @param inputState キー/マウスの入力状態
/// @return 入力状態の判定結果 InputStateで返す
InputState UpdateInputState( bool isPressed, InputState inputState ){
	if ( inputState == InputState::Invalid )return InputState::Invalid;

	if ( isPressed == true ){
		if ( inputState == InputState::NotPressed ){
			return InputState::Pressed;
		}
		else if ( inputState == InputState::Pressed || inputState == InputState::Pressing ){
			return InputState::Pressing;
		}
	}
	else{
		if ( inputState == InputState::Pressed || inputState == InputState::Pressing ){
			return InputState::Released;
		}
	}

	return InputState::NotPressed;
}

int UpdateKeyState() {
	bool currentKeyState[256];

	CheckKeyPushed( currentKeyState );

	for ( int i = 0; i < 256; i++ ) {
		keyState[i] = UpdateInputState( currentKeyState[i], keyState[i] );
	}

	return 0;
}

InputState GetKeyStatus( int keyCode ){
	return keyState[keyCode];
}

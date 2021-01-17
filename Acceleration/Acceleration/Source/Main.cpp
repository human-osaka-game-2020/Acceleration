
#include "DxLib.h"
#include "Function.h"

class Player
{
public:
	Player() :x( 640 ), y( 100 ), jumpPower( 1 ), boundCounter( 0 ){};
	~Player(){};
	void JumpStart();
	void Jump();
	void Draw();

private:
	float x;
	float y;
	float jumpPower;
	const float resetPower = -20;
	int boundCounter;
};

void Player::Jump(){
	if( y > 600 ){
		y = 600;
		boundCounter++;
		jumpPower = resetPower / boundCounter;
		return;
	}

	y += jumpPower;
	jumpPower += 0.5f;

	if( jumpPower > 20 ) jumpPower = 20;
}

void Player::JumpStart(){
	y--;
	jumpPower = resetPower;
	boundCounter = 1;
}

void Player::Draw(){
	DrawCircle( x, y, 16, GetColor( 100, 100, 0 ), true );
	DrawFormatString( 0, 0, GetColor( 0, 0, 0 ), "%f", y );
}

Player player;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	SetOutApplicationLogValidFlag( false );

	SetGraphMode( 1280, 720, 32 );
	ChangeWindowMode( true );
	SetBackgroundColor( 255, 255, 255 );

	if( DxLib_Init() == -1 ) return -1;

	SetDrawScreen( DX_SCREEN_BACK );

	while( true ){
		ClearDrawScreen();

		if( UpdateKeyState() != 0 ) break;

		// --------------------

		if( GetKeyStatus( KEY_INPUT_SPACE ) == InputState::Pressed ) player.JumpStart();

		player.Jump();
		player.Draw();

		// --------------------

		if( ProcessMessage() < 0 ) break;
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break;

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}

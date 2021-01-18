#include "Accelaration.h"

accelaration::accelaration()
{
	posX = 640.0f;
	posY = 800.0f;
	gravity = 0.0f;
	mouseX = 0.0f;
	mouseY = 0.0f;
}

accelaration::~accelaration()
{
}

void accelaration::Control()
{
	Move();
	Draw();
}

void accelaration::Move()
{
	int ClickX;
	int ClickY; 
	int Button;
	int LogType;
	if( GetMouseInputLog2( &Button, &ClickX, &ClickY, &LogType, TRUE ) == 0 )
	{
		int mouseX_ = 0;
		int mouseY_ = 0;
		GetMousePoint( &mouseX_, &mouseY_ );
		mouseX = mouseX_;
		mouseY = mouseY_;
		if( ( Button & MOUSE_INPUT_LEFT ) != 0 && LogType == MOUSE_INPUT_LOG_DOWN )
		{
			if( ( BOX_A_X1 < mouseX ) && ( BOX_A_Y1 < mouseY ) &&
				( BOX_A_X2 > mouseX ) && ( BOX_A_Y2 > mouseY ) )
			{
				posX = 640.0f;
				posY = 650.0f;
				gravity = -26.0f;
			}
			else if( ( BOX_B_X1 < mouseX ) && ( BOX_B_Y1 < mouseY ) &&
					 ( BOX_B_X2 > mouseX ) && ( BOX_B_Y2 > mouseY ) )
			{
				posX = 640.0f;
				posY = 50.0f;
				gravity = 10.0f;
			}
		}
	}

	posY += gravity;
	gravity += 0.6f;
}

void accelaration::Draw()
{
	DrawCircle( posX, posY, 30, GetColor( 255, 255, 0 ), TRUE );
	DrawBox( 0.0f, 490.0f, 160.0f, 720.0f, GetColor( 0, 0, 255 ), TRUE );
	DrawBox( BOX_A_X1, BOX_A_Y1, BOX_A_X2, BOX_A_Y2, GetColor( 255, 255, 255 ), TRUE );
	DrawBox( BOX_B_X1, BOX_B_Y1, BOX_B_X2, BOX_B_Y2, GetColor( 255, 255, 255 ), TRUE );
	DrawString( BOX_A_X1 + 20.0f, BOX_A_Y1 + 45.0f, "鉛直投げ上げ", GetColor( 0, 0, 0 ) );
	DrawString( BOX_B_X1 + 20.0f, BOX_B_Y1 + 45.0f, "鉛直投げ下げ", GetColor( 0, 0, 0 ) );
}

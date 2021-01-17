
#include "Player.h"
#include "DxLib.h"
#include "../Function/Input.h"
#include "../Difinition.h"

Player::Player()
{
	m_PosX = 0.0f;
	m_PosY = 0.0f;
	m_Width = 64.0f;
	m_Height = 64.0f;

	m_InitSpeed = 2.0f;
	m_JumpVelocity = 0.0f;

	m_Time = 0;
	m_FallTime = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	m_FallTime++;
	m_PosY += Gravity * m_FallTime / 60;

	if (GetKeyStatus(KEY_INPUT_LEFT) == InputState::Hold)
	{

	}
	else if (GetKeyStatus(KEY_INPUT_RIGHT) == InputState::Hold)
	{

	}
	else if (GetKeyStatus(KEY_INPUT_A) == InputState::Hold && m_PosY > WindowHeight - m_Height)
	{
		m_Time++;
		m_MoveSpeed = m_InitSpeed * m_Time / 60;
		m_PosX -= m_MoveSpeed;
	}
	else if (GetKeyStatus(KEY_INPUT_D) == InputState::Hold && m_PosY > WindowHeight - m_Height)
	{
		m_Time++;
		m_MoveSpeed = m_InitSpeed * m_Time / 60;
		m_PosX += m_MoveSpeed;
	}
	else if (GetKeyStatus(KEY_INPUT_A) == InputState::Released)
	{
		m_Time = 0;
	}
	else if (GetKeyStatus(KEY_INPUT_D) == InputState::Released)
	{
		m_Time = 0;
	}
	else if (GetKeyStatus(KEY_INPUT_SPACE) == InputState::Pushed && m_PosY > WindowHeight - m_Height)
	{
		m_JumpVelocity = -200.0f;
		m_PosY += m_JumpVelocity;
	}

	if (m_PosX < -m_Width * 2)
	{
		m_PosX = WindowWidth + m_Width;
	}
	else if (m_PosX > WindowWidth + m_Width * 2)
	{
		m_PosX = -m_Width;
	}
	else if (m_PosY > WindowHeight - m_Height)
	{
		m_FallTime = 0;
		m_PosY = WindowHeight - m_Height;
	}
}

void Player::Draw()
{
	DrawBox(m_PosX, m_PosY, m_PosX + m_Width, m_PosY + m_Height, GetColor(180, 0, 255), TRUE);
	DrawCircle(m_PosX + 32, m_PosY + 32 , m_Radius, GetColor(0, 0, 255), FALSE, TRUE);
	DrawFormatString(0, 0, GetColor( 0, 0, 0), "ç¿ïW[%d,%d]",  (int)m_PosX, (int)m_PosY);
}


#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

private:
	float m_PosX;
	float m_PosY;
	float m_Width;
	float m_Height;
	float m_CenterPosX;
	float m_CenterPosY;

	float m_Radius;
	float m_Angle;
	
	float m_InitSpeed;
	float m_JumpVelocity;
	float m_MoveSpeed;
	float m_RotateSpeed;

	int m_Time;
	int m_FallTime;
};

#endif // !PLAYER_H

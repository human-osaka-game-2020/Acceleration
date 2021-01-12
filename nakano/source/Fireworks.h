#ifndef FIREWORKS_H
#define FIREWORKS_H

class Hanabi
{
public:
	//ベクトルの分解
	void DecomposeVec();
	//落下運動
	void Fall();

	float GetPosX() const { return pos_x; };
	float GetPosY() const { return pos_y; };
	float GetTheta() const { return theta; };
	float GetPosV() const { return V; };

	void SetPosX(float posx_) { pos_x = posx_; };
	void SetPosY(float posy_) { pos_y = posy_; };
	void SetTheta(float theta_) { theta = theta_; };
	void SetV(float v_) { V = v_; };
	void SetTimer(float timer_) { timer = timer_; };

public:
	bool isStartedTimer = false;

private:
	float pos_x;
	float pos_y;
	float theta;
	float V;
	float V_X;
	float V_Y;
	float timer;
};

#endif // !FIREWORKS_H

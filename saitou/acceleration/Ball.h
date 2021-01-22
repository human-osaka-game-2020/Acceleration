#ifndef Ball_H
#define Ball_H

class Ball
{
public:
	Ball();
	~Ball();

	void Exec();
	void Draw();
	void InitTexture();
	void ReleseTexture();
private:

	float PosX;
	float PosY;
	float Speed;
	float Gravity;
	float Time;
	float Timer;
	bool IsPushUpArrow;
	bool IsPushDownArrow;
	//画像保存関数
	int Texture;
};


#endif // !Ball_H

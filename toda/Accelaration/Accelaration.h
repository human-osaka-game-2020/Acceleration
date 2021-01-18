#ifndef ACCELARATION_H
#define ACCELARATION_H

#include "Common.h"

class accelaration
{
public:
	accelaration();
	~accelaration();
	void Control();
	void Move();
	void Draw();
	
private:
	float posX;
	float posY;
	float gravity;
	float mouseX;
	float mouseY;
};



#endif ACCELARATION_H

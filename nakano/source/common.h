#ifndef COMMON_H
#define COMMON_H

const int Widht = 640;
const int Height = 640;

//重力
const float g = 9.8f;

//花火の密度, 16, 32, 64
const int density = 32;

//花火の持続時間, 1~50
const int sustaining = 30;

//画面上に表示される花火の個数 ,1~
const int number = 12;

#define _USE_MATH_DEFINES
#include <math.h>

#include "DxLib.h"
#include "Input.h"
#include "GameScene.h"
#include "Fireworks.h"

#endif // !COMMON_H

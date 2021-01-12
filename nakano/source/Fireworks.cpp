#include "common.h"

void Hanabi::DecomposeVec()
{
	V_X = cos(theta / 180.0f * M_PI) * 1;
	V_Y = sin(theta / 180.0f * M_PI) * 1;
}

void Hanabi::Fall()
{
	if (isStartedTimer)
	{
		return;
	}

	timer++;

	if (timer < 0)
	{
		return;
	}

	DecomposeVec();

	V_Y -= g * powf(timer / 60, 2.0f) * 0.01f;

	pos_x += V_X;
	pos_y -= V_Y;
}

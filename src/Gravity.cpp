#include "Gravity.h"

float Gravity::updatePosition(float y, float deltaTime)
{
	v += downacceleration * deltaTime;
	y += v * deltaTime * 100;

	if (y > 775.f)
	{
		y = 775.f;
		v = -v * 0.8f;
	};
	return y;
}
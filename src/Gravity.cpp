#include "Gravity.h"

float Gravity::applyGravity(float y, float deltaTime)
{
	v += downacceleration * deltaTime;
	y += v * deltaTime * 1000;

	return y;
}
#include "Gravity.h"

sf::Vector2f Gravity::applyGravity(float y, float deltaTime, sf::Vector2f velocity)
{
	velocity.y += downacceleration * deltaTime;
	

	return sf::Vector2f(velocity);
}
#pragma once
#include <SFML/Graphics.hpp>

class Gravity
{
public:
	//float v = 0; // Initial velocity (m/s)
	float downacceleration = 9.8f; // Acceleration due to gravity (m/s^2)
	sf::Vector2f applyGravity(float y, float deltaTime, sf::Vector2f velocity);
};

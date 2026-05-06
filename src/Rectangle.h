#pragma once
#include "PhysicsObject.h"
class Rectangle : public PhysicsObject
	 
{
	sf::Color color;
	float height;
	float width;

public:
	Rectangle(sf::Vector2f position, float height, float width, sf::Color color, bool gravityOn);

	void draw(sf::RenderWindow& window);
};


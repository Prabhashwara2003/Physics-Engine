#pragma once
#include <SFML/Graphics.hpp>
#include "Gravity.h"

class PhysicsObject
{
	

public:
	float xPosition;
	float yPosition;

	PhysicsObject(float xPosition , float yPosition );

	virtual void draw(sf::RenderWindow& window , float deltaTime) = 0;

	virtual ~PhysicsObject() = default;
};


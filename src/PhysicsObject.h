#pragma once
#include <SFML/Graphics.hpp>
#include "Gravity.h"

class PhysicsObject
{
	

public:
	float xPosition;
	float yPosition;

	PhysicsObject(float xPosition , float yPosition );

	void update(float deltaTime);

	virtual void draw(sf::RenderWindow& window ) = 0;

	virtual ~PhysicsObject() = default;
};


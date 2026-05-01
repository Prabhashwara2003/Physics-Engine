#pragma once
#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

class Ball : public PhysicsObject
{
    sf::Color color;
	float radius;

public:
    Gravity gravity;

    Ball(float xPosition, float yPosition, float radius, sf::Color color, bool gravityOn);
    
    void draw(sf::RenderWindow& window );
};


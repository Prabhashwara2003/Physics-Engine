#pragma once
#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

class Ball : public PhysicsObject
{
    sf::Color color;
	float radius;
    std::string type = "Ball";

public:
    Gravity gravity;

    Ball(float xPosition, float yPosition,float radius, sf::Color color);
    
    void draw(sf::RenderWindow& window );
};


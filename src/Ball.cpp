#include "Ball.h"

Ball::Ball(float xPosition, float yPosition, float radius, sf::Color color)
	:PhysicsObject(xPosition, yPosition), radius(radius), color(color)
{	
	
}

void Ball::draw(sf::RenderWindow& window , float deltaTime)
{
	sf::CircleShape shape(radius);
	shape.setFillColor(color);
	yPosition = gravity.applyGravity(yPosition, deltaTime);
	shape.setPosition({ xPosition , yPosition});
	window.draw(shape);
}

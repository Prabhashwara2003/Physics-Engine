#include "Rectangle.h"

Rectangle::Rectangle(float xPosition, float yPosition, float height, float width, sf::Color color, bool gravityOn)
	:PhysicsObject(xPosition, yPosition, gravityOn), height(height), width(width), color(color)
{

}

void Rectangle::draw(sf::RenderWindow& window)
{
	sf::RectangleShape shape({ width , height });
	shape.setFillColor(color);
	shape.setPosition({ xPosition , yPosition });
	window.draw(shape);
}
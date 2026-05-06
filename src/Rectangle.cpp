#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f position, float height, float width, sf::Color color, bool gravityOn)
	:PhysicsObject(position, gravityOn), height(height), width(width), color(color)
{

}

void Rectangle::draw(sf::RenderWindow& window)
{
	sf::RectangleShape shape({ width , height });
	shape.setFillColor(color);
	shape.setPosition(position);
	window.draw(shape);
}
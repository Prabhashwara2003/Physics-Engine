#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window)
	: window(window)
{
}

void Renderer::drawArena()
{
	sf::RectangleShape shape({ 1750.f, 850.f });
	shape.setFillColor(sf::Color(0, 0, 0));   // Gray
	shape.setPosition({ 25, 25 });
	window.draw(shape);
}

void Renderer::drawBackground ()
{
	sf::RectangleShape shape({ 1800.f, 900.f });
	shape.setFillColor(sf::Color(128, 128, 128));   
	shape.setPosition({ 0, 0 });
	window.draw(shape);
}

void Renderer::renderPhysicsObject(PhysicsObject& physicsObject)
{
	physicsObject.draw(window);
}
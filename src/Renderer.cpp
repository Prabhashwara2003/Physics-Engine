#include <SFML/Graphics.hpp>
#include "Renderer.h"

void Renderer::drawCircle(sf::RenderWindow& window,float deltaTime)
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition({x, y});
	window.draw(shape);
	v += 9.8f * deltaTime;   // velocity changes over time
	y += v * deltaTime;      // position changes over time
}

void Renderer::drawArena(sf::RenderWindow& window)
{
	sf::RectangleShape shape({ 1750.f, 850.f });
	shape.setFillColor(sf::Color(128, 128, 128));   // Gray
	shape.setPosition({ 25, 25 });
	window.draw(shape);
}

void Renderer::drawBackground (sf::RenderWindow& window)
{
	sf::RectangleShape shape({ 1800.f, 900.f });
	shape.setFillColor(sf::Color(0, 0, 0));   
	shape.setPosition({ 0, 0 });
	window.draw(shape);
}
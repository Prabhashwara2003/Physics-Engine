#include "Application.h"
#include "Renderer.h"
#include "PhysicsObject.h"
#include "Ball.h"
#include "Rectangle.h"

Application::Application()
	: window(sf::VideoMode({ 1800, 900 }), "Arena")
{
}

void Application::run()
{
	std::vector<PhysicsObject* > physicsObjects;
	physicsObjects.push_back(new Ball(500, 500 ,25.f, sf::Color(140, 220, 140),true));
	physicsObjects.push_back(new Rectangle(0, 875, 25.f, 1800.f, sf::Color(128, 128, 128),false));
	physicsObjects.push_back(new Rectangle(0, 0, 900.f, 25.f, sf::Color(128, 128, 128), false));
	physicsObjects.push_back(new Rectangle(0, 0, 25.f, 1800.f, sf::Color(128, 128, 128), false));
	physicsObjects.push_back(new Rectangle(1775, 0, 900.f, 25.f, sf::Color(128, 128, 128), false));

	sf::Clock clock;

	Renderer render(window);


	window.setPosition({ 10, 50 });


	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		while (const std::optional<sf::Event> event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				window.close();
			}

		}
		window.clear();
		
		//render.drawBackground();
		render.drawArena();
		
		for (PhysicsObject* physicsObject : physicsObjects)
		{
			physicsObject->update(deltaTime);
			render.renderPhysicsObject(*physicsObject);
		}

		window.display();
	}
}
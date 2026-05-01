#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include "Ball.h"

class Renderer
{
private:

	sf::RenderWindow& window;

public:

	Renderer(sf::RenderWindow& window);

	float x = 500;
	float y = 500;
	//Gravity gravity;

	

	//void drawCircle( float deltaTime);
	void drawArena();
	void drawBackground(); 
	void renderPhysicsObject(PhysicsObject& physicsObject,float deltaTime);
};	

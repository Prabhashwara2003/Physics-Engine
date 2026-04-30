#pragma once
class Renderer
{
	public:
		float x = 500;
		float y = 500;
		//float v0 = 0;
		//float v = 0;

		void drawCircle(sf::RenderWindow& window, float deltaTime);
		void drawArena(sf::RenderWindow& window);
		void drawBackground(sf::RenderWindow& window); 
};	

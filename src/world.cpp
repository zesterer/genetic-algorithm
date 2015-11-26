#include "world.h"

namespace Genetic
{
	World::World()
	{
		this->window.create(sf::VideoMode(800, 600), "Genetic Test");
	}
	
	int World::run()
	{
		while (this->window.isOpen())
		{
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					this->window.close();
			}
			
			this->window.clear(sf::Color::White);
			this->window.display();
		}
		
		return 0;
	}
}

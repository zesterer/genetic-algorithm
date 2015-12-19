#include "stdio.h"

#include "SFML/Graphics.hpp"

#include "image/surface.h"
#include "image/imageloader.h"
#include "image/negativefilter.h"
#include "image/gradientfilter.h"
#include "image/gaussianfilter.h"

int main(int argc, char* argv[])
{
	printf("Hello, World!\n");
	
	AI::Image::FSurface* test_fsurface = AI::Image::ImageLoader::loadPNG("/home/barry/Pictures/Straw-men-Straw.jpg");
	AI::Image::FSurface* new_fsurface = AI::Image::GradientFilter::applyToFSurface(test_fsurface);
	sf::Texture* test_texture = new_fsurface->convertToTexture();
	
	delete test_fsurface;
	delete new_fsurface;
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test window");
	
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		
		//Draw the texture
		sf::Sprite tmp;
		tmp.setTexture(*test_texture);
		window.draw(tmp);
		
		window.display();
	}
	
	return 0;
}

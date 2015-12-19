#include "stdio.h"

#include "SFML/Graphics.hpp"

#include "image/surface.h"
#include "image/imageloader.h"
#include "image/negativefilter.h"

int main(int argc, char* argv[])
{
	printf("Hello, World!\n");
	
	AI::Image::ISurface* test_surface = AI::Image::ImageLoader::loadPNG("/home/barry/Pictures/tripleright.jpg");
	sf::Texture* test_texture = AI::Image::NegativeFilter::applyToFSurface(test_surface->convertToFSurface())->convertToISurface()->convertToTexture();
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test window");
	
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
		
		//Draw the texture
		sf::Sprite tmp;
		tmp.setTexture(*test_texture);
		window.draw(tmp);
		
		window.display();
	}
	
	return 0;
}

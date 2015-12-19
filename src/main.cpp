#include "stdio.h"

#include "SFML/Graphics.hpp"

#include "image/surface.h"
#include "image/imageloader.h"
#include "image/negativefilter.h"
#include "image/gradientfilter.h"
#include "image/gaussianfilter.h"
#include "image/sobelfilter.h"
#include "image/grayscalefilter.h"
#include "image/thresholdfilter.h"
#include "image/huefilter.h"

int main(int argc, char* argv[])
{
	AI::Image::FSurface* test_fsurface = AI::Image::ImageLoader::loadPNG("../data/tiger.jpg");
	
	//For some weird fucking reason, it doesn't like the below method doing a deallocation on the FSurface object (so delete_src is false here)
	test_fsurface = AI::Image::GaussianFilter::applyToFSurface(test_fsurface, false, 5);
	//test_fsurface = AI::Image::HueFilter::applyToFSurface(test_fsurface, false);
	test_fsurface = AI::Image::GrayscaleFilter::applyToFSurface(test_fsurface, false);
	//test_fsurface = AI::Image::NegativeFilter::applyToFSurface(test_fsurface, false);
	test_fsurface = AI::Image::SobelFilter::applyToFSurfaceGradiented(test_fsurface, false);
	//test_fsurface = AI::Image::ThresholdFilter::applyToFSurface(test_fsurface, false, 0.15f);
	
	sf::Texture* test_texture = test_fsurface->convertToTexture();
	
	delete test_fsurface;
	
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
		tmp.setPosition(sf::Vector2f(0, 0));
		tmp.setTexture(*test_texture);
		window.draw(tmp);
		
		window.display();
	}
	
	return 0;
}

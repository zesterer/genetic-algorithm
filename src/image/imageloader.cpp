#include "imageloader.h"

#include "SFML/Graphics.hpp"

namespace AI
{
	namespace Image
	{
		FSurface* ImageLoader::loadPNG(std::string filename)
		{
			sf::Image tmp;
			
			if (tmp.loadFromFile(filename))
			{
				FSurface* surface = new FSurface(tmp.getSize().x, tmp.getSize().y);
				
				for (int x = 0; x < (int)tmp.getSize().x; x ++)
				{
					for (int y = 0; y < (int)tmp.getSize().y; y ++)
					{
						IColour colour;
						colour.r = tmp.getPixelsPtr()[(tmp.getSize().x * y + x) * 4 + 0];
						colour.g = tmp.getPixelsPtr()[(tmp.getSize().x * y + x) * 4 + 1];
						colour.b = tmp.getPixelsPtr()[(tmp.getSize().x * y + x) * 4 + 2];
						colour.a = tmp.getPixelsPtr()[(tmp.getSize().x * y + x) * 4 + 3];
						surface->setPixel(x, y, colour.toFColour());
					}
				}
				
				return surface;
			}
			else
				return nullptr;
		}
	}
}

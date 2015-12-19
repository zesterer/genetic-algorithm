#ifndef IMAGE_SURFACE_H
#define IMAGE_SURFACE_H

#include "vector"

#include "SFML/Graphics.hpp"

#include "colour.h"

namespace AI
{
	namespace Image
	{
	  	class Surface
		{
			protected:
		 		int w = 0;
		  		int h = 0;
			public:
				void clear();
				int getW();
				int getH();
		};
		
		class ISurface;
		class FSurface;
	  
	  	class ISurface : public Surface
		{
			protected:
				std::vector<IColour> pixels;
			public:
		  		ISurface(int w = 0, int h = 0);
		  		void clear();
		  		IColour getPixel(int x, int y);
		  		IColour getPixel(int i);
		  		void setPixel(int x, int y, IColour colour);
		  		void setPixel(int i, IColour colour);
		  		sf::Texture* convertToTexture();
		  		FSurface* convertToFSurface();
		};
	  
		class FSurface : public Surface
		{
			protected:
				std::vector<FColour> pixels;
			public:
		  		FSurface(int w = 0, int h = 0);
		  		void clear();
		  		FColour getPixel(int x, int y);
		  		FColour getPixel(int i);
		 		void setPixel(int x, int y, FColour colour);
		 		void setPixel(int i, FColour colour);
		 		ISurface* convertToISurface();
		};
	}
}

#endif

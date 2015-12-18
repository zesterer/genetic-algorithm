#ifndef IMAGE_SURFACE_H
#define IMAGE_SURFACE_H

#include "vector"

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
		};
	  
	  	class ISurface : public Surface
		{
			protected:
				std::vector<IColour> pixels;
			public:
		  		ISurface(int w = 0, int h = 0);
		  		void clear();
		};
	  
		class FSurface : public Surface
		{
			protected:
				std::vector<FColour> pixels;
			public:
		  		FSurface(int w = 0, int h = 0);
		  		void clear();
		};
	}
}

#endif

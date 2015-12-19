#ifndef IMAGE_KERNEL_H
#define IMAGE_KERNEL_H

#include "vector"

#include "surface.h"

namespace AI
{
	namespace Image
	{
		class Kernel
		{
			private:
				int w = 0;
				int h = 0;
				std::vector<float> pixels;
				int sanifyX(int x);
				int sanifyY(int y);
			public:
				Kernel(int w = 0, int h = 0);
				void clear();
				float getPixel(int x, int y);
			 	void setPixel(int x, int y, float pixel);
			 	
			 	int getW() { return this->w; }
			 	int getH() { return this->h; }
			 	
			 	FSurface* applyToFSurface(FSurface* src);
		};
	}
}

#endif

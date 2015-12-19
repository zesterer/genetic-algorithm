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
				float total = 0.0f;
				
				int sanifyX(int x);
				int sanifyY(int y);
			public:
				Kernel(int w = 0, int h = 0, float array[] = nullptr);
				void clear();
				float getPixel(int x, int y);
			 	void setPixel(int x, int y, float pixel);
			 	
			 	int getW() { return this->w; }
			 	int getH() { return this->h; }
			 	
			 	float getTotal() { return this->total; }
			 	
			 	float getValueFromFSurface(int x, int y, FSurface* src, int channel);
			 	
			 	void recalculate();
		};
	}
}

#endif

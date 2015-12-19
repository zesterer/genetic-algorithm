#include "gaussianfilter.h"
#include "kernel.h"

namespace AI
{
	namespace Image
	{
		FSurface* GaussianFilter::applyToFSurface(FSurface* src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			const int blur_radius = 4;
			
			Kernel blur_kernel(blur_radius * 2 + 1, blur_radius * 2 + 1);
			
			//Set up the blur kernel
			for (int x = 0; x < blur_kernel.getW(); x ++)
			{
				for (int y = 0; y < blur_kernel.getH(); y ++)
				{
					float dist = std::sqrt(std::pow(x - (blur_radius + 0.5f), 2) + std::pow(y - (blur_radius + 0.5f), 2));
					blur_kernel.setPixel(x, y, 1.0f - dist / blur_radius);
				}
			}
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					FColour col0 = src->getPixel(x - 1, y);
					FColour col1 = src->getPixel(x + 1, y);
					FColour col2 = src->getPixel(x, y - 1);
					FColour col3 = src->getPixel(x, y + 1);
					
					//printf("r=%fg=%fb=%fa=%f\n", col0.r, col0.b, col0.b, col0.a);
					
					col.r = std::sqrt(std::pow(col0.r - col1.r, 2) + std::pow(col2.r - col3.r, 2));
					col.g = std::sqrt(std::pow(col0.g - col1.g, 2) + std::pow(col2.g - col3.g, 2));
					col.b = std::sqrt(std::pow(col0.b - col1.b, 2) + std::pow(col2.b - col3.b, 2));
					
					col = col.greyScale();
					
					dest->setPixel(x, y, col);
				}
			}
			
			return dest;
		}
	}
}

#include "gaussianfilter.h"
#include "kernel.h"

namespace AI
{
	namespace Image
	{
		FSurface* GaussianFilter::applyToFSurface(FSurface* src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			const int blur_radius = 10;
			
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
			
			blur_kernel.recalculate();
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					col.r = blur_kernel.getValueFromFSurface(x - blur_radius, y - blur_radius, src, 0);
					col.g = blur_kernel.getValueFromFSurface(x - blur_radius, y - blur_radius, src, 1);
					col.b = blur_kernel.getValueFromFSurface(x - blur_radius, y - blur_radius, src, 2);
					
					dest->setPixel(x, y, col);
				}
			}
			
			return dest;
		}
	}
}

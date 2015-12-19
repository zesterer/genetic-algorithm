#include "gaussianfilter.h"
#include "kernel.h"

namespace AI
{
	namespace Image
	{
		FSurface* GaussianFilter::applyToFSurface(FSurface* src, bool delete_src, int radius)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			Kernel blur_kernel(radius * 2 + 1, radius * 2 + 1);
			
			//Set up the blur kernel
			for (int x = 0; x < blur_kernel.getW(); x ++)
			{
				for (int y = 0; y < blur_kernel.getH(); y ++)
				{
					float dist = std::sqrt(std::pow(x - radius, 2) + std::pow(y - radius, 2));
					blur_kernel.setPixel(x, y, 1.0f - dist / radius);
				}
			}
			
			blur_kernel.recalculate();
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					col.r = blur_kernel.getValueFromFSurface(x - radius, y - radius, src, 0) / blur_kernel.getTotal();
					col.g = blur_kernel.getValueFromFSurface(x - radius, y - radius, src, 1) / blur_kernel.getTotal();
					col.b = blur_kernel.getValueFromFSurface(x - radius, y - radius, src, 2) / blur_kernel.getTotal();
					
					dest->setPixel(x, y, col);
					
					if ((src->getH() * x + y) % 10000 == 0)
						printf("%f%\n", 100.0f * (src->getH() * x + y) / (src->getW() * src->getH()));
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
	}
}

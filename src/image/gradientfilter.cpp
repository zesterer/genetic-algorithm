#include "gradientfilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* GradientFilter::applyToFSurface(FSurface* src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
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
					
					col.r = std::abs(col0.r - col1.r) + std::abs(col2.r - col3.r);
					col.g = std::abs(col0.g - col1.g) + std::abs(col2.g - col3.g);
					col.b = std::abs(col0.b - col1.b) + std::abs(col2.b - col3.b);;
					
					col = col.greyScale();
					
					dest->setPixel(x, y, col);
					
					/*FColour col = src->getPixel(x, y);
					
					col.r = 1.0f - col.r;
					col.g = 1.0f - col.g;
					col.b = 1.0f - col.b;
					
					dest->setPixel(x, y, col);*/
				}
			}
			
			return dest;
		}
	}
}

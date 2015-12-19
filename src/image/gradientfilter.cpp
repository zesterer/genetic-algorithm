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

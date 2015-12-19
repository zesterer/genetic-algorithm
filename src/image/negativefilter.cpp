#include "negativefilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* NegativeFilter::applyToFSurface(FSurface* src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col = src->getPixel(x, y);
					
					col.r = 1.0f - col.r;
					col.g = 1.0f - col.g;
					col.b = 1.0f - col.b;
					
					dest->setPixel(x, y, col);
				}
			}
			
			return dest;
		}
	}
}

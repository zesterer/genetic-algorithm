#include "thresholdfilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* ThresholdFilter::applyToFSurface(FSurface* src, bool delete_src, float threshold)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col = src->getPixel(x, y);
					
					if (col.r > threshold || col.g > threshold || col.b > threshold)
						dest->setPixel(x, y, col);
					else
						dest->setPixel(x, y, FColour(0.0, 0.0, 0.0, col.a));
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
	}
}

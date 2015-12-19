#include "huefilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* HueFilter::applyToFSurface(FSurface* src, bool delete_src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col = src->getPixel(x, y);
					
					float min = std::min(col.r, std::min(col.g, col.b));
					float max = std::max(col.r, std::max(col.g, col.b));
					
					float hue = 0.0f;
					
					if (col.r == max)
						hue = (col.g - col.b) / (max - min);
					else if (col.g == max)
						hue = 2.0f + (col.b - col.r) / (max - min);
					else
						hue = 4.0f + (col.r - col.g) / (max - min);
					
					hue /= 10.0f;
					hue -= (int)hue;
					
					dest->setPixel(x, y, FColour(hue, hue, hue, 1.0f));
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
	}
}

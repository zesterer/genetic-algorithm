#include "negativefilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* NegativeFilter::applyToFSurface(FSurface* surface)
		{
			for (int x = 0; x < surface->getW(); x ++)
			{
				for (int y = 0; y < surface->getH(); y ++)
				{
					FColour col = surface->getPixel(x, y);
					
					col.r = 1.0f - col.r;
					col.g = 1.0f - col.g;
					col.b = 1.0f - col.b;
					
					surface->setPixel(x, y, col);
				}
			}
			
			return surface;
		}
	}
}

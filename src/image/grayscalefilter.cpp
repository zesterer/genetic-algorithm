#include "grayscalefilter.h"

namespace AI
{
	namespace Image
	{
		FSurface* GrayscaleFilter::applyToFSurface(FSurface* src, bool delete_src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col = src->getPixel(x, y).toGrayscale();
					
					dest->setPixel(x, y, col);
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
	}
}

#include "sobelfilter.h"
#include "kernel.h"

namespace AI
{
	namespace Image
	{
		FSurface* SobelFilter::applyToFSurface(FSurface* src, bool delete_src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			float harray[9] = {-1.0f, 0.0f, 1.0f, -2.0f, 0.0f, 2.0f, -1.0f, 0.0f, 1.0f};
			Kernel hkernel(3, 3, harray);
			
			float varray[9] = {-1.0f, -2.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 1.0f};
			Kernel vkernel(3, 3, varray);
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					float v = std::sqrt(std::pow(hkernel.getValueFromFSurface(x - 1, y - 1, src, 0), 2) + std::pow(vkernel.getValueFromFSurface(x - 1, y - 1, src, 0), 2)) / 2.0f;
					
					col.r = v;
					col.g = v;
					col.b = v;
					
					dest->setPixel(x, y, col);
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
		
		FSurface* SobelFilter::applyToFSurfaceGradiented(FSurface* src, bool delete_src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			float harray[9] = {-1.0f, 0.0f, 1.0f, -2.0f, 0.0f, 2.0f, -1.0f, 0.0f, 1.0f};
			Kernel hkernel(3, 3, harray);
			
			float varray[9] = {-1.0f, -2.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 1.0f};
			Kernel vkernel(3, 3, varray);
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					col.r = std::abs(hkernel.getValueFromFSurface(x - 1, y - 1, src, 0)) / 2.0f;
					col.g = std::abs(vkernel.getValueFromFSurface(x - 1, y - 1, src, 1)) / 2.0f;
					col.b = 0.0f;
					
					dest->setPixel(x, y, col);
				}
			}
			
			if (delete_src)
				delete src;
			
			return dest;
		}
	}
}

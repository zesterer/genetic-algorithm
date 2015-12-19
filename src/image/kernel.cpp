#include "kernel.h"

namespace AI
{
	namespace Image
	{
		Kernel::Kernel(int w, int h)
		{
			this->w = w;
			this->h = h;
			
			this->clear();
		}
		
		int Kernel::sanifyX(int x)
		{
			return std::max(std::min(x, this->w - 1), 0);
		}
		
		int Kernel::sanifyY(int y)
		{
			return std::max(std::min(y, this->h - 1), 0);
		}
		
		void Kernel::clear()
		{
			this->pixels.clear();
			this->pixels.reserve(this->w * this->h);
			
			for (int i = 0; i < this->w * this->h; i ++)
				this->pixels.push_back(0.0f);
		}
		
		float Kernel::getPixel(int x, int y)
		{
			return this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)];
		}
		
		void Kernel::setPixel(int x, int y, float pixel)
		{
			this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)] = pixel;
		}
		
		FSurface* Kernel::applyToFSurface(FSurface* src)
		{
			FSurface* dest = new FSurface(src->getW(), src->getH());
			
			for (int x = 0; x < src->getW(); x ++)
			{
				for (int y = 0; y < src->getH(); y ++)
				{
					/*FColour col(1.0f, 1.0f, 1.0f, 1.0f);
					
					FColour col0 = src->getPixel(x - 1, y);
					FColour col1 = src->getPixel(x + 1, y);
					FColour col2 = src->getPixel(x, y - 1);
					FColour col3 = src->getPixel(x, y + 1);
					
					//printf("r=%fg=%fb=%fa=%f\n", col0.r, col0.b, col0.b, col0.a);
					
					col.r = std::sqrt(std::pow(col0.r - col1.r, 2) + std::pow(col2.r - col3.r, 2));
					col.g = std::sqrt(std::pow(col0.g - col1.g, 2) + std::pow(col2.g - col3.g, 2));
					col.b = std::sqrt(std::pow(col0.b - col1.b, 2) + std::pow(col2.b - col3.b, 2));
					
					col = col.greyScale();*/
					
					dest->setPixel(x, y, FColour(1.0f, 0.0f, 0.0f));
				}
			}
			
			return dest;
		}
	}
}

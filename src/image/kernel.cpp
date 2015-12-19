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
		
		float Kernel::getValueFromFSurface(int x, int y, FSurface* src, int channel)
		{
			float total = 0.0f;
			
			for (int xx = 0; xx < this->w; xx ++)
			{
				for (int yy = 0; yy < this->h; yy ++)
				{
					total += (src->getPixel(x + xx, y + yy)[channel] * this->getPixel(xx, yy)) / this->total;
				}
			}
			
			return total;
		}
		
		void Kernel::recalculate()
		{
			this->total = 0.0f;
			for (int i = 0; i < this->w * this->h; i ++)
				this->total += this->pixels[i];
		}
	}
}

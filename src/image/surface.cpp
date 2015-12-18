#include "surface.h"

namespace AI
{
	namespace Image
	{
		ISurface::ISurface(int w, int h)
		{
			this->w = w;
			this->h = h;
			
			this->clear();
		}
		
		void ISurface::clear()
		{
			this->pixels.clear();
			this->pixels.reserve(this->w * this->h);
			
			for (int i = 0; i < this->w * this->h; i ++)
				this->pixels.emplace_back();
		}
		
		FSurface::FSurface(int w, int h)
		{
			this->w = w;
			this->h = h;
			
			this->clear();
		}
		
		void FSurface::clear()
		{
			this->pixels.clear();
			this->pixels.reserve(this->w * this->h);
			
			for (int i = 0; i < this->w * this->h; i ++)
				this->pixels.emplace_back();
		}
	}
}

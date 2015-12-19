#include "surface.h"

namespace AI
{
	namespace Image
	{
		int Surface::getW()
		{
			return this->w;
		}
		
		int Surface::getH()
		{
			return this->h;
		}
		
		int Surface::sanifyX(int x)
		{
			return std::max(std::min(x, this->w - 1), 0);
		}
		
		int Surface::sanifyY(int y)
		{
			return std::max(std::min(y, this->h - 1), 0);
		}
		
		int Surface::sanifyI(int i)
		{
			return std::max(std::min(i, this->w * this->h - 1), 0);
		}
		
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
		
		void ISurface::setPixel(int x, int y, IColour colour)
		{
			this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)] = colour;
		}
		
		void ISurface::setPixel(int i, IColour colour)
		{
			this->pixels[this->sanifyI(i)] = colour;
		}
		
		sf::Texture* ISurface::convertToTexture()
		{
			sf::Image tmp;
			tmp.create(this->w, this->h, (sf::Uint8*)(void*)&this->pixels);
			
			sf::Texture* tex = new sf::Texture();
			tex->loadFromImage(tmp);
			
			return tex;
		}
		
		FSurface* ISurface::convertToFSurface()
		{
			FSurface* tmp = new FSurface(this->w, this->h);
			
			for (int i = 0; i < (int)this->pixels.size(); i ++)
				tmp->setPixel(i, this->pixels[i].toFColour());
			
			return tmp;
		}
		
		IColour ISurface::getPixel(int x, int y)
		{
			return this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)];
		}
		
		IColour ISurface::getPixel(int i)
		{
			return this->pixels[this->sanifyI(i)];
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
		
		void FSurface::setPixel(int x, int y, FColour colour)
		{
			this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)] = colour;
		}
		
		void FSurface::setPixel(int i, FColour colour)
		{
			this->pixels[this->sanifyI(i)] = colour;
		}
		
		ISurface* FSurface::convertToISurface()
		{
			ISurface* tmp = new ISurface(this->w, this->h);
			
			for (int i = 0; i < (int)this->pixels.size(); i ++)
				tmp->setPixel(i, this->pixels[i].toIColour());
			
			return tmp;
		}
		
		FColour FSurface::getPixel(int x, int y)
		{
			return this->pixels[this->w * this->sanifyY(y) + this->sanifyX(x)];
		}
		
		FColour FSurface::getPixel(int i)
		{
			return this->pixels[this->sanifyI(i)];
		}
		
		sf::Texture* FSurface::convertToTexture()
		{
			ISurface* isurf = this->convertToISurface();
			
			sf::Texture* tmp = isurf->convertToTexture();
			
			delete isurf;
			
			return tmp;
		}
	}
}

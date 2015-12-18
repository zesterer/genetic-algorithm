#ifndef IMAGE_LOADIMAGE_H
#define IMAGE_LOADIMAGE_H

#include "string"

#include "surface.h"

namespace AI
{
  	namespace Image
	{
	  	class ImageLoader
		{
			public:
				static ISurface loadPNG(std::string filename);
		}
	}
}

#endif

#ifndef IMAGE_IMAGELOADER_H
#define IMAGE_IMAGELOADER_H

#include "string"

#include "surface.h"

namespace AI
{
  	namespace Image
	{
	  	class ImageLoader
		{
			public:
				static FSurface* loadPNG(std::string filename);
		};
	}
}

#endif

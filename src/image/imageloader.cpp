#include "imageloader.h"

#include "FreeImage.h"

namespace AI
{
	namespace Image
	{
		ISurface* ImageLoader::loadPNG(std::string filename)
		{
			FIBITMAP* image = FreeImage_Load(FIF_PNG, filename.c_str(), PNG_DEFAULT);
			image = FreeImage_ConvertTo24Bits(image);
			
			if (image != nullptr)
			{
				//TODO - Load the image into an ISurface...
			}
		}
	}
}

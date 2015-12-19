#ifndef IMAGE_GRAYSCALEFILTER_H
#define IMAGE_GRAYSCALEFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct GrayscaleFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, bool delete_src = false);
		};
	}
}

#endif

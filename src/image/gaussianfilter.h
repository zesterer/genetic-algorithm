#ifndef IMAGE_GAUSSIANFILTER_H
#define IMAGE_GAUSSIANFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct GaussianFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, int radius = 4);
		};
	}
}

#endif

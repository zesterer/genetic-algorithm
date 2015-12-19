#ifndef IMAGE_FILTER_H
#define IMAGE_FILTER_H

#include "surface.h"

namespace AI
{
	namespace Image
	{
		struct Filter
		{
			static FSurface* applyToFSurface(FSurface* surface);
		};
	}
}

#endif

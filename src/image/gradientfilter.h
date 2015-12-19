#ifndef IMAGE_GRADIENTFILTER_H
#define IMAGE_GRADIENTFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct GradientFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, bool delete_src = false);
		};
	}
}

#endif

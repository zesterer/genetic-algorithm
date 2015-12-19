#ifndef IMAGE_THRESHOLDFILTER_H
#define IMAGE_THRESHOLDFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct ThresholdFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, bool delete_src = false, float threshold = 0.5);
		};
	}
}

#endif

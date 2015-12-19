#ifndef IMAGE_HUEFILTER_H
#define IMAGE_HUEFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct HueFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, bool delete_src = false);
		};
	}
}

#endif

#ifndef IMAGE_NEGATIVEFILTER_H
#define IMAGE_NEGATIVEFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct NegativeFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* surface);
		};
	}
}

#endif

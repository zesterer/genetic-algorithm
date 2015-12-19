#ifndef IMAGE_SOBELFILTER_H
#define IMAGE_SOBELFILTER_H

#include "filter.h"

namespace AI
{
	namespace Image
	{
		struct SobelFilter : public Filter
		{
			static FSurface* applyToFSurface(FSurface* src, bool delete_src = false);
			static FSurface* applyToFSurfaceGradiented(FSurface* src, bool delete_src = false);
		};
	}
}

#endif

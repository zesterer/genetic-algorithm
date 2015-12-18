#ifndef IMAGE_COLOUR_H
#define IMAGE_COLOUR_H

#include "types.h"

namespace AI
{
  	namespace Image
	{
	  	struct IColour;
	  	struct FColour;
	  	
	  	struct IColour
		{
		  	byte r = 0xff;
		  	byte g = 0xff;
		  	byte b = 0xff;
		  	byte a = 0xff;
		  
		  	IColour(byte r = 0xff, byte g = 0xff, byte b = 0xff, byte a = 0xff)
			{
			  	this->r = r;
			  	this->g = g;
			  	this->b = b;
			  	this->a = a;
			}
		  	
		  	inline FColour toFColour();
		};
	  	
	  	struct FColour
		{
		  	float r = 1.0f;
		  	float g = 1.0f;
		  	float b = 1.0f;
		  	float a = 1.0f;
		  
		  	FColour(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f)
			{
			  	this->r = r;
			  	this->g = g;
			  	this->b = b;
			  	this->a = a;
			}
		  
		  	inline IColour toIColour();
		};
	  
	  	FColour IColour::toFColour()
		{
		  	return FColour(this->r / 256.0f, this->g / 256.0f, this->b / 256.0f, this->a / 256.0f);
		}
	  
	  	IColour FColour::toIColour()
		{
		  	return IColour((byte)(this->r * 256), (byte)(this->g * 256), (byte)(this->b * 256), (byte)(this->a * 256));
		}
	}
}

#endif

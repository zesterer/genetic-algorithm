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
			
			IColour greyScale()
		  	{
		  		int avg = (this->r + this->g + this->b) / 3;
		  		return IColour(avg, avg, avg, this->a);
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
		  	
		  	FColour greyScale()
		  	{
		  		float avg = (this->r + this->g + this->b) / 3.0f;
		  		return FColour(avg, avg, avg, this->a);
		  	}
		};
	  
	  	FColour IColour::toFColour()
		{
		  	return FColour(this->r / 256.0f, this->g / 256.0f, this->b / 256.0f, this->a / 256.0f);
		}
	  
	  	IColour FColour::toIColour()
		{
		  	return IColour((byte)std::max(std::min((this->r * 256), 255.0f), 0.0f), (byte)std::max(std::min((this->g * 256), 255.0f), 0.0f), (byte)std::max(std::min((this->b * 256), 255.0f), 0.0f), (byte)std::max(std::min((this->a * 256), 255.0f), 0.0f));
		}
	}
}

#endif

#ifndef RANDOMLAYOUT
#define RANDOMLAYOUT

#include "ICloudLayout.h"
#include "WordMap.h"
#include "Point.h"

class RandomLayout:ICloudLayout
{
	public:
		RandomLayout();
		~RandomLayout();
		void setLocation(WordMap * wmap);
};

#endif

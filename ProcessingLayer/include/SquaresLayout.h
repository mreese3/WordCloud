#ifndef SQUARESLAYOUT_H
#define SQUARESLAYOUT_H

#include "ICloudLayout.h"
#include "WordMap.h"
#include "Point.h"

class SquaresLayout : public ICloudLayout
{
public:
	void setLocation(WordMap *wmap);
    //pre: Valid wordmap
    //post: Places the words randomly in a square shape
	SquaresLayout();
	~SquaresLayout();	
};

#endif

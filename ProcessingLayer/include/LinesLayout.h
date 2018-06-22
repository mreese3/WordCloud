#ifndef LINESLAYOUT_H
#define LINESLAYOUT_H

#include "ICloudLayout.h"
#include "WordMap.h"
#include "Point.h"

using namespace std;

class LinesLayout : public ICloudLayout
{
private:
	
public:
	LinesLayout();
	void setLocation(WordMap * map);
	ICloudLayout * NewLayout();
	~LinesLayout();
};
#endif

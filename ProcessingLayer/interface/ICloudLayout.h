//ICloudLayout is used by many other methods as implementation
//Changes may take place depending on changes of type or object changes

#ifndef ICLOUDLAYOUT_H
#define ICLOUDLAYOUT_H
#include "WordMap.h"
using namespace std;

class ICloudLayout{
public:
	virtual void setLocation(WordMap*) = 0;
	//virtual ICloudLayout() = 0;
	virtual ~ICloudLayout(){};
};
#endif
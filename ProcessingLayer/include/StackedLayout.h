//StackedLayout implements from the ICloudLayout 
//Method names and types may change in the future to better suit other groups

#ifndef STACKEDLAYOUT_H
#define STACKEDLAYOUT_H
#include "iCloudLayout.h"
#include "WordMap.h"
#include "Point.h"

using namespace std;

class StackedLayout : ICloudLayout{
public:
	StackedLayout();
	~StackedLayout();
	void setLocation(WordMap* map);
};
#endif
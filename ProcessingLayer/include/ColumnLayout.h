#ifndef COLUMNLAYOUT_H
#define COLUMNLAYOUT_H

#include "ICloudLayout.h"


class ColumnLayout : public ICloudLayout
{
private:
	//Point locationHandler;
public:
	ColumnLayout(/*WordMap * */);
	~ColumnLayout();
	void setLocation(WordMap * map);
	ICloudLayout * NewLayout();
};

#endif
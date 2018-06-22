#include "ColumnLayout.h"
#include "ICloudLayout.h"

ColumnLayout::ColumnLayout()
{

}
ColumnLayout::~ColumnLayout()
{

}
void ColumnLayout::setLocations(WordMap * map)
{

}
ICloudLayout * ColumnLayout::NewLayout()
{
	return new ColumnLayout();
}
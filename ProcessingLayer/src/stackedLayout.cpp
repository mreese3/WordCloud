//StackedLayout implements from the ICloudLayout 
//Method names and types may change in the future to better suit other groups
#include "StackedLayout.h"
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include "ICloudLayout.h"

StackedLayout::StackedLayout(){}

void StackedLayout::setLocation(WordMap* map){
	IRenderFactory* rfactory = NewRenderFactory();
	IRenderUtil*    rutil = (*rfactory).NewRenderUtil();
	WordMap* workingmap = new WordMap();
	Point* zeropoint = new Point();
	(*zeropoint).setX(0);
	(*zeropoint).setY(0);

	Size* zerosize = new Size();
	(*zerosize).setHeight(0);
	(*zerosize).setWidth(0);

	MapItem xmap = MapItem();
	xmap.setFontSize(0);
	xmap.setLocation(zeropoint);
	xmap.setWord("");
	xmap.setSize(zerosize);

	int height = 0, width = 0;
	int adjX = 0, adjY = 0;
	MapItem temp = MapItem();

	map->sizeSort();
	while (!((*map).isEmpty()))
	{
		xmap = (*map).popNext();
		height = (*rutil).getHeight(xmap.getFontSize());
		width = (*rutil).getWidth(xmap.getFontSize(), xmap.getWord());
		(*(xmap.getLocation())).setX(width + adjX);
		(*(xmap.getLocation())).setY(height + adjY);
		(*workingmap).append(xmap);

		if (!(*map).isEmpty()){
			temp = (*map).peekNext();
			if (temp.getFontSize() > xmap.getFontSize()){
				adjY += 50;
				adjX = 0;
			}

			else
				adjX += 50;

			if (adjX >= 8500){
				adjX = 0;
				adjY += 50;
			}
		}
	}

	while (!((*workingmap).isEmpty())) 
	{
		xmap = (*workingmap).popNext();
		(*map).append(xmap);
	}
}

StackedLayout::~StackedLayout(){}
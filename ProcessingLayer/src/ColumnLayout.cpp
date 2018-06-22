#include "ColumnLayout.h"
#include "ICloudLayout.h"
#include "IRenderUtil.h"
#include "IRenderFactory.h"

//#define COLUMNLAYOUTHORIZONTALSPACING 100
#define COLUMNLAYOUTVERTICALSPACING 10

ColumnLayout::ColumnLayout()
{
	
}
ColumnLayout::~ColumnLayout()
{
	
}
void ColumnLayout::setLocation(WordMap * map)
{
	IRenderFactory* rfactory = NewRenderFactory();
	IRenderUtil*	rutil = (*rfactory).NewRenderUtil();
	WordMap* workingmap = new WordMap();

	int zerofontsize = 0;
	string zeroword = "";
	Point* zeropoint = new Point();
	(*zeropoint).setX(0);
	(*zeropoint).setY(0);

	Size* zerosize = new Size();
	(*zerosize).setHeight(0);
	(*zerosize).setWidth(0);

	MapItem blankitem = MapItem();
	blankitem.setFontSize(zerofontsize);
	blankitem.setLocation(zeropoint);
	blankitem.setWord(zeroword);
	blankitem.setSize(zerosize);

	MapItem workingitem = blankitem;
	MapItem lastitem = blankitem;

	int remainingheight = POINTYMAX;
	int currentheight = 0;
	int currentwidth = 0;
	int lastheight = 0;
	int totalwidth = 0;
	int wordcount = 0;
	int widestincolumn = 0;
	
	while (!((*map).isEmpty())) 
	{
		workingitem = (*map).popNext();

		currentheight = (*rutil).getHeight(workingitem.getFontSize());
		currentwidth = (*rutil).getWidth(workingitem.getFontSize(), workingitem.getWord());
		lastheight = (*rutil).getHeight(lastitem.getFontSize());

		//currentheight += ((*lastitem.getLocation()).getX() + lastheight + COLUMNLAYOUTVERTICALSPACING);

		if (wordcount == 0)
		{
			(*(workingitem.getLocation())).setX(0);
			(*(workingitem.getLocation())).setY(0);
			remainingheight -= currentheight;
		}

		else
		{
			if (currentheight > remainingheight)
			{
				(*(workingitem.getLocation())).setY(0);
				totalwidth += widestincolumn;
				(*(workingitem.getLocation())).setX(totalwidth);
				remainingheight = POINTYMAX;
				widestincolumn = 0;
			}

			else 
			{
				(*(workingitem.getLocation())).setY(
					(*(lastitem.getLocation())).getY() + lastheight + COLUMNLAYOUTVERTICALSPACING);
				(*(workingitem.getLocation())).setX(totalwidth);
				remainingheight -= currentheight;
			}
		}

		if (currentwidth > widestincolumn)
			widestincolumn = currentwidth;

		wordcount++;

		lastitem = workingitem;

		(*workingmap).append(workingitem);
	}

	while (!((*workingmap).isEmpty())) {

		workingitem = (*workingmap).popNext();
		(*map).append(workingitem);
	}

	delete workingmap;
	delete zeropoint;
	delete zerosize;
}

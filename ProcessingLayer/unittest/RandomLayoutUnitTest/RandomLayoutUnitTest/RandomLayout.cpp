#include "randomLayout.h"
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include "ICloudLayout.h"

RandomLayout::RandomLayout()
{

}

void RandomLayout::setLocation(WordMap *map)
{

	// Create RenderUtil, using factory pattern.
	IRenderFactory* rfactory = NewRenderFactory();
	IRenderUtil*    rutil = (*rfactory).NewRenderUtil();
	// A new WordMap pointer, for storing previously iterated MapItems
	WordMap* workingmap = new WordMap();

	// ================================
	// BLANK MAPITEM FOR COMPARISON

	// Zero values for MapItem properties
	int zerofontsize = 0;
	string zeroword = "";
	// Point object pointer, initilized to zero
	Point* zeropoint = new Point();
	(*zeropoint).setX(0);
	(*zeropoint).setY(0);
	// Size object pointer, preset to zero. You may need to make another 
	// size object pointer later if your code requires it.
	Size* zerosize = new Size();
	(*zerosize).setHeight(0);
	(*zerosize).setWidth(0);

	// Set the blank item
	MapItem blankitem = MapItem();
	blankitem.setFontSize(zerofontsize);
	blankitem.setLocation(zeropoint);
	blankitem.setWord(zeroword);
	blankitem.setSize(zerosize);

	// BLANK MAPITEM FOR COMPARISON
	// ================================

	// The current MapItem, pulled from the workingmap
	// is initialized to the empty item.
	MapItem workingitem = blankitem;


	//Size of current item
	int currentheight = 0;
	int currentwidth = 0;

	while (!((*map).isEmpty()))
	{
		workingitem = (*map).popNext();
		// Set current height and width of the word
		// Save the width from the last item as well.
		currentheight = (*rutil).getHeight(workingitem.getFontSize());
		currentwidth = (*rutil).getWidth(workingitem.getFontSize(), workingitem.getWord());

		(*(workingitem.getLocation())).setX(rand() % 8500);
		(*(workingitem.getLocation())).setY(rand() % 1099);
	}

	// Empty the holding map, and add the modified items back into the passed map.
	while (!((*workingmap).isEmpty())) 
	{
		// Remember Towers of Hanoi
		// Pop off one, push another
		workingitem = (*workingmap).popNext();
		(*map).append(workingitem);
	}

	// Delete what you new! Memory leaks are bad
	delete workingmap;
	delete zeropoint;
	delete zerosize;	
}

RandomLayout::~RandomLayout()
{

}

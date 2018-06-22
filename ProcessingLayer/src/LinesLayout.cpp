#include "LinesLayout.h"
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include "ICloudLayout.h"


// Constants used for horizontal and vertical word spacing
// These have been found by multiple test runs, but can easily be changed
// at compile time.
#define LINESLAYOUTVERTICALSPACING 10
#define LINESLAYOUTHORIZONTALSPACING 100

LinesLayout::LinesLayout() {
	}

void LinesLayout::setLocation(WordMap * map) {

        // Create RenderUtil, using factory pattern.
        IRenderFactory* rfactory        = NewRenderFactory();
        IRenderUtil*    rutil           = (*rfactory).NewRenderUtil();
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

        // A Mapitem for storing the last MapItem operated on. This is changed
        // right before the end of processing while loop.
        MapItem lastitem = blankitem;


        // LinesLayout specific variables
        // height of the tallest item, on the line.
        // Height of current item
	// Width occupied on line
        // Width of current item
	// Row y value
	// Current word number
        int tallestonline       = 0;
        int currentheight       = 0;
		int usedwidth			= 0;
        int currentwidth        = 0;
        int lastwidth           = 0;
        int rowyvalue 	        = 0;
        int wordcount           = 0;

	while(!((*map).isEmpty())) {
		
		workingitem = (*map).popNext();
		// Set current height and width of the word
                // Save the width from the last item as well.
                currentheight   = (*rutil).getHeight(workingitem.getFontSize());
                currentwidth    = (*rutil).getWidth(workingitem.getFontSize(), workingitem.getWord());
                lastwidth       = (*rutil).getWidth(lastitem.getFontSize(), lastitem.getWord());


		// If we are on the first item, set X and Y to 0.
		// This is a functional shortcut, to avoid needless references to the empty item.
		if (wordcount == 0) {
			// Set the location of the first item, using in-place pointer dereference
			// Since it's the first item, it just goes to zero
                        (*(workingitem.getLocation())).setX(0);
                        (*(workingitem.getLocation())).setY(0);
			}

		// Otherwise, we need to detirmine if this word will fit or not.
		else {
			// We need to check if the word will fit.
			// If it won't, we're going to start a new line, and reset the used width
			// back to 0
			// This line is long, but is really just currentwidth + 100 > 8400
			// In general, overun is rare, but can happen with this arrangement.
			if ((usedwidth + currentwidth + LINESLAYOUTHORIZONTALSPACING) > (POINTXMAX - LINESLAYOUTHORIZONTALSPACING)) {
				// Set x to 0 by dereferencing workingitem.getLocation()
				(*(workingitem.getLocation())).setX(0);
				rowyvalue += tallestonline + LINESLAYOUTVERTICALSPACING;
				// Set y to the current row value	
				(*(workingitem.getLocation())).setY(rowyvalue);

				usedwidth = 0;
				// Since we started a new line, we need to reset the linehieght
				tallestonline = currentheight;
				}

			// Otherwise, it's going to fit, so we just place it and move on.
			else {
				// Set X
				(*(workingitem.getLocation())).setX(
					(*(lastitem.getLocation())).getX() + lastwidth + LINESLAYOUTHORIZONTALSPACING);

				// Set Y
				(*(workingitem.getLocation())).setY(rowyvalue);
				}
			}
	
		// If the word's height is taller than the previous tallest on the line,
		// set tallest to the new word!
		// This is used to adjust the line start position
		if (currentheight > tallestonline) {
			tallestonline = currentheight;
			}


		// =======THIS HANDLES THE WIDTH COUNTER============================
		// Increment used width and attempt to avoid overruns
		// This can be adjusted to detirmine the relative width of the layout.
		usedwidth = ((*workingitem.getLocation()).getX() + (currentwidth));

		//Increment the wordcount, though we really only care if the item is the first
		wordcount++;

		// Save the last item touched, so that we can handle comparisons
		// This mostly used for sequential item placement.
		lastitem = workingitem;

		// Push the changed MapItem into the holding Map.
		// We'll restuff the passed map at the end of the loop,
		// allowing this map to be deleted
		(*workingmap).append(workingitem);
		}

	// Empty the holding map, and add the modified items back into the passed map.
	while(!((*workingmap).isEmpty())) {
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

LinesLayout::~LinesLayout() {
	}

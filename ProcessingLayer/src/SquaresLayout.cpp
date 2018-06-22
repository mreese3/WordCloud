#include "SquaresLayout.h"
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include <iostream>
#include <string>
using namespace std;



void SquaresLayout::setLocation(WordMap *wmap)
	{
		IRenderFactory *irfactory = NewRenderFactory();
		IRenderUtil * irutil = irfactory->NewRenderUtil();
		MapItem curItem;
		WordMap* workingmap = new WordMap();
		int direction = 0;
		int cur_x = 0;
		int cur_y = 0;
		int top_buffer = 0;
		int left_buffer = 0;
		int right_buffer = POINTXMAX - 1200;
		int bottom_buffer = POINTYMAX;
		int maxwidth = 0;
		int maxheight = 0;
		bool ready = true;
		//0 = moving from top left to top right
		//1 = moving from top right to bottom right
		//2 = moving from bottom right to bottom left
		//3 = moving from bottom left to top left
		while (!wmap->isEmpty())
		{
			if (ready)
			{
				curItem = wmap->popNext();
				ready = false;
			}
			if(direction == 0)
			{
				if (cur_x + curItem.getSize()->getWidth() < right_buffer)
				{
					//Traverse to the right
					curItem.getLocation()->setX(cur_x);
					curItem.getLocation()->setY(cur_y);
					cur_x += curItem.getSize()->getWidth() + 100;
					ready = true;
					if (curItem.getSize()->getHeight() > maxheight)
						maxheight = curItem.getSize()->getHeight();
				}
				else
				{
					direction = 1;
					right_buffer = cur_x;
					top_buffer += maxheight + 10;
					maxheight = 0;
				}
			}
			if (direction == 1)
			{
				if (cur_y + curItem.getSize()->getHeight() < bottom_buffer)
				{
					//Traverse down
					cur_x = right_buffer - curItem.getSize()->getWidth();
					cur_y += curItem.getSize()->getHeight() + 10;
					curItem.getLocation()->setX(cur_x);
					curItem.getLocation()->setY(cur_y);
					if (curItem.getSize()->getWidth() > maxwidth)
						maxwidth = curItem.getSize()->getWidth();
					ready = true;
				}
				else
				{
					//cur_y = bottom_buffer;
					direction = 2;
					bottom_buffer = cur_y;
					right_buffer -= maxwidth + 100;
				}
			}
			if (direction == 2)
			{
				if (cur_x - (curItem.getSize()->getWidth() + 100) > left_buffer)
				{
					//Traverse left
					cur_x -= curItem.getSize()->getWidth() + 100;
					curItem.getLocation()->setX(cur_x);
					curItem.getLocation()->setY(cur_y);
					ready = true;
					if (curItem.getSize()->getHeight() > maxheight)
						maxheight = curItem.getSize()->getHeight();
				}
				else
				{
					direction = 3;
					//cur_x = left_buffer;
					//left_buffer += curItem.getSize()->getWidth();
					left_buffer = cur_x;
					bottom_buffer -= maxheight + 30;
				}
			}
			if (direction == 3)
			{
				if (cur_y > top_buffer)
				{
					//Traverse up
					cur_y -= curItem.getSize()->getHeight() + 10;
					curItem.getLocation()->setX(cur_x);
					curItem.getLocation()->setY(cur_y);
					ready = true;
					if (curItem.getSize()->getWidth() > maxwidth)
						maxwidth = curItem.getSize()->getWidth();
				}
				else
				{
					direction = 0;
					left_buffer += maxwidth + 10;
					top_buffer = cur_y;
					cur_x = left_buffer;
				}
			}
			if (ready)
				workingmap->append(curItem);
		}
		while (!workingmap->isEmpty())
		{
			curItem = workingmap->popNext();
			cout << curItem.getWord() << "," << curItem.getLocation()->getX() << "," << curItem.getLocation()->getY() << endl;
			wmap->append(curItem);
			
		}

	}
	SquaresLayout::SquaresLayout()
	{

	}
	SquaresLayout::~SquaresLayout()
	{

	}	
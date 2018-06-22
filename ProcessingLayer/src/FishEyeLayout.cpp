#include "FishEyeLayout.h"
#include "ICloudLayout.h"
#include "IRenderUtil.h"
#include "IRenderFactory.h"
#include "Point.h"

FishEyeLayout::FishEyeLayout() {}

FishEyeLayout::~FishEyeLayout() {}

void FishEyeLayout::setLocation(WordMap * word_map) {

	IRenderFactory* rfactory = NewRenderFactory();
	IRenderUtil*	rutil = (*rfactory).NewRenderUtil();
	
	Point *point = new Point();
	//Get the min and max coordinates for the page:
	max_y = point->get_max_y();
	max_x = point->get_max_x();
	min_y = point->get_min_y();
	min_x = point->get_min_x();

	//Find the width and height of the page
	width_page = max_x - min_x;
	height_page = max_y - min_y;

	//Find the center most point in the page
	center_x = width_page / 2;
	center_y = height_page / 2;
	//////////////////////////////////////////////////

	//////////////////////////////////////////////////
	int current_width_word,current_height_word;
	int previous_width_word, previous_height_word;
	/////////////////////////////////////////////////

	WordMap *working_wordmap = new WordMap();

	//Get the map items and first sort them in ascending order
	word_map->sizeSort();

	MapItem temp_item;

	while (!((*word_map).isEmpty())) {
		
		temp_item = (*word_map).popNext();
		current_height_word= (*rutil).getHeight(temp_item.getFontSize());
		current_width_word= (*rutil).getWidth(temp_item.getFontSize(), temp_item.getWord());
		Point *point = new Point();
		point->setX(center_x);
		point->setY(center_y);
		temp_item.setLocation(point);
		Size *size = new Size();
		size->setHeight(current_height_word);
		size->setWidth(current_width_word);
		temp_item.setSize(size);
		
		if(center_y>min_y)
			center_y = center_y - current_height_word;
		
		(*working_wordmap).append(temp_item);
	}

	MapItem temp2_item;
	while (!((*working_wordmap).isEmpty())) {
		temp2_item = (*working_wordmap).popNext();
		(*word_map).append(temp2_item);
	}

}

ICloudLayout *NewLayout() //factory function to generate Fisheye Layout object
{
	return new FishEyeLayout();
}
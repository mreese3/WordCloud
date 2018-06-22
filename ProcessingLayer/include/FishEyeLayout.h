#ifndef FISHEYELAYOUT_H
#define FISHEYELAYOUT_H

#include "ICloudLayout.h"
#include "WordMap.h"
#include "Point.h"

using namespace std;

class FishEyeLayout : public ICloudLayout
{
	public:
		FishEyeLayout();
		void setLocation(WordMap * map);
		~FishEyeLayout();
	
	private:
		int max_y, max_x, min_y, min_x;
		int width_page, height_page;
		int center_x, center_y;

};
#endif
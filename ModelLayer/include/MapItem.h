#if !defined(MAPITEM_H)
#define MAPITEM_H

#include <string>
#include "Point.h"
#include "Size.h"

class MapItem {
private:
	std::string word;
	int fontSize;
	Point* location;
	Size* size;
public:
	MapItem();
	std::string getWord();
	int getFontSize();
	Point* getLocation();
	Size* getSize();
	void setWord(std::string);
	/*
	* fontSize is an int representing the size of the font.
	* range is 0-9
	*/
	void setFontSize(int);
	void setLocation(Point*);
	void setSize(Size*);
	/*
	* String format is:
	* word;Font;LocX;LocY;sizeW;sizeH
	*/
	std::string toString();
	void fromString(std::string);
	~MapItem();
};
#endif
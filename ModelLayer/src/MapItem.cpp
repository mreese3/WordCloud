#include "MapItem.h"
#define FMAX 9
#define FMIN 0
using namespace std;

MapItem::MapItem() {

}
MapItem::~MapItem() {

}
string
MapItem::getWord() {
	return word;
}
int
MapItem::getFontSize() {
	return fontSize;
}
Point*
MapItem::getLocation() {
	return location;
}
Size*
MapItem::getSize() {
	return size;
}
void
MapItem::setWord(string str) {
	word = str;
}
void
MapItem::setFontSize(int f) {
	if (f < FMIN)
		fontSize = FMIN;
	else if (f > FMAX)
		fontSize = FMAX;
	else
		fontSize = f;
}
void
MapItem::setLocation(Point* p) {
	location = p;
}
void
MapItem::setSize(Size* s) {
	size = s;
}
string
MapItem::toString() {
	string str = word;
	string sc = ";";
	str += sc + to_string(fontSize) + sc += to_string(location->getX()) + sc + to_string(location->getY()) + sc
		+ to_string(size->getWidth()) + sc + to_string(size->getHeight()) + sc;
	return (str);
}
void
MapItem::fromString(string str) {
	int count = 0;
	string s1, s2;
	size_t r;
	Point* pTemp = new Point();
	Size* sTemp = new Size();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ';')
			count += 1;
	}
	if (count == 6) {
		r = str.find(';');
		s1 = str.substr(0, r);
		s2 = str.substr(++r, str.length());
		setWord(s1);
		r = s2.find(';');
		s1 = s2.substr(0, r);
		s2 = s2.substr(++r, s2.length());
		setFontSize(stoi(s1, nullptr, 10));
		r = s2.find(';');
		s1 = s2.substr(0, r);
		s2 = s2.substr(++r, s2.length());
		pTemp->setX(stoi(s1, nullptr, 10));
		r = s2.find(';');
		s1 = s2.substr(0, r);
		s2 = s2.substr(++r, s2.length());
		pTemp->setY(stoi(s1, nullptr, 10));
		r = s2.find(';');
		s1 = s2.substr(0, r);
		s2 = s2.substr(++r, s2.length());
		sTemp->setWidth(stoi(s1, nullptr, 10));
		r = s2.find(';');
		s1 = s2.substr(0, r);
		sTemp->setHeight(stoi(s1, nullptr, 10));
	}
	else {
		setWord("");
		setFontSize(0);
		pTemp->setX(0);
		pTemp->setY(0);
		sTemp->setWidth(0);
		sTemp->setHeight(0);
	}
	setLocation(pTemp);
	setSize(sTemp);
}

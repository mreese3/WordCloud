// Testing MapItem+Point+Size

#include "MapItem.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Creating Size object...\n";
	Size size = Size();

	cout << "Size: setWidth(132) and setHeight(852) (within normal range)...\n";
	size.setWidth(132);
	size.setHeight(852);
	cout << "Returns: " << size.getWidth() << " " << size.getHeight() << "\n";

	cout << "Size: setWidth(-132) and setHeight(30852) (out of range 1)...\n";
	size.setWidth(-132);
	size.setHeight(30852);
	cout << "Returns: " << size.getWidth() << " " << size.getHeight() << "\n";

	cout << "Size: setWidth(9000) and setHeight(-852) (out of range 2)...\n";
	size.setWidth(9000);
	size.setHeight(-852);
	cout << "Returns: " << size.getWidth() << " " << size.getHeight() << "\n";

	cout << "Creating Point object...\n";
	Point point = Point();

	cout << "Point: setX(132) and setY(852) (within normal range)...\n";
	point.setX(132);
	point.setY(852);
	cout << "Returns: " << point.getX() << " " << point.getY() << "\n";

	cout << "Point: setX(-132) and setY(30852) (out of range 1)...\n";
	point.setX(-132);
	point.setY(30852);
	cout << "Returns: " << point.getX() << " " << point.getY() << "\n";

	cout << "Point: setX(9000) and setY(-852) (out of range 2)...\n";
	point.setX(9000);
	point.setY(-852);
	cout << "Returns: " << point.getX() << " " << point.getY() << "\n";

	cout << "Creating MapItem...\n";
	MapItem mapItem;
	mapItem.setWord("magus");
	mapItem.setFontSize(5);
	Size *sizePtr = new Size();
	sizePtr->setHeight(500);
	sizePtr->setWidth(386);
	mapItem.setSize(sizePtr);
	Point *pointPtr = new Point();
	pointPtr->setX(159);
	pointPtr->setY(356);
	mapItem.setLocation(pointPtr);
	cout << "Expected output with toString() = magus;5;159;356;386;500;\n"
		<< "Actual output = " << mapItem.toString() << "\n";

	cout << "Testing fromString(miles;4;345;654;234;734;)...\n";
	mapItem.fromString("miles;4;345;654;234;734;");
	cout << "Output from toString(): " << mapItem.toString() + "\n";
	cout << "Output from getters: " 
		<< mapItem.getWord() << "\t" << mapItem.getFontSize() << "\t" 
		<< mapItem.getLocation()->getX() << "\t" << mapItem.getLocation()->getY() << "\t"
		<< mapItem.getSize()->getWidth() << "\t" << mapItem.getSize()->getHeight() << "\n";

	system("pause");
	return 0;
}
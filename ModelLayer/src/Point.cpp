#include "Point.h"

Point::Point() {

}
Point::~Point() {

}
int
Point::getX() {
	return X;
}
int
Point::getY() {
	return Y;
}
void
Point::setX(int x) {
	if (x < POINTXMIN)
		X = POINTXMIN;
	else if (x > POINTXMAX)
		X = POINTXMAX;
	else
		X = x;
}
void
Point::setY(int y) {
	if (y < POINTYMIN)
		Y = POINTYMIN;
	else if (y > POINTYMAX)
		Y = POINTYMAX;
	else
		Y = y;
}

//adding two functions--by group six for returning the max and min x and y coordinates

/*
int Point::get_min_x() {
return POINTXMIN;
}

int Point::get_min_y() {
return POINTYMIN;
}

int Point::get_max_x() {
return POINTXMAX;
}

int Point::get_max_y() {
return POINTYMAX;
}*/

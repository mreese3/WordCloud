#include "Size.h"
#define HMAX 10999
#define WMAX 8499
#define HMIN 0
#define WMIN 0

Size::Size() {

}
Size::~Size() {

}
int
Size::getWidth() {
	return Width;
}
int
Size::getHeight() {
	return Height;
}
void
Size::setHeight(int h) {
	if (h < HMIN)
		Height = HMIN;
	else if (h > HMAX)
		Height = HMAX;
	else
		Height = h;
}
void
Size::setWidth(int w) {
	if (w < WMIN)
		Width = WMIN;
	else if (w > WMAX)
		Width = WMAX;
	else
		Width = w;
}
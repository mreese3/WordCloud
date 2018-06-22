// IRenderUtil.h

#ifndef IRENDERUTIL_H
#define IRENDERUTIL_H
#include <string>
using namespace std;

class IRenderUtil
{
	public:
		virtual string fontSizeToKeyWord(int fontSize) = 0;
		virtual double scale_X_Coordinate(int x) = 0;
		virtual double scale_Y_Coordinate(int y) = 0;
		virtual int getHeight(int fontSize) = 0;
		virtual int getWidth(int fontSize, string word) = 0;
		virtual ~IRenderUtil(){};
};
#endif
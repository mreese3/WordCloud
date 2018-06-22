// LatexUtil.h

#ifndef LATEXUTIL_H
#define LATEXUTIL_H
#include "IRenderUtil.h"
using namespace std;

class LatexUtil : public IRenderUtil
{
	public:
		LatexUtil( );
		virtual string fontSizeToKeyWord(int fontSize);
		virtual double scale_X_Coordinate(int x);
		virtual double scale_Y_Coordinate(int y);
		virtual int getHeight(int fontSize);
		virtual int getWidth(int fontSize, string word);
		virtual ~LatexUtil();
};
#endif
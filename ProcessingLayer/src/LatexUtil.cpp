// LatexUtil.cpp

#include "LatexUtil.h"
using namespace std;

LatexUtil::LatexUtil()
{

}

string LatexUtil::fontSizeToKeyWord(int fontSize)
{
	if (fontSize == 0)
	{
		return "\\tiny";
	}
	else if (fontSize == 1)
	{
		return "\\scriptsize";
	}
	else if (fontSize == 2)
	{
		return "\\footnotesize";
	}
	else if (fontSize == 3)
	{
		return "\\small";
	}
	else if (fontSize == 4)
	{
		return "\\normalsize";
	}
	else if (fontSize == 5)
	{
		return "\\large";
	}
	else if (fontSize == 6)
	{
		return "\\Large";
	}
	else if (fontSize == 7)
	{
		return "\\LARGE";
	}
	else if (fontSize == 8)
	{
		return "\\huge";
	}
	else if (fontSize == 9)
	{
		return "\\Huge";
	}
	return "";
}

double LatexUtil::scale_X_Coordinate(int x)
{	
	return x / 100.0;
}

double LatexUtil::scale_Y_Coordinate(int y)
{
	return y / 100.0;
}

int LatexUtil::getHeight(int fontSize)
{
	const double pt_To_mm = .35136;
	const double mm_To_in = .0393701;
	const double in_To_LatexCoord = 15.714;
	const double LatexCoord_To_PointCoord = 100;
	double pointSize = 0;
	if (fontSize == 0)
	{
		pointSize = 6;
	}
	else if (fontSize == 1)
	{
		pointSize = 8;
	}
	else if (fontSize == 2)
	{
		pointSize = 9;
	}
	else if (fontSize == 3)
	{
		pointSize = 10;
	}
	else if (fontSize == 4)
	{
		pointSize = 10.95;
	}
	else if (fontSize == 5)
	{
		pointSize = 12;
	}
	else if (fontSize == 6)
	{
		pointSize = 14.4;
	}
	else if (fontSize == 7)
	{
		pointSize = 17.28;
	}
	else if (fontSize == 8)
	{
		pointSize = 20.74;
	}
	else if (fontSize == 9)
	{
		pointSize = 24.88;
	}
	// To do list: Round the pointSize before returning. Otherwise, the result will be truncated.
	return pointSize * pt_To_mm * mm_To_in * in_To_LatexCoord * LatexCoord_To_PointCoord;
}

int LatexUtil::getWidth(int fontSize, string word)
{
	int numChar = word.length();
	int charWidth = getHeight(fontSize);
	return numChar * charWidth / 3;
}

LatexUtil::~LatexUtil()
{

}
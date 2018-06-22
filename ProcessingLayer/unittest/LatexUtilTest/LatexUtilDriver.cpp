// LatexUtilDriver.cpp (The main .cpp file.)

#include "LatexUtil.h"
#include <iostream>
using namespace std;

int main()
{
	LatexUtil* albert = new LatexUtil();
	cout << "Expecting:\n(empty string)\n\\tiny\n\\small" << endl << "---" << endl;
	for (int i = -1; i <= 10; i++)
	{
		cout << albert->fontSizeToKeyWord(i) << endl;
	}
	cout << "---" << endl;

	cout << "Expecting height 130" << endl;
	cout << albert->getHeight(0) << endl;

	cout << "Expecting height 217" << endl;
	cout << albert->getHeight(3) << endl;

	cout << "Expecting height 375" << endl;
	cout << albert->getHeight(7) << endl;

	cout << "Expecting height 540" << endl;
	cout << albert->getHeight(9) << endl;

	cout << "Expecting width 506" << endl;
	cout << albert->getWidth(3, "learnin") << endl;

	cout << "Expecting width 1126" << endl;
	cout << albert->getWidth(5, "opportunities") << endl;

	cout << "Expecting width 834" << endl;
	cout << albert->getWidth(6, "identity") << endl;

	cout << "Expecting width 1000" << endl;
	cout << albert->getWidth(7, "teaching") << endl;
	
	cout << endl;
	system("pause");
	return 0;
}
#include "IRenderFactory.h"
#include "IRenderUtil.h"
#include "IRenderMaker.h"

#include <iostream>

int main()
{
	IRenderFactory * test = NewRenderFactory();

	IRenderUtil* util = test -> NewRenderUtil();
	cout << "Calling a method in IRenderUtil just to check that the object is good" << endl;
	cout << "(Using the real LatexUtil, not a stub, because it's available)" << endl;
	cout << "height of a word is " << util->getHeight(3) << " page layout units." << endl;
	cout << endl;

	IRenderMaker* maker = test -> NewRenderMaker();
	cout << "Calling a method in IRenderMaker just to check that the object is good" << endl;
	cout << "(Using a stub for LatexMaker because of parameter issues)" << endl;
	maker->generateDoc(0, "antidisestablishmentarianism");
	 
	system("pause");
	return 0;
}
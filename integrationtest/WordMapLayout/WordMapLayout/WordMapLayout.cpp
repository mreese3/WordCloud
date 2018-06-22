#include <cstdlib>
#include <iostream>
#include <string>

#include "ICloudLayout.h"
//#include "LatexMaker.h"
#include "randomLayout.h"
#include "DocList.h"
#include "FreqList.h"
#include "LatexFactory.h"
#include "LatexUtil.h"
#include "MapItem.h"
#include "Point.h"
#include "Size.h"
#include "WordCount.h"
#include "WordMap.h"
#include "WordMapMaker.h"
#include "IRenderFactory.h"
#include "IRenderMaker.h"
using namespace std;


int main()
{
	WordMap* test = new WordMap();


	//IRenderMaker* rendermaker = new LatexMaker();
	//ICloudLayout* llayout = new RandomLayout();

	int wordCount = 1;


	if ((*test).read("wordmap")) {
		cout << "File Read" << endl;
	}
	else 
	{
		cout << "There is an Error with your file.";
		system("pause");
		return 1;
	}


	MapItem testItem1 = MapItem();
	testItem1.fromString("qwerty;0;0;0;260;130");
	(*test).append(testItem1);


	MapItem testItem2 = MapItem();
	testItem2.fromString("apple;100;300;0;50;80");
	(*test).append(testItem2);


	MapItem testItem3 = MapItem();
	testItem3.fromString("turkey;203;0;100;90");
	(*test).append(testItem3);


	
	system("PAUSE");
	return 0;
}
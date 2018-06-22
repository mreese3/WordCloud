#include "LinesLayout.h"
using namespace std;
#include <iostream>

int main()
{
	LinesLayout *myLinesLayout = new LinesLayout();
	WordMap *wmap = new WordMap;

	// A few MapItes to play with.

	 for (int i = 0; i < 12; i++) {

		MapItem Item1 = MapItem();
		Item1.fromString("magus;5;159;356;386;500;");
		(*wmap).append(Item1);

		MapItem Item2 = MapItem();
		Item2.fromString("peanutbutterjellytime;8;2;4;451;3157;");
		(*wmap).append(Item2);

		MapItem Item3 = MapItem();
		Item3.fromString("lolol;2;2;4;150;385;");
		(*wmap).append(Item3);

		MapItem Item4 = MapItem();
		Item4.fromString("qwerty;9;2;4;1082;541;");
		(*wmap).append(Item4);

		MapItem Item5 = MapItem();
		Item5.fromString("swagamuffin;4;2;4;873;238;");
		(*wmap).append(Item5);

		MapItem Item6 = MapItem();
		Item6.fromString("swagamuffi;7;2;4;1252;376;");
		(*wmap).append(Item6);
	}

	// Shuffle that sucker!
	(*wmap).randomize();
	// Call set location!
	(*myLinesLayout).setLocation(wmap);
	while (!(*wmap).isEmpty()) {
	cout << (*wmap).popNext().toString() << endl;
		}
	cout << "If the program produced output in the form of MapItems, and has not crashed," << endl;
	cout << "save the output to a wordmap, and run the LatexMaker unit test over it, to check the layout" << endl;
	cout << "Everything looks good from here!" << endl;
	system("pause");
	return 0;

}

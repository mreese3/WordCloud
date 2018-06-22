#include "ColumnLayout.h"
#include <iostream>
using namespace std;

int main()
{
	ColumnLayout *cLayout = new ColumnLayout();
	WordMap *wmap = new WordMap;

	for (int i = 0; i < 13; i++) {
		MapItem Item1 = MapItem();
		Item1.fromString("magus;5;159;356;386;500;");
		(*wmap).append(Item1);

		MapItem Item2 = MapItem();
		Item2.fromString("peanutbutterjellytime;8;2;4;451;3157;");
		(*wmap).append(Item2);

		MapItem Item3 = MapItem();
		Item3.fromString("lolol;2;2;4;150;385;");
		(*wmap).append(Item3);
	}

	(*wmap).randomize();
	// Call set location!
	(*cLayout).setLocation(wmap);
	while (!(*wmap).isEmpty()) {
		cout << (*wmap).popNext().toString() << endl;
	}
	system("pause");
	return 0;

}
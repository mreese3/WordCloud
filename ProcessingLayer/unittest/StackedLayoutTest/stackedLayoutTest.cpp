#include "StackedLayout.h"
#include <iostream>

using namespace std;

int main(){
	StackedLayout* test = new StackedLayout();
	WordMap *wmap = new WordMap;

	for (int x = 0; x < 4; x++){
		MapItem Item1 = MapItem();
		Item1.fromString("helloWorld;5;159;356;386;500;");
		(*wmap).append(Item1);

		MapItem Item2 = MapItem();
		Item2.fromString("peanutbutter;8;2;4;451;3157;");
		(*wmap).append(Item2);

		MapItem Item3 = MapItem();
		Item3.fromString("hammertime;2;2;4;150;385;");
		(*wmap).append(Item3);

		MapItem Item4 = MapItem();
		Item4.fromString("lunch;9;2;4;1082;541;");
		(*wmap).append(Item4);

		MapItem Item5 = MapItem();
		Item5.fromString("bacon;4;2;4;873;238;");
		(*wmap).append(Item5);

		MapItem Item6 = MapItem();
		Item6.fromString("cheese;7;2;4;1252;376;");
		(*wmap).append(Item6);
	}
	(*wmap).randomize();

	(*test).setLocation(wmap);

	MapItem temp;

	while (!(*wmap).isEmpty()) {
		temp = (*wmap).popNext();
		cout<<"Font Size: "<<temp.getFontSize()<<" Location: "<<temp.getLocation()->getX() << ", " << temp.getLocation()->getY() << "\n";
	}

	system("pause");
	return 0;
}
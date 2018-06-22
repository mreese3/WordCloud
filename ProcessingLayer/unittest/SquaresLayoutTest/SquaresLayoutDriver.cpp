#include "SquaresLayout.h"
using namespace std;
#include <iostream>
#include <fstream>
#include "LatexMaker.h"
#include "WordMap.h"


int main()
{
	SquaresLayout *mySquaresLayout = new SquaresLayout();
	WordMap *wmap = new WordMap;


	for (int i = 0; i < 60; i++) {

		MapItem Item1 = MapItem();
		Item1.fromString("abcdef;5;159;356;386;500;");
		(*wmap).append(Item1);
		
		
		MapItem Item3 = MapItem();
		Item3.fromString("ghijkl;7;2;4;600;500;");
		(*wmap).append(Item3);
		/*
		MapItem Item4 = MapItem();
		Item4.fromString("qwerty;9;2;4;1082;541;");
		(*wmap).append(Item4);

		MapItem Item5 = MapItem();
		Item5.fromString("swagamuffin;4;2;4;873;238;");
		(*wmap).append(Item5);

		MapItem Item6 = MapItem();
		Item6.fromString("swagamuffi;7;2;4;1252;376;");
		(*wmap).append(Item6);
		*/
	}

	//wmap->randomize();
	mySquaresLayout->setLocation(wmap);
	ofstream myfile;
	myfile.open("wordmap");
	while (!(*wmap).isEmpty()) {
		myfile << (*wmap).popNext().toString() << endl;
	}
	myfile.close();

	system("del output.tex");
	string filename = "output.tex";
	WordMap* testmap = new WordMap();
	if ((*testmap).read("wordmap")) {
		cout << "Successfully read wordmap" << endl;
	}
	else {
		cerr << "Could not read WordMap, Major Issue" << endl;
		cerr << "Dieing a horrible death!" << endl;
		system("pause");
		return 1;
	}
	// Make a copy of testmap. Popping the elements of makes the second part difficult.
	WordMap mappymap = (*testmap);
	WordMap* testmap2 = &mappymap;


	cout << "\n================================================\n" << endl;
	IRenderMaker* rendermaker = new LatexMaker();
	cout << "Creating a new document from the WordMap" << endl;
	(*rendermaker).generateDoc(testmap, filename);
	cout << "The new document!" << endl;
	system("type output.tex");
	cout << endl;

	return 0;

}
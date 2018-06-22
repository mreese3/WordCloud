#include <cstdlib>
#include <iostream>
#include <string>

#include "MapItem.h"
#include "Point.h"
#include "Size.h"
#include "WordMap.h"
#include "ICloudLayout.h"
#include "LinesLayout.h"
#include "LatexFactory.h"
#include "LatexMaker.h"
#include "LatexUtil.h"
using namespace std;

int main()
{
	// Initalize the WordMap(s) and call RenderMaker!
	WordMap* testmap 	= new WordMap();
	WordMap* testmap2 	= new WordMap();
	WordMap* holdingmap	= new WordMap();

	IRenderMaker* rendermaker = new LatexMaker();
	ICloudLayout* llayout = new LinesLayout();

	// Output filename strings
	string filename1 = "output.tex1";
	string filename2 = "output.tex2";

	// The WordMap below should have 20 items.
	int wordcount = 1;

	// Read in the first WordMap, and fail if unable.
	// The failure here could just be a missing file, but we don't know.
	if ((*testmap).read("wordmap")) {
		cout << "Successfully read wordmap" << endl;
		}
	else {
		cerr << "Could not read WordMap, Major Issue" << endl;
		cerr << "Dieing a horrible death!" << endl;
		system("pause");
		return 1;
		}

	// Make a WordMap with (2 * 10) items.
	for (int i = 0; i < 2; i++) {

                MapItem Item1 = MapItem();
                Item1.fromString("abacus;0;0;0;260;130;");
                (*testmap2).append(Item1);

                MapItem Item2 = MapItem();
                Item2.fromString("bovine;1;2;4;347;174;");
                (*testmap2).append(Item2);

                MapItem Item3 = MapItem();
                Item3.fromString("carnivore;2;2;4;586;196;");
                (*testmap2).append(Item3);

                MapItem Item4 = MapItem();
                Item4.fromString("derrick;3;2;4;507;217;");
                (*testmap2).append(Item4);

                MapItem Item5 = MapItem();
                Item5.fromString("euphrates;4;2;4;714;238;");
                (*testmap2).append(Item5);

                MapItem Item6 = MapItem();
                Item6.fromString("firefly;5;2;4;609;261;");
                (*testmap2).append(Item6);

                MapItem Item7 = MapItem();
                Item7.fromString("golfcart;6;2;4;834;313;");
                (*testmap2).append(Item7);

                MapItem Item8 = MapItem();
                Item8.fromString("hicky;7;2;4;626;376;");
                (*testmap2).append(Item8);

                MapItem Item9 = MapItem();
                Item9.fromString("indigo;8;2;4;902;451;");
                (*testmap2).append(Item9);

                MapItem Item10 = MapItem();
                Item10.fromString("jiggle;9;2;4;1082;541;");
                (*testmap2).append(Item10);
        	}

	// Shuffle for funzies!
	(*testmap2).randomize();
	
	while (!(*testmap2).isEmpty()) {
		(*holdingmap).append((*testmap2).popNext());
		wordcount++;
		}

	while (!(*holdingmap).isEmpty()) {
		(*testmap2).append((*holdingmap).popNext());
		}

	if (wordcount != 20) {
		cerr << "WARN: testmap2 is not the right size." << endl;
		}
	else {
		cout << "testmap2 generated successfully" << endl;
		}
	

	cout << "\n================================================\n" << endl;
	cout << "Creating a new document from the first WordMap" << endl;
	
	(*llayout).setLocation(testmap);
	(*rendermaker).generateDoc(testmap, filename1);
	cout << "\n================================================\n" << endl;
	
	cout << "The New Document (Arranged in Lines): " << endl;
	cout << "(FIRST WORDMAP)" << endl;
	system("type output.tex1");
	system("pause");

	cout << "\n================================================\n" << endl;
	cout << "Creating a new document from the second WordMap" << endl;
	
	(*llayout).setLocation(testmap2);
	(*rendermaker).generateDoc(testmap2, filename2);
	cout << "\n================================================\n" << endl;
	
	cout << "The New Document (Arranged in Lines): " << endl;
	cout << "(SECOND WORDMAP)" << endl;
	system("type output.tex2");
	system("pause");

	// Clean up logic!
	cout << endl << "Cleaning up with \"del output.tex*\"" << endl;
	system("del output.tex*");


	delete testmap;
	delete testmap2;
	delete holdingmap;
	
	return 0;
}

#include <iostream>
#include <string>
#include "LatexMaker.h"
#include "WordMap.h"

using namespace std;

int main() {
	// This driver makes use of dos commands to print and remove the file.
	// No point reinventing the wheel, when dumping the file to the screen
	// is outside the scope of the project.

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
	cout << "\n================================================\n" << endl;
	cout << "Creating a new document, even though the filename is in use." << endl;
	(*rendermaker).generateDoc(testmap2, filename);
	system("type output.tex.1");
	cout << endl << "Cleaning up with \"del output.tex*\"" << endl;
	system("del output.tex*");
	system("pause");
}

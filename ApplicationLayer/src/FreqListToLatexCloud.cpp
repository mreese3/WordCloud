#include "DocList.h"
#include "WordMapMaker.h"
#include "WordMap.h"
#include "ICloudLayout.h"
#include "IRenderMaker.h"
#include "MapItem.h"
#include "FreqList.h"
#include <fstream>
#include <iostream>
#include <string>
#include "FreqMaker.h"
#include "StemmedList.h"
#include "LinesLayout.h"
#include "LatexMaker.h"

//pre: Valid input filename and output filename, the input file contains word frequencies. 
//pre: Command line parameters of freqListFileName and latexOutputFileName.
//post: Latex Cloud output to .tex

int main(string args[])
{
	StemmedList *beginList = new StemmedList;
	beginList->read("output");
	FreqMaker *makeFreq = new FreqMaker;
	ICloudLayout *layout = new LinesLayout;
	WordMapMaker *mMaker = new WordMapMaker();
	WordMap *wmap = mMaker->convertList(makeFreq->stemToFreq(beginList));
	layout->setLocation(wmap);
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
		cerr << "Unable to read wordmap" << endl;
		system("pause");
		return 1;
	}

	cout << "\n================================================\n" << endl;
	IRenderMaker* rendermaker = new LatexMaker();
	cout << "Creating a new document from the WordMap" << endl;
	(*rendermaker).generateDoc(testmap, filename);
	cout << "The new document!" << endl;
	system("type output.tex");
	cout << endl;

}
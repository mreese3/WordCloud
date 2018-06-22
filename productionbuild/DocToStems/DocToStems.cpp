// DocToStems.cpp

#include "wordlistparser.h"
#include "stemMaker.h"
#include "StemmedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	string fileName = "example.txt";
	WordListParser* parser = new WordListParser(); // fileName);

	wordlist* wList = parser->Parser("example.txt");
	wordlist* stopList = new wordlist();
	stopList->readfile("stoplist.txt");

	stemMaker* sMaker = new stemMaker();
	sMaker->readStopList(stopList);
	StemmedList* sList = sMaker->createStemmedList(wList);

	sList->write("output");
	system("pause");
	return 0;
}
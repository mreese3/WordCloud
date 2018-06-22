#include "wordlistparser.h"
#include "stemMaker.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{	
	//creates a wordlistparser
	WordListParser parser("example.txt");

	//creates a wordlist
	wordlist wList;

	//create a stemmedlist
	StemmedList sList;

	//create a stemmaker
	stemMaker sMaker;

	//calls worlistparser to parse words from file and puts them into a wordlist
	wList = *parser.Parser("example.txt");

	//uses stemmaker to create a stemmedlist
	sList = *sMaker.createStemmedList(&wList);

	//writes the stemmed list to a file
	sList.write("filename");

	system("pause");
	return 0;
}
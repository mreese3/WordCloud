//wordlistparser.h
//Takes input from a file and removes all punctuation leaving only abc characters
//wordlist object may change 

#ifndef WORDLISTPARSER_H
#define WORDLISTPARSER_H
#include <string>
#include "WordList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class WordListParser{
public:
	WordList* Parser(string);
	~WordListParser();
	WordListParser(string);
private:
	string FILELOCATION;
};

#endif


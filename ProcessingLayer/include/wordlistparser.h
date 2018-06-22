//wordlistparser.h
//Takes input from a file and removes all punctuation leaving only abc characters
//wordlist object may change 

#ifndef WORDLISTPARSER_H
#define WORDLISTPARSER_H
#include <string>
#include "wordlist.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class WordListParser{
public:
	wordlist* Parser(string);
	wordlist write(string word);
	~WordListParser();
	WordListParser();
private:
	string FILELOCATION;
};

#endif


//WordListParser
//Takes input from a file and removes all punctuation leaving only abc characters
//WordList object may change 

#include "WordListParser.h"
using namespace std;

wordlist* WordListParser::Parser(string fileLocation){
	wordlist* list;
	ifstream infile;
	string words;
	FILELOCATION = fileLocation;
	list = new wordlist;
	infile.open(FILELOCATION);

	if (infile.is_open()){
		while (getline(infile, words, '\n')){
			for (int x = 0; x < words.length(); x++){
				if ((words[x] < 'a' || words[x] > 'z') && (words[x] < 'A' || words[x] > 'Z'))
					list->addWord(words);//words[x] = NULL;
			}
			//list->writeToFile("outfile.txt");
		}

		infile.close();
		return list;
	}
	else
		cout << "failed to open";
}

//Constructor requires file input
WordListParser::WordListParser(string fileLoc){
	FILELOCATION = fileLoc;
}

//Deconstructor
WordListParser::~WordListParser(){
	FILELOCATION = "";
}
//WordListParser
//Takes input from a file and removes all punctuation leaving only abc characters
//WordList object may change 

#include "wordlistparser.h"
#include <sstream>
using namespace std;

wordlist* WordListParser::Parser(string fileLocation){
	wordlist* list;
	ifstream infile;
	string words;
	FILELOCATION = fileLocation;
	list = new wordlist();
	infile.open(FILELOCATION);

	if (infile.is_open()){
		while (getline(infile, words, '\n')){

			for (int i = 0; i < words.size(); i++) 
				words.replace(i, 1, 1, tolower(words[i]));
		
			for (int x = 0; x < words.length(); x++){
				if ((words[x] < 'a' || words[x] > 'z') && (words[x] < 'A' || words[x] > 'Z') && words[x] != '\'')
					words[x] = ' ';
			}

			istringstream iss(words);
			string word;
			while (iss >> word){
				//cout << word;
				list->addWord(word);
			}
		}

		infile.close();
		return list;
	}
	else
		cout << "failed to open";
}

//Constructor requires file input
WordListParser::WordListParser() { //string fileLoc){
	//Parser(fileLoc);
	//FILELOCATION = fileLoc;
}

//Deconstructor
WordListParser::~WordListParser(){
	FILELOCATION = "";
}

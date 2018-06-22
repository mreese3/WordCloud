
#ifndef WORDLIST_H
#define WORDLIST_H
#include <list>
#include <iostream>
#include <string>
using namespace std;

class wordlist
{
public:

	wordlist();
	 ~wordlist();
	 void writeToFile(string file);
	 void readfile(string file);
	 void addWord(string word);
	// methods to look through the list: get first word, get next word
	string first();
	string getnext();
	// isWordlist checks wether the word in the list
	bool isWordinlist(string word);


private:
	list<string> words; 
	list<string>:: const_iterator i ;
	
};

#endif


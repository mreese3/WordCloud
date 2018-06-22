#ifndef WORDLIST_H
#define WORDLIST_H

#include <string>
#include <list>
using namespace std;

class WordList
{
public:
	virtual ~WordList();
	virtual string getword();
	virtual string getstoplist();
	virtual void write(string word) = 0;
	//virtual void writestoplist(string stoplist_word);
	virtual void writeToFile(string file_path);
	
private:
	list<string> asci_words;
	list<string> stoplist_words;
	string file_path;
};

#endif
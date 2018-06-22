#include <iostream>
#include "stemMaker.h"
#include "wordlist.h"
#include "StemmedList.h"

using namespace std;

int main()
{
	wordlist* stopList = new wordlist();
	stopList->addWord("the");
	stopList->addWord("and");
	stopList->addWord("a");
	stopList->addWord("or");
	stopList->addWord("if");
	stopList->addWord("but");

	wordlist* wordList = new wordlist();
	wordList->addWord("the");
	wordList->addWord("quick");
	wordList->addWord("brown");
	wordList->addWord("fox");
	wordList->addWord("jumped");
	wordList->addWord("over");
	wordList->addWord("the");
	wordList->addWord("yellow");
	wordList->addWord("fence");
	wordList->addWord("and");
	wordList->addWord("brown");
	wordList->addWord("fox");
	wordList->addWord("fox");
	wordList->addWord("yellow");
	wordList->addWord("fox");

	stemMaker* maker = new stemMaker();
	maker->readStopList(stopList);
	StemmedList* stemmedList = maker->createStemmedList(wordList);
	stemmedList->write("testoutput");
	delete maker;

}
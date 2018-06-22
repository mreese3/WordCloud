#include <iostream>

#include "stemMaker.h"
#include "wordlist.h"
#include "StemmedList.h"

using namespace std;

stemMaker::stemMaker()
{
	_stopList = 0;
}

stemMaker::~stemMaker()
{
}

void
stemMaker::readStopList(wordlist* stopList )
{
	_stopList = stopList;
}

StemmedList*
stemMaker::createStemmedList(wordlist* wordList)
{
	StemmedList* stemmedList = new StemmedList();

	string word = wordList->first();
	int size = wordList->getSize();
	for (int i = 1; i < size; i++)
	{
		// if the word is not in the stop list
		if (!_stopList->isWordinlist(word))
		{
			// to do: stem it!
			string stem = word;

			// add it to the stemmedList
			stemmedList->add(stem, word);
		}
		word = wordList->getnext();
	}
	return stemmedList;
}

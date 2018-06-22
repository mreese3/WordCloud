#include <iostream>

#include "stemMaker.h"
#include "wordlist.h"
#include "StemmedList.h"

using namespace std;

stemMaker::stemMaker()
{
}

stemMaker::~stemMaker()
{
}

void stemMaker::readStopList(wordlist* stopList)
{
}

StemmedList* stemMaker::createStemmedList(wordlist* stopList)
{
	StemmedList* list = new StemmedList();
	return list;
}

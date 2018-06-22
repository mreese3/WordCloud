#include "freqmaker.h"
#include "StemmedList.h"
#include "DocList.h"
//#include "WordCount.h"
//#include "FreqList.h"

FreqMaker::FreqMaker()
{

}
FreqMaker::~FreqMaker()
{

}
DocList * FreqMaker::stemToFreq(StemmedList * list)
{
	FreqList * newFreqList = new FreqList;
	FreqList * currentList = list->getFirst();
	WordCount * currentWord;
	while (currentList != NULL)
	{
		
		currentWord = currentList->getNext();
		currentWord->setCount(currentList->getFirst()->getCount());
		newFreqList->addinlist(currentWord);
		currentList = list->getNext();
	}
	newFreqList->write("newFreqList.txt");
	DocList * newDocList = new DocList("newFreqList.txt");
	return newDocList;
}
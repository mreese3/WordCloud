#include "FreqList.h";
#include "WordCount.h";

FreqList::~FreqList() {}

void FreqList::read(string path) {}

void FreqList::write(string path) {}

WordCount *FreqList::getFirst()
{
	return new WordCount("dad", 7);
}

WordCount *FreqList::getLast()
{
	return new WordCount("mom", 10);
}

WordCount *FreqList::getNext()
{
	return new WordCount("sister", 6);
}

WordCount *FreqList::getSize()
{
	return new WordCount("brother", 42);
}

void FreqList::sortbycount() {}

void FreqList::addinlist(WordCount *wc) {}

WordCount *FreqList::removefromlist()
{
	return new WordCount("uncle", 19);
}

void FreqList::updatelist(int count) {}

list<WordCount*> FreqList::getlist()
{
	return freqList;
}

list<WordCount*> FreqList::Topn(int index)
{
	return freqList;
}

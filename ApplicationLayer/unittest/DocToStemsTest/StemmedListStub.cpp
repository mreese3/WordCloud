#include "StemmedList.h"
#include "FreqList.h"

StemmedList::StemmedList()
{

}
StemmedList::~StemmedList()
{

}
void StemmedList::read(std::string fileName)
{

}
void StemmedList::write(std::string fileName)
{
	ofstream file;
	file.open(fileName + ".txt");
	StemItem * currentItem = firstItem;
	FreqList * currentList = currentItem->currentList;
	while (currentList != NULL)
	{
		WordCount * currentWord = currentList->getFirst();
		while (currentWord != NULL)
		{
			file << currentWord->getWord() << "\t" << currentWord->getCount() << "\n";
			currentWord = currentList->getNext();
			if (currentWord = currentList->getLast())
			{
				file << currentWord->getWord() << "\t" << currentWord->getCount() << "\n";
				break;
			}
			else
			{
				currentWord = currentList->getNext();
			}
		}
		currentItem = currentItem->nextList;
		if (currentItem != NULL)
			currentList = currentItem->currentList;
		else
			break;
	}
	file.close();
}
FreqList * StemmedList::getFirst()
{
	return ((firstItem->nextList)->currentList);
}
FreqList * StemmedList::getNext(StemItem item)
{
	return item.nextList->currentList;
}
void StemmedList::add(string stem, string word)
{
	if (firstItem == NULL)
	{
		FreqList * newStemFreqList = new FreqList();
		WordCount * newWordStem = new WordCount(stem, 1);
		newStemFreqList->addinlist(newWordStem);
		if (stem != word)
		{
			FreqList * newFreqList = new FreqList();
			WordCount * newWord = new WordCount(word, 1);
			newFreqList->addinlist(newWord);
		}
		StemItem * item = new StemItem();
		item->currentList = newStemFreqList;
		firstItem = item;
	}
	else
	{
		StemItem * currentItem = firstItem;
		FreqList * currentFreqList = currentItem->currentList;
		bool itemNotFound = true;
		while (currentFreqList != NULL && itemNotFound)
		{
			WordCount * currentWord = currentFreqList->getFirst();
			if (stem == currentWord->getWord())
			{
				currentWord->setCount((currentWord->getCount() + 1));
				while (stem != word)
				{
					currentWord = currentFreqList->getNext();
					if (word == currentWord->getWord())
					{
						currentWord->setCount(currentWord->getCount() + 1);
						break;
					}
					else if (currentWord == currentFreqList->getLast())
					{
						WordCount * newWord = new WordCount(word, 1);
						currentFreqList->addinlist(newWord);
						break;
					}
				}
				break;
			}
			else
			{
				if (currentItem->nextList == NULL)
				{
					FreqList * newFreqList = new FreqList();
					WordCount * newStem = new WordCount(stem, 1);
					newFreqList->addinlist(newStem);
					if (stem != word)
					{
						WordCount * newWord = new WordCount(word, 1);
						newFreqList->addinlist(newWord);
					}
					StemItem * newStemItem = new StemItem;
					newStemItem->currentList = newFreqList;
					newStemItem->previousList = currentItem;
					currentItem->nextList = newStemItem;
					break;
				}
				else
				{
					currentItem = currentItem->nextList;
					currentFreqList = currentItem->currentList;
				}
			}
		}
	}
}
void StemmedList::makeEmpty()
{
	StemItem * currentItem = firstItem;
	while (currentItem != NULL)
	{
		FreqList * currentList = currentItem->currentList;
		while (currentList != NULL)
		{
			//currentList->
		}
	}
}
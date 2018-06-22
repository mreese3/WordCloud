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
	makeEmpty();
	string currentLine;
	bool isStem = false;
	StemItem* newStem;
	StemItem* currentItem;
	FreqList * newList;
	WordCount * newWord;
	string path = fileName + ".txt";
	if (ifstream(path))
	{
		ifstream ifs;
		ifs.open(path);
		getline(ifs, currentLine);
		getline(ifs, currentLine);
		StemItem * first = new StemItem;
		newList = new FreqList;
		newWord = new WordCount(currentLine);
		newList->addinlist(newWord);
		first->currentList = newList;
		firstItem = first;
		currentItem = firstItem;
		getline(ifs, currentLine);
		while (currentLine != "")
		{
			if (currentLine == "Stem:")
			{
				isStem = true;			
			}
			if (isStem == true)
			{
				newStem = new StemItem;
				newList = new FreqList;
				getline(ifs, currentLine);
				newWord = new WordCount(currentLine);
				newList->addinlist(newWord);
				newStem->currentList = newList;
				currentItem->nextList = newStem;
				currentItem = currentItem->nextList;
				getline(ifs, currentLine);
				isStem = false;
			}
			else
			{
				newWord = new WordCount(currentLine);
				newList->addinlist(newWord);
				newList->sortbycount();
				getline(ifs, currentLine);
			}
		}
	}
	else
	{
		cout << "StemmedList says: No file by the name of " << fileName << " exists.\n";
	}
}

void StemmedList::write(std::string name)
{
	ofstream ofs;
	string fileName = name + ".txt";
	int i = 0;
	// First check if file exists, since FreqList opens the file for appending
	if (ifstream(fileName))
	{
		fileName = name + "1.txt";
		if (ofstream(fileName))
		{
			// open and close the file in order to empty it out
			ofs.open(fileName);
			ofs.close();
		}
	}
	StemItem * currentItem = firstItem;
	WordCount * stem;
	FreqList * currentList;
	while (currentItem != NULL)
	{
		/*currentList = currentItem->currentList;
		currentList->write(fileName);
		currentItem = currentItem->nextList;*/
		currentList = currentItem->currentList;
		stem = currentList->getFirst();
		ofs.open(fileName, std::ios_base::app);
		ofs << "Stem:\n";
		ofs.close();
		currentList->write(fileName);
		currentItem = currentItem->nextList;
	}
}
FreqList * StemmedList::getFirst()
{
	currentItem = firstItem;
	return currentItem->currentList;
}
FreqList * StemmedList::getNext()
{
	if (currentItem == NULL)
	{
		return getFirst();
	}
	else if (currentItem->nextList != NULL)
	{
		currentItem = currentItem->nextList;
	}
	else
	{
		return NULL;
	}
	return currentItem->currentList;
}
void StemmedList::add(string stem, string word)
{
	if (firstItem == NULL)
	{
		StemItem * item = new StemItem();
		FreqList * newStemFreqList = new FreqList();
		WordCount * newWordStem = new WordCount(stem, 1);
		newStemFreqList->addinlist(newWordStem);
		if (stem != word)
		{
			WordCount * newWord = new WordCount(word, 1);
			newStemFreqList->addinlist(newWord);
		}	
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
					if (currentFreqList->getSize() != 1)
						currentWord = currentFreqList->getNext();
					else
					{
						WordCount * newWord = new WordCount(word, 1);
						currentFreqList->addinlist(newWord);
						//currentFreqList->sortbycount();
						break;
					}
					if (word == currentWord->getWord())
					{
						currentWord->setCount(currentWord->getCount() + 1);
						//currentFreqList->sortbycount();
						break;
					}
					else if (currentWord == currentFreqList->getLast())
					{
						WordCount * newWord = new WordCount(word, 1);
						currentFreqList->addinlist(newWord);
						break;
					}
					//currentFreqList->sortbycount();
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
					currentFreqList->sortbycount();
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
		FreqList * currentList;	
		currentList = currentItem->currentList;		
		currentList->removeall();		
		currentItem = currentItem->nextList;
	}
	firstItem = NULL;
}


#include "WordMapMaker.h"
#include "WordCount.h"
#include <list>

WordMapMaker::WordMapMaker()
{
}

WordMapMaker::WordMapMaker(string filename)
{
	convertList(new DocList(filename));
}

WordMapMaker::~WordMapMaker()
{
}

void WordMapMaker::printWordmap()
{
	MapItem temp;
	while (!mapWords.isEmpty())
	{
		temp = mapWords.popNext();
		cout << "Word: " << temp.getWord() << " Font Size: " << temp.getFontSize() << endl;
		
	}
	system("pause");
}

WordMap* WordMapMaker::convertList(DocList *freqList)
{
	MapItem *tempMap = new MapItem;
	WordCount *tempWord = freqList->getFirst();
	int high = tempWord->getCount(), low = tempWord->getCount();


	do
	{
			tempWord = freqList->getNext();
		if (tempWord->getCount() > high)
			high = tempWord->getCount();
		else if (tempWord->getCount() < low)
			low = tempWord->getCount();
	} while (tempWord != freqList->getLast());
	int difference = high - low + 1;
	int fontlevels = difference / 10;

	tempWord = freqList->getFirst();
	do
	{
		if (!mapWords.isEmpty())
			tempWord = freqList->getNext();
		tempMap->setWord(tempWord->getWord());
		tempMap->setFontSize(tempWord->getCount() * 10 / difference);
		Size * newSize = new Size;
		newSize->setHeight(tempWord->getCount() * 10 / difference);
		newSize->setWidth(tempWord->getCount() * 10 / difference);
		tempMap->setSize(newSize);
		Point * newPoint = new Point;
		newPoint->setX(0);
		newPoint->setY(0);
		tempMap->setLocation(newPoint);
		mapWords.append(*tempMap);
	} while (tempWord != freqList->getLast());

	/*for (int i = 1; i <= freqList->getSize(); i++)
	{
		tempMap = new MapItem;
		tempMap->setWord(tempWord->getWord());
		tempMap->setFontSize(fontsize);

		if (i % fontlevels == 0 && i  >= fontlevels)
			fontsize++;
		mapWords.append(*tempMap);
		if(i < freqList->getSize())
			tempWord = freqList->getNext();
	}*/
	//printWordmap();
	//mapWords.write("coolfile.txt");
    return &mapWords;
}
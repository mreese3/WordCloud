#include <iostream>
#include "DocList.h"
#include "WordCount.h"

int DocList::read()
{
	return fList->read(nameFile);
}
    
int DocList::write()
{
	return fList->write(nameFile);
}

WordCount * DocList::getFirst()
{
	return fList->getFirst();
}

WordCount * DocList::getLast()
{
	return fList->getLast();
}

WordCount * DocList::getNext()
{
	return fList->getNext();
}

int DocList::getSize()
{
	return fList->getSize();
}

void DocList::sortbycount()
{
	fList->sortbycount();
}

void DocList::addinlist(WordCount * w)
{
	fList->addinlist(w);
}


//void DocList::updatelist(int count)
//{
//	fList->updatelist(count);
//}

vector<WordCount *> DocList::getlist()
{
	return fList->getlist();
}

vector<WordCount *> DocList::Topn(int index)
{
	return fList->Topn(index);
}

DocList::DocList(string name)
{
	nameFile = name;
	fList = new FreqList;
	fList->read(nameFile);
}

DocList::DocList()
{
	fList = new FreqList;
}

DocList::~DocList()
{
}

void DocList::printfList()
{
	WordCount *temp = getFirst();
	cout << "Word: " <<temp->getWord() << " Frequency: "<< temp->getCount() << endl;
	for (int i = 1; i < fList->getSize(); i++)
	{
		temp = getNext();
		cout << "Word: " << temp->getWord() << " Frequency: " << temp->getCount() << endl;
	}
	system("pause");
}

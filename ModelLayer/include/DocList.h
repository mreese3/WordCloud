#ifndef DOCLIST_H
#define DOCLIST_H

#include "MapItem.h"
#include "FreqList.h"
#include <string>
using namespace std;

class DocList
{
public:
    int read();
    ////pre: Valid filename
    ////post: frequency list is read into fList. If bad filename, program exits
    //
    int write();
    ////pre: Valid filename, fList containing frequencies
    ////post: Frequency list written to file. If bad filename, program exits
    
	virtual WordCount * getFirst();
	//Calls fList.getFirst()

	virtual WordCount * getLast();
	//Calls fList.getLast()

	virtual WordCount * getNext();
	//Calls fList.getNext()

	virtual int getSize();
	//Calls fList.getSize()

	virtual void sortbycount();
	//Calls fList.sortbycount()

	virtual void addinlist(WordCount * w);
	////Calls fList.addinlist()

	//virtual void updatelist(int count);
	////Calls fList.updatelist()

	virtual vector<WordCount*>getlist();
	////Calls fList.getlist()

	virtual vector<WordCount *> Topn(int index);
	////Calls fList.Topn()
	DocList(string);
	DocList();
	~DocList();
private:
    FreqList *fList;
	string nameFile;
	void printfList();
};

#endif
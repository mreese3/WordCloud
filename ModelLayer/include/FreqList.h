#ifndef FREQLIST_H
#define FREQLIST_H

#include "WordCount.h"
#include "WordMap.h"
#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class WordCount;

class FreqList {
public:
	FreqList();
	virtual ~FreqList();
	virtual int read(string path_file);
	virtual int write(string path_file);
	virtual WordCount* getFirst();
	virtual WordCount* getLast();
	virtual WordCount* getNext();
	virtual int getSize();
	virtual void sortbycount();
	virtual void addinlist(WordCount* wc);
	//virtual void updatelist(int count);
	virtual vector<WordCount*>getlist();
	virtual vector<WordCount*>Topn(int index);
	//void FreqList::resetposition();
	WordCount* FreqList::remove();
	void FreqList::removeall();
	
public:
	//int position = 1;
	vector<WordCount*>::iterator position;
	bool done = false;
	vector<MapItem*> mapitemlist;
	vector<WordCount*> freqList;
	//int _current_item;
	//vector<WordCount*>::iterator start = freqList.begin();
	//vector<WordCount*>::iterator end = freqList.end();
	
};

#endif
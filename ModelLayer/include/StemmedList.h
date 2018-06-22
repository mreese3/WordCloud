#ifndef STEMMEDLIST_H
#define STEMMEDLIST_H

#include <string>
using namespace std;

//class FreqList;
#include "FreqList.h"

class StemmedList
{
private:
	struct StemItem
	{
		StemItem * previousList = NULL;
		FreqList * currentList = NULL;
		StemItem * nextList = NULL;
	};
	StemItem * firstItem = NULL;
	StemItem * currentItem = NULL;
public:
	StemmedList();
	~StemmedList();
	void read(std::string);
	void write(std::string);
	FreqList * getFirst();
	FreqList * getNext();
	void add(string stem, string word);
	void makeEmpty();
};

#endif
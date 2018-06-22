#ifndef WORDMAPMAKER_H
#define WORDMAPMAKER_H

#include "DocList.h"
#include "WordMap.h"

class WordMapMaker
{
public:
    WordMap* convertList(DocList *freqList);
    //pre: Valid DocList file with word frequencies
    //post: Makes a WordMap object out of the frequency list. Mapped to 10 font sizes.
	WordMapMaker();
	WordMapMaker(string);
	void printWordmap();
	~WordMapMaker();

private:
	WordMap mapWords;
	DocList *freqDoc;
	
};
#endif

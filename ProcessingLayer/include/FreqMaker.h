#ifndef FREQMAKER_H
#define FREQMAKER_H

class StemmedList;
class DocList;

class FreqMaker
{
public:
	FreqMaker();
	~FreqMaker();
	DocList * stemToFreq(StemmedList *);
};

#endif
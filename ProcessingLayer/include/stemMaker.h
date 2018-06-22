#ifndef STEMMAKER
#define STEMMAKER

class StemmedList;
class wordlist;

class stemMaker
{
private:
	wordlist* _stopList;
public:
	stemMaker();
	virtual void readStopList(wordlist* stopList);
	virtual StemmedList* createStemmedList(wordlist* wordList);
	virtual ~stemMaker();
};

#endif

#include "WordMapMaker.h"

int main()
{
	WordMapMaker* m = new WordMapMaker("freqlist.txt");
	m->printWordmap();
	return 0;
}
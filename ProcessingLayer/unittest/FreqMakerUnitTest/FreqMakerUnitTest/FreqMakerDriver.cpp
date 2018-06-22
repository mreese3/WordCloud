#include <fstream>
#include <iostream>
#include "StemmedList.h"
#include "DocList.h"
#include "FreqMaker.h"
using namespace std;

int main()
{
	StemmedList * stemsFile = new StemmedList;
	stemsFile->read("StemmedList");
	DocList * doc;
	FreqMaker * maker = new FreqMaker;
	maker->stemToFreq(stemsFile);
	return 0;
}
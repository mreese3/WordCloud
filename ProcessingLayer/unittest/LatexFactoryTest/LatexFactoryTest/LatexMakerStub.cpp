#include <iostream>
#include <fstream>

// For string int concatenation
#include <sstream>

// For remove function
#include <cstdio>

#include "LatexMaker.h"
#include "LatexUtil.h"
#include "WordMap.h"

using namespace std;

LatexMaker::LatexMaker() {}
LatexMaker::~LatexMaker() {}

void LatexMaker::generateDoc(WordMap* wordmap, string fname) {

	cout << "Called generateDoc with parameter " << fname << endl;
	}
#include "StemmedList.h"
//#include "FreqList.h"

#include <iostream>

using namespace std;

int main()
{
	StemmedList * list = new StemmedList();
	list->add("grease", "greasey");
	list->add("grease", "greased");
	list->add("grease", "greasing");
	list->add("tree", "trees");
	list->add("tree", "tree");
	list->add("tree", "treed");
	list->add("awake", "awakes");
	list->add("tree", "trees");
	list->add("grease", "greased");
	list->add("tree", "treed");
	list->add("tree", "treed");
	list->write("output");
	list->read("output");
	list->write("outputc");
	return 0;
}
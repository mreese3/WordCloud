#include "StemmedList.h"
#include "FreqMaker.h"
#include "WordMapMaker.h"
#include "WordMap.h"
#include "LatexMaker.h"
#include "ColumnLayout.h"

int main(int argc, char * argv[])
{
	bool trace = false;
	ofstream ofs;
	if (argc < 2)
	{
		cerr << "ERROR: StemsToLatexCloud.exe <STEMMEDLISTFILE> -<OPTIONAL TRACE FLAG: t>" << endl;
		exit(0);
	}
	if (argc > 2)
	{
		string flag = argv[2];
		if (flag == "t" || flag == "-t")
		{
			trace = true;
		}
	}
	StemmedList * sList = new StemmedList;
	if (trace == true)
	{
		ofs.open("StemsToLatexCloudLog.txt");
	}
	sList->read(argv[1]);
	if (trace == true)
	{
		ofs << "[1] Started with " << argv[1] << "\n";
	}
	FreqMaker * fMaker = new FreqMaker;
	fMaker->stemToFreq(sList);
	if (trace == true)
	{
		ofs << "[2] Converted " << argv[1] << " to newFreqList.txt"<< "\n";
	}
	WordMapMaker * mapMaker = new WordMapMaker;
	WordMap * map = mapMaker->convertList(new DocList("newFreqList.txt"));
	map->write("mapfile.txt");
	if (trace == true)
	{
		ofs << "[3] Converted newFreqList.txt to map " << argv[1] << "\n";
	}
	ICloudLayout * newLayout = new ColumnLayout;
	newLayout->setLocation(map);
	if (trace == true)
	{
		ofs << "[4] Set locations of map\n";
	}
	LatexMaker * lMaker = new LatexMaker;
	lMaker->generateDoc(map, "newlatexdoc.tex");
	if (trace == true)
	{
		ofs << "[5] Generated latex document...Done\n";
	}
}

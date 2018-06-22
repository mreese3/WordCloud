#include <iostream>
#include <fstream>

// For string int concatenation
#include <sstream>

#include "LatexMaker.h"
#include "LatexUtil.h"
// LatexUtil was not in the original specification. That said, it has
// nice functions that I would just be copying otherwise.
// I can't figure out why it exists if LatexMaker is not supposed to use it.

// G++ wouldn't let me build until I included these two. These may be redundant
// but I tried a fair deal of include hackery before conceding. IDK about
// Visual Studio.
#include "MapItem.h"
#include "WordMap.h"


// The getWidth function is useful for the setting the width of the \hbox. However, I need
// value in multiples of \TPHorizModule. \TPHorizModule is defined as .1in, and changing that
// causes all the other scales to change, were just going to divide LatexUtil::getWidth by 100
// The bounding boxes are not perfect, but they are pretty close, especially for small words.
#define WIDTHSCALEFACTOR .01


using namespace std;

LatexMaker::LatexMaker() {}
LatexMaker::~LatexMaker() {}

// Implimentation is now patched to use the fancy new WordMap methods.

void LatexMaker::generateDoc(WordMap* wordmap, string fname) {
	
	// Initialize a new LatexUtil object. We'll use that later for parameter scaling.
	LatexUtil* lutil = new LatexUtil();

	// C++ does not support a here-document, so this is going to be extremely ugly
	// This is the required syntactic headers for a LaTeX document. We can probably
	// trim some packages, but I don't know what everybody is using as their TeX
	// distribution, so we'll leave everything in from ../../../Design/Background/Comm_Princ.tex
	// 		IMPORTANT: C++ has no option for "Take this string literally", so it has been
	// 		escaped by hand. If you modify it, WATCH YOUR \s!
	// Prof H: You got a little overzealous-- no escape chars are needed for []{}
	const string latexheaders = "\\documentclass[11pt]{letter}\n\\usepackage{times}\n\\usepackage[absolute]{textpos}\n\\pagestyle{empty}\n\\setlength{\\TPHorizModule}{.1in}\n\\setlength{\\TPVertModule}{.1in}\n\\textblockorigin{10mm}{10mm}\n\\begin{document}\n";

	// If the file exists, were going to append a number to the end of the
	// filename. We'll keep going all the way to the end of the interger range,
	// if we have to. We don't know or care what the maximum filename length is
	// on these filesystems, so if the filesystem chokes on fname.(2^64 - 1),
	// I won't shed a single tear.
	unsigned int filenameappend = 0;

	
	// Test for existing file, because it's not 1975 anymore, and tar(1) is not
	// an example of a well-behaved program.
	ifstream outputtest;
	outputtest.open(fname);
	// This is dirty but common idiom for file existence. 
	// I'm using it backwards.
	string basefname = fname;
	while(outputtest.good()){
		outputtest.close();
		filenameappend++;
		// Because Stroustrup didn't think casting an int to string would be
		// useful. Argggggggggggh. This just appends filenameappend to fname
		stringstream sstm;
		sstm << basefname << "." << filenameappend;
		fname = sstm.str();
		outputtest.open(fname);
		}
	outputtest.close();

	// At this point, fname is a nonexistant or unreadable filename
	// In any case, we won't munge any data by writing to it.
	ofstream output;
	output.open(fname);
	try {
		// We need the document headers, so we may as well put them in now.
		// This is a good place to crash and burn.
		output << latexheaders;

		// While there are still objects in the WordMap
		while (!(*wordmap).isEmpty()){
			// Get our MapItem
			MapItem newItem = (*wordmap).popNext();

			//		Start Line!
			output << "\\begin{textblock}";
			// This is ugly, but is still more reliable than a string parse...
			output << "{" << ((*lutil).getWidth(newItem.getFontSize(), newItem.getWord()) * WIDTHSCALEFACTOR) << "}";
			output << "(" << (*lutil).scale_X_Coordinate((*newItem.getLocation()).getX());
			output << ",";
			output << (*lutil).scale_Y_Coordinate((*newItem.getLocation()).getY()) << ")";
			output << " " << (*lutil).fontSizeToKeyWord(newItem.getFontSize());
			output << "{" << newItem.getWord();
			output << "} \\end{textblock}" << endl;
			}
		// Close the LaTeX document and the file descriptor.
		output << "\\end{document}";
		output.close();
		}

	// We should never fall in this block. That said, some people have managed to break
	// their file permissions in amazing ways, and I'm not taking chances.
	catch(ofstream::failure e) {
		cerr << "The output file could not be written to." << endl;
		cerr << "This means your filesystem is a bloody mess, and you should feel bad." << endl;
		cerr << "Bad user!" << endl;
		}
	
	}

#ifndef LATEXMAKER_H
#define LATEXMAKER_H

#include "IRenderMaker.h"

class LatexMaker : public IRenderMaker {
	public:
		LatexMaker();
		void generateDoc(WordMap*, std::string);
		~LatexMaker();
};
#endif

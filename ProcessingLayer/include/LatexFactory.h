#ifndef LATEXFACTORY_H
#define LATEXFACTORY_H

#include "IRenderFactory.h"
class IRenderMaker;
class IRenderUtil;

class LatexFactory: public IRenderFactory
{
	public:
		LatexFactory();
		IRenderMaker* NewRenderMaker();
		IRenderUtil* NewRenderUtil();
		virtual ~LatexFactory();
};
#endif

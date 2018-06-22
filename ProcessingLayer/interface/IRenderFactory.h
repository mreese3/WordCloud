#ifndef IRENDERFACTORY_H
#define IRENDERFACTORY_H

class IRenderMaker;
class IRenderUtil;

class IRenderFactory
{
	public:
//		IRenderFactory();  // no constructor in an interface!
		virtual IRenderMaker* NewRenderMaker(void) = 0;
		virtual IRenderUtil* NewRenderUtil(void) = 0;
		virtual ~IRenderFactory() {}  // need to inline code for destructor
};

IRenderFactory* NewRenderFactory();

#endif

#ifndef IRENDERFACTORY_H
#define IRENDERFACTORY_H

class IRenderMaker;
class IRenderUtil;

class IRenderFactory
{
	public:
		IRenderFactory();
		virtual IRenderMaker* NewRenderMaker(void) = 0;
		virtual IRenderUtil* NewRenderUtil(void) = 0;
		virtual ~IRenderFactory();
};

IRenderFactory* NewRenderFactory();

#endif

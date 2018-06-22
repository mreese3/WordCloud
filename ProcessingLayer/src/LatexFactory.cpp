#include "LatexFactory.h"
#include "LatexMaker.h"
#include "LatexUtil.h"
#include "IRenderFactory.h"

LatexFactory::LatexFactory()
{
	return;
}

LatexFactory::~LatexFactory()
{
	return;
}

IRenderMaker*
LatexFactory::NewRenderMaker()
{
	return new LatexMaker();
}

IRenderUtil*
LatexFactory::NewRenderUtil()
{
	return new LatexUtil();
}

IRenderFactory* NewRenderFactory()
{
	return new LatexFactory();
}
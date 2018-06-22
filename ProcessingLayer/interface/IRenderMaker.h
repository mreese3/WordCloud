#ifndef IRENDERMAKER_H
#define	IRENDERMAKER_H

#include <string>
//#include "WordMap.h"
class WordMap;

class IRenderMaker {
        public:
                virtual void generateDoc(WordMap*, std::string) = 0;
				virtual ~IRenderMaker(){}
};

#endif
